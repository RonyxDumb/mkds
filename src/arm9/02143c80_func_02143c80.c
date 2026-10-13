/* Decompiled C draft; module arm9; ROM address 02143c80. No matching claim. */
#include "types.h"
#include "deps/02143c80_func_02143c80.h"

int func_02143c80(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = func_02142988(1,2);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 != 0) {
    if ((*(short *)(param_2 + 4) != 0) &&
       (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 == 0 &&
        *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20 == 0)) {
      return 6;
    }
    if (*(short *)(param_2 + 0x14) == 0) {
      iVar1 = 0;
    }
    else {
      iVar1 = 0x2a;
    }
    if ((uint)*(ushort *)(param_2 + 0x34) + iVar1 < 0x201) {
      if (*(short *)(param_2 + 0x14) == 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = 6;
      }
      if ((uint)*(ushort *)(param_2 + 0x36) + iVar1 < 0x201) {
        func_02143c30(param_2);
        SetSomeFunctionPtr(7,param_1);
        DC_SomeClean(param_2,0x40);
        if (*(short *)(param_2 + 4) != 0) {
          DC_SomeClean(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20);
        }
        iVar1 = WM_SomeFn(7,1,param_2);
        if (iVar1 == 0) {
          iVar1 = 2;
        }
        return iVar1;
      }
    }
    return 6;
  }
  return 6;
}

