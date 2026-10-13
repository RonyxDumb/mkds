/* Decompiled C draft; module arm9; ROM address 02014954. No matching claim. */
#include "types.h"
#include "deps/02014954_func_02014954.h"

void func_02014954(uint *param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_3 + 4 & 3;
  uVar6 = *(uint *)(param_3 + 4 & 0xfffffffc);
  uVar5 = (int)param_2 >> 0xc;
  psVar4 = (short *)(param_4 + (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20));
  uVar7 = *(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
          *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20;
  if (uVar5 == *(ushort *)(param_4 + 4) - 1) {
    if ((uVar7 & 0xc0000000) != 0) {
      if ((uVar7 & 0x40000000) == 0) {
        uVar5 = (uVar5 & 3) + (uVar5 >> 2);
      }
      else {
        uVar5 = (uVar5 & 1) + (uVar5 >> 1);
      }
    }
    uVar6 = param_4 + 8U & 3;
    uVar2 = *(uint *)(param_4 + 8U & 0xfffffffc);
    if (((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 2) == 0) {
      if ((uVar7 & 0x20000000) == 0) {
        uVar7 = (uint)(psVar4 + uVar5 * 2) & 3;
        uVar5 = *(uint *)((uint)(psVar4 + uVar5 * 2) & 0xfffffffc);
        *param_1 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      }
      else {
        *param_1 = (int)psVar4[uVar5];
      }
      return;
    }
    if ((uVar7 & 0x20000000) == 0) {
      uVar7 = (uint)(psVar4 + uVar5 * 2) & 3;
      uVar5 = *(uint *)((uint)(psVar4 + uVar5 * 2) & 0xfffffffc);
      uVar5 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
      uVar7 = *(uint *)((uint)psVar4 & 0xfffffffc) >> ((uint)psVar4 & 3) * 8 |
              *(uint *)((uint)psVar4 & 0xfffffffc) << ((uint)psVar4 & 3) * -8 + 0x20;
    }
    else {
      uVar5 = (uint)psVar4[uVar5];
      uVar7 = (uint)*psVar4;
    }
    *param_1 = uVar5 + ((int)((param_2 & uRam02014ac0) * (uVar7 - uVar5)) >> 0xc);
    return;
  }
  if ((uVar7 & 0xc0000000) != 0) {
    uVar6 = (uVar7 & uRam02014ac4) >> 0x10;
    if ((uVar7 & 0x40000000) == 0) {
      if (uVar5 < uVar6) {
        uVar5 = uVar5 >> 2;
        param_2 = param_2 & uRam02014acc;
        iVar3 = 4;
        iVar1 = 2;
        goto LAB_02014a7c;
      }
      uVar5 = (uVar5 & 3) + (uVar5 >> 2);
    }
    else {
      if (uVar5 < uVar6) {
        uVar5 = uVar5 >> 1;
        param_2 = param_2 & uRam02014ac8;
        iVar3 = 2;
        iVar1 = 1;
        goto LAB_02014a7c;
      }
      uVar5 = (uVar7 & uRam02014ac4) >> 0x11;
    }
  }
  iVar3 = 1;
  param_2 = param_2 & uRam02014ac0;
  iVar1 = 0;
LAB_02014a7c:
  if ((uVar7 & 0x20000000) == 0) {
    uVar7 = (uint)(psVar4 + uVar5 * 2) & 3;
    uVar6 = *(uint *)((uint)(psVar4 + uVar5 * 2) & 0xfffffffc);
    uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
    uVar6 = (uint)(psVar4 + uVar5 * 2 + 2) & 3;
    uVar5 = *(uint *)((uint)(psVar4 + uVar5 * 2 + 2) & 0xfffffffc);
    uVar5 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  }
  else {
    uVar7 = (uint)psVar4[uVar5];
    uVar5 = (uint)psVar4[uVar5 + 1];
  }
  *param_1 = (int)(uVar7 * iVar3 + ((int)(param_2 * (uVar5 - uVar7)) >> 0xc)) >> iVar1;
  return;
}

