#pragma once
/* Function-specific inferred declarations. */
uint Os_ComputeMemoryRegionEndAddress(undefined4 param_1);
undefined4 Os_ComputeMemoryRegionStartAddress(undefined4 param_1);
uint Os_GetSystemFlags(void);
void Os_InitializeMainExMemoryRegionAddress(void);
void Os_SetMemoryRegionEndAddress(int param_1,undefined4 param_2);
void Os_SetMemoryRegionStartAddress(int param_1,undefined4 param_2);
void Os_SetSystemRomPU(undefined4 param_1);
void Os_SetVectorBasePU(undefined4 param_1);
#define uRam0200f204 (*(uint *)(uintptr_t)0x200f204u)
#define uRam0200f208 (*(undefined4 *)(uintptr_t)0x200f208u)
#define uRam0200f20c (*(undefined4 *)(uintptr_t)0x200f20cu)
