/* Decompiled C draft; module arm9_ov001; ROM address 02197274. No matching claim. */
#include "types.h"
#include "deps/02197274_FUN_02197274.h"

void FUN_02197274(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021972ac;
  *(int *)(*DAT_021972ac + 0x6c) = *(int *)(*DAT_021972ac + 0x6c) + -1;
  if (*(int *)(*piVar1 + 0x6c) < 0) {
    *(undefined4 *)(*piVar1 + 0x6c) = 0x1f;
  }
  iVar2 = func_0x020600b4(*(undefined4 *)(DAT_021972b0 + *(int *)(*DAT_021972ac + 0x6c) * 4));
  if (iVar2 == 0) {
    FUN_02197274();
  }
  return;
}

