/* Decompiled C draft; module arm9; ROM address 02007f38. No matching claim. */
#include "types.h"
#include "deps/02007f38_func_02007f38.h"

undefined4 func_02007f38(int param_1,uint param_2,uint param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = *(int *)(iRam02007fd4 + param_1 * 4);
  if (iVar2 != 0) {
    if (iVar2 == 1) {
      if ((param_2 < uRam02007fd8) || (uRam02007fdc <= param_2)) {
        if ((uRam02007fe8 <= param_2) && (param_2 < uRam02007fec)) {
          if (param_2 + param_3 <= uRam02007fec) {
            return 1;
          }
          return 0;
        }
        return 0;
      }
      uVar3 = param_2 + param_3;
      if ((param_2 < uRam02007fe0) && (uRam02007fe0 < uVar3)) {
        return 0;
      }
      if (uVar3 <= uRam02007fe0) {
        return 1;
      }
      if ((uVar3 < uRam02007fdc) && (param_3 <= uRam02007fe4)) {
        return 1;
      }
      return 0;
    }
    if (iVar2 != 2) {
      return 0;
    }
  }
  uVar1 = func_02007ff0();
  return uVar1;
}

