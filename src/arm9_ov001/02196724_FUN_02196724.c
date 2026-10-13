/* Decompiled C draft; module arm9_ov001; ROM address 02196724. No matching claim. */
#include "types.h"
#include "deps/02196724_FUN_02196724.h"

void FUN_02196724(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  ushort *puVar9;
  int local_24;
  ushort *local_20;
  ushort *local_1c;
  
  piVar2 = DAT_02196884;
  *(int *)(*DAT_02196884 + 0x58) = *(int *)(*DAT_02196884 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,DAT_02196888,0,*(undefined4 *)(*piVar2 + 0x58),10);
  piVar2 = DAT_02196884;
  *(undefined4 *)(*DAT_02196884 + 0x60) = uVar3;
  *(undefined4 *)(*piVar2 + 0x68) = uVar3;
  iVar7 = *piVar2;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar7 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar7 + 0x1c) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(iVar7 + 0x38) + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_0219688c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196890) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196894) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar4 * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 1) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 2) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 3) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 4) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196898) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_0219689c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021968a0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021968a4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_021968a8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + 8) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_021968b4;
  local_1c = DAT_021968b8;
  puVar8 = DAT_021968ac;
  puVar9 = DAT_021968b0;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + *puVar9) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + *local_20) * 0x40 + 4) = uVar1;
    iVar7 = 0;
    puVar6 = local_1c;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar1;
      puVar6 = puVar6 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
    local_20 = local_20 + 1;
    local_1c = local_1c + 2;
    local_24 = local_24 + 1;
  } while (local_24 < 5);
  if (9 < *(int *)(*piVar2 + 0x58)) {
    FUN_02197024();
  }
  return;
}

