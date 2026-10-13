/* Decompiled C draft; module arm9; ROM address 020cee5c. No matching claim. */
#include "types.h"
#include "deps/020cee5c_func_020cee5c.h"

void func_020cee5c(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_r1;
  int iVar4;
  int local_38 [9];
  
  iVar4 = 8;
  if ((*(int *)(*piRam020ceee0 + iRam020ceee4) == 0) &&
     ((iVar1 = func_020cef08(), iVar1 == 1 || (iVar1 = func_020cef08(), iVar1 == 2)))) {
    uVar2 = func_020ceeec();
    iVar1 = 0;
    do {
      local_38[iVar1] = iVar1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    iVar1 = 0;
    do {
      iVar3 = func_020951b4((int *)(uintptr_t)(uVar2));
      _s32_div_f(iVar3 >> 8,iVar4);
      *(int *)(*piRam020ceee0 + iVar1 * 4 + iRam020ceee8) = local_38[extraout_r1];
      iVar4 = iVar4 + -1;
      iVar3 = extraout_r1;
      while (iVar3 < iVar4) {
        local_38[iVar3] = local_38[iVar3 + 1];
        iVar3 = iVar3 + 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    *(undefined4 *)(*piRam020ceee0 + iRam020ceee4) = 1;
  }
  return;
}

