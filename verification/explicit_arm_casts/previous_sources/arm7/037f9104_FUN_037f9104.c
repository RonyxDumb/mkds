/* Decompiled C draft; module arm7; ROM address 037f9104. No matching claim. */
#include "types.h"
#include "deps/037f9104_FUN_037f9104.h"

void FUN_037f9104(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = FUN_037faf70();
  uVar2 = *(uint *)(DAT_037f9154 & 0xfffffffc) >> (DAT_037f9154 & 3) * 8 |
          *(uint *)(DAT_037f9154 & 0xfffffffc) << (DAT_037f9154 & 3) * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if (param_1 != 0) {
    *(int *)(uVar3 + 0x5c) = param_1;
    FUN_037f95e8(param_1,uVar3);
  }
  *(undefined4 *)(uVar3 + 0x48) = 0;
  FUN_037f8f48();
  FUN_037faf84(uVar1);
  return;
}

