/* Decompiled C draft; module arm9; ROM address 0201456c. No matching claim. */
#include "types.h"
#include "deps/0201456c_func_0201456c.h"

void func_0201456c(uint *param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  uVar1 = param_3 + 4 & 3;
  uVar7 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar5 = (int)param_2 >> 0xc;
  iVar8 = param_4 + (uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  uVar1 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  if (uVar5 == *(ushort *)(param_4 + 4) - 1) {
    if ((uVar1 & 0xc0000000) != 0) {
      if ((uVar1 & 0x40000000) == 0) {
        uVar5 = (uVar5 & 3) + (uVar5 >> 2);
      }
      else {
        uVar5 = (uVar5 & 1) + (uVar5 >> 1);
      }
    }
    uVar7 = param_4 + 8U & 3;
    uVar2 = *(uint *)(param_4 + 8U & 0xfffffffc);
    if (((uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 2) == 0) {
      if ((uVar1 & 0x20000000) != 0) {
        *param_1 = (int)*(short *)(iVar8 + uVar5 * 4);
        param_1[1] = (int)*(short *)(iVar8 + uVar5 * 4 + 2);
        return;
      }
      uVar1 = iVar8 + uVar5 * 8;
      uVar7 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      *param_1 = uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20;
      uVar5 = iVar8 + uVar5 * 8 + 4;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      param_1[1] = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
      return;
    }
    iVar4 = 0;
  }
  else if ((uVar1 & 0xc0000000) == 0) {
    iVar4 = uVar5 + 1;
  }
  else {
    uVar7 = (uVar1 & uRam02014714) >> 0x10;
    if ((uVar1 & 0x40000000) == 0) {
      if (uVar5 < uVar7) {
        uVar5 = uVar5 >> 2;
        iVar4 = uVar5 + 1;
        param_2 = param_2 & uRam0201471c;
        iVar9 = 4;
        iVar3 = 2;
        goto LAB_02014694;
      }
      uVar5 = (uVar5 & 3) + (uVar5 >> 2);
      iVar4 = uVar5 + 1;
    }
    else {
      if (uVar5 < uVar7) {
        uVar5 = uVar5 >> 1;
        iVar4 = uVar5 + 1;
        param_2 = param_2 & uRam02014718;
        iVar9 = 2;
        iVar3 = 1;
        goto LAB_02014694;
      }
      uVar5 = (uVar1 & uRam02014714) >> 0x11;
      iVar4 = uVar5 + 1;
    }
  }
  iVar9 = 1;
  param_2 = param_2 & uRam02014720;
  iVar3 = 0;
LAB_02014694:
  if ((uVar1 & 0x20000000) == 0) {
    uVar1 = iVar8 + uVar5 * 8;
    uVar7 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar2 = uVar1 >> uVar7 * 8 | uVar1 << uVar7 * -8 + 0x20;
    uVar5 = iVar8 + uVar5 * 8 + 4;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    uVar5 = iVar8 + iVar4 * 8;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar6 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
    uVar5 = iVar8 + iVar4 * 8 + 4;
    uVar1 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  }
  else {
    uVar2 = (uint)*(short *)(iVar8 + uVar5 * 4);
    uVar7 = (uint)*(short *)(iVar8 + uVar5 * 4 + 2);
    uVar6 = (uint)*(short *)(iVar8 + iVar4 * 4);
    uVar5 = (uint)*(short *)(iVar8 + iVar4 * 4 + 2);
  }
  *param_1 = (int)(uVar2 * iVar9 + ((int)(param_2 * (uVar6 - uVar2)) >> 0xc)) >> iVar3;
  param_1[1] = (int)(uVar7 * iVar9 + ((int)(param_2 * (uVar5 - uVar7)) >> 0xc)) >> iVar3;
  return;
}

