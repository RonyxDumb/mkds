/* Decompiled C draft; module arm9_ov001; ROM address 02198e94. No matching claim. */
#include "types.h"
#include "deps/02198e94_FUN_02198e94.h"

void FUN_02198e94(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02198ebc;
  *(int *)(*DAT_02198ebc + 0x20) = *(int *)(*DAT_02198ebc + 0x20) + 1;
  iVar2 = *piVar1;
  if (9 < *(int *)(iVar2 + 0x20)) {
    *(undefined4 *)(iVar2 + 4) = 4;
    *(undefined4 *)(*piVar1 + 0x20) = 0;
    return;
  }
  if (4 < *(int *)(iVar2 + 0x20)) {
    *(undefined4 *)(iVar2 + 0x38) = 1;
  }
  return;
}

