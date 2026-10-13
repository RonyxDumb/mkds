/* Decompiled C draft; module arm9_ov000; ROM address 0218b260. No matching claim. */
#include "types.h"
#include "deps/0218b260_FUN_0218b260.h"

uint FUN_0218b260(int param_1)

{
  return (int)(uint)*(ushort *)(param_1 + 4) >> 8 |
         (uint)*(ushort *)(param_1 + 4) << 8 & DAT_0218b278 & 0xffff;
}

