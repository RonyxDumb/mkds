/* Decompiled C draft; module arm9; ROM address 0203c5ac. No matching claim. */
#include "types.h"
#include "deps/0203c5ac_Maybe_helper_03c5ac.h"

uint Maybe_helper_03c5ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * 0x8c +
          (*(uint *)(uRam0203c5c4 & 0xfffffffc) >> (uRam0203c5c4 & 3) * 8 |
          *(uint *)(uRam0203c5c4 & 0xfffffffc) << (uRam0203c5c4 & 3) * -8 + 0x20) + 0x5c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

