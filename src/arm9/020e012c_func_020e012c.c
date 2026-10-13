/* Decompiled C draft; module arm9; ROM address 020e012c. No matching claim. */
#include "types.h"
#include "deps/020e012c_func_020e012c.h"

void func_020e012c(int param_1)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar9 = param_1 + 0x144;
  iVar3 = func_020d8cac(uVar9);
  uVar6 = param_1 + 0x168U & 3;
  uVar4 = *(uint *)(param_1 + 0x168U & 0xfffffffc);
  lVar2 = (longlong)
          (int)*(short *)(iRam020e01e8 + ((int)((uint)(iVar3 << 0x12) >> 0xc & 0xffff) >> 4) * 4) *
          (longlong)(int)(uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20);
  uVar4 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar6 = uVar4;
  if ((int)uVar4 < 0x201) {
    uVar6 = 0x200;
  }
  *(uint *)(param_1 + 0x148) = uVar6;
  uVar5 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
          *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
  uVar6 = param_1 + 0x150U & 3;
  uVar8 = *(uint *)(param_1 + 0x150U & 0xfffffffc);
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar6 = (uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) * 0x54 +
          (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) + 0x34;
  uVar1 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  if ((int)uVar4 < 0x201) {
    uVar4 = 0x200;
  }
  lVar2 = (longlong)(int)uVar4 * (longlong)(int)(uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20);
  *(uint *)(param_1 + 0x154) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  iVar7 = func_020d8cac(uVar9);
  iVar3 = iVar7;
  if (0xff < iVar7) {
    iVar3 = 1;
  }
  if (0xff < iVar7) {
    *(short *)(param_1 + 0x90) = (short)iVar3;
    *(short *)(param_1 + 0x92) = (short)iVar3;
  }
  return;
}

