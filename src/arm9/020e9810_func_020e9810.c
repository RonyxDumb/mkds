/* Decompiled C draft; module arm9; ROM address 020e9810. No matching claim. */
#include "types.h"
#include "deps/020e9810_func_020e9810.h"

void func_020e9810(void)

{
  int iVar1;
  ushort uVar2;
  bool bVar3;
  bool bVar4;
  ushort *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  undefined4 uStack_a8;
  undefined4 uStack_a4;
  undefined4 uStack_a0;
  undefined4 uStack_9c;
  undefined4 uStack_98;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined1 auStack_88 [36];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  int iStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  int iStack_40;
  int iStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uVar7 = (*(uint *)(DAT_020e9cb4 & 0xfffffffc) >> (DAT_020e9cb4 & 3) * 8 |
          *(uint *)(DAT_020e9cb4 & 0xfffffffc) << (DAT_020e9cb4 & 3) * -8 + 0x20) + 0xc;
  uVar10 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  if ((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) == 6) {
    return;
  }
  if (*(uint *)(DAT_020e9cb8 & 0xfffffffc) >> (DAT_020e9cb8 & 3) * 8 == 0 &&
      *(uint *)(DAT_020e9cb8 & 0xfffffffc) << (DAT_020e9cb8 & 3) * -8 + 0x20 == 0) {
    return;
  }
  if (*(uint *)(DAT_020e9cbc & 0xfffffffc) >> (DAT_020e9cbc & 3) * 8 == 0 &&
      *(uint *)(DAT_020e9cbc & 0xfffffffc) << (DAT_020e9cbc & 3) * -8 + 0x20 == 0) {
    *DAT_020e9cd0 = 0;
    return;
  }
  uVar7 = *(uint *)(DAT_020e9cc0 & 0xfffffffc) >> (DAT_020e9cc0 & 3) * 8 |
          *(uint *)(DAT_020e9cc0 & 0xfffffffc) << (DAT_020e9cc0 & 3) * -8 + 0x20;
  uVar11 = 0;
  uVar10 = 0;
  switch(uVar7) {
  case 0:
    break;
  case 1:
    break;
  case 2:
    goto LAB_020e988c;
  case 3:
LAB_020e988c:
    uVar7 = DAT_020e9cc4 + uVar7 * 0x10;
    uVar11 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    uVar11 = uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20;
  default:
    goto switchD_020e9874_default;
  }
  uVar7 = DAT_020e9cc8 + uVar7 * 0x10;
  uVar10 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar10 = uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20;
switchD_020e9874_default:
  LightInfo_MaybeApply
            ((ushort *)(uintptr_t)(*(uint *)(DAT_020e9ccc & 0xfffffffc) >> (DAT_020e9ccc & 3) * 8 |
             *(uint *)(DAT_020e9ccc & 0xfffffffc) << (DAT_020e9ccc & 3) * -8 + 0x20));
  iVar1 = DAT_020e9cd4;
  puVar5 = DAT_020e9cd0;
  uVar7 = DAT_020e9cd4 + 0x14U & 3;
  uVar12 = *(uint *)(DAT_020e9cd4 + 0x14U & 0xfffffffc);
  *DAT_020e9cd0 = *DAT_020e9cd0 + 1;
  uVar2 = *puVar5;
  uVar7 = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) & 0xffe0ffff;
  *(uint *)(iVar1 + 0x14) = uVar7;
  if (0x1f < uVar2) {
    *puVar5 = 0x1f;
  }
  iVar6 = DAT_020e9cd8;
  uVar2 = *DAT_020e9cd0;
  uVar12 = DAT_020e9cd8 + 0x14U & 3;
  uVar9 = *(uint *)(DAT_020e9cd8 + 0x14U & 0xfffffffc);
  uVar12 = (uVar9 >> uVar12 * 8 | uVar9 << uVar12 * -8 + 0x20) & 0xffe0ffff;
  *(uint *)(DAT_020e9cd8 + 0x14) = uVar12;
  *(uint *)(iVar1 + 0x14) = uVar7 | (uint)uVar2 << 0x10;
  *(uint *)(iVar6 + 0x14) = uVar12 | (uint)uVar2 << 0x10;
  if (uVar11 != 0) {
    uVar7 = uVar11 + 4 & 3;
    uVar12 = *(uint *)(uVar11 + 4 & 0xfffffffc);
    Maybe_helper_01308c(uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20);
  }
  puVar5 = DAT_020e9cd0;
  if (uVar10 != 0) {
    uVar7 = uVar10 + 0x14 & 3;
    uVar12 = *(uint *)(uVar10 + 0x14 & 0xfffffffc);
    *(uint *)(uVar10 + 0x14) = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) & 0xffe0ffff;
    uVar7 = uVar10 + 0x14 & 3;
    uVar12 = *(uint *)(uVar10 + 0x14 & 0xfffffffc);
    *(uint *)(uVar10 + 0x14) =
         uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20 | (uint)*puVar5 << 0x10;
  }
  bVar3 = *(uint *)(DAT_020e9cdc & 0xfffffffc) >> (DAT_020e9cdc & 3) * 8 != 0;
  bVar4 = *(uint *)(DAT_020e9cdc & 0xfffffffc) << (DAT_020e9cdc & 3) * -8 + 0x20 != 0;
  if (bVar3 || bVar4) {
    uStack_a8 = 0;
    func_01ff9048(0x10,(undefined4)(uintptr_t)(&uStack_a8),1);
    func_01ff9048(0x11,0,0);
    uStack_64 = DAT_020e9ce0;
    uStack_60 = DAT_020e9ce0;
    uStack_5c = DAT_020e9ce0;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_64),3);
    uStack_a4 = 2;
    func_01ff9048(0x10,(undefined4)(uintptr_t)(&uStack_a4),1);
  }
  uStack_a0 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&uStack_a0),1);
  uVar8 = func_020e6cf8(DAT_020e9ce4);
  func_01ff9048(0x19,uVar8,0xc);
  iStack_54 = (int)*(short *)((*(uint *)(DAT_020e9cec & 0xfffffffc) >> (DAT_020e9cec & 3) * 8 |
                              *(uint *)(DAT_020e9cec & 0xfffffffc) << (DAT_020e9cec & 3) * -8 + 0x20
                              ) + (*(uint *)(DAT_020e9ce8 & 0xfffffffc) >> (DAT_020e9ce8 & 3) * 8 |
                                  *(uint *)(DAT_020e9ce8 & 0xfffffffc) <<
                                  (DAT_020e9ce8 & 3) * -8 + 0x20) * 2);
  uStack_58 = 0;
  uStack_50 = 0;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&uStack_58),3);
  uStack_4c = DAT_020e9cf0;
  if (*(uint *)(DAT_020e9cf4 & 0xfffffffc) >> (DAT_020e9cf4 & 3) * 8 == 0 &&
      *(uint *)(DAT_020e9cf4 & 0xfffffffc) << (DAT_020e9cf4 & 3) * -8 + 0x20 == 0) {
    uStack_4c = DAT_020e9cf8;
  }
  uStack_48 = DAT_020e9cf0;
  uStack_44 = DAT_020e9cf0;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_4c),3);
  func_01ff9048(0x11,0,0);
  iVar1 = (*(uint *)(DAT_020e9ce8 & 0xfffffffc) >> (DAT_020e9ce8 & 3) * 8 |
          *(uint *)(DAT_020e9ce8 & 0xfffffffc) << (DAT_020e9ce8 & 3) * -8 + 0x20) * 2;
  iStack_3c = (int)*(short *)((*(uint *)(DAT_020e9d00 & 0xfffffffc) >> (DAT_020e9d00 & 3) * 8 |
                              *(uint *)(DAT_020e9d00 & 0xfffffffc) << (DAT_020e9d00 & 3) * -8 + 0x20
                              ) + iVar1);
  iStack_40 = (int)*(short *)((*(uint *)(DAT_020e9cfc & 0xfffffffc) >> (DAT_020e9cfc & 3) * 8 |
                              *(uint *)(DAT_020e9cfc & 0xfffffffc) << (DAT_020e9cfc & 3) * -8 + 0x20
                              ) + iVar1);
  uStack_38 = 0;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&iStack_40),3);
  func_020e6a18(DAT_020e9cd8);
  func_020e6854(DAT_020e9cd8,0,0,0x1f);
  uStack_9c = 1;
  func_01ff9048(0x12,&uStack_9c);
  uStack_34 = 0;
  uStack_30 = 0;
  uStack_2c = 0xa4;
  func_01ff9048(0x1c,(undefined4)(uintptr_t)(&uStack_34),3);
  iVar1 = (*(uint *)(DAT_020e9ce8 & 0xfffffffc) >> (DAT_020e9ce8 & 3) * 8 |
          *(uint *)(DAT_020e9ce8 & 0xfffffffc) << (DAT_020e9ce8 & 3) * -8 + 0x20) * 2;
  MTX_RotZ33__from_thumb
            ((undefined4 *)(void *)(auStack_88),
             (int)*(short *)((*(uint *)(DAT_020e9d04 & 0xfffffffc) >> (DAT_020e9d04 & 3) * 8 |
                             *(uint *)(DAT_020e9d04 & 0xfffffffc) << (DAT_020e9d04 & 3) * -8 + 0x20)
                            + iVar1),
             (int)*(short *)((*(uint *)(DAT_020e9d08 & 0xfffffffc) >> (DAT_020e9d08 & 3) * 8 |
                             *(uint *)(DAT_020e9d08 & 0xfffffffc) << (DAT_020e9d08 & 3) * -8 + 0x20)
                            + iVar1));
  func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_88),9);
  func_020e6a18(DAT_020e9cd4);
  func_020e6854(DAT_020e9cd4,0,0,0x1f);
  if (uVar11 != 0) {
    if ((*(uint *)(DAT_020e9cc0 & 0xfffffffc) >> (DAT_020e9cc0 & 3) * 8 |
        *(uint *)(DAT_020e9cc0 & 0xfffffffc) << (DAT_020e9cc0 & 3) * -8 + 0x20) == 3) {
      uStack_98 = 0;
      func_01ff9048(0x12,(undefined4)(uintptr_t)(&uStack_98),1);
      func_01ff8cf0((uint *)(uintptr_t)(uVar11));
    }
    else {
      func_01ff9048(0x1c,DAT_020e9d0c,3);
      if (*(uint *)(DAT_020e9cf4 & 0xfffffffc) >> (DAT_020e9cf4 & 3) * 8 == 0 &&
          *(uint *)(DAT_020e9cf4 & 0xfffffffc) << (DAT_020e9cf4 & 3) * -8 + 0x20 == 0) {
        uStack_28 = 0xfffff000;
        uStack_24 = 0x1000;
        uStack_20 = 0x1000;
        func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_28),3);
      }
      func_01ff8cf0((uint *)(uintptr_t)(uVar11));
    }
  }
  if (uVar10 != 0) {
    func_01ff9048(0x1c,DAT_020e9d0c,3);
    if (*(uint *)(DAT_020e9cf4 & 0xfffffffc) >> (DAT_020e9cf4 & 3) * 8 == 0 &&
        *(uint *)(DAT_020e9cf4 & 0xfffffffc) << (DAT_020e9cf4 & 3) * -8 + 0x20 == 0) {
      uStack_1c = 0xfffff000;
      uStack_18 = 0x1000;
      uStack_14 = 0x1000;
      func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_1c),3);
    }
    func_020e6a18(uVar10);
    func_020e6854(uVar10,0,0,0x1f);
  }
  if (!bVar3 && !bVar4) {
    return;
  }
  uStack_94 = 0;
  func_01ff9048(0x10,(undefined4)(uintptr_t)(&uStack_94),1);
  uStack_90 = 1;
  func_01ff9048(0x12,&uStack_90);
  uStack_8c = 2;
  func_01ff9048(0x10,&uStack_8c,1);
  return;
}

