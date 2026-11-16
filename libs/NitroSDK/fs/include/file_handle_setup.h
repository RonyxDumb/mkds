#pragma once

#include "types.h"

typedef struct FSFile FSFile;

void Fs_File_Initialize(FSFile *file);
u32 Fs_IsInitialized(void);
