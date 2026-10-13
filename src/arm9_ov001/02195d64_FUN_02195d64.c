/* Decompiled C draft; module arm9_ov001; ROM address 02195d64. No matching claim. */
#include "types.h"
#include "deps/02195d64_FUN_02195d64.h"

void FUN_02195d64(void)

{
  undefined2 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  piVar2 = DAT_02195e24;
  *(int *)(*DAT_02195e24 + 0x58) = *(int *)(*DAT_02195e24 + 0x58) + 1;
  if (*(int *)(*piVar2 + 0x74) != 0) {
    uVar3 = func_0x020ae4c0(1,0,DAT_02195e28,*(undefined4 *)(*piVar2 + 0x58),10);
    piVar2 = DAT_02195e24;
    *(undefined4 *)(*DAT_02195e24 + 0x60) = uVar3;
    uVar5 = (uint)*(ushort *)(*(int *)(*piVar2 + 8) + 6);
    uVar1 = (undefined2)uVar3;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x44) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0x84) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + 0xc4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195e2c) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195e30) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + DAT_02195e34) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + uVar5 * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar5 + 1) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar5 + 2) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar5 + 3) * 0x40 + 4) = uVar1;
    *(undefined2 *)(*(int *)(*piVar2 + 0x38) + (uVar5 + 4) * 0x40 + 4) = uVar1;
  }
  if ((9 < *(int *)(*DAT_02195e24 + 0x58)) && (iVar4 = func_0x02125f88(), iVar4 != 0)) {
    FUN_02196e54();
  }
  return;
}

