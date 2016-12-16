#include "stdafx.h"
#include "Key.h"


void Print_Enter()
{
	printf("\n");
}
/*
void My_Printer(error numb, int count_str)
{
	switch(numb)
	{
		case(NotAWorldSide):
			printf(StrErr_NotAWorldSide, count_str);
			break;
		case(OneWordOnly):
			printf(StrErr2_OneWordOnly, count_str);
			break;
		case(EmptyStr):
			printf(StrErr3_EmptyStr, count_str);
			break;
		case(CouldNotRead):
			printf(StrErr4_CouldNotRead, count_str);
			perror(" произошла ошибка");
			break;
	}
	Print_Enter();
}

void My_Printer(error numb)
{
	switch(numb)
	{
		case(NotMemory):
			printf(StrErr5_NotMemory);
			break;
		case(FileNotReceived):
			printf(StrErr7_FileNotReceived);
			break;
		
	}
	Print_Enter();
}

void My_Printer(error numb, char* File_Name)
{
	switch(numb)
	{
		case (ErrorOpeningFile):
			printf(StrErr6_ErrorOpeningFile, File_Name);
			break;
	}
	Print_Enter();
}
*/
void My_PrinterV2(error numb, int count_str, char* NameFile)
{
	switch(numb)
	{
		case(NotAWorldSide):
			printf(StrErr_NotAWorldSide, count_str);
			break;
		case(OneWordOnly):
			printf(StrErr2_OneWordOnly, count_str);
			break;
		case(EmptyStr):
			printf(StrErr3_EmptyStr, count_str);
			break;
		case(CouldNotRead):
			printf(StrErr4_CouldNotRead, count_str);
			perror(" произошла ошибка");
			break;
		case(NotMemory):
			printf(StrErr5_NotMemory);
			break;
		case(FileNotReceived):
			printf(StrErr7_FileNotReceived);
			break;
		case (ErrorOpeningFile):
			printf(StrErr6_ErrorOpeningFile, NameFile);
			break;
	}
	Print_Enter();
}
