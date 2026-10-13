/* Decompiled C draft; module arm9; ROM address 021123a0. No matching claim. */
#include "types.h"
#include "deps/021123a0_func_021123a0.h"

void func_021123a0(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int *piVar3;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  int local_2c;
  int local_20;
  ushort *local_18;
  
  func_021137f4();
  iVar6 = *piRam02112548;
  if (*(int *)(iVar6 + 0x6c) == 0) {
    uVar5 = 0xffffff00;
  }
  else {
    uVar5 = uRam0211254c;
    if (*(int *)(iVar6 + 0x6c) != 1) {
      uVar5 = 0;
    }
  }
  *(int *)(iVar6 + 0x54) = *(int *)(iVar6 + 0x54) + 1;
  iVar6 = *piRam02112548;
  uVar9 = (uint)*(ushort *)(*(int *)(iVar6 + 8) + 6);
  uVar4 = (uint)*(ushort *)(*(int *)(iVar6 + 0x18) + 6);
  uVar1 = *(ushort *)(*(int *)(iVar6 + 0x30) + 6);
  uVar5 = ComputeValueInterpolation_from_thumb(1,0,uVar5,*(undefined4 *)(iVar6 + 0x54),10);
  piVar3 = piRam02112548;
  *(undefined4 *)(*piRam02112548 + 0x58) = uVar5;
  *(undefined4 *)(*piVar3 + 0x60) = uVar5;
  uVar2 = (undefined2)uVar5;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0x84) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + 0xc4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + uVar9 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar9 + 1) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar9 + 0xb) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar9 + 0xc) * 0x40 + 4) = uVar2;
  local_2c = 0;
  puVar8 = puRam02112550;
  do {
    iVar6 = 0;
    puVar7 = puVar8;
    do {
      *(undefined2 *)(*(int *)(*piVar3 + 0x14) + (uVar9 + *puVar7) * 0x40 + 4) = uVar2;
      puVar7 = puVar7 + 1;
      iVar6 = iVar6 + 1;
    } while (iVar6 < 3);
    puVar8 = puVar8 + 3;
    local_2c = local_2c + 1;
  } while (local_2c < 3);
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + 0x44) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + uVar4 * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar4 + 1) * 0x40 + 4) = uVar2;
  *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar4 + 0xe) * 0x40 + 4) = uVar2;
  piVar3 = piRam02112548;
  iVar6 = 0;
  puVar8 = puRam02112554;
  do {
    *(undefined2 *)(*(int *)(*piVar3 + 0x24) + (uVar4 + *puVar8) * 0x40 + 4) = uVar2;
    puVar8 = puVar8 + 1;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0xc);
  local_20 = 0;
  local_18 = puRam02112568;
  puVar8 = puRam02112564;
  puVar7 = puRam02112560;
  puVar10 = puRam0211255c;
  puVar11 = puRam02112558;
  do {
    *(undefined2 *)(*(int *)(*piRam02112548 + 0x3c) + (uint)*puVar11 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piRam02112548 + 0x3c) + (uint)*puVar10 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piRam02112548 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piRam02112548 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar2;
    *(undefined2 *)(*(int *)(*piRam02112548 + 0x3c) + ((uint)uVar1 + (uint)*local_18) * 0x40 + 4) =
         uVar2;
    puVar11 = puVar11 + 1;
    puVar10 = puVar10 + 1;
    puVar7 = puVar7 + 1;
    puVar8 = puVar8 + 1;
    local_18 = local_18 + 1;
    local_20 = local_20 + 1;
  } while (local_20 < 5);
  if (9 < *(int *)(*piRam02112548 + 0x54)) {
    func_02113420();
  }
  return;
}

