/* Decompiled C draft; module arm9; ROM address 020165b8. No matching claim. */
#include "types.h"
#include "deps/020165b8_StructTEQ_GetNextFreeTEQSub.h"

int StructTEQ_GetNextFreeTEQSub(uint param_1)

{
  return (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
         (uint)*(ushort *)(param_1 + 10) * 0x10;
}

