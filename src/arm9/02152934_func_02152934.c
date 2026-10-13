/* Decompiled C draft; module arm9; ROM address 02152934. No matching claim. */
#include "types.h"
#include "deps/02152934_func_02152934.h"

undefined4 func_02152934(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Friend_VerifyChecksum_from_thumb();
  if (iVar1 == 0) {
    param_1 = 0;
  }
  return param_1;
}

