#include "stdafx.h"
#include "Key.h"

char West[]  = "Запад";
char East[]  = "Восток";
char North[] = "Север";
char South[] = "Юг";

char Str_Err1[] = "Cтрока № %i не совпадает ни с 1 из сторон света\n";
char Str_Err2[] = "Cтрока № %i состоит из 1 слова\n";
char Str_Err3[] = "Cтрока № %i пустая\n";
char Str_Err4[] = "Произошла ошибка: %s при считывании строки %d\n";
char Str_Err5[] = "Недостаточно памяти\n";
char Str_Err6[] = "Ошибка открытия файла %s\n";
char Str_Err7[] = "Файл с координатами не получен\n";
char Str_Err8[] = "Для работы с данным продуктом пожалуйста укажите путь к текстовому файлу содержащему координаты\n";
char Str_Res[] = "Финальная координата = %d, %d\n";

void My_Printer(int Error, int count_str)
{
	switch(Error)
	{
		case(1):
			printf(Str_Err1, count_str);
			break;
		case(2):
			printf(Str_Err2, count_str);
			break;
		case(3):
			printf(Str_Err3, count_str);
			break;
	}
}
void My_Printer(int Error, char* str_error, int count_str)
{
	switch(Error)
	{
		case (4):
			printf(Str_Err4, str_error, count_str);
			break;
	}
}

void My_Printer(int Error)
{
	switch(Error)
	{
		case(5):
			printf(Str_Err5);
			break;
		case(7):
			printf(Str_Err7);
			break;
		case(8):
			printf(Str_Err8);
			break;
	}

}
void My_Printer(int Error, char* File_Name)
{
	switch(Error)
	{
		case (6):
			printf(Str_Err6, File_Name);
			break;
	}
}

void My_Printer(int Error, int First_Coord, int Second_Coord)
{
	switch(Error)
	{
		case (9):
			printf(Str_Res, First_Coord, Second_Coord);
			break;
	}
}
