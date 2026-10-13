/* Decompiled C draft; module arm9_ov000; ROM address 02197e20. No matching claim. */
#include "types.h"
#include "deps/02197e20_FUN_02197e20.h"

void FUN_02197e20(int *param_1,undefined1 param_2)

{
  int iVar1;
  
  if (param_1[1] <= param_1[2]) {
    func_0x0213442c(DAT_02197e50,DAT_02197e54,0,0x23);
  }
  iVar1 = param_1[2];
  param_1[2] = iVar1 + 1;
  *(undefined1 *)(*param_1 + iVar1) = param_2;
  return;
}

