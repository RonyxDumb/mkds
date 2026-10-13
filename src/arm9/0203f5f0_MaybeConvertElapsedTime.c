/* Decompiled C draft; module arm9; ROM address 0203f5f0. No matching claim. */
#include "types.h"
#include "deps/0203f5f0_MaybeConvertElapsedTime.h"

void MaybeConvertElapsedTime
               (undefined1 *param_1,undefined1 *param_2,undefined2 *param_3,uint param_4,
               uint param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined2 uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  
  uVar4 = *(uint *)(uRam0203f7a4 & 0xfffffffc) >> (uRam0203f7a4 & 3) * 8 |
          *(uint *)(uRam0203f7a4 & 0xfffffffc) << (uRam0203f7a4 & 3) * -8 + 0x20;
  uVar2 = uVar4 + 0x4ec;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    uVar4 = uVar4 + 0x4f4;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
    if (param_5 < uVar2) {
      param_5 = uVar2 - param_5;
    }
    else {
      param_5 = 0;
    }
  }
  if (uRam0203f7a8 <= param_5) {
    param_4 = 0x1000;
    param_5 = uRam0203f7b0;
  }
  uVar2 = ((int)((int)((ulonglong)((longlong)iRam0203f7ac * (longlong)(int)(param_5 << 0xc)) >> 0x20
                      ) + param_5 * 0x1000) >> 5) - ((int)(param_5 << 0xc) >> 0x1f);
  iVar3 = (int)uVar2 >> 0xc;
  iVar6 = (uVar2 & uRam0203f7b4) * 16000;
  iVar7 = (-((int)uVar2 >> 0x1f) +
          ((int)((ulonglong)((longlong)iRam0203f7ac * (longlong)iVar3) >> 0x20) + iVar3 >> 5)) *
          0x1000000 >> 0x18;
  uVar5 = (undefined2)((uint)iVar6 >> 0x10);
  iVar3 = (iVar3 - iRam0203f7b8 *
                   (-((int)uVar2 >> 0x1f) +
                   ((int)((ulonglong)((longlong)iRam0203f7ac * (longlong)iVar3) >> 0x20) + iVar3 >>
                   5))) * 0x1000000 >> 0x18;
  if (param_4 != 0) {
    uVar2 = (uint)((ulonglong)param_4 * 0x44);
    iVar6 = ((iVar6 >> 0x10) +
            ((int)((uVar2 + 0x800 >> 0xc |
                   (((int)param_4 >> 0x1f) * 0x44 + (int)((ulonglong)param_4 * 0x44 >> 0x20) +
                   (uint)(0xfffff7ff < uVar2)) * 0x100000) * 1000) >> 0xc)) * 0x10000 >> 0x10;
    if (iVar6 < 0) {
      iVar6 = (iVar6 + 1000) * 0x10000 >> 0x10;
      iVar3 = (iVar3 + -1) * 0x1000000 >> 0x18;
    }
    else if (999 < iVar6) {
      iVar6 = (iVar6 + -1000) * 0x10000 >> 0x10;
      iVar3 = (iVar3 + 1) * 0x1000000 >> 0x18;
    }
    if (iVar3 < 0) {
      iVar3 = (iVar3 + 0x3c) * 0x1000000 >> 0x18;
      iVar7 = (iVar7 + -1) * 0x1000000 >> 0x18;
    }
    else if (0x3b < iVar3) {
      iVar3 = (iVar3 + -0x3c) * 0x1000000 >> 0x18;
      iVar7 = (iVar7 + 1) * 0x1000000 >> 0x18;
    }
    bVar8 = iVar7 < 0;
    if (bVar8) {
      iVar6 = 0;
      iVar7 = iVar6;
      iVar3 = iVar6;
    }
    uVar5 = (undefined2)iVar6;
    if ((!bVar8) && (99 < iVar7)) {
      uVar5 = (undefined2)uRam0203f7bc;
      iVar7 = 99;
      iVar3 = 0x3b;
    }
  }
  *param_1 = (char)iVar7;
  *param_2 = (char)iVar3;
  *param_3 = uVar5;
  return;
}

