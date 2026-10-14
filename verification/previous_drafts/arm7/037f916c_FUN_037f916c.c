/* Decompiled C draft; module arm7; ROM address 037f916c. No matching claim. */
#include "types.h"
#include "deps/037f916c_FUN_037f916c.h"

void FUN_037f916c(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar2 = FUN_037faf70();
  uVar1 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != 2) {
    FUN_037f9104(param_1 + 0x80);
  }
  FUN_037faf84(uVar2);
  return;
}

