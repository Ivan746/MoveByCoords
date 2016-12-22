#include "stdafx.h"
#include "Key.h"
#include <iostream>

char ** Processing_Array_Message(int *Numb_Str_Array_Mess, int *was_error_Proc_Array_Mess, char * File_Name)
{
		FILE *file_with_message;
		file_with_message = fopen(File_Name, "r");
		if(file_with_message != NULL){

			const int length_str = 256;
			const int Increments = 2;

			char ** Array_Mess = (char **) malloc(sizeof(char *) * (*Numb_Str_Array_Mess));
			for(int i = 0; i < (*Numb_Str_Array_Mess); i++){
				Array_Mess[i] = (char*) malloc (sizeof(char) * length_str);
			}
			
			if(Array_Mess != NULL){

			int i = 0;

			while(!feof(file_with_message)){

				if(i >= *Numb_Str_Array_Mess){

					*Numb_Str_Array_Mess = (*Numb_Str_Array_Mess + Increments);
					Array_Mess = (char **) realloc(Array_Mess, *Numb_Str_Array_Mess * sizeof(char*));
					for(int j = i; j < *Numb_Str_Array_Mess; j++){
						Array_Mess[j] = (char*) malloc (sizeof(char) * length_str);
					}

					if(Array_Mess == NULL){
							universal_print_messages(MES_NOT_MEMORY);
							*was_error_Proc_Array_Mess = 1;
							break;
						}
				}

				if(fgets(Array_Mess[i], length_str, file_with_message) != NULL){
				}
				if(ferror(file_with_message)){ 
					universal_print_messages(MES_COULD_NOT_READ, (i + 1), strerror(errno));
					*was_error_Proc_Array_Mess = 1;
					break;
				}
					
				i++;
			}
			if(!(*was_error_Proc_Array_Mess)){
				return Array_Mess;
			} 
			} else {
				universal_print_messages(MES_NOT_MEMORY);
			}
			fclose(file_with_message);
		} else {
			universal_print_messages(MES_ERROR_OPENING_FILE, File_Name);
		}

		system("pause");
}
