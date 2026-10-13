/* Decompiled C draft; module arm9; ROM address 0204e1a8. No matching claim. */
#include "types.h"
#include "deps/0204e1a8_func_0204e1a8.h"

undefined4 func_0204e1a8(int param_1)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  piVar2 = (int *)*puRam0204e200;
  if (piVar2[4] == 0) {
    if (piVar2 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *piVar2;
    }
    if (iVar1 == 0) {
      if (param_1 == 0) {
        *piVar2 = 2;
      }
      else {
        *piVar2 = 1;
      }
    }
    else if (iVar1 == 1) {
      uVar3 = func_0204e29c();
    }
    else if (iVar1 == 2) {
      uVar3 = func_0204e204();
    }
    return uVar3;
  }
  return 0;
}

