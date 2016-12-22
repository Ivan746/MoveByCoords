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
extern const char StrErr_FileWithCoordsNotReceived[];
extern const char StrErr_FileWithMessagesNotReceived[];
extern const char StrErr_ErrorProcessingFileWithMessage[];
extern const char Str_Res_Bias[];

//extern char **Array_Mess;

enum MES_NUMBERS{
MES_NOT_A_WORLD_SIDE = 1,
MES_ONE_WORD_ONLY,
MES_EMPTY_STR,
MES_COULD_NOT_READ,
MES_NOT_MEMORY,
MES_ERROR_OPENING_FILE,
MES_FILE_WITH_COORDS_NOT_RECEIVED,
MES_FILE_WITH_MESSAGES_NOT_RECEIVED,
MES_ERROR_PROCESSING_FILE_WITH_MESSAGE,
MES_RES_BIAS
};

//void Data_collection_for_print(char** Array_Mess);
extern char ** Processing_Array_Message(int *Numb_Str_Array_Mess, int *was_error_Proc_Array_Mess, char * File_Name);
extern void universal_print_messages(MES_NUMBERS numb, ...);

extern void Print_Enter();
