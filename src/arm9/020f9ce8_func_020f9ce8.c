/* Decompiled C draft; module arm9; ROM address 020f9ce8. No matching claim. */
#include "types.h"
#include "deps/020f9ce8_func_020f9ce8.h"

undefined4 func_020f9ce8(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar8 = param_1 + 0x100U & 3;
  uVar2 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
  if (uVar2 >> uVar8 * 8 != 0 || uVar2 << uVar8 * -8 + 0x20 != 0) {
    uVar8 = param_1 + 0x74U & 3;
    uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    uVar2 = param_1 + 0x44U & 3;
    uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20 | 0x40;
    uVar8 = param_1 + 0x6cU & 3;
    uVar4 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    uVar7 = uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20;
    uVar8 = param_1 + 0x100U & 3;
    uVar4 = *(uint *)(param_1 + 0x100U & 0xfffffffc);
    uVar8 = (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) - uVar7;
    lVar1 = (ulonglong)uRam020f9dc0 * (ulonglong)uVar8;
    *(uint *)(param_1 + 0x6c) =
         uVar7 + ((uint)lVar1 >> 0xc |
                 (((int)uVar8 >> 0x1f) * uRam020f9dc0 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000)
    ;
    uVar8 = param_1 + 0x70U & 3;
    uVar6 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uVar4 = param_1 + 0x6cU & 3;
    uVar7 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    *(uint *)(param_1 + 0x68) =
         (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) * 2 -
         (uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20);
    uVar4 = param_1 + 0x6cU & 3;
    uVar6 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    iVar5 = (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) * 0xa8 +
            (*(uint *)(uRam020f9dc4 & 0xfffffffc) >> (uRam020f9dc4 & 3) * 8 |
            *(uint *)(uRam020f9dc4 & 0xfffffffc) << (uRam020f9dc4 & 3) * -8 + 0x20);
    uVar8 = iVar5 + 100;
    uVar2 = uVar8 & 3;
    uVar7 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = iVar5 + 0x6c;
    uVar3 = uVar8 & 3;
    uVar9 = *(uint *)(uVar8 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20) *
            (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
    *(uint *)(param_1 + 0xdc) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar8 = param_1 + 0x6cU & 3;
    uVar2 = *(uint *)(param_1 + 0x6cU & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) *
            (longlong)(int)(uVar9 >> uVar3 * 8 | uVar9 << uVar3 * -8 + 0x20);
    *(uint *)(param_1 + 0xe0) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar8 = param_1 + 0xe0U & 3;
    uVar2 = *(uint *)(param_1 + 0xe0U & 0xfffffffc);
    func_020d5148((int)*(short *)(param_1 + 0xda),
                  (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + 0xa000);
    return 1;
  }
  return 0;
}

