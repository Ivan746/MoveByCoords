#include "stdafx.h"
#include "Key.h"
#include <iostream>

int Processing_Array_Message(int *Numb_Str_Array_Mess, char * File_Name)
{
	FILE *file_with_message;
	file_with_message = fopen(File_Name, "r");
	if(file_with_message != NULL){

		const int length_str = 256;
		const int Increments = 2;
		int was_error_Proc_Array_Mess = 0;
		int numb_str_err_mem = 0;

		Array_Mess = (char **) malloc(sizeof(char *) * (*Numb_Str_Array_Mess));

		if(Array_Mess != NULL){

			for(int i = 0; i < (*Numb_Str_Array_Mess); i++){

				Array_Mess[i] = NULL;
				Array_Mess[i] = (char*) malloc (sizeof(char) * length_str);

				if(Array_Mess[i] == NULL){
					numb_str_err_mem = i;
					was_error_Proc_Array_Mess = 1;
					break;
				}
			}
			if(!was_error_Proc_Array_Mess){
			
				int i = 0;
				int j = 0;

				while(!feof(file_with_message)){

					if(i >= *Numb_Str_Array_Mess){

						*Numb_Str_Array_Mess = (*Numb_Str_Array_Mess + Increments);
						Array_Mess = (char **) realloc(Array_Mess, *Numb_Str_Array_Mess * sizeof(char*));

						if(Array_Mess != NULL){

							for(j = i; j < *Numb_Str_Array_Mess; j++){

								Array_Mess[j] = NULL;
								Array_Mess[j] = (char*) malloc (sizeof(char) * length_str);

								if(Array_Mess[j] == NULL){
									numb_str_err_mem = j;
									was_error_Proc_Array_Mess = 1;
									break;
								}
							}
						} else {
							universal_print_messages(MES_NOT_MEMORY_SYS);
							was_error_Proc_Array_Mess = 1;
							break;
						}
					}

					if(!(was_error_Proc_Array_Mess)){
					
						if(fgets(Array_Mess[i], length_str, file_with_message) != NULL){
						}
						if(ferror(file_with_message)){ 
							universal_print_messages(MES_COULD_NOT_READ_SYS, (i + 1), strerror(errno));
							was_error_Proc_Array_Mess = 1;
							break;
						}
							i++;
					} else {
						universal_print_messages(MES_NOT_MEMORY_SYS);
						break;
					}
				}
				
				if(!(was_error_Proc_Array_Mess)){
					return 0;
					
				} else {
					for (int i = 0; i < numb_str_err_mem; i++){
						free(Array_Mess[i]);
					}
					free(Array_Mess);
				}
			} else {

				for (int i = 0; i < numb_str_err_mem; i++){
					free(Array_Mess[i]);
				}
				free(Array_Mess);
				universal_print_messages(MES_NOT_MEMORY_SYS);
			}
		} else {
			universal_print_messages(MES_NOT_MEMORY_SYS);
		}

		fclose(file_with_message);
	} else {
		universal_print_messages(MES_ERROR_OPENING_FILE_SYS, File_Name);
	}
	return 1;
}

