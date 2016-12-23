#include "stdafx.h"
#include "stdarg.h"
#include "Key.h"

#define NUMB_SYS_MESSAGE 5
#define DIFFER_BETW_DELIM_AND_FIRST_CHAR_MESS 2
#define TRANSIT_MESS_FORMAT	10

void Print_Enter()
{
	printf("\n");
}

void universal_print_messages(MES_NUMBERS numb, ...)
{
	int Numb_simv = 0;

	if((numb > NUMB_SYS_MESSAGE) && (numb <= NUMB_SYS_MESSAGE + TRANSIT_MESS_FORMAT)){ /** если строк в файле 10 строк или менее */
		char *adr_delimiter = NULL;
		adr_delimiter = strchr(Array_Mess[0], '|'); 
		Numb_simv = adr_delimiter - Array_Mess[0];
		Numb_simv  +=  DIFFER_BETW_DELIM_AND_FIRST_CHAR_MESS; /** т.к. между разделителем и началом строки стоит пробел */                                          
	}
	
	if((numb > NUMB_SYS_MESSAGE + TRANSIT_MESS_FORMAT)){ /** Если сообщений в файле оказывается более 10 (при наличии боле 101 строки требуется доработка)*/
		char *adr_delimiter = NULL;
		adr_delimiter = strchr(Array_Mess[10], '|');
		Numb_simv = adr_delimiter - Array_Mess[10];
		Numb_simv  +=  DIFFER_BETW_DELIM_AND_FIRST_CHAR_MESS; /** т.к. между разделителем и началом строки стоит пробел */                                          
	}
	va_list ptr;
	
	va_start(ptr, numb);

	switch (numb)
	{
		case MES_COULD_NOT_READ_SYS:
			vprintf(StrSysErr_CouldNotRead, ptr);
			break;
		case MES_NOT_MEMORY_SYS:
			vprintf(StrSysErr_NotMemory, ptr);
			break;
		case MES_ERROR_OPENING_FILE_SYS:
			vprintf(StrSysErr_ErrorOpeningFile, ptr);
			break;
		case MES_FILE_WITH_MESSAGES_NOT_RECEIVED_SYS:
			vprintf(StrSysErr_FileWithMessagesNotReceived, ptr);
			break;
		case MES_ERROR_PROCESSING_FILE_WITH_MESSAGE_SYS:
			vprintf(StrSysErr_ErrorProcessingFileWithMessage, ptr);
			break;
		case MES_NOT_A_WORLD_SIDE:
			vprintf(Array_Mess[0] + Numb_simv, ptr);
			break;
		case MES_ONE_WORD_ONLY:
			vprintf(Array_Mess[1] + Numb_simv, ptr);
			break;
		case MES_EMPTY_STR:
			vprintf(Array_Mess[2] + Numb_simv, ptr);
			break;
		case MES_FILE_WITH_COORDS_NOT_RECEIVED:
			vprintf(Array_Mess[3] + Numb_simv, ptr);
			break;
		case MES_RES_BIAS:
			vprintf(Array_Mess[4] + Numb_simv, ptr);
			break;
			
	}
	if((numb < 6) || (numb == MES_RES_BIAS)){ // последняя строка в файле отображается иначе чем все остальные
		Print_Enter();
	}
	va_end(ptr);
}

