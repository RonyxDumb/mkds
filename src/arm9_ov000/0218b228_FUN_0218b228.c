/* Decompiled C draft; module arm9_ov000; ROM address 0218b228. No matching claim. */
#include "types.h"
#include "deps/0218b228_FUN_0218b228.h"

uint FUN_0218b228(int param_1)

{
  return (int)(uint)*(ushort *)(param_1 + 0xc) >> 8 |
         (uint)*(ushort *)(param_1 + 0xc) << 8 & DAT_0218b240 & 0xffff;
}

