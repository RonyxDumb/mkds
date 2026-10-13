/* Decompiled C draft; module arm9; ROM address 02078f78. No matching claim. */
#include "types.h"
#include "deps/02078f78_func_02078f78.h"

void func_02078f78(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Nsbtx_GetTEX0Block();
  *(undefined4 *)(*piRam02078f94 + iRam02078f98) = uVar1;
  NNS_G3dResDefaultSetup(param_1);
  return;
}

