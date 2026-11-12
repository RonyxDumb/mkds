#pragma once
#include "types.h"
#include "code_02134398.h"
#include "output_effect.h" // CallbackInfo

extern CallbackInfo sCallbackInfo;

// Walked by FflushAll; fwrite compares its argument with entries 1 and 2; printf passes entry 1
// to fwide and FormatWithPutFunc.
extern FILE gStdioFiles[3];

