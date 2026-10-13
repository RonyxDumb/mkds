/* Decompiled C draft; module arm7; ROM address 037f93cc. No matching claim. */
#include "types.h"
#include "deps/037f93cc_FUN_037f93cc.h"

void FUN_037f93cc(void)

{
  uint uVar1;
  int iVar2;
  undefined2 *puVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  
  if (*(uint *)((uint)DAT_037f94a4 & 0xfffffffc) >> ((uint)DAT_037f94a4 & 3) * 8 == 0 &&
      *(uint *)((uint)DAT_037f94a4 & 0xfffffffc) << ((uint)DAT_037f94a4 & 3) * -8 + 0x20 == 0) {
    *DAT_037f94a4 = 1;
    *DAT_037f94ac = DAT_037f94a8;
    iVar2 = DAT_037f94b0;
    *(undefined4 *)(DAT_037f94b0 + 0x54) = 0x10;
    *(undefined4 *)(iVar2 + 0x50) = 0;
    *(undefined4 *)(iVar2 + 0x48) = 1;
    *(undefined4 *)(iVar2 + 0x4c) = 0;
    *(undefined4 *)(iVar2 + 0x58) = 0;
    puVar3 = DAT_037f94b4;
    *(int *)(DAT_037f94b4 + 4) = iVar2;
    *(int *)(puVar3 + 2) = iVar2;
    iVar2 = DAT_037f94b0;
    if (DAT_037f94b8 < 1) {
      iVar4 = DAT_037f94bc - DAT_037f94b8;
    }
    else {
      iVar4 = (DAT_037f94c4 - DAT_037f94c0) - DAT_037f94b8;
    }
    iVar6 = DAT_037f94c4 - DAT_037f94c0;
    *(int *)(DAT_037f94b0 + 0x78) = iVar6;
    *(int *)(iVar2 + 0x74) = iVar4;
    *(undefined4 *)(iVar2 + 0x7c) = 0;
    *(undefined4 *)(iVar6 + -4) = DAT_037f94c8;
    uVar1 = iVar2 + 0x74U & 3;
    uVar5 = *(uint *)(iVar2 + 0x74U & 0xfffffffc);
    *(undefined4 *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) = DAT_037f94cc;
    *(undefined4 *)(iVar2 + 0x84) = 0;
    *(undefined4 *)(iVar2 + 0x80) = 0;
    puVar3 = DAT_037f94b4;
    *DAT_037f94b4 = 0;
    puVar3[1] = 0;
    *DAT_037f94d0 = puVar3;
    FUN_037f8db0();
  }
  return;
}

