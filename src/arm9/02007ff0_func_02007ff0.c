/* Decompiled C draft; module arm9; ROM address 02007ff0. No matching claim. */
#include "types.h"
#include "deps/02007ff0_func_02007ff0.h"

undefined4 func_02007ff0(int param_1,uint param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(iRam02008054 + param_1 * 4);
  if (iVar1 == 0) {
    if ((uRam02008060 <= param_2) && (param_2 + param_3 <= uRam02008064)) {
      return 1;
    }
  }
  else if (iVar1 == 1) {
    if ((uRam02008064 <= param_2) && (param_2 + param_3 <= uRam02008068)) {
      return 1;
    }
    if ((uRam02008060 <= param_2) && (param_2 + param_3 <= uRam02008068)) {
      return 1;
    }
  }
  else {
    if (iVar1 != 2) {
      return 0;
    }
    if ((uRam02008058 <= param_2) && (param_2 + param_3 <= uRam0200805c)) {
      return 1;
    }
  }
  return 0;
}

