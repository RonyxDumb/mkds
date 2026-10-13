/* Decompiled C draft; module arm9; ROM address 021134d4. No matching claim. */
#include "types.h"
#include "deps/021134d4_func_021134d4.h"

void func_021134d4(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  ushort *puVar10;
  int local_28;
  int local_1c;
  ushort *local_14;
  
  piVar2 = piRam021136b8;
  local_28 = 0;
  *(undefined4 *)(*piRam021136b8 + 0x50) = 0;
  *(undefined4 *)(*piVar2 + 0x54) = 0;
  *(undefined4 *)(*piVar2 + 0x58) = 0;
  *(undefined4 *)(*piVar2 + 0x5c) = 0xffffff40;
  *(undefined4 *)(*piVar2 + 0x60) = 0;
  *(undefined4 *)(*piVar2 + 100) = 0xffffff40;
  iVar3 = *piVar2;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar3 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar3 + 0x18) + 6);
  uVar6 = (uint)*(ushort *)(*(int *)(iVar3 + 0x30) + 6);
  *(undefined2 *)(*(int *)(iVar3 + 0x14) + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x46) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x86) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0xc6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + uVar4 * 0x40 + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 1) * 0x40 + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 0xb) * 0x40 + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 0xc) * 0x40 + 6) = 0xff40;
  puVar8 = puRam021136bc;
  do {
    iVar3 = 0;
    puVar7 = puVar8;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + *puVar7) * 0x40 + 6) = 0xff40;
      puVar7 = puVar7 + 1;
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
    puVar8 = puVar8 + 3;
    local_28 = local_28 + 1;
  } while (local_28 < 3);
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 0x46) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + uVar5 * 0x40 + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + 1) * 0x40 + 6) = 0xff40;
  *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + 0xe) * 0x40 + 6) = 0xff40;
  piVar2 = piRam021136b8;
  iVar3 = 0;
  puVar8 = puRam021136c0;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar5 + *puVar8) * 0x40 + 6) = 0xff40;
    puVar8 = puVar8 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0xc);
  uVar1 = (undefined2)uRam021136c4;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021136c8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021136cc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021136d0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021136d4) = uVar1;
  local_1c = 0;
  *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + iRam021136d8) = 0;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam021136dc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar6 + 5) * 0x40 + 4) = uVar1;
  local_14 = puRam021136f0;
  puVar8 = puRam021136ec;
  puVar7 = puRam021136e8;
  puVar9 = puRam021136e4;
  puVar10 = puRam021136e0;
  do {
    *(undefined2 *)(*(int *)(*piRam021136b8 + 0x3c) + (uint)*puVar10 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piRam021136b8 + 0x3c) + (uint)*puVar9 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piRam021136b8 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piRam021136b8 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piRam021136b8 + 0x3c) + (uVar6 + *local_14) * 0x40 + 4) = uVar1;
    piVar2 = piRam021136b8;
    puVar10 = puVar10 + 1;
    puVar9 = puVar9 + 1;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    local_14 = local_14 + 1;
    local_1c = local_1c + 1;
  } while (local_1c < 5);
  iVar3 = 0;
  puVar8 = puRam021136f4;
  do {
    *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40) = 0;
    puVar8 = puVar8 + 1;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  return;
}

