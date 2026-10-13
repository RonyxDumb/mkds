/* Decompiled C draft; module arm9; ROM address 0200f038. No matching claim. */
#include "types.h"
#include "deps/0200f038_Os_ComputeMemoryRegionEndAddress.h"

uint Os_ComputeMemoryRegionEndAddress(undefined4 param_1)

{
  uint uVar1;
  
  switch(param_1) {
  case 0:
    return DAT_0200f148;
  case 1:
    return 0;
  case 2:
    break;
  case 3:
    return 0x2000000;
  case 4:
    if (DAT_0200f154 != 0) {
      if (DAT_0200f154 < 0) {
        uVar1 = DAT_0200f15c - DAT_0200f154;
      }
      else {
        uVar1 = ((DAT_0200f150 + 0x3f80) - DAT_0200f158) - DAT_0200f154;
      }
      return uVar1;
    }
    uVar1 = DAT_0200f150;
    if (DAT_0200f150 < DAT_0200f15c) {
      uVar1 = DAT_0200f15c;
    }
    return uVar1;
  case 5:
    return DAT_0200f160;
  case 6:
    return DAT_0200f164;
  default:
    return 0;
  }
  if ((*(uint *)(DAT_0200f14c & 0xfffffffc) >> (DAT_0200f14c & 3) * 8 != 0 ||
       *(uint *)(DAT_0200f14c & 0xfffffffc) << (DAT_0200f14c & 3) * -8 + 0x20 != 0) &&
     (uVar1 = Os_GetSystemFlags(), (uVar1 & 3) != 1)) {
    return 0x2700000;
  }
  return 0;
}

