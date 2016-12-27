#include "stdafx.h"
#include "Key.h"
#include <iostream>

char ** Array_Mess = NULL;

#define LENGTH_STR 256
#define INCREMENTS 2
#define NUMB_STR_ARRAY_MESS 4

void freeMem(char ** Array_Mess, int Numb_Str_Array_Mess){
	
	for (int i = 1; i < Numb_Str_Array_Mess; i++){
				free(Array_Mess[i]);
			}
			free(Array_Mess);
	
}

int Processing_Array_Message(char * File_Name)
{
	int Numb_Str_Array_Mess = 0;
	int was_error_Proc_Array_Mess = 0;

	FILE *file_with_message;
	file_with_message = fopen(File_Name, "r");
	if(file_with_message != NULL){

		Numb_Str_Array_Mess = NUMB_STR_ARRAY_MESS;
		was_error_Proc_Array_Mess = 0;
		int numb_str_err_mem = 0;

		Array_Mess = (char **) malloc(sizeof(char *) * (Numb_Str_Array_Mess));

		if(Array_Mess != NULL){

			for(int i = 1; i < (Numb_Str_Array_Mess); i++){ // для удобства функции печати

				Array_Mess[i] = NULL;
				Array_Mess[i] = (char*) malloc (sizeof(char) * LENGTH_STR);

				if(Array_Mess[i] == NULL){
					numb_str_err_mem = i;
					was_error_Proc_Array_Mess = MES_NOT_MEMORY_SYS;
					break;
				}
			}
			if(!was_error_Proc_Array_Mess){
			
				int i = 1;
				int j = 0;

				while(!feof(file_with_message)){

					if(i >= Numb_Str_Array_Mess){ 

						Numb_Str_Array_Mess = (Numb_Str_Array_Mess + INCREMENTS); 
						Array_Mess = (char **) realloc(Array_Mess, Numb_Str_Array_Mess * sizeof(char*));  

						if(Array_Mess != NULL){

							for(j = i; j < Numb_Str_Array_Mess; j++){ 

								Array_Mess[j] = NULL;
								Array_Mess[j] = (char*) malloc (sizeof(char) * LENGTH_STR);

								if(Array_Mess[j] == NULL){
									numb_str_err_mem = j;
									was_error_Proc_Array_Mess = MES_NOT_MEMORY_SYS;
									break;
								}
							}
						} else {
							was_error_Proc_Array_Mess = MES_NOT_MEMORY_SYS;
							break;
						}
					}

					if(!(was_error_Proc_Array_Mess)){
					
						if(fgets(Array_Mess[i], LENGTH_STR, file_with_message) != NULL){
						}
						if(ferror(file_with_message)){ 
							universal_print_messages(MES_COULD_NOT_READ_SYS, (i + 1), strerror(errno));
							was_error_Proc_Array_Mess = MES_NOT_MEMORY_SYS;
							break;
						}
						 else {
							int numb_symb = 0;
							char *adr_delimiter = NULL;
							char *adr_first_ch_mess = NULL;
							adr_delimiter = strchr(Array_Mess[i], '|'); 
							numb_symb = adr_delimiter - Array_Mess[i] + 1; 
							for(int j = numb_symb; j < strlen(Array_Mess[i]); j++){
								if((Array_Mess[i][j] != ' ') && (Array_Mess[i][j] != '\t')){
									numb_symb = j;
									break;
								}
							}
							adr_first_ch_mess = Array_Mess[i] + numb_symb;
							strcpy(Array_Mess[i], adr_first_ch_mess);
						} 
							i++;
					} else {
						universal_print_messages(MES_NOT_MEMORY_SYS);
						break;
					}
				}
				
				if(was_error_Proc_Array_Mess){
					freeMem(Array_Mess, numb_str_err_mem); 
					universal_print_messages(MES_NOT_MEMORY_SYS); 
				}
			} else {

				freeMem(Array_Mess, numb_str_err_mem);
				universal_print_messages(MES_NOT_MEMORY_SYS);
			}
		} else {
			was_error_Proc_Array_Mess = MES_NOT_MEMORY_SYS;
			universal_print_messages(MES_NOT_MEMORY_SYS);
		}

		fclose(file_with_message);
	} else {
		was_error_Proc_Array_Mess = MES_ERROR_OPENING_FILE_SYS;
		universal_print_messages(MES_ERROR_OPENING_FILE_SYS, File_Name);
	}

	int return_numb = 0; 
	was_error_Proc_Array_Mess == 0 ? return_numb = Numb_Str_Array_Mess : return_numb = 0;
	return return_numb;
}


