/* Decompiled C draft; module arm7; ROM address 06007bfc. No matching claim. */
#include "types.h"
#include "deps/06007bfc_FUN_06007bfc.h"

void FUN_06007bfc(void)

{
  uint uVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  iVar4 = FUN_06000680();
  uVar6 = iVar4 + 0x154cU & 3;
  uVar5 = *(uint *)(iVar4 + 0x154cU & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  uVar6 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  thunk_FUN_037f9a0c(uVar5 + DAT_06007cc8);
  thunk_FUN_037fb218(0,uVar5 + 0x2f4,0x400);
  uVar6 = 0;
  do {
    uVar1 = uVar6 + 1 & 0xffff;
    uVar2 = (undefined2)((uVar6 + 1) * 0x10000 >> 0x10);
    *(undefined2 *)(uVar5 + uVar6 * 0x20 + 0x2f4) = uVar2;
    uVar6 = uVar1;
  } while (uVar1 < 0x1f);
  uVar3 = (undefined2)DAT_06007ccc;
  *(undefined2 *)(uVar5 + uVar1 * 0x20 + 0x2f4) = uVar3;
  uVar6 = 0;
  *(undefined2 *)(uVar5 + 0x6f4) = 0;
  *(undefined2 *)(uVar5 + 0x6f6) = uVar2;
  do {
    iVar4 = uVar5 + uVar6 * 4;
    *(undefined2 *)(iVar4 + 0x708) = uVar3;
    *(undefined2 *)(iVar4 + 0x70a) = uVar3;
    *(undefined2 *)(iVar4 + 0x6f8) = uVar3;
    *(undefined2 *)(iVar4 + 0x6fa) = uVar3;
    uVar6 = uVar6 + 1 & 0xffff;
  } while (uVar6 < 4);
  thunk_FUN_037f999c(uVar5 + DAT_06007cc8);
  return;
}

