/* Decompiled C draft; module arm9; ROM address 0211489c. No matching claim. */
#include "types.h"
#include "deps/0211489c_func_0211489c.h"

void func_0211489c(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  ushort *puVar9;
  ushort *puVar10;
  ushort *puVar11;
  int local_3c;
  ushort *local_2c;
  ushort *local_28;
  ushort *local_24;
  int local_20;
  ushort *local_18;
  
  piVar2 = piRam02114aa4;
  *(int *)(*piRam02114aa4 + 0x5c) = *(int *)(*piRam02114aa4 + 0x5c) + 1;
  uVar3 = ComputeValueInterpolation_from_thumb(1,uRam02114aa8,0,*(undefined4 *)(*piVar2 + 0x5c),10);
  uVar4 = ComputeValueInterpolation_from_thumb
                    (1,0xffffff40,0,*(undefined4 *)(*piRam02114aa4 + 0x5c),10);
  piVar2 = piRam02114aa4;
  iVar5 = *piRam02114aa4;
  uVar6 = (uint)*(ushort *)(*(int *)(iVar5 + 8) + 6);
  uVar7 = (uint)*(ushort *)(*(int *)(iVar5 + 0x18) + 6);
  uVar8 = (uint)*(ushort *)(*(int *)(iVar5 + 0x30) + 6);
  uVar1 = (undefined2)uVar3;
  if (*(int *)(iVar5 + 0x84) != 0) {
    *(undefined4 *)(iVar5 + 0x68) = uVar3;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x44) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0x84) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + 0xc4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + uVar6 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar6 + 1) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar6 + 0xb) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar6 + 0xc) * 0x40 + 4) = uVar1;
    local_3c = 0;
    puVar10 = puRam02114aac;
    do {
      iVar5 = 0;
      puVar9 = puVar10;
      do {
        *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar6 + *puVar9) * 0x40 + 4) = uVar1;
        puVar9 = puVar9 + 1;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 3);
      puVar10 = puVar10 + 3;
      local_3c = local_3c + 1;
    } while (local_3c < 3);
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + 0x44) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + uVar7 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar7 + 1) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar7 + 0xe) * 0x40 + 4) = uVar1;
    piVar2 = piRam02114aa4;
    iVar5 = 0;
    puVar10 = puRam02114ab0;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x24) + (uVar7 + *puVar10) * 0x40 + 4) = uVar1;
      puVar10 = puVar10 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 0xc);
  }
  piVar2 = piRam02114aa4;
  *(undefined4 *)(*piRam02114aa4 + 0x70) = uVar4;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02114ab4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + iRam02114ab8) = uVar1;
  *(short *)(*(int *)(*piVar2 + 0x3c) + (uVar8 + 5) * 0x40 + 6) = (short)uVar4;
  local_20 = 0;
  local_18 = puRam02114ac8;
  local_2c = puRam02114acc;
  local_28 = puRam02114ad0;
  local_24 = puRam02114ad4;
  puVar10 = puRam02114ac4;
  puVar9 = puRam02114ac0;
  puVar11 = puRam02114abc;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar11 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar9 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar10 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_18 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_2c * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*local_28 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar8 + *local_24) * 0x40 + 4) = uVar1;
    puVar11 = puVar11 + 1;
    puVar9 = puVar9 + 1;
    puVar10 = puVar10 + 1;
    local_18 = local_18 + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  if ((10 < *(int *)(*piVar2 + 0x5c)) && (iVar5 = func_02128294(), iVar5 != 0)) {
    func_02115e0c();
  }
  return;
}

