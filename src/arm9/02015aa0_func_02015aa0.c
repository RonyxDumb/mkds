/* Decompiled C draft; module arm9; ROM address 02015aa0. No matching claim. */
#include "types.h"
#include "deps/02015aa0_func_02015aa0.h"

uint func_02015aa0(int param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_2 & 0x20000000) != 0) {
    return param_3;
  }
  param_1 = param_1 + param_3;
  if ((param_2 & 0xc0000000) != 0) {
    uVar3 = param_2 & uRam02015b98;
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
            if ((param_2 & 0x10000000) == 0) {
              uVar3 = param_1 + uVar3 * 4;
              uVar2 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
              uVar2 = param_1 + param_4 * 4;
              uVar1 = uVar2 & 3;
              uVar2 = *(uint *)(uVar2 & 0xfffffffc);
              uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
            }
            else {
              uVar3 = (uint)*(short *)(param_1 + uVar3 * 2);
              uVar2 = (uint)*(short *)(param_1 + param_4 * 2);
            }
            return (int)(uVar3 * 3 + uVar2) >> 2;
          }
          param_4 = param_4 >> 2;
          goto LAB_02015b6c;
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
LAB_02015b6c:
        if ((param_2 & 0x10000000) == 0) {
          uVar3 = param_1 + param_4 * 4;
          uVar2 = uVar3 & 3;
          uVar3 = *(uint *)(uVar3 & 0xfffffffc);
          uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
          uVar2 = param_1 + param_4 * 4 + 4;
          uVar1 = uVar2 & 3;
          uVar2 = *(uint *)(uVar2 & 0xfffffffc);
          uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
        }
        else {
          uVar3 = (uint)*(short *)(param_1 + param_4 * 2);
          uVar2 = (uint)*(short *)(param_1 + param_4 * 2 + 2);
        }
        return (int)(uVar3 + uVar2) >> 1;
      }
      param_4 = (uVar3 >> 1) + 1;
    }
  }
  if ((param_2 & 0x10000000) == 0) {
    uVar3 = param_1 + param_4 * 4;
    uVar2 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  }
  else {
    uVar3 = (uint)*(short *)(param_1 + param_4 * 2);
  }
  return uVar3;
}

