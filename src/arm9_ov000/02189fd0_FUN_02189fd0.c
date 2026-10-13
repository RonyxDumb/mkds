/* Decompiled C draft; module arm9_ov000; ROM address 02189fd0. No matching claim. */
#include "types.h"
#include "deps/02189fd0_FUN_02189fd0.h"

uint FUN_02189fd0(int param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = 0;
  uVar2 = 0xffffffff;
  if (0 < 0x20 - param_1) {
    do {
      uVar2 = uVar2 << 1;
      iVar1 = iVar1 + 1;
    } while (iVar1 < 0x20 - param_1);
  }
  return uVar2 << 0x18 & DAT_0218a00c |
         uVar2 << 8 & DAT_0218a010 | uVar2 >> 0x18 | uVar2 >> 8 & DAT_0218a014;
}

