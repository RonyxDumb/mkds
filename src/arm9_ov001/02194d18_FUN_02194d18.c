/* Decompiled C draft; module arm9_ov001; ROM address 02194d18. No matching claim. */
#include "types.h"
#include "deps/02194d18_FUN_02194d18.h"

void FUN_02194d18(void)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = DAT_02194d44;
  *(int *)(*DAT_02194d44 + 0x78) = *(int *)(*DAT_02194d44 + 0x78) + -1;
  if (*(int *)(*piVar1 + 0x78) < 0) {
    *(undefined4 *)(*piVar1 + 0x78) = 7;
  }
  iVar2 = FUN_02194c9c();
  if (iVar2 == 0) {
    FUN_02194d18();
  }
  return;
}

