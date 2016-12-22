// MoveByCoords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>
#include "Key.h"

#define START_STR_SIZE 8
#define INCREMENTS 4
#define MAX_SIZE_STR_NUMB 20


void MagStr (char *str)
{

	int i, j = 0;
	int flag = 0;

	int strlen_str = strlen(str);


	for(i = 0; i < strlen_str; i++){
		if((str[i] != ' ') && (str[i] != '\t') && (str[i] != '\n')){

			if((flag == 1) && ((str[i - 1] == ' ') || (str[i - 1] == '\t'))){
				str[j] = ' ';
				j++;
			}
			if(flag == 0){
				flag = 1;
			}
			str[j] = str[i];
			j++;
		}
	}
	str[j] = '\0';
}

void Bias(char *str, int count_str, int *x, int *y)
{
	
	int Strlen_Str = strlen(str);

	if (Strlen_Str > 0){

		char *adr_space = NULL;
		adr_space = strchr(str, ' ');
		if(adr_space != NULL){
		
			int Numb_simv = adr_space - str;
			char buffer[MAX_SIZE_STR_NUMB] = "";
			strcpy(buffer, adr_space + 1);

			if (!strncmp(North, str, Numb_simv)){
				*y += atoi(buffer);
			} else {

				if (!strncmp(South, str, Numb_simv)){
					*y -= atoi(buffer);
				} else {

					if (!strncmp(East, str, Numb_simv)){
						*x += atoi(buffer);
					} else {

						if (!strncmp(West, str, Numb_simv)){
							*x -= atoi(buffer);
						} else {
							My_Printer(STR_NOT_A_WORLD_SIDE, count_str);
						}
					}
				}
			}
		} else {
			 My_Printer(STR_ONE_WORD_ONLY, count_str);
		}
	} else {
		My_Printer(STR_EMPTY_STR, count_str);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	
	if (argc > 1){

		FILE *file;
		file = fopen(argv[1], "r");
	
		if(file != NULL){
			
			int x = 0, y = 0, i = 0;
			int was_error = 0;

			char *buffer = (char*) malloc(sizeof(char) * START_STR_SIZE);
			if (buffer != NULL){
				
				int count_str = 1;
				int Str_Size = START_STR_SIZE;

				while(!feof(file)){
					
					if(i >= Str_Size){ 
						Str_Size = (Str_Size + INCREMENTS);
						buffer = (char*) realloc(buffer, ((Str_Size) * sizeof(char)));

						if(buffer == NULL){
							My_Printer(STR_NOT_MEMORY);
							was_error = 1;
							break;
						}
					}
						
					buffer[i] = getc(file);

						if(!ferror(file)){ 
							My_Printer(STR_COULD_NOT_READ, count_str, strerror(errno));
							was_error = 1;
							break;
						}
						if (buffer[i] == '\n'){
							buffer[i] = '\0';
							MagStr(buffer);
							Bias(buffer, count_str, &x, &y);
							count_str++;
							i = -1; /** Для того чтобы запись каждой новой строки начиналась с 0 эллемента */
						}
						i++;
				}
				if(!was_error){
					printf(Str_Res, x, y);
					Print_Enter();
				}
				free(buffer);
			} else {
				My_Printer(STR_NOT_MEMORY);
			}
			fclose(file);
		} else {
			My_Printer(STR_ERROR_OPENING_FILE, argv[1]); 
		}
	} else {
		My_Printer(STR_FILE_NOT_RECEIVED);
	}
	system("pause");
}
