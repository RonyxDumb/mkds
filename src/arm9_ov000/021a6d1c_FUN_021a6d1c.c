/* Decompiled C draft; module arm9_ov000; ROM address 021a6d1c. No matching claim. */
#include "types.h"
#include "deps/021a6d1c_FUN_021a6d1c.h"

undefined4 FUN_021a6d1c(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (*(char *)(param_1 + iVar1) != *(char *)(param_2 + iVar1)) {
      return 0;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 6);
  return 1;
}

