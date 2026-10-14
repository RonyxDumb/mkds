/* Decompiled C draft; module arm7; ROM address 037fb6c0. No matching claim. */
#include "types.h"
#include "deps/037fb6c0_FUN_037fb6c0.h"

void FUN_037fb6c0(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  FUN_037faf70();
  *(int *)(DAT_037fb724 + param_1 * 4) = param_2;
  if (param_2 == 0) {
    uVar1 = DAT_037fb728 + 0x38cU & 3;
    uVar2 = *(uint *)(DAT_037fb728 + 0x38cU & 0xfffffffc);
    *(uint *)(DAT_037fb728 + 0x38c) =
         (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & ~(1 << (param_1 & 0xff));
  }
  else {
    uVar1 = DAT_037fb728 + 0x38cU & 3;
    uVar2 = *(uint *)(DAT_037fb728 + 0x38cU & 0xfffffffc);
    *(uint *)(DAT_037fb728 + 0x38c) =
         uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20 | 1 << (param_1 & 0xff);
  }
  FUN_037faf84();
  return;
}

