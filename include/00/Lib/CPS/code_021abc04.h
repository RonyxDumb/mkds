#pragma once

#include "types.h"

void Md5BlockCopyBytes(void *destination, const void *source, u32 size);
void Md5ResultCopyBytes(u32 destination, u32 source, u32 size);
