/* Decompiled C draft; module arm9; ROM address 02014ad0. No matching claim. */
#include "types.h"
#include "deps/02014ad0_func_02014ad0.h"

void func_02014ad0(uint *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_3 + 4 & 3;
  uVar3 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar2 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar1 = param_2 >> 0xc;
  param_4 = param_4 + (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  if ((uVar2 & 0xc0000000) != 0) {
    uVar4 = uVar2 & uRam02014c58;
    if ((uVar2 & 0x40000000) == 0) {
      if ((uVar1 & 3) == 0) {
        uVar1 = uVar1 >> 2;
      }
      else {
        if (uVar1 <= uVar4 >> 0x10) {
          if ((uVar1 & 1) != 0) {
            if ((uVar1 & 2) == 0) {
              uVar4 = uVar1 >> 2;
              uVar1 = uVar4 + 1;
            }
            else {
              uVar1 = uVar1 >> 2;
              uVar4 = uVar1 + 1;
            }
            if ((uVar2 & 0x20000000) == 0) {
              uVar4 = param_4 + uVar4 * 4;
              uVar2 = uVar4 & 3;
              uVar4 = *(uint *)(uVar4 & 0xfffffffc);
              uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
              uVar1 = param_4 + uVar1 * 4;
              uVar4 = uVar1 & 3;
              uVar1 = *(uint *)(uVar1 & 0xfffffffc);
              uVar1 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
              *param_1 = uVar2 * 3 + uVar1 >> 2 |
                         ((((int)uVar2 >> 0x1f) << 1 | uVar2 >> 0x1f) + ((int)uVar2 >> 0x1f) +
                          (uint)CARRY4(uVar2 * 2,uVar2) + ((int)uVar1 >> 0x1f) +
                         (uint)CARRY4(uVar2 * 3,uVar1)) * 0x40000000;
              return;
            }
            *param_1 = *(short *)(param_4 + uVar4 * 2) * 3 + (int)*(short *)(param_4 + uVar1 * 2) >>
                       2;
            return;
          }
          uVar1 = uVar1 >> 2;
          goto LAB_02014be0;
        }
        uVar1 = (uVar1 & 3) + (uVar4 >> 0x12);
      }
    }
    else if ((uVar1 & 1) == 0) {
      uVar1 = uVar1 >> 1;
    }
    else {
      if (uVar1 <= uVar4 >> 0x10) {
        uVar1 = uVar1 >> 1;
LAB_02014be0:
        if ((uVar2 & 0x20000000) == 0) {
          uVar4 = param_4 + uVar1 * 4;
          uVar2 = uVar4 & 3;
          uVar3 = *(uint *)(uVar4 & 0xfffffffc);
          uVar1 = param_4 + uVar1 * 4 + 4;
          uVar4 = uVar1 & 3;
          uVar1 = *(uint *)(uVar1 & 0xfffffffc);
          *param_1 = ((int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) >> 1) +
                     ((int)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) >> 1);
          return;
        }
        *param_1 = (int)*(short *)(param_4 + uVar1 * 2) + (int)*(short *)(param_4 + uVar1 * 2 + 2)
                   >> 1;
        return;
      }
      uVar1 = (uVar4 >> 0x11) + 1;
    }
  }
  if ((uVar2 & 0x20000000) == 0) {
    uVar1 = param_4 + uVar1 * 4;
    uVar4 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    *param_1 = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  }
  else {
    *param_1 = (int)*(short *)(param_4 + uVar1 * 2);
  }
  return;
}

