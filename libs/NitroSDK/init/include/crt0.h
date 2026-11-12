#pragma once

#include "types.h"
#include "unk_02000000.h"
#include "code_02000a5c.h"
#include "code_0200c914.h"
#include "code_02000b44.h"

void _fp_init(void);
void __call_static_initializers(void);
void main(void);

void _start(void);

void INITi_CpuClear32(u32 value, u32 *dest, u32 byteCount);
void MIi_UncompressBackward(void *compressedEnd);
void do_autoload(void);
