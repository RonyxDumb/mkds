#pragma once
/* Function-specific inferred declarations. */
uint Os_ComputeMemoryRegionEndAddress(undefined4 param_1);
undefined4 Os_ComputeMemoryRegionStartAddress(undefined4 param_1);
void Os_InitializeMemoryRegionAddresses(void);
void Os_SetMemoryRegionEndAddress(int param_1,undefined4 param_2);
void Os_SetMemoryRegionStartAddress(int param_1,undefined4 param_2);
#define puRam0200f324 (*(undefined4 **)(uintptr_t)0x200f324u)
