/* Decompiled C draft; module arm9_ov000; ROM address 0218a018. No matching claim. */
#include "types.h"
#include "deps/0218a018_FUN_0218a018.h"

uint FUN_0218a018(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1 << 0x18 | (uint)param_1[1] << 0x10 | (uint)param_1[2] << 8;
  return (uint)param_1[3] << 0x18 & DAT_0218a058 |
         (uVar1 | param_1[3]) << 8 & DAT_0218a05c | (uint)*param_1 | uVar1 >> 8 & DAT_0218a060;
}

