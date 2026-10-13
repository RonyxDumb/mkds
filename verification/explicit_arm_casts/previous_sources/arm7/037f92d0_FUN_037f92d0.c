/* Decompiled C draft; module arm7; ROM address 037f92d0. No matching claim. */
#include "types.h"
#include "deps/037f92d0_FUN_037f92d0.h"

void FUN_037f92d0(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5,
                 undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  uint uVar4;
  
  uVar2 = FUN_037faf70();
  uVar3 = FUN_037f9660();
  *(undefined4 *)(param_1 + 0x54) = param_6;
  *(undefined4 *)(param_1 + 0x50) = uVar3;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x58) = 0;
  FUN_037f951c(param_1);
  *(int *)(param_1 + 0x78) = param_4;
  *(int *)(param_1 + 0x74) = param_4 - param_5;
  *(undefined4 *)(param_1 + 0x7c) = 0;
  uVar1 = param_1 + 0x78U & 3;
  uVar4 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  *(undefined4 *)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) - 4) = DAT_037f93c0;
  uVar1 = param_1 + 0x74U & 3;
  uVar4 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  *(undefined4 *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) = DAT_037f93c4;
  *(undefined4 *)(param_1 + 0x84) = 0;
  uVar1 = param_1 + 0x84U & 3;
  uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  *(uint *)(param_1 + 0x80) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  FUN_037f9678(param_1,param_2,param_4 + -4);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(undefined4 *)(param_1 + 0x3c) = DAT_037f93c8;
  FUN_037fb24c(0,(param_4 - param_5) + 4,param_5 + -8);
  FUN_037f8d38(param_1,0);
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 100) = 0;
  uVar1 = param_1 + 100U & 3;
  uVar4 = *(uint *)(param_1 + 100U & 0xfffffffc);
  *(uint *)(param_1 + 0x60) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x94) = 0;
  FUN_037faf84(uVar2);
  return;
}

