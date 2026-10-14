/* Decompiled C draft; module arm7; ROM address 037f999c. No matching claim. */
#include "types.h"
#include "deps/037f999c_FUN_037f999c.h"

void FUN_037f999c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = FUN_037faf70();
  uVar1 = DAT_037f9a08 + 4U & 3;
  uVar3 = *(uint *)(DAT_037f9a08 + 4U & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == uVar3) {
    uVar1 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    *(uint *)(param_1 + 0xc) = (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 1;
    uVar1 = param_1 + 0xcU & 3;
    uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
    if (uVar4 >> uVar1 * 8 == 0 && uVar4 << uVar1 * -8 + 0x20 == 0) {
      FUN_037f9918(uVar3,param_1);
      *(undefined4 *)(param_1 + 8) = 0;
      FUN_037f9088((uint *)(uintptr_t)(param_1));
    }
  }
  FUN_037faf84(uVar2);
  return;
}

