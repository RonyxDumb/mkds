/* Decompiled C draft; module arm7; ROM address 060091e0. No matching claim. */
#include "types.h"
#include "deps/060091e0_FUN_060091e0.h"

void FUN_060091e0(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(DAT_06009230 & 0xfffffffc) >> (DAT_06009230 & 3) * 8 |
          *(uint *)(DAT_06009230 & 0xfffffffc) << (DAT_06009230 & 3) * -8 + 0x20;
  FUN_0600c404();
  uVar3 = (*(uint *)(DAT_06009230 & 0xfffffffc) >> (DAT_06009230 & 3) * 8 |
          *(uint *)(DAT_06009230 & 0xfffffffc) << (DAT_06009230 & 3) * -8 + 0x20) + 0x318;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  FUN_060090b4(uVar2 + 0x188,(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 0xc);
  uVar3 = (*(uint *)(DAT_06009230 & 0xfffffffc) >> (DAT_06009230 & 3) * 8 |
          *(uint *)(DAT_06009230 & 0xfffffffc) << (DAT_06009230 & 3) * -8 + 0x20) + 0x3e0;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  FUN_060090b4(uVar2 + 0x188,(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) - 0xc);
  thunk_FUN_037f92a4();
  return;
}

