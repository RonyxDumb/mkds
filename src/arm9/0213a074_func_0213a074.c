/* Decompiled C draft; module arm9; ROM address 0213a074. No matching claim. */
#include "types.h"
#include "deps/0213a074_func_0213a074.h"

int func_0213a074(uint param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
  iVar3 = uVar1 - ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                   *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff);
  if (iVar3 != 0) {
    return iVar3;
  }
  uVar4 = param_1 & 3;
  if ((param_2 & 3) == uVar4) {
    if (uVar4 != 0) {
      if (uVar1 == 0) {
        return 0;
      }
      for (iVar3 = 3 - uVar4; iVar3 != 0; iVar3 = iVar3 + -1) {
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
        uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
        iVar2 = uVar1 - ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                         *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff);
        if (iVar2 != 0) {
          return iVar2;
        }
        if (uVar1 == 0) {
          return 0;
        }
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    if ((uVar1 + iRam0213a1b8 & uRam0213a1bc) == 0) {
      if (uVar1 == (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                   *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20)) {
        do {
          param_1 = param_1 + 4;
          uVar1 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
          param_2 = param_2 + 4;
          if ((uVar1 + iRam0213a1b8 & uRam0213a1bc) != 0) goto LAB_0213a154;
        } while (uVar1 == (*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20));
      }
      param_1 = param_1 - 1;
      param_2 = param_2 - 1;
    }
    else {
LAB_0213a154:
      uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
      iVar3 = uVar1 - ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
  }
  if (uVar1 == 0) {
    return 0;
  }
  do {
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
    uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) & 0xff;
    iVar3 = uVar1 - ((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                     *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) & 0xff);
    if (iVar3 != 0) {
      return iVar3;
    }
  } while (uVar1 != 0);
  return 0;
}

