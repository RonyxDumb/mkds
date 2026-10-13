/* Decompiled C draft; module arm9_ov001; ROM address 02195a6c. No matching claim. */
#include "types.h"
#include "deps/02195a6c_FUN_02195a6c.h"

void FUN_02195a6c(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  int iVar7;
  ushort *puVar8;
  int local_24;
  ushort *local_20;
  ushort *local_1c;
  
  piVar2 = DAT_02195b70;
  *(int *)(*DAT_02195b70 + 0x58) = *(int *)(*DAT_02195b70 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,0,DAT_02195b74,*(undefined4 *)(*piVar2 + 0x58),10);
  piVar2 = DAT_02195b70;
  *(undefined4 *)(*DAT_02195b70 + 0x68) = uVar3;
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x1c) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195b78) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195b7c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195b80) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195b84) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195b88) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + 8) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_02195b94;
  local_1c = DAT_02195b98;
  puVar6 = DAT_02195b8c;
  puVar8 = DAT_02195b90;
  do {
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar6 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + *puVar8) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + *local_20) * 0x40 + 4) = uVar1;
    iVar7 = 0;
    puVar5 = local_1c;
    do {
      *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uint)*puVar5 * 0x40 + 4) = uVar1;
      puVar5 = puVar5 + 1;
      iVar7 = iVar7 + 1;
    } while (iVar7 < 2);
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
    local_20 = local_20 + 1;
    local_1c = local_1c + 2;
    local_24 = local_24 + 1;
  } while (local_24 < 5);
  if (10 < *(int *)(*piVar2 + 0x58)) {
    FUN_02196dbc();
  }
  piVar2 = DAT_02195b70;
  if (*(int *)(*DAT_02195b70 + 0x58) == 7) {
    *(undefined4 *)(*(int *)(*DAT_02195b70 + 0x3c) + DAT_02195b9c) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195ba0) = 0;
  }
  return;
}

