/* Decompiled C draft; module arm9; ROM address 020b2f88. No matching claim. */
#include "types.h"
#include "deps/020b2f88_func_020b2f88.h"

void func_020b2f88(int param_1)

{
  int iVar1;
  
  if (*(int *)(*piRam020b3004 + 0xc) == 0) {
    if ((param_1 == 0) || (iVar1 = func_020b2e98(), iVar1 != 0)) {
      if ((param_1 == 0) && (iVar1 = func_020b2e98(), iVar1 != 0)) {
        iVar1 = func_020b29c4();
        if (iVar1 == 0) {
          iVar1 = func_020b2b70();
          if (iVar1 == 0) {
            return;
          }
          *(undefined4 *)(*piRam020b3004 + 8) = 0;
        }
        else {
          *(undefined4 *)*piRam020b3004 = 0;
        }
      }
    }
    else {
      iVar1 = func_020b29c4();
      if (iVar1 == 0) {
        iVar1 = func_020b2b70();
        if (iVar1 == 0) {
          return;
        }
        *(int *)(*piRam020b3004 + 8) = param_1;
      }
      else {
        *(int *)*piRam020b3004 = param_1;
      }
      func_020b3008();
    }
    if (*(int *)(*piRam020b3004 + 0x24) != 0) {
      *(undefined4 *)(*piRam020b3004 + 0xc) = 1;
    }
  }
  return;
}

