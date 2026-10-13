/* Decompiled C draft; module arm9_ov001; ROM address 0219623c. No matching claim. */
#include "types.h"
#include "deps/0219623c_FUN_0219623c.h"

void FUN_0219623c(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  ushort *puVar9;
  int local_24;
  ushort *local_20;
  ushort *local_1c;
  
  FUN_02196cd0();
  iVar5 = *DAT_02196384;
  uVar3 = DAT_02196388;
  if ((*(int *)(iVar5 + 0x70) != 0) && (uVar3 = 0, *(int *)(iVar5 + 0x70) == 1)) {
    uVar3 = 0xffffff00;
  }
  *(int *)(iVar5 + 0x58) = *(int *)(iVar5 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,uVar3,0,*(undefined4 *)(*DAT_02196384 + 0x58),10);
  piVar2 = DAT_02196384;
  *(undefined4 *)(*DAT_02196384 + 0x60) = uVar3;
  *(undefined4 *)(*piVar2 + 0x68) = uVar3;
  iVar5 = *piVar2;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar5 + 8) + 6);
  uVar6 = (uint)*(ushort *)(*(int *)(iVar5 + 0x1c) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(iVar5 + 0x38) + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_0219638c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196390) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196394) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar4 * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 1) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 2) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 3) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 4) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_021963a0;
  local_1c = DAT_021963a4;
  puVar8 = DAT_02196398;
  puVar9 = DAT_0219639c;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar8 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar6 + *puVar9) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar6 + *local_20) * 0x40 + 4) = uVar1;
    iVar5 = 0;
    puVar7 = local_1c;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar7 * 0x40 + 4) = uVar1;
      puVar7 = puVar7 + 1;
      iVar5 = iVar5 + 1;
    } while (iVar5 < 2);
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

