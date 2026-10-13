/* Decompiled C draft; module arm7; ROM address 0600068c. No matching claim. */
#include "types.h"
#include "deps/0600068c_FUN_0600068c.h"

void FUN_0600068c(int param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = DAT_06000804;
  *(uint *)(DAT_06000804 + 0x540) =
       *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar1 = param_1 + 0x24U & 3;
  uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(iVar2 + 0x544) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x28U & 3;
  uVar3 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
  *(uint *)(iVar2 + 0x548) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(iVar2 + 0x54c) = 0;
  thunk_FUN_037f98e8(DAT_06000808,DAT_0600080c,2);
  thunk_FUN_037f98e8(DAT_06000810,DAT_06000814,4);
  thunk_FUN_037f98e8(DAT_06000818,DAT_0600081c,4);
  thunk_FUN_037f98e8(DAT_06000820,DAT_06000824,0x20);
  *(int *)(param_1 + 0x10) = DAT_06000808;
  *(undefined4 *)(param_1 + 0x14) = DAT_06000810;
  iVar2 = DAT_06000804;
  uVar1 = param_2 + 8 & 3;
  uVar3 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(DAT_06000804 + 0x564) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x18 & 3;
  uVar3 = *(uint *)(param_2 + 0x18 & 0xfffffffc);
  *(uint *)(iVar2 + 0x568) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x10 & 3;
  uVar3 = *(uint *)(param_2 + 0x10 & 0xfffffffc);
  *(uint *)(iVar2 + 0x56c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  *(uint *)(iVar2 + 0x570) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0x14 & 3;
  uVar3 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
  *(uint *)(iVar2 + 0x574) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_2 + 0xc & 3;
  uVar3 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  *(uint *)(iVar2 + 0x578) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  thunk_FUN_037f9a98(DAT_06000828);
  uVar1 = param_2 + 4 & 3;
  uVar3 = *(uint *)(param_2 + 4 & 0xfffffffc);
  thunk_FUN_037f92d0(DAT_0600082c,DAT_06000830,0,DAT_06000828,0x400,
                     uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  thunk_FUN_037f9054(DAT_0600082c);
  uVar1 = param_2 + 0xc & 3;
  uVar3 = *(uint *)(param_2 + 0xc & 0xfffffffc);
  thunk_FUN_037f92d0(DAT_06000834,DAT_06000838,0,DAT_0600083c,0x1000,
                     uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  thunk_FUN_037f9054(DAT_06000834);
  iVar2 = DAT_06000808;
  iVar4 = 0;
  do {
    *(undefined1 *)(iVar2 + iVar4 + 0x1550) = 0;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x10);
  *(undefined4 *)(DAT_06000804 + 0x560) = 0;
  thunk_FUN_037fb72c();
  thunk_FUN_037fb6c0(10,DAT_06000840);
  *(undefined4 *)(param_1 + 0x18) = 2;
  uVar1 = param_2 + 0x14 & 3;
  uVar3 = *(uint *)(param_2 + 0x14 & 0xfffffffc);
  *(uint *)(param_1 + 0xc) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  FUN_06008738(param_1);
  return;
}

