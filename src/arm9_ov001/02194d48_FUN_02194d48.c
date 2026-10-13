/* Decompiled C draft; module arm9_ov001; ROM address 02194d48. No matching claim. */
#include "types.h"
#include "deps/02194d48_FUN_02194d48.h"

void FUN_02194d48(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02194d74;
  *(int *)(*DAT_02194d74 + 0x78) = *(int *)(*DAT_02194d74 + 0x78) + 1;
  if (7 < *(int *)(*piVar1 + 0x78)) {
    *(undefined4 *)(*piVar1 + 0x78) = 0;
  }
  iVar2 = FUN_02194c9c();
  if (iVar2 == 0) {
    FUN_02194d48();
  }
  return;
}

