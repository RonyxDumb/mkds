/* Decompiled C draft; module arm9; ROM address 0214fcb0. No matching claim. */
#include "types.h"
#include "deps/0214fcb0_func_0214fcb0.h"

void func_0214fcb0(int param_1)

{
  int iVar1;
  
  if (param_1 == 1) {
    iVar1 = 1;
  }
  else if (param_1 == 2) {
    iVar1 = 3;
  }
  else if (param_1 == 3) {
    iVar1 = 2;
  }
  else {
    iVar1 = 0;
  }
  if (iVar1 != 0) {
    func_0214fe88(iVar1);
    return;
  }
  return;
}

