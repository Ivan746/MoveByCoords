// MoveByCoords.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdio>
#include <conio.h>
#include <cstring>

#define MAX_SIZE 101
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
			} else {
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
	static const char West[]  = "Запад";
	static const char East[]  = "Восток";
	static const char North[] = "Север";
	static const char South[] = "Юг";
	
	int Strlen_Str = strlen(str);

	if (Strlen_Str > 0){

		int i, j;

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
							printf("Cтрока № %i не совпадает ни с 1 из сторон света\n", count_str);
						}
					}
				}
			}
		} else {
			 printf("Cтрока № %i состоит из 1 слова\n", count_str);
		}
	} else {
		printf("Cтрока № %i пустая\n", count_str);
	}
}

// dummy function
void my_perror(char *s)
{
	char errstr[] = "Input/output error 5";

	printf("%s: %s\n", s, errstr);
}

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_CTYPE, "Russian_Russia.1251");
	
	if (argc > 1){

		FILE *file;
		file = fopen(argv[1], "r");
	
		if(file != NULL){
			
			int x = 0, y = 0;
			int was_error = 0;

			char buffer[MAX_SIZE];

			int count_str = 1;
	
			while(!feof(file)){
				if (fgets(buffer, MAX_SIZE, file)){
					int error;
					error = ferror(file);
					if(!error){ // убрать ! после отладки обработки ошибки
						my_perror("Произошла ошибка"); // 
						printf("При считывании %d строки из файла", count_str);
						was_error = 1;
						break;
					} else {
						MagStr(buffer);
						Bias(buffer, count_str, &x, &y);
						count_str++;
					}	
				}
			}
			if(!was_error){
				printf("Финальная координата = %d, %d\n", x, y);
			}
			fclose(file);
		} else {
			printf("Ошибка открытия файла %s\n", argv[1]);
		}
	} else {
		printf("Файл с координатами не получен\n");
		printf("Для работы с данным продуктом пожалуйста укажите путь к текстовому файлу содержащему координаты\n");
	}

	system("pause");
}
