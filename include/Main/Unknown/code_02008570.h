#pragma once

#include "types.h"

extern u32 *data_usa_02161788;
extern u8 data_usa_0216178c[];

typedef struct FSFile FSFile;

int func_02008570(FSFile *file, void *buffer, u32 bufferSize);
