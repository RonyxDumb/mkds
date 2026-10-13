/* Decompiled C draft; module arm7; ROM address 06008d48. No matching claim. */
#include "types.h"
#include "deps/06008d48_FUN_06008d48.h"

void FUN_06008d48(uint param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = *(uint *)(DAT_06008e28 & 0xfffffffc) >> (DAT_06008e28 & 3) * 8 |
          *(uint *)(DAT_06008e28 & 0xfffffffc) << (DAT_06008e28 & 3) * -8 + 0x20;
  *(uint *)(uVar4 + 0x17c) =
       *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
       *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(uVar4 + 0x180) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  *(uint *)(uVar4 + 0x184) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  FUN_06008e2c(uVar4 + 0x188,2);
  FUN_06008e2c(uVar4 + 0x194,3);
  FUN_06008e2c(uVar4 + 0x1a0,4);
  FUN_06008e2c(uVar4 + 0x1ac,5);
  FUN_06008e2c(uVar4 + 0x1b8,6);
  FUN_06008e2c(uVar4 + 0x1c4,7);
  FUN_06008e2c(uVar4 + 0x1d0,8);
  FUN_06008e2c(uVar4 + 0x1dc,9);
  FUN_06008e2c(uVar4 + 0x1e8,10);
  FUN_06008e2c(uVar4 + 500,0xb);
  FUN_06008e2c(uVar4 + 0x200,0xc);
  iVar2 = FUN_06009138(uVar4 + 0x188,0x81);
  *(int *)(uVar4 + 0x3e0) = iVar2 + 0xc;
  *(undefined2 *)(uVar4 + 0x3e4) = 0;
  *(undefined2 *)(uVar4 + 1000) = 0;
  return;
}

