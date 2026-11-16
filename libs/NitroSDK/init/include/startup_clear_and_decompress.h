#pragma once

#include "types.h"
#include "build_info_layout.h"
#include "cache_mode_setup.h"
#include "interrupt_control.h"
#include "startup_entry.h"

void Crt0_Reset32sAndAlphaFlags(void);
void Crt0_RunInitArray(void);
void NtrMain(void);

void start(void);

void Crt0_MemorySet32(u32 value, u32 *dest, u32 byteCount);
void Crt0_DecompressFlushCode(void *compressedEnd);
void Crt0_RegionCopy(void);
