/* Decompiled C draft; module arm9; ROM address 0214fb54. No matching claim. */
#include "types.h"
#include "deps/0214fb54_func_0214fb54.h"

int func_0214fb54(void)

{
  int iVar1;
  int aiStack_8 [2];
  
  iVar1 = func_0214fb90(uRam0214fb8c,aiStack_8);
  if (iVar1 == 0) {
    func_021501c0();
    return aiStack_8[0];
  }
  return iVar1;
}

