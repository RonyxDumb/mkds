/* Decompiled C draft; module arm9; ROM address 02125004. No matching claim. */
#include "types.h"
#include "deps/02125004_func_02125004.h"

int func_02125004(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  iVar2 = 0;
  do {
    param_1 = MaybeBoundsCheck(param_1,10);
    if (param_1 == 0) {
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return iVar1;
}

