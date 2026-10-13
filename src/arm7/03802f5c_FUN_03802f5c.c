/* Decompiled C draft; module arm7; ROM address 03802f5c. No matching claim. */
#include "types.h"
#include "deps/03802f5c_FUN_03802f5c.h"

void FUN_03802f5c(int param_1)

{
  ushort *puVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar3 = DAT_038031a8;
  uVar6 = param_1 + 4U & 3;
  uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (uVar6 == 0x40) {
    uVar4 = FUN_037faf70();
    iVar3 = FUN_03801450(2);
    if (iVar3 == 0) {
      FUN_037faf84(uVar4);
      uVar6 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      FUN_0380146c((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffff,4);
    }
    else {
      FUN_03801438(2);
      FUN_037faf84(uVar4);
      uVar6 = param_1 + 8U & 3;
      uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
      if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 1) == 1) {
        uVar2 = FUN_03803570();
        puVar1 = DAT_038031a0;
        uVar6 = param_1 + 8U & 3;
        uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
        if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 2) != 0) {
          uVar2 = uVar2 ^ 0x8000;
        }
        *DAT_038031a0 = uVar2;
        *DAT_038031a4 = puVar1;
      }
      else {
        uVar2 = FUN_03803638();
        puVar1 = DAT_038031a0;
        uVar6 = param_1 + 8U & 3;
        uVar5 = *(uint *)(param_1 + 8U & 0xfffffffc);
        if (((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 2) != 0) {
          uVar2 = uVar2 ^ 0x80;
        }
        *DAT_038031a0 = uVar2;
        *DAT_038031a4 = puVar1;
      }
      uVar6 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      FUN_0380146c((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffff,0);
      FUN_038013f4(2);
    }
  }
  else if (uVar6 == 0x41) {
    uVar6 = DAT_038031a8 + 0x20U & 3;
    uVar5 = *(uint *)(DAT_038031a8 + 0x20U & 0xfffffffc);
    if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 1) {
      *(undefined2 *)(DAT_038031a8 + 0x3a) = 0;
      *(undefined2 *)(iVar3 + 0x38) = 0;
      uVar4 = FUN_037faf70();
      FUN_037f888c(0x40);
      FUN_0380393c(0x40,DAT_038031ac);
      FUN_038038d0();
      iVar3 = DAT_038031a8;
      *DAT_038031b0 = *(undefined2 *)(DAT_038031a8 + 0x34);
      *DAT_038031b4 = *(ushort *)(iVar3 + 0x36) | 0xc0;
      FUN_037faf84(uVar4);
      uVar6 = param_1 + 4U & 3;
      uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
      FUN_0380146c((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffff,0);
      *(undefined4 *)(DAT_038031a8 + 0x20) = 2;
    }
    else {
      FUN_0380146c(0x41,3);
    }
  }
  else if (uVar6 == 0x42) {
    uVar6 = DAT_038031a8 + 0x20U & 3;
    uVar5 = *(uint *)(DAT_038031a8 + 0x20U & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (uVar6 - 3 < 2) {
      *DAT_038031b4 = *DAT_038031b4 & 0xff7f;
      uVar4 = FUN_037faf70();
      FUN_0380393c(0x40,0);
      FUN_03803884();
      FUN_037faf84(uVar4);
      uVar6 = DAT_038031a8 + 0x20U & 3;
      uVar5 = *(uint *)(DAT_038031a8 + 0x20U & 0xfffffffc);
      if ((uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 3) {
        FUN_0380146c(0x42,0);
      }
      else {
        FUN_0380146c(0x51,0);
      }
      *(undefined4 *)(DAT_038031a8 + 0x20) = 0;
    }
    else if (uVar6 == 3) {
      FUN_0380146c(0x42,3);
    }
    else {
      FUN_0380146c(0x51,3);
    }
  }
  return;
}

