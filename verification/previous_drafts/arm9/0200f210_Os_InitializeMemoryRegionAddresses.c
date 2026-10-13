/* Decompiled C draft; module arm9; ROM address 0200f210. No matching claim. */
#include "types.h"
#include "deps/0200f210_Os_InitializeMemoryRegionAddresses.h"

void Os_InitializeMemoryRegionAddresses(void)

{
  undefined4 uVar1;
  
  if (*(uint *)((uint)puRam0200f324 & 0xfffffffc) >> ((uint)puRam0200f324 & 3) * 8 == 0 &&
      *(uint *)((uint)puRam0200f324 & 0xfffffffc) << ((uint)puRam0200f324 & 3) * -8 + 0x20 == 0) {
    *puRam0200f324 = 1;
    uVar1 = Os_ComputeMemoryRegionEndAddress(0);
    Os_SetMemoryRegionEndAddress(0,uVar1);
    uVar1 = Os_ComputeMemoryRegionStartAddress(0);
    Os_SetMemoryRegionStartAddress(0,uVar1);
    Os_SetMemoryRegionStartAddress(2,0);
    Os_SetMemoryRegionEndAddress(2,0);
    uVar1 = Os_ComputeMemoryRegionEndAddress(3);
    Os_SetMemoryRegionEndAddress(3,uVar1);
    uVar1 = Os_ComputeMemoryRegionStartAddress(3);
    Os_SetMemoryRegionStartAddress(3,uVar1);
    uVar1 = Os_ComputeMemoryRegionEndAddress(4);
    Os_SetMemoryRegionEndAddress(4,uVar1);
    uVar1 = Os_ComputeMemoryRegionStartAddress(4);
    Os_SetMemoryRegionStartAddress(4,uVar1);
    uVar1 = Os_ComputeMemoryRegionEndAddress(5);
    Os_SetMemoryRegionEndAddress(5,uVar1);
    uVar1 = Os_ComputeMemoryRegionStartAddress(5);
    Os_SetMemoryRegionStartAddress(5,uVar1);
    uVar1 = Os_ComputeMemoryRegionEndAddress(6);
    Os_SetMemoryRegionEndAddress(6,uVar1);
    uVar1 = Os_ComputeMemoryRegionStartAddress(6);
    Os_SetMemoryRegionStartAddress(6,uVar1);
    return;
  }
  return;
}

