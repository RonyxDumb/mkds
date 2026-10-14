/* Decompiled C draft; module arm9; ROM address 02014724. No matching claim. */
#include "types.h"
#include "deps/02014724_func_02014724.h"

void func_02014724(uint *param_1,int param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  uVar2 = param_3 + 4 & 3;
  uVar3 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar5 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  uVar1 = param_2 >> 0xc;
  param_4 = param_4 + (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  if ((uVar5 & 0xc0000000) != 0) {
    uVar2 = uVar5 & uRam02014950;
    if ((uVar5 & 0x40000000) == 0) {
      if ((uVar1 & 3) == 0) {
        uVar1 = uVar1 >> 2;
      }
      else {
        if (uVar1 <= uVar2 >> 0x10) {
          if ((uVar1 & 1) != 0) {
            if ((uVar1 & 2) == 0) {
              uVar2 = uVar1 >> 2;
              uVar1 = uVar2 + 1;
            }
            else {
              uVar1 = uVar1 >> 2;
              uVar2 = uVar1 + 1;
            }
            if ((uVar5 & 0x20000000) == 0) {
              uVar3 = param_4 + uVar2 * 8;
              uVar5 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              uVar4 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
              uVar3 = param_4 + uVar1 * 8;
              uVar5 = uVar3 & 3;
              uVar3 = *(uint *)(uVar3 & 0xfffffffc);
              uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
              *param_1 = uVar4 * 3 + uVar3 >> 2 |
                         ((((int)uVar4 >> 0x1f) << 1 | uVar4 >> 0x1f) + ((int)uVar4 >> 0x1f) +
                          (uint)CARRY4(uVar4 * 2,uVar4) + ((int)uVar3 >> 0x1f) +
                         (uint)CARRY4(uVar4 * 3,uVar3)) * 0x40000000;
              uVar2 = param_4 + uVar2 * 8 + 4;
              uVar3 = uVar2 & 3;
              uVar2 = *(uint *)(uVar2 & 0xfffffffc);
              uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
              uVar1 = param_4 + uVar1 * 8 + 4;
              uVar2 = uVar1 & 3;
              uVar1 = *(uint *)(uVar1 & 0xfffffffc);
              uVar1 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
              param_1[1] = uVar3 * 3 + uVar1 >> 2 |
                           ((((int)uVar3 >> 0x1f) << 1 | uVar3 >> 0x1f) + ((int)uVar3 >> 0x1f) +
                            (uint)CARRY4(uVar3 * 2,uVar3) + ((int)uVar1 >> 0x1f) +
                           (uint)CARRY4(uVar3 * 3,uVar1)) * 0x40000000;
              return;
            }
            *param_1 = (int)*(short *)(param_4 + uVar1 * 4) + *(short *)(param_4 + uVar2 * 4) * 3 >>
                       2;
            param_1[1] = (int)*(short *)(param_4 + uVar1 * 4 + 2) +
                         *(short *)(param_4 + uVar2 * 4 + 2) * 3 >> 2;
            return;
          }
          uVar1 = uVar1 >> 2;
          goto LAB_020148d4;
        }
        uVar1 = (uVar1 & 3) + (uVar2 >> 0x12);
      }
    }
    else if ((uVar1 & 1) == 0) {
      uVar1 = uVar1 >> 1;
    }
    else {
      if (uVar1 <= uVar2 >> 0x10) {
        uVar1 = uVar1 >> 1;
LAB_020148d4:
        if ((uVar5 & 0x20000000) == 0) {
          iVar6 = param_4 + uVar1 * 8;
          uVar1 = param_4 + uVar1 * 8;
          uVar2 = uVar1 & 3;
          uVar5 = *(uint *)(uVar1 & 0xfffffffc);
          uVar1 = iVar6 + 8U & 3;
          uVar3 = *(uint *)(iVar6 + 8U & 0xfffffffc);
          *param_1 = (int)((uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) +
                          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) >> 1;
          uVar1 = iVar6 + 4U & 3;
          uVar5 = *(uint *)(iVar6 + 4U & 0xfffffffc);
          uVar2 = iVar6 + 0xcU & 3;
          uVar3 = *(uint *)(iVar6 + 0xcU & 0xfffffffc);
          param_1[1] = (int)((uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) +
                            (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20)) >> 1;
          return;
        }
        iVar6 = param_4 + uVar1 * 4;
        *param_1 = (int)*(short *)(param_4 + uVar1 * 4) + (int)*(short *)(iVar6 + 4) >> 1;
        param_1[1] = (int)*(short *)(iVar6 + 2) + (int)*(short *)(iVar6 + 6) >> 1;
        return;
      }
      uVar1 = (uVar2 >> 0x11) + 1;
    }
  }
  if ((uVar5 & 0x20000000) != 0) {
    *param_1 = (int)*(short *)(param_4 + uVar1 * 4);
    param_1[1] = (int)*(short *)(param_4 + uVar1 * 4 + 2);
    return;
  }
  uVar2 = param_4 + uVar1 * 8;
  uVar3 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *param_1 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  uVar1 = param_4 + uVar1 * 8 + 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  param_1[1] = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  return;
}

