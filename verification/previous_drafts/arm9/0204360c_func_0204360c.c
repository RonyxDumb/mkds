/* Decompiled C draft; module arm9; ROM address 0204360c. No matching claim. */
#include "types.h"
#include "deps/0204360c_func_0204360c.h"

void func_0204360c(int param_1,ushort param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = param_1 * 0x5c;
  uVar2 = iRam02043640 + param_1 & 3;
  uVar1 = *(uint *)(iRam02043640 + param_1 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 != 3) && (uVar2 != 7)) {
    return;
  }
  *(ushort *)(iRam02043644 + param_1) = *(ushort *)(iRam02043644 + param_1) | param_2;
  return;
}

