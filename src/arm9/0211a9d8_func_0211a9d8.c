/* Decompiled C draft; module arm9; ROM address 0211a9d8. No matching claim. */
#include "types.h"
#include "deps/0211a9d8_func_0211a9d8.h"

void func_0211a9d8(void)

{
  undefined2 uVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  ushort *puVar6;
  ushort *puVar7;
  ushort *puVar8;
  int iVar9;
  int local_3c;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  
  piVar2 = piRam0211ab90;
  *(int *)(*piRam0211ab90 + 0x38) = *(int *)(*piRam0211ab90 + 0x38) + 1;
  iVar9 = *piVar2;
  iVar4 = ComputeValueInterpolation_from_thumb(1,0,0xffffff40,*(undefined4 *)(iVar9 + 0x38),10);
  iVar4 = (*(short *)(iVar9 + 0x58) + iVar4) * 0x10000;
  sVar3 = func_02128244(*(undefined4 *)(iVar9 + 0x38));
  piVar2 = piRam0211ab90;
  sVar3 = -sVar3;
  *(int *)(*piRam0211ab90 + 0x5c) = iVar4 >> 0x10;
  uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 4) + 6);
  local_3c = 0;
  local_34 = puRam0211ab94;
  local_30 = puRam0211ab98;
  local_2c = puRam0211ab9c;
  local_28 = puRam0211aba0;
  do {
    iVar9 = 0;
    puVar6 = local_2c;
    puVar7 = local_30;
    puVar8 = local_34;
    do {
      uVar1 = (undefined2)((uint)iVar4 >> 0x10);
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar8 * 0x40 + 6) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar7 * 0x40 + 6) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar6 * 0x40 + 6) = uVar1;
      puVar8 = puVar8 + 1;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    iVar9 = 0;
    puVar6 = local_28;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + *puVar6) * 0x40 + 6) = uVar1;
      puVar6 = puVar6 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    local_34 = local_34 + 2;
    local_30 = local_30 + 2;
    local_2c = local_2c + 2;
    local_28 = local_28 + 2;
    local_3c = local_3c + 1;
  } while (local_3c < 5);
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 10) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 0xc) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211aba4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211aba8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211abac) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211abb0) = uVar1;
  piVar2 = piRam0211ab90;
  iVar4 = 0;
  puVar6 = puRam0211abb4;
  do {
    iVar9 = 0;
    puVar7 = puVar6;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar7 * 0x40 + 6) = uVar1;
      puVar7 = puVar7 + 1;
      iVar9 = iVar9 + 1;
    } while (iVar9 < 2);
    puVar6 = puVar6 + 2;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  if (*(int *)(*piRam0211abb8 + 0x20) != 2) {
    *(short *)(*(int *)(*piVar2 + 0x14) + iRam0211abbc) = sVar3;
    *(short *)(*(int *)(*piVar2 + 0x14) + iRam0211abc0) = sVar3;
    *(short *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 0xd) * 0x40 + 6) = sVar3;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 8) * 0x40 + 6) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211abc4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211abc8) = uVar1;
    return;
  }
  *(short *)(*(int *)(*piVar2 + 0x14) + iRam0211abcc) = sVar3;
  *(short *)(*(int *)(*piVar2 + 0x14) + (uVar5 + 0xe) * 0x40 + 6) = sVar3;
  return;
}

