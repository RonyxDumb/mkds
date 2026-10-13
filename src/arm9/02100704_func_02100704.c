/* Decompiled C draft; module arm9; ROM address 02100704. No matching claim. */
#include "types.h"
#include "deps/02100704_func_02100704.h"

void func_02100704(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  
  if ((*(ushort *)(param_1 + 0x78) & 0x8000) == 0) {
    uVar1 = *(ushort *)(param_1 + 0x78) & 0xffff00ff;
  }
  else {
    uVar1 = 8;
  }
  uVar2 = param_1 + 0x24cU & 3;
  uVar4 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  iVar6 = uVar1 * 0x210 +
          (*(uint *)(uRam021009f4 & 0xfffffffc) >> (uRam021009f4 & 3) * 8 |
          *(uint *)(uRam021009f4 & 0xfffffffc) << (uRam021009f4 & 3) * -8 + 0x20);
  if (((uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) ||
      (uVar1 = iVar6 + 0x14U & 3, uVar2 = *(uint *)(iVar6 + 0x14U & 0xfffffffc),
      (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0x10)) ||
     (uVar1 = param_1 + 0x158U & 3, uVar2 = *(uint *)(param_1 + 0x158U & 0xfffffffc),
     (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0xffffffc0)) {
    uVar1 = param_1 + 0x15cU & 3;
    uVar2 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
    iVar3 = func_021014a0(param_1,uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0,6);
    if (0x28U - iVar3 < 7) {
      if (0 < *(short *)(param_1 + 0x164)) {
        *(short *)(param_1 + 0x164) = *(short *)(param_1 + 0x164) + -5;
      }
      if (0x28U - iVar3 == 1) {
        uVar1 = param_1 + 0x24cU & 3;
        uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
        if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
          uVar1 = param_1 + 0x260U & 3;
          uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
          if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 0xffffffff) {
            uVar1 = param_1 + 0x130U & 3;
            uVar2 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
            *(uint *)(param_1 + 0x130) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1;
            *(undefined4 *)(param_1 + 0x26c) = 1;
            uVar1 = param_1 + 0x270U & 3;
            uVar2 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
            *(uint *)(param_1 + 0x270) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
            uVar1 = param_1 + 0x270U & 3;
            uVar2 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
            if (0x3c < (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)) {
              *(undefined4 *)(param_1 + 0x25c) = 0x13;
              *(undefined4 *)(param_1 + 0x260) = 0xffffffc0;
              *(undefined4 *)(param_1 + 0x160) = 0xe;
            }
            goto LAB_02100920;
          }
          uVar1 = param_1 + 0x25cU & 3;
          uVar2 = *(uint *)(param_1 + 0x25cU & 0xfffffffc);
          *(uint *)(param_1 + 0x154) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
          uVar1 = param_1 + 0x260U & 3;
          uVar2 = *(uint *)(param_1 + 0x260U & 0xfffffffc);
          *(uint *)(param_1 + 0x158) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
          *(undefined4 *)(param_1 + 0x25c) = 0x12;
          *(undefined4 *)(param_1 + 0x260) = 0xffffffff;
        }
        *(undefined4 *)(iVar6 + 0x14) = 0x13;
        uVar1 = param_1 + 0x154U & 3;
        uVar2 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
        uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
        if (uVar1 == 0x13) {
          *(undefined4 *)(param_1 + 0x158) = 0xffffffc0;
          *(undefined4 *)(param_1 + 0x160) = 0xe;
        }
        else {
          uVar2 = param_1 + 0x24cU & 3;
          uVar4 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
          if (uVar4 >> uVar2 * 8 == 0 && uVar4 << uVar2 * -8 + 0x20 == 0) {
            uVar2 = param_1 + 0x158U & 3;
            uVar4 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
            func_0205a548(*(undefined1 *)
                           ((*(uint *)(uRam021009f8 & 0xfffffffc) >> (uRam021009f8 & 3) * 8 |
                            *(uint *)(uRam021009f8 & 0xfffffffc) << (uRam021009f8 & 3) * -8 + 0x20)
                           + (*(ushort *)(iVar6 + 0x1f8) & 0xff)),uVar1,
                          uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          }
          else {
            uVar2 = param_1 + 0x158U & 3;
            uVar4 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
            func_020f40dc((int *)(uintptr_t)(iVar6 + 0x30),uVar1,uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
          }
          *(undefined4 *)(param_1 + 0x154) = 0x13;
          *(undefined4 *)(param_1 + 0x158) = 0xffffffc0;
          *(undefined4 *)(param_1 + 0x160) = 0xe;
          uVar1 = iVar6 + 0x1fcU & 3;
          uVar2 = *(uint *)(iVar6 + 0x1fcU & 0xfffffffc);
          func_020f8e3c(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0xf8);
        }
        uVar1 = param_1 + 0x74U & 3;
        uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        if ((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) != 0) &&
           (uVar1 = param_1 + 0x24cU & 3, uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc),
           uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0)) {
          uVar1 = iVar6 + 0x30U & 3;
          uVar5 = *(uint *)(iVar6 + 0x30U & 0xfffffffc);
          uVar2 = iVar6 + 0x38U & 3;
          uVar4 = *(uint *)(iVar6 + 0x38U & 0xfffffffc);
          func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),3,
                        (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20 |
                        (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20) << 2) & 0xff);
        }
      }
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x144) = 1;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) != 0) {
      func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),1,5);
    }
  }
LAB_02100920:
  uVar1 = param_1 + 0x15cU & 3;
  uVar2 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) &&
     (uVar1 = param_1 + 0x144U & 3, uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc),
     uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0)) {
    uVar1 = param_1 + 0x16cU & 3;
    uVar8 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
    uVar2 = param_1 + 0x174U & 3;
    uVar7 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    func_021014a0(param_1,1,6);
    uVar4 = param_1 + 0x16cU & 3;
    uVar5 = *(uint *)(param_1 + 0x16cU & 0xfffffffc);
    *(uint *)(param_1 + 0x178) =
         (uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) -
         (uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
    uVar1 = param_1 + 0x174U & 3;
    uVar4 = *(uint *)(param_1 + 0x174U & 0xfffffffc);
    *(uint *)(param_1 + 0x180) =
         (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) -
         (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20);
    *(undefined2 *)(param_1 + 0x13c) = 6;
    *(undefined2 *)(param_1 + 0x13e) = 1;
    *(undefined4 *)(param_1 + 0x26c) = 0;
  }
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  uVar1 = param_1 + 0x24cU & 3;
  uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  uVar1 = param_1 + 0x144U & 3;
  uVar2 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    return;
  }
  uVar1 = param_1 + 0x264U & 3;
  uVar2 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
  uVar1 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  if (uVar1 == 0xffffffff) {
    return;
  }
  if ((uVar1 != 5) && (uVar1 != 7)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x144) = 1;
  *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
  return;
}

