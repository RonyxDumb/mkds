/* Decompiled C draft; module arm9; ROM address 021059e0. No matching claim. */
#include "types.h"
#include "deps/021059e0_func_021059e0.h"

void func_021059e0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = iRam02105a28 + 0xcU & 3;
  uVar2 = *(uint *)(iRam02105a28 + 0xcU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  uVar1 = iRam02105a2c + 4U & 3;
  uVar2 = *(uint *)(iRam02105a2c + 4U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_0210d5c0();
    return;
  }
  return;
}

