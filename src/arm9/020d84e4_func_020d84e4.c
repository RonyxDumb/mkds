/* Decompiled C draft; module arm9; ROM address 020d84e4. No matching claim. */
#include "types.h"
#include "deps/020d84e4_func_020d84e4.h"

int func_020d84e4(uint param_1)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  iVar3 = func_020d8cc8();
  if (iVar3 != 0) {
    uVar7 = param_1 + 0x34 & 3;
    uVar4 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    uVar7 = param_1 + 0x20 & 3;
    uVar4 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
    iVar6 = (int)*(short *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0xe);
    if (iVar6 == 0) {
      uVar7 = param_1 + 0x28 & 3;
      uVar4 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
      uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    }
    else {
      uVar7 = param_1 + 0x24 & 3;
      uVar4 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
      uVar7 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * iVar6;
    }
    *(uint *)(param_1 + 0x34) = uVar7;
  }
  uVar7 = param_1 + 0x2c & 3;
  uVar8 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
  uVar4 = param_1 + 0x34 & 3;
  uVar5 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
  if ((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) !=
      (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20)) {
    iVar6 = func_020d8cac(param_1);
    uVar7 = param_1 + 0x34 & 3;
    uVar5 = *(uint *)(param_1 + 0x34 & 0xfffffffc);
    uVar4 = param_1 + 0x2c & 3;
    uVar8 = *(uint *)(param_1 + 0x2c & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) *
            (longlong)(0x1000 - iVar6);
    lVar2 = (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) * (longlong)iVar6;
    iVar6 = ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14) +
            ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14);
    *(int *)(param_1 + 4) = iVar6;
    uVar5 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar7 = param_1 + 0xc & 3;
    uVar8 = *(uint *)(param_1 + 0xc & 0xfffffffc);
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar7 = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) * 0x54 +
            (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) + 0x34;
    uVar4 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    lVar1 = (longlong)iVar6 * (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    *(uint *)(param_1 + 0x10) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  }
  return iVar3;
}

