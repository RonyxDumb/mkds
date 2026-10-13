/* Decompiled C draft; module arm9; ROM address 0202577c. No matching claim. */
#include "types.h"
#include "deps/0202577c_GetCourseBgmEntry.h"

uint GetCourseBgmEntry(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = iRam02025788 + param_1 * 4;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

