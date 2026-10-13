/* Decompiled C draft; module arm7; ROM address 060078bc. No matching claim. */
#include "types.h"
#include "deps/060078bc_FUN_060078bc.h"

void FUN_060078bc(ushort param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  ushort uVar5;
  uint uVar6;
  undefined1 auStack_218 [516];
  
  iVar2 = FUN_06000680();
  uVar6 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar6 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  thunk_FUN_037faf70();
  thunk_FUN_037faf84();
  uVar1 = *DAT_06007978;
  uVar5 = *(ushort *)(uVar6 + 0x3e);
  param_1 = param_1 & *(ushort *)(uVar6 + 0x17e);
  if ((*(short *)(uVar6 + 0x36) == 1) || (*(short *)(uVar6 + 0x38) == 1)) {
    uVar4 = FUN_06006a10(*(undefined2 *)(uVar6 + 0x42),*(undefined2 *)(uVar6 + 0x40),param_1);
    uVar5 = uVar5 | 0x8000;
  }
  else {
    uVar4 = 0;
    uVar5 = uVar5 & 0x7fff;
  }
  FUN_06002658(auStack_218,DAT_0600797c,0,0,param_1,uVar4,uVar1,0,uVar5,0);
  return;
}

