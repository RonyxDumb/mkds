/* Decompiled C draft; module arm9_ov001; ROM address 02195ff8. No matching claim. */
#include "types.h"
#include "deps/02195ff8_FUN_02195ff8.h"

void FUN_02195ff8(void)

{
  ushort uVar1;
  int *piVar2;
  undefined2 uVar3;
  
  piVar2 = DAT_02196048;
  *(int *)(*DAT_02196048 + 0x58) = *(int *)(*DAT_02196048 + 0x58) + 1;
  uVar3 = func_0x020ae488(*(undefined4 *)(*piVar2 + 0x58));
  piVar2 = DAT_02196048;
  uVar1 = *(ushort *)(*(int *)(*DAT_02196048 + 0x1c) + 6);
  *(undefined2 *)(*(int *)(*DAT_02196048 + 0x3c) + DAT_0219604c) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196050) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + DAT_02196054) = uVar3;
  *(undefined2 *)(*(int *)(*piVar2 + 0x3c) + (uVar1 + 8) * 0x40 + 4) = uVar3;
  if (9 < *(int *)(*piVar2 + 0x58)) {
    FUN_02196f64();
  }
  return;
}

