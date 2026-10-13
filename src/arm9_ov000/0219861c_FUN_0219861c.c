/* Decompiled C draft; module arm9_ov000; ROM address 0219861c. No matching claim. */
#include "types.h"
#include "deps/0219861c_FUN_0219861c.h"

undefined4 FUN_0219861c(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    return 1;
  }
  if ((100 < (uint)(param_2 - *(int *)(param_1 + 0x94))) && (iVar1 = FUN_02198c08(), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

