/* Decompiled C draft; module arm9; ROM address 0211b07c. No matching claim. */
#include "types.h"
#include "deps/0211b07c_func_0211b07c.h"

void func_0211b07c(void)

{
  undefined2 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  ushort *puVar7;
  int iVar8;
  int local_3c;
  ushort *local_38;
  ushort *local_34;
  ushort *local_30;
  ushort *local_2c;
  
  func_0211c818();
  func_0211c14c();
  piVar2 = piRam0211b1f0;
  *(int *)(*piRam0211b1f0 + 0x38) = *(int *)(*piRam0211b1f0 + 0x38) + 1;
  iVar8 = *piVar2;
  iVar3 = ComputeValueInterpolation_from_thumb(1,0xffffff40,0,*(undefined4 *)(iVar8 + 0x38),10);
  iVar3 = (*(short *)(iVar8 + 0x58) + iVar3) * 0x10000;
  *(int *)(iVar8 + 0x5c) = iVar3 >> 0x10;
  piVar2 = piRam0211b1f0;
  uVar4 = (uint)*(ushort *)(*(int *)(*piRam0211b1f0 + 4) + 6);
  local_3c = 0;
  local_38 = puRam0211b1f4;
  local_34 = puRam0211b1f8;
  local_30 = puRam0211b1fc;
  local_2c = puRam0211b200;
  do {
    iVar8 = 0;
    puVar5 = local_30;
    puVar6 = local_34;
    puVar7 = local_38;
    do {
      uVar1 = (undefined2)((uint)iVar3 >> 0x10);
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar7 * 0x40 + 6) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar6 * 0x40 + 6) = uVar1;
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar5 * 0x40 + 6) = uVar1;
      puVar7 = puVar7 + 1;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    iVar8 = 0;
    puVar5 = local_2c;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + *puVar5) * 0x40 + 6) = uVar1;
      puVar5 = puVar5 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    local_38 = local_38 + 2;
    local_34 = local_34 + 2;
    local_30 = local_30 + 2;
    local_2c = local_2c + 2;
    local_3c = local_3c + 1;
  } while (local_3c < 5);
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 10) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 0xc) * 0x40 + 6) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b204) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b208) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b20c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b210) = uVar1;
  piVar2 = piRam0211b1f0;
  iVar3 = 0;
  puVar5 = puRam0211b214;
  do {
    iVar8 = 0;
    puVar6 = puVar5;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uint)*puVar6 * 0x40 + 6) = uVar1;
      puVar6 = puVar6 + 1;
      iVar8 = iVar8 + 1;
    } while (iVar8 < 2);
    puVar5 = puVar5 + 2;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  if (*(int *)(*piRam0211b218 + 0x20) != 2) {
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + (uVar4 + 8) * 0x40 + 6) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b21c) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x14) + iRam0211b220) = uVar1;
  }
  if (9 < *(int *)(*piRam0211b1f0 + 0x38)) {
    func_0211baac();
  }
  return;
}

