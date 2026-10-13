/* Decompiled C draft; module arm9; ROM address 0200f190. No matching claim. */
#include "types.h"
#include "deps/0200f190_Os_InitializeMainExMemoryRegionAddress.h"

void Os_InitializeMainExMemoryRegionAddress(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  uVar1 = Os_ComputeMemoryRegionEndAddress(2);
  Os_SetMemoryRegionEndAddress(2,uVar1);
  uVar1 = Os_ComputeMemoryRegionStartAddress(2);
  Os_SetMemoryRegionStartAddress(2,uVar1);
  if ((*(uint *)(uRam0200f204 & 0xfffffffc) >> (uRam0200f204 & 3) * 8 != 0 ||
       *(uint *)(uRam0200f204 & 0xfffffffc) << (uRam0200f204 & 3) * -8 + 0x20 != 0) &&
     (uVar2 = Os_GetSystemFlags(), (uVar2 & 3) != 1)) {
    return;
  }
  Os_SetSystemRomPU(uRam0200f208);
  Os_SetVectorBasePU(uRam0200f20c);
  return;
}

