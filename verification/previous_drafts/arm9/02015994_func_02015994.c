/* Decompiled C draft; module arm9; ROM address 02015994. No matching claim. */
#include "types.h"
#include "deps/02015994_func_02015994.h"

uint func_02015994(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 & 0x20000000) != 0) {
    return param_3;
  }
  param_1 = param_1 + param_3;
  if ((param_2 & 0xc0000000) != 0) {
    uVar3 = param_2 & uRam02015a9c;
    if ((param_2 & 0x40000000) == 0) {
      if ((param_4 & 3) == 0) {
        param_4 = param_4 >> 2;
      }
      else {
        if (param_4 <= uVar3) {
          if ((param_4 & 1) != 0) {
            if ((param_4 & 2) == 0) {
              uVar3 = param_4 >> 2;
              param_4 = uVar3 + 1;
            }
            else {
              param_4 = param_4 >> 2;
              uVar3 = param_4 + 1;
            }
            return uRam02015a9c &
                   *(short *)(param_1 + uVar3 * 4) * 3 + (int)*(short *)(param_1 + param_4 * 4) >> 2
                   | (*(short *)(param_1 + uVar3 * 4 + 2) * 3 +
                      (int)*(short *)(param_1 + param_4 * 4 + 2) >> 2) << 0x10;
          }
          param_4 = param_4 >> 2;
          goto LAB_02015a68;
        }
        param_4 = (param_4 & 3) + (uVar3 >> 2);
      }
    }
    else if ((param_4 & 1) == 0) {
      param_4 = param_4 >> 1;
    }
    else {
      if (param_4 <= uVar3) {
        param_4 = param_4 >> 1;
LAB_02015a68:
        iVar2 = param_1 + param_4 * 4;
        return uRam02015a9c &
               (int)*(short *)(param_1 + param_4 * 4) + (int)*(short *)(iVar2 + 4) >> 1 |
               ((int)*(short *)(iVar2 + 2) + (int)*(short *)(iVar2 + 6) >> 1) << 0x10;
      }
      param_4 = (uVar3 >> 1) + 1;
    }
  }
  uVar3 = param_1 + param_4 * 4;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  return uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
}

