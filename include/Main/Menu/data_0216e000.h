#pragma once
#include "types.h"
#include "code_02134398.h"
#include "output_effect.h" // CallbackInfo

extern const char gKeyboardSBnblName[];

extern const char gKeyboardSBnclName[];

extern const char gKeyboardSBnllName[];

extern const char gKeyboardSONceNcgrName[];

extern const char gKeyboardSONceNcerName[];

extern const char gKeyboardSONclrName[];

extern const char gKeyboardSBFlameNcgrName[];

extern const char gKeyboardSBFlame02NscrName[];

extern const char gKeyboardSBFlame01NscrName[];

extern const char gKeyboardSBNclrName[];

extern CallbackInfo sCallbackInfo;

// Walked by FflushAll; fwrite compares its argument with entries 1 and 2; printf passes entry 1
// to fwide and FormatWithPutFunc.
extern FILE gStdioFiles[3];

