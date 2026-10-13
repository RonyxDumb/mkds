/* Decompiled C draft; module arm9; ROM address 020aa790. No matching claim. */
#include "types.h"
#include "deps/020aa790_func_020aa790.h"

int func_020aa790(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != iRam020aa808)) {
    iVar1 = func_020aa600();
    if (iVar1 == 0) {
      iVar1 = func_020aa5d8(param_1);
      if (iVar1 == 0) {
        iVar1 = func_020aa094((undefined4 *)(uintptr_t)(uRam020aa80c),param_1);
      }
      else {
        iVar2 = func_020aa6e0(param_1);
        iVar1 = func_020aa094((undefined4 *)(uintptr_t)(uRam020aa80c),iVar2);
        if (iVar1 == iVar2) {
          return param_1;
        }
      }
    }
    else {
      iVar2 = func_020aa738(param_1);
      iVar1 = func_020aa094((undefined4 *)(uintptr_t)(uRam020aa80c),iVar2);
      if (iVar1 == iVar2) {
        return param_1;
      }
    }
    return iVar1;
  }
  return param_1;
}

