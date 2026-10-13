/* Decompiled C draft; module arm9; ROM address 020d8cc8. No matching claim. */
#include "types.h"
#include "deps/020d8cc8_func_020d8cc8.h"

undefined4 func_020d8cc8(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  uVar6 = param_1 + 0x18 & 3;
  uVar2 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
    uVar6 = param_1 + 0x14 & 3;
    uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    uVar2 = param_1 + 0x10 & 3;
    uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
    *(uint *)(param_1 + 0x14) =
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) -
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar6 = param_1 + 0x14 & 3;
    uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    if ((int)uVar6 < 1) {
      uVar2 = param_1 + 0xc & 3;
      uVar5 = *(uint *)(param_1 + 0xc & 0xfffffffc);
      uVar2 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
      if (uVar2 == 0) {
        uVar2 = uVar8 + 8 & 3;
        uVar5 = *(uint *)(uVar8 + 8 & 0xfffffffc);
        if (uVar5 >> uVar2 * 8 == 0 && uVar5 << uVar2 * -8 + 0x20 == 0) {
          *(undefined4 *)(param_1 + 0x18) = 1;
          *(undefined4 *)(param_1 + 0x14) = 0;
          uVar6 = param_1 + 0x20 & 3;
          uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
          *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8));
          *(undefined4 *)(param_1 + 0x20) = uVar4;
        }
        else {
          uVar2 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x30;
          uVar5 = uVar2 & 3;
          uVar2 = *(uint *)(uVar2 & 0xfffffffc);
          lVar1 = (longlong)(int)uVar6 *
                  (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
          *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
          uVar6 = uVar8 + 4 & 3;
          uVar2 = *(uint *)(uVar8 + 4 & 0xfffffffc);
          *(uint *)(param_1 + 0xc) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - 1;
          uVar6 = param_1 + 0x20 & 3;
          uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
          *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          uVar6 = uVar8 + 4 & 3;
          uVar2 = *(uint *)(uVar8 + 4 & 0xfffffffc);
          uVar4 = GetLoadedNkmPathEntryPOIT
                            (*(undefined2 *)(param_1 + 8),
                             (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - 1 & 0xffff);
          *(undefined4 *)(param_1 + 0x20) = uVar4;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
          uVar6 = param_1 + 0xc & 3;
          uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
          uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          lVar1 = CONCAT44(uVar6,uVar8);
          uVar6 = uVar6 * 0x54 + uVar8 + 0x34;
          uVar2 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
          if (uVar6 != 0) {
            uVar2 = param_1 + 0x14 & 3;
            uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                    (longlong)(int)uVar6;
          }
          if (uVar6 != 0) {
            *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
          }
          uVar2 = param_1 + 0x14 & 3;
          uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          *(uint *)(param_1 + 0x14) = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 0x1000000;
          if (uVar6 != 0) {
            uVar2 = param_1 + 4 & 3;
            uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                    (longlong)(int)uVar6;
          }
          if (uVar6 != 0) {
            uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
          }
          else {
            uVar6 = 0x1000000;
          }
          *(uint *)(param_1 + 0x10) = uVar6;
        }
      }
      else {
        uVar2 = uVar2 * 0x54 +
                (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x30;
        uVar5 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        lVar1 = (longlong)(int)uVar6 *
                (longlong)(int)(uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20);
        *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        uVar6 = param_1 + 0xc & 3;
        uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        *(uint *)(param_1 + 0xc) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - 1;
        uVar6 = param_1 + 0x20 & 3;
        uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
        *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
        uVar6 = param_1 + 0xc & 3;
        uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        uVar4 = GetLoadedNkmPathEntryPOIT
                          (*(undefined2 *)(param_1 + 8),
                           (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0xffff);
        *(undefined4 *)(param_1 + 0x20) = uVar4;
        uVar8 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
        uVar6 = param_1 + 0xc & 3;
        uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
        lVar1 = CONCAT44(uVar6,uVar8);
        uVar6 = uVar6 * 0x54 + uVar8 + 0x34;
        uVar2 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
        if (uVar6 != 0) {
          uVar2 = param_1 + 0x14 & 3;
          uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                  (longlong)(int)uVar6;
        }
        if (uVar6 != 0) {
          *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
        }
        uVar2 = param_1 + 0x14 & 3;
        uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
        *(uint *)(param_1 + 0x14) = (uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) + 0x1000000;
        if (uVar6 != 0) {
          uVar2 = param_1 + 4 & 3;
          uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                  (longlong)(int)uVar6;
        }
        if (uVar6 != 0) {
          uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        }
        else {
          uVar6 = 0x1000000;
        }
        *(uint *)(param_1 + 0x10) = uVar6;
      }
      return 1;
    }
  }
  else {
    uVar6 = param_1 + 0x14 & 3;
    uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    uVar2 = param_1 + 0x10 & 3;
    uVar5 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
    piVar3 = (int *)(param_1 + 0x14);
    *(uint *)(param_1 + 0x14) =
         (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) +
         (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    uVar6 = param_1 + 0x14 & 3;
    uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    if (0xffffff < (int)(uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20)) {
      uVar6 = uVar8 + 4 & 3;
      uVar5 = *(uint *)(uVar8 + 4 & 0xfffffffc);
      uVar2 = param_1 + 0xc & 3;
      uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
      if ((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) ==
          (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1) {
        uVar6 = uVar8 + 8 & 3;
        uVar2 = *(uint *)(uVar8 + 8 & 0xfffffffc);
        if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
          *(undefined4 *)(param_1 + 0x18) = 0;
          *(undefined4 *)(param_1 + 0x14) = 0x1000000;
          uVar6 = param_1 + 0x20 & 3;
          uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
          *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          uVar6 = param_1 + 0xc & 3;
          uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
          uVar4 = GetLoadedNkmPathEntryPOIT
                            (*(undefined2 *)(param_1 + 8),
                             (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) & 0xffff);
          *(undefined4 *)(param_1 + 0x20) = uVar4;
        }
        else {
          *piVar3 = (*(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
                    *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20) -
                    0x1000000;
          uVar6 = param_1 + 0xc & 3;
          uVar5 = *(uint *)(param_1 + 0xc & 0xfffffffc);
          uVar2 = param_1 + 0x14 & 3;
          uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 0x54 +
                  (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x30;
          uVar5 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) *
                  (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
          *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
          *(undefined4 *)(param_1 + 0xc) = 0;
          uVar6 = param_1 + 0x20 & 3;
          uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
          *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8),1);
          *(undefined4 *)(param_1 + 0x20) = uVar4;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                  *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
          uVar6 = param_1 + 0xc & 3;
          uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
          uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
          lVar1 = CONCAT44(uVar6,uVar8);
          uVar6 = uVar6 * 0x54 + uVar8 + 0x34;
          uVar2 = uVar6 & 3;
          uVar6 = *(uint *)(uVar6 & 0xfffffffc);
          uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
          if (uVar6 != 0) {
            uVar2 = param_1 + 0x14 & 3;
            uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                    (longlong)(int)uVar6;
          }
          if (uVar6 != 0) {
            *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
          }
          if (uVar6 != 0) {
            uVar2 = param_1 + 4 & 3;
            uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
            lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                    (longlong)(int)uVar6;
          }
          if (uVar6 != 0) {
            uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
          }
          else {
            uVar6 = 0x1000000;
          }
          *(uint *)(param_1 + 0x10) = uVar6;
        }
      }
      else {
        *piVar3 = (*(uint *)((uint)piVar3 & 0xfffffffc) >> ((uint)piVar3 & 3) * 8 |
                  *(uint *)((uint)piVar3 & 0xfffffffc) << ((uint)piVar3 & 3) * -8 + 0x20) -
                  0x1000000;
        uVar6 = param_1 + 0xc & 3;
        uVar5 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        uVar2 = param_1 + 0x14 & 3;
        uVar7 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
        uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) * 0x54 +
                (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + 0x30;
        uVar5 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) *
                (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
        *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        uVar6 = param_1 + 0xc & 3;
        uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        *(uint *)(param_1 + 0xc) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 1;
        uVar6 = param_1 + 0x20 & 3;
        uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
        *(uint *)(param_1 + 0x1c) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
        uVar6 = uVar8 + 4 & 3;
        uVar5 = *(uint *)(uVar8 + 4 & 0xfffffffc);
        uVar2 = param_1 + 0xc & 3;
        uVar7 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        uVar2 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
        if ((uVar2 == (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) - 1) &&
           (uVar6 = uVar8 + 8 & 3, uVar5 = *(uint *)(uVar8 + 8 & 0xfffffffc),
           uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
          uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8),0);
          *(undefined4 *)(param_1 + 0x20) = uVar4;
        }
        else {
          uVar4 = GetLoadedNkmPathEntryPOIT(*(undefined2 *)(param_1 + 8),uVar2 + 1 & 0xffff);
          *(undefined4 *)(param_1 + 0x20) = uVar4;
        }
        uVar8 = *(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
                *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20;
        uVar6 = param_1 + 0xc & 3;
        uVar2 = *(uint *)(param_1 + 0xc & 0xfffffffc);
        uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
        lVar1 = CONCAT44(uVar6,uVar8);
        uVar6 = uVar6 * 0x54 + uVar8 + 0x34;
        uVar2 = uVar6 & 3;
        uVar6 = *(uint *)(uVar6 & 0xfffffffc);
        uVar6 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
        if (uVar6 != 0) {
          uVar2 = param_1 + 0x14 & 3;
          uVar8 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                  (longlong)(int)uVar6;
        }
        if (uVar6 != 0) {
          *(uint *)(param_1 + 0x14) = (uint)lVar1 >> 0x18 | (int)((ulonglong)lVar1 >> 0x20) << 8;
        }
        if (uVar6 != 0) {
          uVar2 = param_1 + 4 & 3;
          uVar8 = *(uint *)(param_1 + 4 & 0xfffffffc);
          lVar1 = (longlong)(int)(uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) *
                  (longlong)(int)uVar6;
        }
        if (uVar6 != 0) {
          uVar6 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
        }
        else {
          uVar6 = 0x1000000;
        }
        *(uint *)(param_1 + 0x10) = uVar6;
      }
      return 1;
    }
  }
  return 0;
}

