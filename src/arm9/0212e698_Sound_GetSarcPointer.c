/* Decompiled C draft; module arm9; ROM address 0212e698. No matching claim. */
#include "types.h"
#include "deps/0212e698_Sound_GetSarcPointer.h"

undefined4
Sound_GetSarcPointer
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Sound_GetSarcInfoEntry();
  if (uVar1 == 0) {
    return 3;
  }
  if ((param_2 & 8) == 0) {
    iVar2 = Sound_MaybeGetRawFilePointer
                      (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  }
  else {
    iVar2 = Sound_PrepareSarcData
                      (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,param_3,param_4);
    if (iVar2 == 0) {
      return 7;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar2;
  }
  return 0;
}

