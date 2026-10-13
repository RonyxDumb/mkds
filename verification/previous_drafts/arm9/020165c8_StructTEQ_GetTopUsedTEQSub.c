/* Decompiled C draft; module arm9; ROM address 020165c8. No matching claim. */
#include "types.h"
#include "deps/020165c8_StructTEQ_GetTopUsedTEQSub.h"

int StructTEQ_GetTopUsedTEQSub(uint param_1)

{
  return (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
         (uint)*(ushort *)(param_1 + 8) * 0x10;
}

