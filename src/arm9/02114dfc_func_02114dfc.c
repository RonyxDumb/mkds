/* Decompiled C draft; module arm9; ROM address 02114dfc. No matching claim. */
#include "types.h"
#include "deps/02114dfc_func_02114dfc.h"

void func_02114dfc(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  uint uVar10;
  ushort *puVar11;
  int local_3c;
  ushort *local_30;
  ushort *local_2c;
  ushort *local_28;
  int local_24;
  ushort *local_1c;
  
  func_02116084();
  iVar7 = *piRam02114fd4;
  uVar6 = uRam02114fd8;
  if ((*(int *)(iVar7 + 0x78) != 0) && (uVar6 = 0, *(int *)(iVar7 + 0x78) == 1)) {
    uVar6 = 0xffffff00;
  }
  *(int *)(iVar7 + 0x5c) = *(int *)(iVar7 + 0x5c) + 1;
  iVar7 = *piRam02114fd4;
  uVar10 = (uint)*(ushort *)(*(int *)(iVar7 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar7 + 0x18) + 6);
  uVar1 = *(ushort *)(*(int *)(iVar7 + 0x30) + 6);
  uVar6 = ComputeValueInterpolation_from_thumb(1,uVar6,0,*(undefined4 *)(iVar7 + 0x5c),10);
  piVar3 = piRam02114fd4;
  *(undefined4 *)(*piRam02114fd4 + 0x60) = uVar6;
  *(undefined4 *)(*piVar3 + 0x68) = uVar6;
  uVar2 = (undefined2)uVar6;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0x84) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0xc4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + uVar10 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar10 + 1) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar10 + 0xb) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar10 + 0xc) * 0x40 + 4) = uVar2;
  local_3c = 0;
  puVar9 = puRam02114fdc;
  do {
    iVar7 = 0;
    puVar8 = puVar9;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar10 + *puVar8) * 0x40 + 4) = uVar2;
      puVar8 = puVar8 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 3);
    puVar9 = puVar9 + 3;
    local_3c = local_3c + 1;
  } while (local_3c < 3);
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + uVar5 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar5 + 1) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar5 + 0xe) * 0x40 + 4) = uVar2;
  piVar3 = piRam02114fd4;
  iVar7 = 0;
  puVar9 = puRam02114fe0;
  do {
    *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar5 + *puVar9) * 0x40 + 4) = uVar2;
    piVar4 = piRam02114fd4;
    puVar9 = puVar9 + 1;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 0xc);
  local_24 = 0;
  local_1c = puRam02114ff0;
  local_30 = puRam02114ff4;
  local_2c = puRam02114ff8;
  local_28 = puRam02114ffc;
  puVar9 = puRam02114fec;
  puVar8 = puRam02114fe8;
  puVar11 = puRam02114fe4;
  do {
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*puVar11 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*puVar9 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*local_1c * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*local_30 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + (uint)*local_2c * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piVar4 + 0x3c) + ((uint)uVar1 + (uint)*local_28) * 0x40 + 4) = uVar2;
    puVar11 = puVar11 + 1;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
    local_1c = local_1c + 1;
    local_30 = local_30 + 1;
    local_2c = local_2c + 1;
    local_28 = local_28 + 1;
    local_24 = local_24 + 1;
  } while (local_24 < 5);
  if (9 < *(int *)(*piVar4 + 0x5c)) {
    func_02115e0c();
  }
  return;
}

