/* Decompiled C draft; module arm9; ROM address 0200ef4c. No matching claim. */
#include "types.h"
#include "deps/0200ef4c_Os_ComputeMemoryRegionStartAddress.h"

undefined4 Os_ComputeMemoryRegionStartAddress(undefined4 param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case 0:
    return DAT_0200f01c;
  case 1:
    return 0;
  case 2:
    break;
  case 3:
    return DAT_0200f028;
  case 4:
    return DAT_0200f02c;
  case 5:
    return DAT_0200f030;
  case 6:
    return DAT_0200f034;
  default:
    return 0;
  }
  if ((*(uint *)(DAT_0200f020 & 0xfffffffc) >> (DAT_0200f020 & 3) * 8 != 0 ||
       *(uint *)(DAT_0200f020 & 0xfffffffc) << (DAT_0200f020 & 3) * -8 + 0x20 != 0) &&
     (uVar1 = Os_GetSystemFlags(), (uVar1 & 3) != 1)) {
    return DAT_0200f024;
  }
  return 0;
}

