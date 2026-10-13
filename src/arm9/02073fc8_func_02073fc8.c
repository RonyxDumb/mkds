/* Decompiled C draft; module arm9; ROM address 02073fc8. No matching claim. */
#include "types.h"
#include "deps/02073fc8_func_02073fc8.h"

void func_02073fc8(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  
  uVar6 = *(uint *)(uRam02074084 & 0xfffffffc) >> (uRam02074084 & 3) * 8 |
          *(uint *)(uRam02074084 & 0xfffffffc) << (uRam02074084 & 3) * -8 + 0x20;
  if (uRam02074080 < param_2) {
    return;
  }
  iVar7 = iRam0207408c;
  if ((param_2 <= uRam02074088) && (iVar7 = 0x1000, uRam02074090 < param_2)) {
    iVar7 = iRam02074094;
  }
  lVar2 = (longlong)param_1 *
          (longlong)
          (int)((uint)((longlong)param_3 * (longlong)iVar7) >> 0xc |
               (int)((ulonglong)((longlong)param_3 * (longlong)iVar7) >> 0x20) << 0x14);
  uVar1 = uVar6 + 0x140 & 3;
  uVar4 = *(uint *)(uVar6 + 0x140 & 0xfffffffc);
  uVar5 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  if ((uVar4 >> uVar1 * 8 != 0 || uVar4 << uVar1 * -8 + 0x20 != 0) &&
     (uVar1 = uVar6 + 0x148 & 3, uVar4 = *(uint *)(uVar6 + 0x148 & 0xfffffffc),
     (int)uVar5 < (int)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20))) {
    return;
  }
  *(uint *)(uVar6 + 0x148) = uVar5;
  *(undefined4 *)(uVar6 + 0x140) = 1;
  *(undefined4 *)(uVar6 + 0x144) = 0;
  *(undefined4 *)(uVar6 + 0x14c) = 0x800;
  uVar3 = uRam02074098;
  *(undefined2 *)(uVar6 + 0x150) = 1;
  *(undefined4 *)(uVar6 + 0x154) = uVar3;
  *(undefined4 *)(uVar6 + 0x158) = 0;
  return;
}

