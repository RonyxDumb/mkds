/* Decompiled C draft; module arm9; ROM address 0200da28. No matching claim. */
#include "types.h"
#include "deps/0200da28_MaybeUtil_SPrintF.h"

void MaybeUtil_SPrintF(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_8 = param_3;
  uStack_4 = param_4;
  Util_VSPrintF(param_1,param_2,&uStack_8);
  return;
}

