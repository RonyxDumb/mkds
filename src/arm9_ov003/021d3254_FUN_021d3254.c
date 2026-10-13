/* Decompiled C draft; module arm9_ov003; ROM address 021d3254. No matching claim. */
#include "types.h"
#include "deps/021d3254_FUN_021d3254.h"

int FUN_021d3254(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (0 < param_2) {
    do {
      if (*(char *)(param_1 + iVar1) == '\0') {
        return iVar1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < param_2);
  }
  return iVar1;
}

