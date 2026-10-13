/* Decompiled C draft; module arm9_ov000; ROM address 021a4b98. No matching claim. */
#include "types.h"
#include "deps/021a4b98_FUN_021a4b98.h"

int FUN_021a4b98(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; (uint)LZCOUNT(param_1) < 0x20;
      param_1 = param_1 & ~(1 << (0x1fU - LZCOUNT(param_1) & 0xff))) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}

