/* Decompiled C draft; module arm9; ROM address 02100564. No matching claim. */
#include "types.h"
#include "deps/02100564_func_02100564.h"

void func_02100564(int param_1)

{
  longlong lVar1;
  ushort uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int unaff_r4;
  bool bVar8;
  
  uVar4 = uRam021006f8;
  uVar7 = param_1 + 0x154U & 3;
  uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
  bVar8 = (uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20) != 0x13;
  if (bVar8) {
    unaff_r4 = 1;
  }
  uVar7 = param_1 + 0x15cU & 3;
  uVar3 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  if (!bVar8) {
    unaff_r4 = 0;
  }
  if (uVar3 >> uVar7 * 8 == 0 && uVar3 << uVar7 * -8 + 0x20 == 0) {
    uVar7 = param_1 + 0x178U & 3;
    uVar3 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    lVar1 = (ulonglong)uRam021006f8 * (ulonglong)uVar7;
    *(uint *)(param_1 + 0x178) =
         (uint)lVar1 >> 0xc |
         (((int)uVar7 >> 0x1f) * uRam021006f8 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar7 = param_1 + 0x180U & 3;
    uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
    uVar7 = uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20;
    lVar1 = (ulonglong)uVar4 * (ulonglong)uVar7;
    *(uint *)(param_1 + 0x180) =
         (uint)lVar1 >> 0xc |
         (((int)uVar7 >> 0x1f) * uVar4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
    uVar7 = param_1 + 0x16cU & 3;
    uVar6 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
    uVar4 = param_1 + 0x178U & 3;
    uVar3 = *(uint *)(param_1 + 0x178U & 0xfffffffc);
    *(uint *)(param_1 + 0x16c) =
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    uVar7 = param_1 + 0x174U & 3;
    uVar6 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    uVar4 = param_1 + 0x180U & 3;
    uVar3 = *(uint *)(param_1 + 0x180U & 0xfffffffc);
    *(uint *)(param_1 + 0x174) =
         (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
         (uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
  }
  if ((unaff_r4 != 0) && (*(short *)(param_1 + 0x164) < 0x1f)) {
    *(short *)(param_1 + 0x164) = *(short *)(param_1 + 0x164) + 8;
  }
  uVar7 = param_1 + 0x15cU & 3;
  uVar4 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  iVar5 = func_02101618(param_1,uVar4 >> uVar7 * 8 == 0 && uVar4 << uVar7 * -8 + 0x20 == 0,7);
  if (iVar5 != 0) {
    if (unaff_r4 != 0) {
      if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
        uVar2 = *(ushort *)(param_1 + 0x78) & 0xff;
      }
      else {
        uVar2 = 8;
      }
      uVar7 = param_1 + 0x154U & 3;
      uVar3 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
      uVar4 = param_1 + 0x158U & 3;
      uVar6 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
      func_020f40a0(uVar3 >> uVar7 * 8 | uVar3 << uVar7 * -8 + 0x20,
                    uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20,uVar2);
    }
    uVar7 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam021006fc & 0xfffffffc) >> (uRam021006fc & 3) * 8 |
                  *(uint *)(uRam021006fc & 0xfffffffc) << (uRam021006fc & 3) * -8 + 0x20),param_1);
  }
  uVar7 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  uVar7 = param_1 + 0x24cU & 3;
  uVar4 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar4 >> uVar7 * 8 != 0 || uVar4 << uVar7 * -8 + 0x20 != 0) {
    return;
  }
  uVar7 = param_1 + 0x144U & 3;
  uVar4 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar4 >> uVar7 * 8 == 0 && uVar4 << uVar7 * -8 + 0x20 == 0) {
    uVar7 = param_1 + 0x264U & 3;
    uVar4 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
    uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
    if (uVar7 != 0xffffffff) {
      if (uVar7 - 5 < 2) {
        *(undefined4 *)(param_1 + 0x144) = 1;
        *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
      }
      return;
    }
    return;
  }
  return;
}

