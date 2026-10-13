/* Decompiled C draft; module arm7; ROM address 03802388. No matching claim. */
#include "types.h"
#include "deps/03802388_FUN_03802388.h"

void FUN_03802388(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = FUN_037faf70();
  iVar2 = FUN_03801450(3);
  if (iVar2 == 0) {
    FUN_037faf84(uVar1);
    uVar4 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    FUN_0380146c((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0xffff,4);
  }
  else {
    FUN_03801438(3);
    FUN_037faf84(uVar1);
    iVar2 = DAT_03802504;
    uVar4 = param_1 + 4U & 3;
    uVar3 = *(uint *)(param_1 + 4U & 0xfffffffc);
    uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
    switch(uVar4) {
    case 0x61:
      *(undefined4 *)(DAT_03802504 + 0x20) = 1;
      uVar4 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *DAT_03802508 = (ushort)(uVar3 >> uVar4 * 8) | (ushort)(uVar3 << uVar4 * -8 + 0x20);
      uVar4 = param_1 + 0xcU & 3;
      uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      *DAT_0380250c = (ushort)(uVar3 >> uVar4 * 8) | (ushort)(uVar3 << uVar4 * -8 + 0x20);
      FUN_03802a84();
      break;
    case 0x62:
    default:
      FUN_0380146c(uVar4 & 0xffff,1);
      break;
    case 99:
      *(undefined4 *)(DAT_03802504 + 0x20) = 2;
      uVar4 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      *(uint *)(iVar2 + 0x24) = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      FUN_03802950();
      FUN_0380146c(99,0);
      break;
    case 100:
      *(undefined4 *)(DAT_03802504 + 0x20) = 4;
      uVar4 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar5 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      *(uint *)(iVar2 + 0x28) = uVar5;
      uVar4 = param_1 + 0xcU & 3;
      uVar3 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      *(uint *)(iVar2 + 0x24) = uVar4;
      FUN_0380285c(uVar5 & 0xffff,uVar4 & 0xff);
      FUN_0380146c(100,0);
      break;
    case 0x65:
      *(undefined4 *)(DAT_03802504 + 0x20) = 3;
      uVar4 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
      *(uint *)(iVar2 + 0x28) = uVar4;
      uVar4 = uVar4 & 0xffff;
      uVar1 = FUN_038027cc(uVar4);
      FUN_0380146c(uVar4 + 0x70 & 0xffff,uVar1);
      break;
    case 0x66:
      uVar4 = param_1 + 8U & 3;
      uVar3 = *(uint *)(param_1 + 8U & 0xfffffffc);
      FUN_038028e8(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20);
    }
    FUN_038013f4(3);
  }
  return;
}

