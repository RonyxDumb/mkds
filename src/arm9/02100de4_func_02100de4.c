/* Decompiled C draft; module arm9; ROM address 02100de4. No matching claim. */
#include "types.h"
#include "deps/02100de4_func_02100de4.h"

void func_02100de4(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined2 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  uVar7 = param_1 + 0x140U & 3;
  uVar6 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 8) {
    uVar7 = param_1 + 0x130U & 3;
    uVar6 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
    if (0x6e < (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) {
      *(undefined4 *)(param_1 + 0x160) = 0xf;
      uVar7 = param_1 + 0x74U & 3;
      uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) == 0) {
        uVar5 = 5;
      }
      else {
        uVar5 = 4;
      }
      *(undefined2 *)(param_1 + 0x13c) = uVar5;
      *(undefined2 *)(param_1 + 0x13e) = 1;
    }
  }
  else {
    iVar2 = func_021014a0(param_1,1,3);
    uVar7 = param_1 + 0x160U & 3;
    uVar6 = *(uint *)(param_1 + 0x160U & 0xfffffffc);
    uVar9 = 0x28 - iVar2;
    if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 0xe) {
      uVar7 = param_1 + 0x24cU & 3;
      uVar6 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
      if (uVar6 >> uVar7 * 8 == 0 && uVar6 << uVar7 * -8 + 0x20 == 0) {
        if (uVar9 < 0xb) {
          uVar7 = param_1 + 600U & 3;
          uVar6 = *(uint *)(param_1 + 600U & 0xfffffffc);
          if ((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) == 0xffffffff) {
            bVar1 = false;
          }
          else {
            uVar7 = param_1 + 0x254U & 3;
            uVar6 = *(uint *)(param_1 + 0x254U & 0xfffffffc);
            *(uint *)(param_1 + 0x154) = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
            uVar7 = param_1 + 600U & 3;
            uVar6 = *(uint *)(param_1 + 600U & 0xfffffffc);
            *(uint *)(param_1 + 0x158) = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
            *(undefined4 *)(param_1 + 0x254) = 0x12;
            *(undefined4 *)(param_1 + 600) = 0xffffffff;
            uVar6 = uRam02101010;
            uVar7 = param_1 + 0x154U & 3;
            uVar8 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
            uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
            if (uVar7 == 0x13) {
              *(undefined4 *)(param_1 + 0x160) = 0xf;
            }
            else {
              uVar7 = uVar7 * 0x1c +
                      (*(uint *)(uRam0210100c & 0xfffffffc) >> (uRam0210100c & 3) * 8 |
                      *(uint *)(uRam0210100c & 0xfffffffc) << (uRam0210100c & 3) * -8 + 0x20) + 8;
              uVar8 = uVar7 & 3;
              uVar7 = *(uint *)(uVar7 & 0xfffffffc);
              *(uint *)(param_1 + 0x160) = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
              uVar7 = param_1 + 0x140U & 3;
              uVar4 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
              uVar8 = uVar6 & 3;
              uVar6 = *(uint *)(uVar6 & 0xfffffffc);
              func_0205a5b0(*(undefined1 *)
                             ((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) +
                             ((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) & 0xff)));
            }
            *(undefined2 *)(param_1 + 0x164) = 0;
            bVar1 = true;
          }
          if ((!bVar1) && (uVar9 == 1)) {
            uVar7 = param_1 + 0x130U & 3;
            uVar6 = *(uint *)(param_1 + 0x130U & 0xfffffffc);
            *(uint *)(param_1 + 0x130) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) - 1;
            *(undefined4 *)(param_1 + 0x26c) = 1;
            uVar7 = param_1 + 0x270U & 3;
            uVar6 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
            *(uint *)(param_1 + 0x270) = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 1;
            uVar7 = param_1 + 0x270U & 3;
            uVar6 = *(uint *)(param_1 + 0x270U & 0xfffffffc);
            if (0x3c < (int)(uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20)) {
              *(undefined4 *)(param_1 + 0x254) = 0x13;
              *(undefined4 *)(param_1 + 600) = 0;
            }
          }
        }
      }
      else if (uVar9 == 10) {
        uVar3 = func_02101014(param_1);
        *(undefined4 *)(param_1 + 0x160) = uVar3;
        *(undefined2 *)(param_1 + 0x164) = 0;
        uVar7 = param_1 + 0x74U & 3;
        uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
        if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) != 0) {
          uVar7 = param_1 + 0x154U & 3;
          uVar8 = *(uint *)(param_1 + 0x154U & 0xfffffffc);
          uVar6 = param_1 + 0x158U & 3;
          uVar9 = *(uint *)(param_1 + 0x158U & 0xfffffffc);
          func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),2,
                        (uVar9 >> uVar6 * 8 | uVar9 << uVar6 * -8 + 0x20 |
                        (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) << 2) & 0xff);
        }
      }
    }
  }
  uVar7 = param_1 + 0x74U & 3;
  uVar6 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) & 0x8000000) == 0) {
    return;
  }
  uVar7 = param_1 + 0x24cU & 3;
  uVar6 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    return;
  }
  uVar7 = param_1 + 0x144U & 3;
  uVar6 = *(uint *)(param_1 + 0x144U & 0xfffffffc);
  if (uVar6 >> uVar7 * 8 != 0 || uVar6 << uVar7 * -8 + 0x20 != 0) {
    return;
  }
  uVar7 = param_1 + 0x264U & 3;
  uVar6 = *(uint *)(param_1 + 0x264U & 0xfffffffc);
  uVar7 = uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20;
  if (uVar7 == 0xffffffff) {
    return;
  }
  if ((uVar7 != 2) && (uVar7 != 7)) {
    return;
  }
  *(undefined4 *)(param_1 + 0x144) = 1;
  *(undefined4 *)(param_1 + 0x264) = 0xffffffff;
  return;
}

