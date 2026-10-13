/* Decompiled C draft; module arm9; ROM address 020aa738. No matching claim. */
#include "types.h"
#include "deps/020aa738_func_020aa738.h"

int func_020aa738(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 != iRam020aa788)) {
    iVar1 = func_020aa628();
    if (iVar1 == 0) {
      iVar1 = func_020aa094(uRam020aa78c,param_1);
    }
    else {
      iVar2 = func_020aa790(param_1);
      iVar1 = func_020aa094(uRam020aa78c,iVar2);
      if (iVar1 == iVar2) {
        return param_1;
      }
    }
    return iVar1;
  }
  return param_1;
}

