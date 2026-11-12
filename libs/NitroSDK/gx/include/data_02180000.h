#pragma once
#include "types.h"

// Objects whose layout isn't known yet.
extern u32 gNvramEntriesOffset;

extern u8 gPackedWiFiInfo[];

// Defined by the linker script.
extern u8 OV000_TEXT_START[];

extern u8 OV001_TEXT_START[];

extern u8 OV002_CTOR_START[];

extern u8 OV000_BSS_END[];

extern u8 OV001_BSS_END[];

extern u8 OV002_BSS_END[];
