/* Decompiled C draft; module arm9; ROM address 0212d580. No matching claim. */
#include "types.h"
#include "deps/0212d580_func_0212d580.h"

int func_0212d580(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Sound_GetSarcInfoEntry();
  if (uVar1 == 0) {
    return 0;
  }
  iVar2 = Sound_MaybeGetRawFilePointer
                    (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  if (iVar2 != 0) {
    iVar2 = func_0212f788(iVar2,param_2);
    if (iVar2 == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = iVar2 + 4;
    }
    return iVar2;
  }
  return 0;
}

