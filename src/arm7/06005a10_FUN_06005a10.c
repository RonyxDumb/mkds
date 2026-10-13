/* Decompiled C draft; module arm7; ROM address 06005a10. No matching claim. */
#include "types.h"
#include "deps/06005a10_FUN_06005a10.h"

void FUN_06005a10(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined1 auStack_290 [512];
  undefined1 auStack_90 [132];
  
  iVar1 = FUN_06000680();
  uVar3 = iVar1 + 0x154cU & 3;
  uVar2 = *(uint *)(iVar1 + 0x154cU & 0xfffffffc);
  uVar2 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar5 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(uVar5 + 0xe4) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 8U & 3;
  uVar2 = *(uint *)(param_1 + 8U & 0xfffffffc);
  *(ushort *)(uVar5 + 0xe8) = (ushort)(uVar2 >> uVar3 * 8) | (ushort)(uVar2 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(uVar5 + 0xec) = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(ushort *)(uVar5 + 0xf0) = (ushort)(uVar2 >> uVar3 * 8) | (ushort)(uVar2 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0x14U & 3;
  uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(ushort *)(uVar5 + 0xf2) = (ushort)((uVar3 & 1) != 0);
  *(ushort *)(uVar5 + 0xf6) = (ushort)((uVar3 & 2) != 0);
  *(ushort *)(uVar5 + 0xf8) = (ushort)((uVar3 & 4) != 0);
  *(ushort *)(uVar5 + 0xfa) = (ushort)((uVar3 & 8) != 0);
  FUN_0600044c((undefined2 *)(void *)(auStack_90),uVar5 + 0xe4);
  iVar1 = FUN_06002180((undefined2 *)(void *)(auStack_290),*(short *)(uVar5 + 0xe8) + 0x10,(undefined4)(uintptr_t)(auStack_90));
  puVar4 = (undefined2 *)thunk_FUN_03807424();
  *puVar4 = 0x18;
  puVar4[1] = (ushort)(*(short *)(iVar1 + 4) != 0);
  if (*(short *)(iVar1 + 4) != 0) {
    puVar4[2] = (short)DAT_06005b08;
    puVar4[3] = *(undefined2 *)(iVar1 + 4);
  }
  thunk_FUN_038074cc();
  return;
}

