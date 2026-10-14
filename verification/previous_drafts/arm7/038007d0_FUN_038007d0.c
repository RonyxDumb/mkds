/* Decompiled C draft; module arm7; ROM address 038007d0. No matching claim. */
#include "types.h"
#include "deps/038007d0_FUN_038007d0.h"

void FUN_038007d0(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = DAT_03800840;
  uVar1 = DAT_03800840 + 0xfcU & 3;
  uVar3 = *(uint *)(DAT_03800840 + 0xfcU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    *(undefined4 *)(DAT_03800840 + 0xfc) = 1;
    *(undefined4 *)(iVar2 + 0x28) = 0;
    uVar1 = iVar2 + 0x28U & 3;
    uVar3 = *(uint *)(iVar2 + 0x28U & 0xfffffffc);
    *(uint *)(iVar2 + 0x24) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = iVar2 + 0x24U & 3;
    uVar3 = *(uint *)(iVar2 + 0x24U & 0xfffffffc);
    *(uint *)(iVar2 + 0x20) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    *(undefined4 *)(iVar2 + 0x2c) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x3c) = 0;
    *(undefined4 *)(iVar2 + 0x40) = 0;
    *DAT_03800844 = 0;
    FUN_037ffea4();
    uVar4 = FUN_038007c4();
    *DAT_03800848 = uVar4;
    FUN_03801140();
  }
  return;
}

