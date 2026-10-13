/* Decompiled C draft; module arm7; ROM address 06007cd0. No matching claim. */
#include "types.h"
#include "deps/06007cd0_FUN_06007cd0.h"

void FUN_06007cd0(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined1 auStack_290 [512];
  undefined1 auStack_90 [132];
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar5 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(ushort *)(uVar5 + 0xf2) = (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  FUN_0600044c((undefined2 *)(void *)(auStack_90),uVar5 + 0xe4);
  iVar2 = FUN_06002180((undefined2 *)(void *)(auStack_290),*(short *)(uVar5 + 0xe8) + 0x10,(undefined4)(uintptr_t)(auStack_90));
  puVar4 = (undefined2 *)thunk_FUN_03807424();
  *puVar4 = 0x21;
  if (*(short *)(iVar2 + 4) == 0) {
    puVar4[1] = 0;
  }
  else {
    puVar4[1] = 1;
    puVar4[2] = (short)DAT_06007d68;
    puVar4[3] = *(undefined2 *)(iVar2 + 4);
  }
  thunk_FUN_038074cc();
  return;
}

