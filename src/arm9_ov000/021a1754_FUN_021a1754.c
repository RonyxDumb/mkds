/* Decompiled C draft; module arm9_ov000; ROM address 021a1754. No matching claim. */
#include "types.h"
#include "deps/021a1754_FUN_021a1754.h"

undefined4 FUN_021a1754(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *DAT_021a1794;
  if (iVar1 == 0) {
    return 0;
  }
  iVar2 = 0;
  if (0 < param_2) {
    do {
      if (param_1 == *(int *)(iVar1 + 0xf4)) {
        FUN_021a1620(iVar2);
        return 1;
      }
      iVar1 = iVar1 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  return 0;
}

