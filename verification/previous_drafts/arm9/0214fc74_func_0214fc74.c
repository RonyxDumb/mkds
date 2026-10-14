/* Decompiled C draft; module arm9; ROM address 0214fc74. No matching claim. */
#include "types.h"
#include "deps/0214fc74_func_0214fc74.h"

int func_0214fc74(undefined4 param_1)

{
  int iVar1;
  int aiStack_8 [2];
  
  iVar1 = func_0214fcb0(param_1,uRam0214fcac,aiStack_8);
  if (iVar1 == 0) {
    func_021501c0();
    return aiStack_8[0];
  }
  return iVar1;
}

