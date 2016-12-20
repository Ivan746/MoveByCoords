#include "stdafx.h"
#include "Key.h"

void Print_Enter()
{
	printf("\n");
}

static void My_PrinterV2(STR_ERRORS numb, int NumbStr = 0, char* NameFile_or_StrError = "")
{
	switch(numb)
	{
		case STR_NOT_A_WORLD_SIDE:
			printf(StrErr_NotAWorldSide, NumbStr);
			break;
		case STR_ONE_WORD_ONLY:
			printf(StrErr_OneWordOnly, NumbStr);
			break;
		case STR_EMPTY_STR:
			printf(StrErr_EmptyStr, NumbStr);
			break;
		case STR_COULD_NOT_READ:
			printf(StrErr_CouldNotRead, NumbStr, NameFile_or_StrError);
			break;
		case STR_NOT_MEMORY:
			printf(StrErr_NotMemory);
			break;
		case STR_FILE_NOT_RECEIVED:
			printf(StrErr_FileNotReceived);
			break;
		case STR_ERROR_OPENING_FILE:
			printf(StrErr_ErrorOpeningFile, NameFile_or_StrError);
			break;
	}
	Print_Enter();
}


void My_Printer(STR_ERRORS numb, int NumbStr)
{
	My_PrinterV2(numb, NumbStr);
}

void My_Printer(STR_ERRORS numb)
{
	My_PrinterV2(numb);
}

void My_Printer(STR_ERRORS numb, char* NameFile)
{
	My_PrinterV2(numb, 0, NameFile);
}

void My_Printer(STR_ERRORS numb, int NumbStr, char* StrError)
{
	My_PrinterV2(numb, NumbStr, StrError);
}
