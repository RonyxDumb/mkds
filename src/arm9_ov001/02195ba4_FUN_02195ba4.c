/* Decompiled C draft; module arm9_ov001; ROM address 02195ba4. No matching claim. */
#include "types.h"
#include "deps/02195ba4_FUN_02195ba4.h"

void FUN_02195ba4(void)

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
  
  piVar2 = DAT_02195d28;
  *(int *)(*DAT_02195d28 + 0x58) = *(int *)(*DAT_02195d28 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,DAT_02195d2c,0,*(undefined4 *)(*piVar2 + 0x58),10);
  piVar2 = DAT_02195d28;
  uVar1 = (undefined2)uVar3;
  if (*(int *)(*DAT_02195d28 + 0x74) != 0) {
    *(undefined4 *)(*DAT_02195d28 + 0x60) = uVar3;
    uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 8) + 6);
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195d30) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195d34) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195d38) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar4 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 1) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 2) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 3) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 4) * 0x40 + 4) = uVar1;
  }
  piVar2 = DAT_02195d28;
  *(undefined4 *)(*DAT_02195d28 + 0x68) = uVar3;
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x1c) + 6);
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195d3c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195d40) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195d44) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195d48) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195d4c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + 8) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_02195d58;
  local_1c = DAT_02195d5c;
  puVar6 = DAT_02195d50;
  puVar8 = DAT_02195d54;
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
  if ((10 < *(int *)(*piVar2 + 0x58)) && (iVar7 = func_0x02128294(), iVar7 != 0)) {
    FUN_02197024();
  }
  if (*(int *)(*DAT_02195d28 + 0x58) == 2) {
    *(undefined4 *)(*(int *)(*DAT_02195d28 + 0x3c) + DAT_02195d60) = 1;
  }
  return;
}

