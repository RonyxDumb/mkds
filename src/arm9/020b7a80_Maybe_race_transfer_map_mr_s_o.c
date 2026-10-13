/* Decompiled C draft; module arm9; ROM address 020b7a80. No matching claim. */
#include "types.h"
#include "deps/020b7a80_Maybe_race_transfer_map_mr_s_o.h"

void Maybe_race_transfer_map_mr_s_o(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_30;
  int iStack_2c;
  int iStack_28;
  int local_24;
  int iStack_20;
  int local_1c;
  int iStack_18;
  int local_14 [2];
  uint uVar4;
  
  local_30 = 0;
  uVar2 = func_020b47c0(uRam020b7ec4);
  Gfx_ReadCharGraphics(&local_30,uVar2);
  uVar4 = local_30 + 0x14U & 3;
  uVar3 = *(uint *)(local_30 + 0x14U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  bVar1 = *(byte *)((*(uint *)(uRam020b7ec8 & 0xfffffffc) >> (uRam020b7ec8 & 3) * 8 |
                    *(uint *)(uRam020b7ec8 & 0xfffffffc) << (uRam020b7ec8 & 3) * -8 + 0x20) + 0x2e);
  if (0x15 < bVar1) {
    if (bVar1 < 0x32) {
      if (bVar1 == 0x31) {
        func_020b46d0(uVar4,0,4,8);
        local_14[0] = 0;
        uVar2 = func_020b47c0(uRam020b7ee4);
        Gfx_ReadPalette(local_14,uVar2);
        iVar7 = 0;
        do {
          iVar5 = iVar7 + 0x80;
          uVar4 = local_14[0] + 0xcU & 3;
          uVar3 = *(uint *)(local_14[0] + 0xcU & 0xfffffffc);
          iVar6 = iVar7 + 0x50;
          iVar7 = iVar7 + 1;
          *(undefined2 *)(param_1 + iVar6 * 2) =
               *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5 * 2);
        } while (iVar7 < 0x10);
        return;
      }
      return;
    }
    if (0x33 < bVar1) {
      return;
    }
    if (bVar1 < 0x32) {
      return;
    }
    if (bVar1 != 0x32) {
      if (bVar1 == 0x33) {
        func_020b46d0(uVar4,0x10);
        iStack_20 = 0;
        uVar2 = func_020b47c0(uRam020b7ed8);
        Gfx_ReadPalette(&iStack_20,uVar2);
        iVar7 = 0;
        do {
          uVar4 = iStack_20 + 0xcU & 3;
          uVar3 = *(uint *)(iStack_20 + 0xcU & 0xfffffffc);
          iVar5 = (iVar7 + 0x50) * 2;
          iVar7 = iVar7 + 1;
          *(undefined2 *)(param_1 + iVar5) =
               *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5);
        } while (iVar7 < 0x10);
        return;
      }
      return;
    }
    func_020b46d0(uVar4,4,0,8);
    iStack_28 = 0;
    uVar2 = func_020b47c0(uRam020b7ed0);
    Gfx_ReadPalette(&iStack_28,uVar2);
    iVar7 = 0;
    do {
      iVar5 = iVar7 + 0x10;
      uVar4 = iStack_28 + 0xcU & 3;
      uVar3 = *(uint *)(iStack_28 + 0xcU & 0xfffffffc);
      iVar6 = iVar7 + 0x50;
      iVar7 = iVar7 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5 * 2);
    } while (iVar7 < 0x10);
    return;
  }
  if (0x14 < bVar1) {
    func_020b46d0(uVar4);
    local_24 = 0;
    uVar2 = func_020b47c0(uRam020b7ed4);
    Gfx_ReadPalette(&local_24,uVar2);
    iVar7 = 0;
    do {
      iVar5 = iVar7 + 0x20;
      uVar4 = local_24 + 0xcU & 3;
      uVar3 = *(uint *)(local_24 + 0xcU & 0xfffffffc);
      iVar6 = iVar7 + 0x50;
      iVar7 = iVar7 + 1;
      *(undefined2 *)(param_1 + iVar6 * 2) =
           *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5 * 2);
    } while (iVar7 < 0x10);
    return;
  }
  if (10 < bVar1) {
    if (bVar1 == 0x11) {
      func_020b46d0(uVar4,0x14);
      local_1c = 0;
      uVar2 = func_020b47c0(uRam020b7edc);
      Gfx_ReadPalette(&local_1c,uVar2);
      iVar7 = 0;
      do {
        iVar5 = iVar7 + 0x60;
        uVar4 = local_1c + 0xcU & 3;
        uVar3 = *(uint *)(local_1c + 0xcU & 0xfffffffc);
        iVar6 = iVar7 + 0x50;
        iVar7 = iVar7 + 1;
        *(undefined2 *)(param_1 + iVar6 * 2) =
             *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5 * 2);
      } while (iVar7 < 0x10);
      return;
    }
    return;
  }
  if (bVar1 < 9) {
    return;
  }
  if (bVar1 != 9) {
    if (bVar1 == 10) {
      func_020b46d0(uVar4,0x18);
      iStack_18 = 0;
      uVar2 = func_020b47c0(uRam020b7ee0);
      Gfx_ReadPalette(&iStack_18,uVar2);
      iVar7 = 0;
      do {
        iVar5 = iVar7 + 0x70;
        uVar4 = iStack_18 + 0xcU & 3;
        uVar3 = *(uint *)(iStack_18 + 0xcU & 0xfffffffc);
        iVar6 = iVar7 + 0x50;
        iVar7 = iVar7 + 1;
        *(undefined2 *)(param_1 + iVar6 * 2) =
             *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5 * 2);
      } while (iVar7 < 0x10);
      return;
    }
    return;
  }
  func_020b46d0(uVar4,0,0);
  iStack_2c = 0;
  uVar2 = func_020b47c0(uRam020b7ecc);
  Gfx_ReadPalette(&iStack_2c,uVar2);
  iVar7 = 0;
  do {
    iVar6 = iVar7 + 0x50;
    uVar4 = iStack_2c + 0xcU & 3;
    uVar3 = *(uint *)(iStack_2c + 0xcU & 0xfffffffc);
    iVar5 = iVar7 * 2;
    iVar7 = iVar7 + 1;
    *(undefined2 *)(param_1 + iVar6 * 2) =
         *(undefined2 *)((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) + iVar5);
  } while (iVar7 < 0x10);
  return;
}

