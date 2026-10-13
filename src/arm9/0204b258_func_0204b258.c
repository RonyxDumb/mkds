/* Decompiled C draft; module arm9; ROM address 0204b258. No matching claim. */
#include "types.h"
#include "deps/0204b258_func_0204b258.h"

undefined4 func_0204b258(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    *(undefined1 *)(param_1 + param_2 + -4) = 0;
    *(undefined1 *)(param_1 + param_2 + -3) = 0;
  }
  iVar1 = ComputeCRC_from_thumb();
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}

