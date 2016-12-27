#include "stdafx.h"
#include "stdarg.h"
#include "Key.h"

void Print_Enter()
{
	printf("\n");
}

void universal_print_messages(MES_NUMBERS numb, ...)
{
	
	va_list ptr;
	
	va_start(ptr, numb);

	if(numb > NUMB_SYS_MESSAGE){

		vprintf(Array_Mess[numb - NUMB_SYS_MESSAGE] , ptr);
		if (numb == TOT_NUMB_MESS){
			Print_Enter();
		}
	} else {

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
		}
		Print_Enter();
	}
	va_end(ptr);
}

