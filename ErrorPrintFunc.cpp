#include "stdafx.h"
#include "stdarg.h"
#include "Key.h"

void Print_Enter()
{
	printf("\n");
}
/*
void Data_collection_for_print(char **Array_Mess)
{
	Array_Mess;
	
}*/
void universal_print_messages(MES_NUMBERS numb, ...)
{
	
	va_list ptr;

	va_start(ptr, numb);

	switch (numb)
	{
		case MES_NOT_A_WORLD_SIDE:
			vprintf(StrErr_NotAWorldSide, ptr);
			break;
		case MES_ONE_WORD_ONLY:
			vprintf(StrErr_OneWordOnly, ptr);
			break;
		case MES_EMPTY_STR:
			vprintf(StrErr_EmptyStr, ptr);
			break;
		case MES_COULD_NOT_READ:
			vprintf(StrErr_CouldNotRead, ptr);
			break;
		case MES_NOT_MEMORY:
			vprintf(StrErr_NotMemory, ptr);
			break;
		case MES_FILE_WITH_COORDS_NOT_RECEIVED:
			vprintf(StrErr_FileWithCoordsNotReceived, ptr);
			break;
		case MES_FILE_WITH_MESSAGES_NOT_RECEIVED:
			vprintf(StrErr_FileWithMessagesNotReceived, ptr);
			break;
		case MES_ERROR_OPENING_FILE:
			vprintf(StrErr_ErrorOpeningFile, ptr);
			break;
		case MES_ERROR_PROCESSING_FILE_WITH_MESSAGE:
			vprintf(StrErr_ErrorProcessingFileWithMessage, ptr);
			break;
		case MES_RES_BIAS:
			vprintf(Str_Res_Bias, ptr);
			break;
			
	}
	Print_Enter();
	va_end(ptr);
}
