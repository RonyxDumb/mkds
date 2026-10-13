/* Decompiled C draft; module arm9_ov001; ROM address 02188220. No matching claim. */
#include "types.h"
#include "deps/02188220_FUN_02188220.h"

uint FUN_02188220(int param_1)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0xac);
  if ((int)uVar1 < 0) {
    uVar1 = -uVar1;
  }
  return uVar1 & 0xffff;
}

