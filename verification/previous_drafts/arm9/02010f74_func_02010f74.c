/* Decompiled C draft; module arm9; ROM address 02010f74. No matching claim. */
#include "types.h"
#include "deps/02010f74_func_02010f74.h"

void func_02010f74(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  
  bVar1 = param_3 != 0;
  if (bVar1) {
    param_3 = 1;
  }
  if (!bVar1) {
    param_3 = 0;
  }
  *(uint *)(iRam02010f94 + 0x94) = param_1 | param_2 << 0x10 | param_3 << 0xf;
  return;
}

