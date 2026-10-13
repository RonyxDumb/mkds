/* Decompiled C draft; module arm9; ROM address 01ffc158. No matching claim. */
#include "types.h"
#include "deps/01ffc158_func_01ffc158.h"

undefined4 func_01ffc158(int param_1,int param_2,short param_3,int param_4,int param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0x48U & 3;
  uVar5 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20 | param_6;
  if (param_5 != 0) {
    uVar6 = param_1 + 0x44U & 3;
    uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 8) == 0) {
      *(int *)(param_1 + 0x3ec) = param_4 * 0x32;
    }
    return 1;
  }
  uVar6 = param_1 + 0x44U & 3;
  uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if ((uVar6 & 8) == 0) {
    uVar5 = param_1 + 0x2a0U & 3;
    uVar4 = *(uint *)(param_1 + 0x2a0U & 0xfffffffc);
    iVar1 = (param_2 -
            ((int)*psRam01ffc274 * (int)param_3 * (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)
            >> 0xc)) * 0x10000;
  }
  else {
    uVar5 = param_1 + 0x2c4U & 3;
    uVar2 = *(uint *)(param_1 + 0x2c4U & 0xfffffffc);
    uVar4 = param_1 + 0x2ccU & 3;
    uVar3 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
    if ((int)((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) * param_4) < 1) {
      iVar1 = ((int)*(short *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0x32) +
              (int)*(short *)(param_1 + 0x38a)) * 0x10000;
    }
    else {
      iVar1 = *(short *)(param_1 + 0x38a) * -0x10000;
    }
  }
  if ((uVar6 & 0x10) != 0) {
    uVar6 = param_1 + 0x2d4U & 3;
    uVar5 = *(uint *)(param_1 + 0x2d4U & 0xfffffffc);
    *(uint *)(param_1 + 0x2d4) =
         param_4 * iRam01ffc278 + (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20);
    uVar6 = param_1 + 0x2d4U & 3;
    uVar5 = *(uint *)(param_1 + 0x2d4U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < 0x1001) {
      if ((int)uVar6 < -0x1000) {
        *(undefined4 *)(param_1 + 0x2d4) = 0xfffff000;
      }
    }
    else {
      *(undefined4 *)(param_1 + 0x2d4) = 0x1000;
    }
  }
  uVar6 = param_1 + 0x2a4U & 3;
  uVar5 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  if ((uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0) &&
     (uVar6 = param_1 + 0x44U & 3, uVar5 = *(uint *)(param_1 + 0x44U & 0xfffffffc),
     ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x8000000) == 0)) {
    *(int *)(param_1 + 0x3ec) = (iVar1 >> 0x10) * param_4;
  }
  return 1;
}

