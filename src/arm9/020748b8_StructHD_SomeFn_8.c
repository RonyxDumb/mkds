/* Decompiled C draft; module arm9; ROM address 020748b8. No matching claim. */
#include "types.h"
#include "deps/020748b8_StructHD_SomeFn_8.h"

void StructHD_SomeFn_8(int param_1)

{
  longlong lVar1;
  longlong lVar2;
  longlong lVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar6;
  uint uVar11;
  
  uVar11 = param_1 + 0x218U & 3;
  uVar10 = *(uint *)(param_1 + 0x218U & 0xfffffffc);
  uVar11 = uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20;
  if (*(short *)(uVar11 + 0x44) == 0) {
    uVar10 = uVar11 + 0x18 & 3;
    uVar5 = *(uint *)(uVar11 + 0x18 & 0xfffffffc);
    *(uint *)(param_1 + 0x18) = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
    uVar10 = uVar11 + 0x1c & 3;
    uVar5 = *(uint *)(uVar11 + 0x1c & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
    uVar10 = uVar11 + 0x20 & 3;
    uVar11 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
    *(uint *)(param_1 + 0x20) = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
    return;
  }
  uVar10 = uVar11 + 0x18 & 3;
  uVar5 = *(uint *)(uVar11 + 0x18 & 0xfffffffc);
  uVar6 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
  uVar10 = uVar11 + 0x24 & 3;
  uVar4 = *(uint *)(uVar11 + 0x24 & 0xfffffffc);
  uVar5 = param_1 + 0x244U & 3;
  uVar7 = *(uint *)(param_1 + 0x244U & 0xfffffffc);
  uVar7 = uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)((uVar4 >> uVar10 * 8 | uVar4 << uVar10 * -8 + 0x20) - uVar6) *
          (longlong)(int)uVar7;
  uVar10 = uVar11 + 0x1c & 3;
  uVar5 = *(uint *)(uVar11 + 0x1c & 0xfffffffc);
  uVar4 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
  uVar10 = uVar11 + 0x28 & 3;
  uVar8 = *(uint *)(uVar11 + 0x28 & 0xfffffffc);
  uVar5 = uVar11 + 0x20 & 3;
  uVar9 = *(uint *)(uVar11 + 0x20 & 0xfffffffc);
  uVar9 = uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20;
  uVar5 = uVar11 + 0x2c & 3;
  uVar12 = *(uint *)(uVar11 + 0x2c & 0xfffffffc);
  lVar2 = (longlong)(int)((uVar8 >> uVar10 * 8 | uVar8 << uVar10 * -8 + 0x20) - uVar4) *
          (longlong)(int)uVar7;
  lVar3 = (longlong)(int)((uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) - uVar9) *
          (longlong)(int)uVar7;
  *(uint *)(param_1 + 0x18) = uVar6 + ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14)
  ;
  *(uint *)(param_1 + 0x1c) = uVar4 + ((uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14)
  ;
  *(uint *)(param_1 + 0x20) = uVar9 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14)
  ;
  uVar10 = param_1 + 0x244U & 3;
  uVar5 = *(uint *)(param_1 + 0x244U & 0xfffffffc);
  *(uint *)(param_1 + 0x244) =
       (uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) + (uint)*(ushort *)(uVar11 + 0x44);
  uVar11 = param_1 + 0x244U & 3;
  uVar10 = *(uint *)(param_1 + 0x244U & 0xfffffffc);
  if (0x1000 < (int)(uVar10 >> uVar11 * 8 | uVar10 << uVar11 * -8 + 0x20)) {
    *(undefined4 *)(param_1 + 0x244) = 0x1000;
  }
  return;
}

