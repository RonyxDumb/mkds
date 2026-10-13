/* Decompiled C draft; module arm9; ROM address 0214f680. No matching claim. */
#include "types.h"
#include "deps/0214f680_func_0214f680.h"

int func_0214f680(undefined4 param_1)

{
  int iVar1;
  int aiStack_8 [2];
  
  iVar1 = func_0214f6bc(param_1,uRam0214f6b8,aiStack_8);
  if (iVar1 == 0) {
    func_021501c0();
    return aiStack_8[0];
  }
  return iVar1;
}

