#pragma once

extern const char West[];
extern const char East[];
extern const char North[];
extern const char South[];

extern const char StrErr_NotAWorldSide[];
extern const char StrErr2_OneWordOnly[];
extern const char StrErr3_EmptyStr[];
extern const char StrErr4_CouldNotRead[];
extern const char StrErr5_NotMemory[];
extern const char StrErr6_ErrorOpeningFile[];
extern const char StrErr7_FileNotReceived[];
extern const char Str_Res[];

extern const enum error {NotAWorldSide = 1, OneWordOnly, EmptyStr, CouldNotRead, NotMemory, ErrorOpeningFile, FileNotReceived};

extern void My_Printer(error WhenNotMem_or_FileNotReceived);
extern void My_Printer(error WhenErrorOpeningFile, char* NameFile);
extern void My_Printer(error WhenErrorInProcessingStr, int NumbStr);

extern void Print_Enter();


