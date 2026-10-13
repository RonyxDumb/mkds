/* Decompiled C draft; module arm9; ROM address 02075fe0. No matching claim. */
#include "types.h"
#include "deps/02075fe0_StructHD_SomeFn_6.h"

void StructHD_SomeFn_6(int param_1,int param_2,int param_3)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar4;
  
  uVar4 = param_2 + 0x48U & 3;
  uVar3 = *(uint *)(param_2 + 0x48U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  iVar6 = -0x2d000;
  uVar3 = uVar4 & 0x10000;
  if (uVar3 != 0) {
    iVar6 = -0x3c000;
  }
  uVar5 = param_2 + 0x44U & 3;
  uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
  iVar7 = iRam020760e4;
  if (0 < *(short *)(param_2 + 1000)) {
    iVar7 = 0x52;
  }
  uVar8 = 0;
  if ((((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) & 0x10) != 0) || (uVar3 != 0)) {
    uVar3 = param_3 + 4U & 3;
    uVar5 = *(uint *)(param_3 + 4U & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if ((int)uVar3 < 1) {
      if ((int)(uVar3 + iRam020760e8) < 0) {
        uVar8 = (uint)((ulonglong)uVar3 * 0xffff1000) >> 0xc |
                ((int)((ulonglong)uVar3 * 0xffff1000 >> 0x20) - uVar3) * 0x100000;
      }
    }
    else {
      uVar8 = (uint)((longlong)(int)uVar3 * (longlong)iVar6) >> 0xc |
              (int)((ulonglong)((longlong)(int)uVar3 * (longlong)iVar6) >> 0x20) << 0x14;
    }
  }
  if ((uVar4 & 0x40000000) == 0) {
    uVar4 = param_1 + 0x168U & 3;
    uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    lVar1 = (longlong)(int)(uVar8 - uVar4) * (longlong)iVar7 + 0x800;
    *(uint *)(param_1 + 0x168) =
         uVar4 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    return;
  }
  uVar4 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (longlong)(int)-uVar4 * (longlong)iVar7 + 0x800;
  *(uint *)(param_1 + 0x168) =
       uVar4 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
  return;
}

