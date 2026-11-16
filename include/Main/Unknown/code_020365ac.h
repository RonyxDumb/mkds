#pragma once

#include "types.h"

// Declared here until the code that defines it is decompiled.

void *getMainHeapHandle(void);
void mkds_runMainProc(u32 func);
void mkds_init(void);
void checkArenas(void);
void initSdk(void);
void mkds_restoreIrqs(void);
void vblankIrq(void);
