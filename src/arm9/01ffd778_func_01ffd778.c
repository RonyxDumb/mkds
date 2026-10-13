/* Decompiled C draft; module arm9; ROM address 01ffd778. No matching claim. */
#include "types.h"
#include "deps/01ffd778_func_01ffd778.h"

uint func_01ffd778(uint param_1,int param_2,int param_3,int param_4,ushort param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar7 = uRam01ffd8f4 + 0x10 & 3;
  uVar5 = *(uint *)(uRam01ffd8f4 + 0x10 & 0xfffffffc);
  uVar6 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  iVar1 = (int)((uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20) -
               (uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20)) >> 0xc;
  uVar7 = uRam01ffd8f4 + 8 & 3;
  uVar6 = *(uint *)(uRam01ffd8f4 + 8 & 0xfffffffc);
  iVar2 = param_3 + param_2 >> 0xc;
  uVar7 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) -
          (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20);
  iVar3 = (int)uVar7 >> 0xc;
  uVar6 = iVar3 * iVar3 + iVar1 * iVar1;
  if (param_4 < (int)uVar6) {
    uVar7 = uRam01ffd8f8;
  }
  uVar5 = uVar6 & 0x3fffffe0;
  if (param_4 < (int)uVar6) {
    uVar5 = uVar5 | *(uint *)(uVar7 & 0xfffffffc) >> (uVar7 & 3) * 8 |
                    *(uint *)(uVar7 & 0xfffffffc) << (uVar7 & 3) * -8 + 0x20;
  }
  if (iVar2 * iVar2 < (int)uVar6) {
    if (param_5 < 2) {
      return uVar5 | 3;
    }
    uVar5 = uVar5 | *(uint *)(uRam01ffd8fc & 0xfffffffc) >> (uRam01ffd8fc & 3) * 8 |
                    *(uint *)(uRam01ffd8fc & 0xfffffffc) << (uRam01ffd8fc & 3) * -8 + 0x20;
  }
  uVar7 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar6 = uRam01ffd8f4 + 0xc & 3;
  uVar4 = *(uint *)(uRam01ffd8f4 + 0xc & 0xfffffffc);
  uVar8 = uRam01ffd8f4 + 0x18 & 3;
  uVar10 = *(uint *)(uRam01ffd8f4 + 0x18 & 0xfffffffc);
  iVar2 = (int)((uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20) -
               (uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20)) >> 0xc;
  uVar7 = uRam01ffd8f4 + 0x14 & 3;
  uVar4 = *(uint *)(uRam01ffd8f4 + 0x14 & 0xfffffffc);
  uVar6 = uRam01ffd8f4 + 0x1c & 3;
  uVar9 = *(uint *)(uRam01ffd8f4 + 0x1c & 0xfffffffc);
  if ((int)(iVar1 * (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           iVar3 * (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) +
           iVar2 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20)) <
      (int)((*(uint *)(uRam01ffd8f4 & 0xfffffffc) >> (uRam01ffd8f4 & 3) * 8 |
            *(uint *)(uRam01ffd8f4 & 0xfffffffc) << (uRam01ffd8f4 & 3) * -8 + 0x20) - param_2)) {
    return uVar5 | 2;
  }
  uVar7 = uRam01ffd8f4 + 0x24 & 3;
  uVar4 = *(uint *)(uRam01ffd8f4 + 0x24 & 0xfffffffc);
  uVar6 = uRam01ffd8f4 + 0x20 & 3;
  uVar9 = *(uint *)(uRam01ffd8f4 + 0x20 & 0xfffffffc);
  uVar8 = uRam01ffd8f4 + 0x28 & 3;
  uVar10 = *(uint *)(uRam01ffd8f4 + 0x28 & 0xfffffffc);
  if (param_2 < (int)(iVar1 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
                     iVar3 * (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
                     iVar2 * (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20))) {
    return uVar5 | 2;
  }
  uVar7 = uRam01ffd8f4 + 0x30 & 3;
  uVar4 = *(uint *)(uRam01ffd8f4 + 0x30 & 0xfffffffc);
  uVar6 = uRam01ffd8f4 + 0x2c & 3;
  uVar9 = *(uint *)(uRam01ffd8f4 + 0x2c & 0xfffffffc);
  uVar8 = uRam01ffd8f4 + 0x34 & 3;
  uVar10 = *(uint *)(uRam01ffd8f4 + 0x34 & 0xfffffffc);
  if ((int)(iVar1 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
           iVar3 * (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
           iVar2 * (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) <= param_2) {
    uVar7 = uRam01ffd8f4 + 0x3c & 3;
    uVar4 = *(uint *)(uRam01ffd8f4 + 0x3c & 0xfffffffc);
    uVar6 = uRam01ffd8f4 + 0x38 & 3;
    uVar9 = *(uint *)(uRam01ffd8f4 + 0x38 & 0xfffffffc);
    uVar8 = uRam01ffd8f4 + 0x40 & 3;
    uVar10 = *(uint *)(uRam01ffd8f4 + 0x40 & 0xfffffffc);
    if ((int)(iVar1 * (uVar10 >> uVar8 * 8 | uVar10 << uVar8 * -8 + 0x20) +
             iVar3 * (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20) +
             iVar2 * (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20)) <= param_2) {
      uVar7 = uRam01ffd8f4 + 0x48 & 3;
      uVar9 = *(uint *)(uRam01ffd8f4 + 0x48 & 0xfffffffc);
      uVar6 = uRam01ffd8f4 + 0x44 & 3;
      uVar10 = *(uint *)(uRam01ffd8f4 + 0x44 & 0xfffffffc);
      uVar8 = uRam01ffd8f4 + 0x4c & 3;
      uVar4 = *(uint *)(uRam01ffd8f4 + 0x4c & 0xfffffffc);
      if (param_2 < (int)(iVar1 * (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) +
                         iVar3 * (uVar10 >> uVar6 * 8 | uVar10 << uVar6 * -8 + 0x20) +
                         iVar2 * (uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20))) {
        uVar5 = uVar5 | 2;
      }
      return uVar5;
    }
    return uVar5 | 2;
  }
  return uVar5 | 2;
}

