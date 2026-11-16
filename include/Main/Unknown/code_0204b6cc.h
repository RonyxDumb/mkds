#pragma once

#include "types.h"

void savc_readWithBackup(u32 firstAddress, u32 secondAddress, u32 *destination, u32 byteCount,
                              void (*callback)(u32, u32), u32 expectedFirstWord, s32 hasPrefix);
void savc_readBlock(u32 address, void *destination, u32 byteCount, void (*callback)(u32, u32),
                            u32 expectedFirstWord);
