/* Decompiled C draft; module arm9; ROM address 0212e538. No matching claim. */
#include "types.h"
#include "deps/0212e538_Sound_GetSbnkPointer.h"

int Sound_GetSbnkPointer
              (undefined4 param_1,uint param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uStack_2c;
  
  uVar1 = Sound_GetSbnkInfoEntry();
  if (uVar1 == 0) {
    return 4;
  }
  if ((param_2 & 2) == 0) {
    iVar2 = Sound_MaybeGetRawFilePointer
                      (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  }
  else {
    iVar2 = Sound_PrepareSbnkData
                      (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20,param_3,param_4);
    if (iVar2 == 0) {
      return 8;
    }
  }
  iVar5 = 0;
  do {
    if (*(ushort *)(uVar1 + iVar5 * 2 + 4) != uRam0212e694) {
      uVar3 = Sound_GetSwarInfoEntry();
      if (uVar3 == 0) {
        return 5;
      }
      iVar4 = Sound_GetSwarPointer(*(undefined2 *)(uVar1 + iVar5 * 2 + 4),param_2,param_3,param_4);
      if (iVar4 != 0) {
        return iVar4;
      }
      if (((*(byte *)(uVar3 + 3) & 1) != 0) && ((param_2 & 4) != 0)) {
        iVar4 = func_0212dd64(uStack_2c,iVar2,iVar5,
                              (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff);
        if (iVar4 == 0) {
          return 9;
        }
      }
      if ((iVar2 != 0) && (uStack_2c != 0)) {
        func_02021cd4(iVar2,iVar5);
      }
    }
    iVar5 = iVar5 + 1;
    if (3 < iVar5) {
      if (param_5 != (int *)0x0) {
        *param_5 = iVar2;
      }
      return 0;
    }
  } while( true );
}

