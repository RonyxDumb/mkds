/* Decompiled C draft; module arm7; ROM address 06005694. No matching claim. */
#include "types.h"
#include "deps/06005694_FUN_06005694.h"

void FUN_06005694(int param_1)

{
  uint uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined2 *puVar5;
  uint uVar6;
  bool bVar7;
  undefined2 local_23c [3];
  ushort local_236;
  undefined1 local_22e;
  undefined1 auStack_224 [6];
  undefined1 auStack_21e [14];
  uint local_210;
  undefined1 auStack_20c [512];
  
  iVar3 = FUN_06000680();
  uVar1 = iVar3 + 0x154cU & 3;
  uVar4 = *(uint *)(iVar3 + 0x154cU & 0xfffffffc);
  uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar6 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  thunk_FUN_037fb390(param_1 + 4,uVar6 + 0x9e,6);
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(uVar6 + 0xa4) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(ushort *)(uVar6 + 0xa8) = (ushort)(uVar4 >> uVar1 * 8) | (ushort)(uVar4 << uVar1 * -8 + 0x20);
  *(undefined4 *)(uVar6 + 0x18) = 1;
  thunk_FUN_037fb218(0,local_23c,0x30);
  local_23c[0] = 0;
  uVar1 = param_1 + 0x10U & 3;
  uVar4 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  local_236 = (ushort)(uVar4 >> uVar1 * 8) | (ushort)(uVar4 << uVar1 * -8 + 0x20);
  sVar2 = *(short *)(uVar6 + 0x1e8);
  bVar7 = sVar2 == 2;
  if (bVar7) {
    sVar2 = 0x14;
  }
  local_22e = (undefined1)sVar2;
  if (!bVar7) {
    local_22e = 10;
  }
  thunk_FUN_037fb390(param_1 + 4,auStack_224,6);
  thunk_FUN_037fb390(uVar6 + 0xdc,auStack_21e,6);
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  local_210 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  iVar3 = FUN_06002760((undefined2 *)(void *)(auStack_20c),(int)(uintptr_t)(local_23c));
  puVar5 = (undefined2 *)thunk_FUN_03807424();
  *puVar5 = 0x12;
  puVar5[1] = (ushort)(*(short *)(iVar3 + 4) != 0);
  if (*(short *)(iVar3 + 4) != 0) {
    puVar5[2] = 0x100;
    puVar5[3] = *(undefined2 *)(iVar3 + 4);
  }
  thunk_FUN_038074cc();
  return;
}

