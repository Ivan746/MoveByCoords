#pragma once

extern const char West[];
extern const char East[];
extern const char North[];
extern const char South[];

extern const char StrErr_NotAWorldSide[];
extern const char StrErr_OneWordOnly[];
extern const char StrErr_EmptyStr[];
extern const char StrErr_CouldNotRead[];
extern const char StrErr_NotMemory[];
extern const char StrErr_ErrorOpeningFile[];
extern const char StrErr_FileNotReceived[];
extern const char Str_Res[];

enum STR_ERRORS{
STR_NOT_A_WORLD_SIDE = 1,
STR_ONE_WORD_ONLY,
STR_EMPTY_STR,
STR_COULD_NOT_READ,
STR_NOT_MEMORY,
STR_ERROR_OPENING_FILE,
STR_FILE_NOT_RECEIVED
};

extern void My_Printer(STR_ERRORS WhenNotMem_or_FileNotReceived);
extern void My_Printer(STR_ERRORS WhenErrorOpeningFile, char* NameFile);
extern void My_Printer(STR_ERRORS WhenErrorInProcessingStr, int NumbStr);
extern void My_Printer(STR_ERRORS CouldNotRead, int NumbStr, char* StrError);
extern void Print_Enter();
