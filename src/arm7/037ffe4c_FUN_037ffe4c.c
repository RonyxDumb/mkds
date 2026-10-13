/* Decompiled C draft; module arm7; ROM address 037ffe4c. No matching claim. */
#include "types.h"
#include "deps/037ffe4c_FUN_037ffe4c.h"

uint FUN_037ffe4c(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = DAT_037ffe90;
  uVar4 = FUN_037faf70();
  uVar1 = iVar3 + 0xf0U & 3;
  uVar6 = *(uint *)(iVar3 + 0xf0U & 0xfffffffc);
  *(undefined4 *)(iVar3 + 0xf0) = param_1;
  uVar2 = iVar3 + 0xf0U & 3;
  uVar5 = *(uint *)(iVar3 + 0xf0U & 0xfffffffc);
  FUN_037f8e98(iVar3 + 0x48,uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
  FUN_037faf84(uVar4);
  return uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
}

