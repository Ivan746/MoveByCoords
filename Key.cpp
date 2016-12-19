#include "stdafx.h"
#include "Key.h"

const char West[]  = "Запад";
const char East[]  = "Восток";
const char North[] = "Север";
const char South[] = "Юг";

const char StrErr_NotAWorldSide[] = "Cтрока № %d не совпадает ни с 1 из сторон света";
const char StrErr_OneWordOnly[] = "Cтрока № %d состоит из 1 слова";
const char StrErr_EmptyStr[] = "Cтрока № %d пустая";
const char StrErr_CouldNotRead[] = "При считывании строки %d произошла ошибка : %s";
const char StrErr_NotMemory[] = "Недостаточно памяти";
const char StrErr_ErrorOpeningFile[] = "Ошибка открытия файла %s";
const char StrErr_FileNotReceived[] = "Файл с координатами не получен\n Для работы с данным продуктом пожалуйста укажите путь к текстовому файлу содержащему координаты ";
const char Str_Res[] = "Финальная координата = %d, %d";
