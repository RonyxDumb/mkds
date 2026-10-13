/* Decompiled C draft; module arm9_ov001; ROM address 0219e34c. No matching claim. */
#include "types.h"
#include "deps/0219e34c_FUN_0219e34c.h"

void FUN_0219e34c(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = func_0x02036c5c();
  piVar1 = DAT_0219e384;
  if (iVar2 != 0) {
    if (*(int *)(*DAT_0219e384 + 0x70) != 0) {
      *(undefined4 *)(*DAT_0219e388 + 4) = 5;
      *(undefined4 *)(*piVar1 + 0x70) = 0;
      return;
    }
    *(undefined4 *)(*DAT_0219e388 + 4) = 1;
  }
  return;
}

