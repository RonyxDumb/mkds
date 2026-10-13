/* Decompiled C draft; module arm7; ROM address 060058b4. No matching claim. */
#include "types.h"
#include "deps/060058b4_FUN_060058b4.h"

void FUN_060058b4(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  uint uVar5;
  undefined1 auStack_210 [516];
  
  iVar2 = FUN_06000680();
  uVar1 = iVar2 + 0x154cU & 3;
  uVar3 = *(uint *)(iVar2 + 0x154cU & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar5 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 4U & 3;
  uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(ushort *)(uVar5 + 0x192) = (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  switch(*(undefined2 *)(uVar5 + 0x192)) {
  case 0:
    *(undefined4 *)(uVar5 + 0x194) = 0;
    goto LAB_0600591c;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  default:
    *(undefined4 *)(uVar5 + 0x194) = 0;
    goto LAB_0600591c;
  }
  *(undefined4 *)(uVar5 + 0x194) = 1;
LAB_0600591c:
  uVar1 = param_1 + 8U & 3;
  uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
  thunk_FUN_037fb390(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,uVar5 + 0x198,0x50);
  uVar1 = param_1 + 0xcU & 3;
  uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(ushort *)(uVar5 + 0xc0) = (ushort)(uVar3 >> uVar1 * 8) | (ushort)(uVar3 << uVar1 * -8 + 0x20);
  iVar2 = FUN_06002540((undefined2 *)(void *)(auStack_210),*(undefined2 *)(uVar5 + 0xc0));
  if (*(short *)(iVar2 + 4) != 0) {
    FUN_06005878(DAT_06005978);
  }
  puVar4 = (undefined2 *)thunk_FUN_03807424();
  *puVar4 = 0x27;
  puVar4[1] = 0;
  thunk_FUN_038074cc();
  return;
}

