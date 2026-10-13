/* Decompiled C draft; module arm9; ROM address 0202da44. No matching claim. */
#include "types.h"
#include "deps/0202da44_func_0202da44.h"

undefined4 func_0202da44(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar2 = func_0202dd9c();
  piVar1 = piRam0202da94;
  if (0 < iVar2) {
    iVar2 = 0;
    do {
      iVar3 = func_02061654(*(int *)(*piVar1 + iRam0202da98) +
                            iRam0202daa0 * (*(uint *)(*piVar1 + iVar2 + iRam0202da9c) & 0xff));
      if (param_1 == iVar3) {
        return 1;
      }
      iVar2 = iVar2 + 4;
      iVar4 = iVar4 + 1;
      iVar3 = func_0202dd9c();
    } while (iVar4 < iVar3);
  }
  return 0;
}

