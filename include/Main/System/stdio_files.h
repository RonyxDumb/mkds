#pragma once
#include "types.h"
#include "print_memory_functions.h"
#include "capture_output_effect.h" // CallbackInfo

extern CallbackInfo sCallbackInfo;

// Walked by FflushAll; fwrite compares its argument with entries 1 and 2; printf passes entry 1
// to fwide and FormatWithPutFunc.
extern FILE gStdioFiles[3];

