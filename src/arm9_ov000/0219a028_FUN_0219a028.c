/* Decompiled C draft; module arm9_ov000; ROM address 0219a028. No matching claim. */
#include "types.h"
#include "deps/0219a028_FUN_0219a028.h"

uint FUN_0219a028(int param_1,int param_2)

{
  return (uint)*(byte *)(param_1 + param_2) << 8 & DAT_0219a040 |
         (uint)*(byte *)(param_1 + param_2 + 1);
}

