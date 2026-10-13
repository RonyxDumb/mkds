/* Decompiled C draft; module arm9; ROM address 0212ec04. No matching claim. */
#include "types.h"
#include "deps/0212ec04_func_0212ec04.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0212ec04(undefined4 param_1,uint param_2,uint param_3,uint param_4,undefined4 param_5,
                  undefined4 param_6)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = Sound_GetSarcInfoEntry(param_5);
  if (uVar1 == 0) {
    return;
  }
  iVar2 = Sound_MaybeGetRawFilePointer
                    (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                     *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20);
  if (iVar2 != 0) {
    iVar2 = func_0212f788(iVar2,param_6);
    if (iVar2 != 0) {
      if ((int)param_4 < 0) {
        param_4 = (uint)*(byte *)(iVar2 + 8);
      }
      if ((int)param_3 < 0) {
        param_3 = (uint)*(ushort *)(iVar2 + 4);
      }
      if ((int)param_2 < 0) {
        param_2 = (uint)*(byte *)(iVar2 + 9);
      }
      func_0212ea28(param_1,param_2,param_3,param_4);
      return;
    }
    return;
  }
  return;
}

