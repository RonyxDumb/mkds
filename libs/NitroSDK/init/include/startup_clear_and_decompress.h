#pragma once

#include "types.h"
#include "build_info_layout.h"
#include "cache_mode_setup.h"
#include "interrupt_control.h"
#include "startup_entry.h"

void _fp_init(void);
void __call_static_initializers(void);
void main(void);

void _start(void);

void INITi_CpuClear32(u32 value, u32 *dest, u32 byteCount);
void MIi_UncompressBackward(void *compressedEnd);
void do_autoload(void);
