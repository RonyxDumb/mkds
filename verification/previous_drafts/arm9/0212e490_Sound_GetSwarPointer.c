/* Decompiled C draft; module arm9; ROM address 0212e490. No matching claim. */
#include "types.h"
#include "deps/0212e490_Sound_GetSwarPointer.h"

undefined4
Sound_GetSwarPointer
          (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Sound_GetSwarInfoEntry();
  if (uVar1 == 0) {
    return 5;
  }
  if ((param_2 & 4) == 0) {
    iVar2 = Sound_MaybeGetRawFilePointer
                      ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0xffffff);
  }
  else {
    if ((*(byte *)(uVar1 + 3) & 1) == 0) {
      iVar2 = Sound_PrepareSwarData
                        ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0xffffff,
                         param_3,param_4);
    }
    else {
      iVar2 = Sound_PrepareSwarDataImpl
                        ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                         *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) & 0xffffff,
                         param_3,param_4);
    }
    if (iVar2 == 0) {
      return 9;
    }
  }
  if (param_5 != (int *)0x0) {
    *param_5 = iVar2;
  }
  return 0;
}

