/* Decompiled C draft; module arm9; ROM address 0204a620. No matching claim. */
#include "types.h"
#include "deps/0204a620_StructCYB_SomeFn_0.h"

bool StructCYB_SomeFn_0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 2) {
    return uRam0204a64c < (uint)*(ushort *)(param_1 + 4) * 2;
  }
  return false;
}

