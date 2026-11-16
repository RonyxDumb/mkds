#pragma once

#include "types.h"

// Returns cp15 c9,c1,0 (data TCM region) with the low 12 bits cleared.
u32 GetDtcmStartAddress(void);
// Sets bit 0 of cp15 c1,c0,0.
void Os_EnablePU(void);
// Clears bit 0 of cp15 c1,c0,0.
void Os_DisablePU(void);
// Writes param to cp15 c6,c1,0.
void Os_SetSystemRomPU(u32 param);
// Writes param to cp15 c6,c2,0.
void Os_SetVectorBasePU(u32 param);
void Os_ExceptionHandler(void);
