/* Decompiled C draft; module arm9; ROM address 020f9dc8. No matching claim. */
#include "types.h"
#include "deps/020f9dc8_func_020f9dc8.h"

undefined4 func_020f9dc8(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar4;
  
  uVar4 = param_1 + 0x100U & 3;
  uVar3 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  if ((((-0x29 < (int)uVar4) && ((int)uVar4 < 0x29)) &&
      (uVar4 = param_1 + 0x68U & 3, uVar7 = *(uint *)(param_1 + 0x68U & 0xfffffffc),
      uVar3 = param_1 + 0x6cU & 3, uVar5 = *(uint *)(param_1 + 0x6cU & 0xfffffffc),
      iVar6 = (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) -
              (uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20), -0x29 < iVar6)) && (iVar6 < 0x29))
  {
    *(undefined4 *)(param_1 + 0x100) = 0;
    return 0;
  }
  uVar4 = param_1 + 0x74U & 3;
  uVar5 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  uVar3 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  *(uint *)(param_1 + 0x74) = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20 | 0x40;
  uVar7 = uRam020f9f00;
  uVar4 = param_1 + 0x6cU & 3;
  uVar9 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  uVar5 = param_1 + 0x100U & 3;
  uVar8 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  *(uint *)(param_1 + 0x6c) =
       (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) +
       (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
  uVar4 = param_1 + 0x70U & 3;
  uVar9 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar5 = param_1 + 0x6cU & 3;
  uVar8 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  uVar5 = (uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20) -
          (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20);
  lVar1 = (ulonglong)uVar7 * (ulonglong)uVar5;
  uVar4 = param_1 + 0x100U & 3;
  uVar8 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  *(uint *)(param_1 + 0x100) =
       (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc |
       (((int)uVar5 >> 0x1f) * uVar7 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar4 = param_1 + 0x100U & 3;
  uVar5 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar4 * 0xc00;
  *(uint *)(param_1 + 0x100) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * 0xc00 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0x70U & 3;
  uVar8 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
  uVar5 = param_1 + 0x6cU & 3;
  uVar7 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  *(uint *)(param_1 + 0x68) =
       (uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20) * 2 -
       (uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  uVar5 = param_1 + 0x6cU & 3;
  uVar8 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  iVar6 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0xa8 +
          (*(uint *)(uRam020f9f04 & 0xfffffffc) >> (uRam020f9f04 & 3) * 8 |
          *(uint *)(uRam020f9f04 & 0xfffffffc) << (uRam020f9f04 & 3) * -8 + 0x20);
  uVar4 = iVar6 + 100;
  uVar3 = uVar4 & 3;
  uVar2 = *(uint *)(uVar4 & 0xfffffffc);
  uVar4 = iVar6 + 0x6c;
  uVar7 = uVar4 & 3;
  uVar9 = *(uint *)(uVar4 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) *
          (longlong)(int)(uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20);
  *(uint *)(param_1 + 0xdc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar4 = param_1 + 0x6cU & 3;
  uVar3 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) *
          (longlong)(int)(uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20);
  *(uint *)(param_1 + 0xe0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar4 = param_1 + 0xe0U & 3;
  uVar3 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
  func_020d5148((int)*(short *)(param_1 + 0xda),
                (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + 0xa000);
  return 1;
}

