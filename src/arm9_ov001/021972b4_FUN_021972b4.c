/* Decompiled C draft; module arm9_ov001; ROM address 021972b4. No matching claim. */
#include "types.h"
#include "deps/021972b4_FUN_021972b4.h"

void FUN_021972b4(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_021972ec;
  *(int *)(*DAT_021972ec + 0x6c) = *(int *)(*DAT_021972ec + 0x6c) + 1;
  if (0x1f < *(int *)(*piVar1 + 0x6c)) {
    *(undefined4 *)(*piVar1 + 0x6c) = 0;
  }
  iVar2 = func_0x020600b4(*(undefined4 *)(DAT_021972f0 + *(int *)(*DAT_021972ec + 0x6c) * 4));
  if (iVar2 == 0) {
    FUN_021972b4();
  }
  return;
}

