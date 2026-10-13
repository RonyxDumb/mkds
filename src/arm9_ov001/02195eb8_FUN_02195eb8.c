/* Decompiled C draft; module arm9_ov001; ROM address 02195eb8. No matching claim. */
#include "types.h"
#include "deps/02195eb8_FUN_02195eb8.h"

void FUN_02195eb8(void)

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
  
  piVar2 = DAT_02195fc4;
  *(int *)(*DAT_02195fc4 + 0x58) = *(int *)(*DAT_02195fc4 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,0,DAT_02195fc8,*(undefined4 *)(*piVar2 + 0x58),10);
  piVar2 = DAT_02195fc4;
  *(undefined4 *)(*DAT_02195fc4 + 0x68) = uVar3;
  uVar4 = (uint)*(ushort *)(*(int *)(*piVar2 + 0x1c) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195fcc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195fd0) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195fd4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195fd8) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195fdc) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar4 + 8) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_02195fe8;
  local_1c = DAT_02195fec;
  puVar6 = DAT_02195fe0;
  puVar8 = DAT_02195fe4;
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
  if ((10 < *(int *)(*piVar2 + 0x58)) && (iVar7 = func_0x02128274(), iVar7 != 0)) {
    FUN_02196ecc();
  }
  piVar2 = DAT_02195fc4;
  if (*(int *)(*DAT_02195fc4 + 0x58) == 7) {
    *(undefined4 *)(*(int *)(*DAT_02195fc4 + 0x3c) + DAT_02195ff0) = 0;
    *(undefined4 *)(*(int *)(*piVar2 + 0x3c) + DAT_02195ff4) = 0;
  }
  return;
}

