/* Decompiled C draft; module arm9; ROM address 02033c80. No matching claim. */
#include "types.h"
#include "deps/02033c80_func_02033c80.h"

void func_02033c80(uint param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  iVar5 = *piRam02033d94;
  uVar3 = (uint)(*(uint *)(iVar5 + 0xd0) == param_1);
  iVar2 = *(int *)(iVar5 + param_1 * 0xc + 0xec);
  if (*(char *)(*piRam02033d98 + 0x58) == '\0') {
    *(uint *)(*(int *)(iVar5 + 0x7c) + iVar2 * 0x40) = uVar3;
    *(uint *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 8) * 0x40) = (uint)(uVar3 == 0);
    iVar4 = (iVar2 + 0x28) * 0x40;
    *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4) = 0;
    iVar6 = (iVar2 + 0x20) * 0x40;
    *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar6) =
         *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4);
    iVar4 = (iVar2 + 0x18) * 0x40;
    *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4) =
         *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar6);
    *(undefined4 *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 0x10) * 0x40) =
         *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4);
    return;
  }
  bVar7 = *(int *)(*piRam02033d98 + (param_1 & 0xffff) * 0x30 + 0x74) != 1;
  uVar1 = 0;
  if ((bVar7) && (uVar3 != 0)) {
    uVar1 = 1;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 0x10) * 0x40) = uVar1;
  if ((!bVar7) || (uVar3 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 0x18) * 0x40) = uVar1;
  if ((bVar7) || (uVar3 == 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 0x20) * 0x40) = uVar1;
  if ((bVar7) || (uVar3 != 0)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + (iVar2 + 0x28) * 0x40) = uVar1;
  iVar4 = (iVar2 + 8) * 0x40;
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4) = 0;
  *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar2 * 0x40) =
       *(undefined4 *)(*(int *)(iVar5 + 0x7c) + iVar4);
  return;
}

