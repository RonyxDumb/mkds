/* Decompiled C draft; module arm9; ROM address 020dffac. No matching claim. */
#include "types.h"
#include "deps/020dffac_func_020dffac.h"

void func_020dffac(int param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = param_1 + 0x144;
  iVar2 = func_020d8cac(uVar7);
  uVar5 = param_1 + 0x168U & 3;
  uVar3 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  lVar1 = (longlong)
          -(int)*(short *)(iRam020e0054 + ((int)((uint)(iVar2 << 0x12) >> 0xc & 0xffff) >> 4) * 4) *
          (longlong)(int)(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20);
  uVar3 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = uVar3;
  if ((int)uVar3 < 0x201) {
    uVar5 = 0x200;
  }
  *(uint *)(param_1 + 0x148) = uVar5;
  uVar4 = *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
          *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  uVar5 = param_1 + 0x150U & 3;
  uVar6 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
  uVar7 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) * 0x54 +
          (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x34;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((int)uVar3 < 0x201) {
    uVar3 = 0x200;
  }
  lVar1 = (longlong)(int)uVar3 * (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
  *(uint *)(param_1 + 0x154) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  return;
}

