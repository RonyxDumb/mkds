/* Decompiled C draft; module arm9; ROM address 02010f50. No matching claim. */
#include "types.h"
#include "deps/02010f50_func_02010f50.h"

void func_02010f50(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  
  bVar1 = param_3 != 0;
  if (bVar1) {
    param_3 = 1;
  }
  if (!bVar1) {
    param_3 = 0;
  }
  *(uint *)(iRam02010f70 + 0x98) = param_1 | param_2 << 0x10 | param_3 << 0xf;
  return;
}

