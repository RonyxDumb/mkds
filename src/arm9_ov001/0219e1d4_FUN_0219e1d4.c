/* Decompiled C draft; module arm9_ov001; ROM address 0219e1d4. No matching claim. */
#include "types.h"
#include "deps/0219e1d4_FUN_0219e1d4.h"

void FUN_0219e1d4(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_0x02036d08();
  piVar1 = DAT_0219e1f4;
  if (iVar2 != 0) {
    *(undefined4 *)(*DAT_0219e1f4 + 4) = 7;
    *(undefined4 *)(*piVar1 + 8) = 0;
  }
  return;
}

