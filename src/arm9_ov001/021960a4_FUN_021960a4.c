/* Decompiled C draft; module arm9_ov001; ROM address 021960a4. No matching claim. */
#include "types.h"
#include "deps/021960a4_FUN_021960a4.h"

void FUN_021960a4(void)

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
  
  piVar2 = DAT_02196204;
  *(int *)(*DAT_02196204 + 0x58) = *(int *)(*DAT_02196204 + 0x58) + 1;
  uVar3 = func_0x020ae4c0(1,0,DAT_02196208,*(undefined4 *)(*piVar2 + 0x58),10);
  piVar2 = DAT_02196204;
  *(undefined4 *)(*DAT_02196204 + 0x60) = uVar3;
  *(undefined4 *)(*piVar2 + 0x68) = uVar3;
  iVar7 = *piVar2;
  uVar4 = (uint)*(ushort *)(*(int *)(iVar7 + 8) + 6);
  uVar5 = (uint)*(ushort *)(*(int *)(iVar7 + 0x1c) + 6);
  uVar1 = (undefined2)uVar3;
  *(undefined2 *)(*(int *)(iVar7 + 0x38) + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_0219620c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196210) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02196214) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar4 * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 1) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 2) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 3) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar4 + 4) * 0x40 + 4) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196218) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_0219621c) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196220) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196224) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196228) = uVar1;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar5 + 8) * 0x40 + 4) = uVar1;
  local_24 = 1;
  local_20 = DAT_02196234;
  local_1c = DAT_02196238;
  puVar8 = DAT_0219622c;
  puVar9 = DAT_02196230;
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
    FUN_02196fb0();
  }
  return;
}

