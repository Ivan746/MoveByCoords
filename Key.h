#pragma once

extern const char West[];
extern const char East[];
extern const char North[];
extern const char South[];

extern const char StrSysErr_CouldNotRead[];
extern const char StrSysErr_NotMemory[];
extern const char StrSysErr_ErrorOpeningFile[];
extern const char StrSysErr_FileWithMessagesNotReceived[];
extern const char StrSysErr_ErrorProcessingFileWithMessage[];

extern char **Array_Mess;

enum MES_NUMBERS{ /** Cначала нумеруются системные сообщения */
MES_COULD_NOT_READ_SYS = 1,
MES_NOT_MEMORY_SYS,
MES_ERROR_OPENING_FILE_SYS,
MES_FILE_WITH_MESSAGES_NOT_RECEIVED_SYS,
MES_ERROR_PROCESSING_FILE_WITH_MESSAGE_SYS,
MES_NOT_A_WORLD_SIDE,
MES_ONE_WORD_ONLY,
MES_EMPTY_STR,
MES_FILE_WITH_COORDS_NOT_RECEIVED,
MES_RES_BIAS
};

extern int Processing_Array_Message(int *Numb_Str_Array_Mess, char * File_Name);
extern void universal_print_messages(MES_NUMBERS numb, ...);

extern void Print_Enter();

