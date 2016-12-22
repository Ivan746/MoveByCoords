#include "stdafx.h"
#include "Key.h"

const char West[]  = "Запад";
const char East[]  = "Восток";
const char North[] = "Север";
const char South[] = "Юг";


const char StrErr_CouldNotRead[] = "При считывании строки %d произошла ошибка : %s";//sys
const char StrErr_NotMemory[] = "Недостаточно памяти"; // sys
const char StrErr_ErrorOpeningFile[] = "Ошибка открытия файла %s"; // sys
const char StrErr_FileWithMessagesNotReceived[] = "Файл с сообщениями программы не получен\n Для работы с данным продуктом пожалуйста укажите путь к текстовому файлу содержащему сообщения данной программы ";// sys
const char StrErr_ErrorProcessingFileWithMessage[] = "При обработке файла с сообщениями программы %s произошла ошибка"; // sys


const char StrErr_NotAWorldSide[] = "Cтрока № %d не совпадает ни с 1 из сторон света";
const char StrErr_OneWordOnly[] = "Cтрока № %d состоит из 1 слова";
const char StrErr_EmptyStr[] = "Cтрока № %d пустая";
const char StrErr_FileWithCoordsNotReceived[] = "Файл с координатами не получен\n Для работы с данным продуктом пожалуйста укажите путь к текстовому файлу содержащему координаты ";
const char Str_Res_Bias[] = "Финальная координата = %d, %d";
