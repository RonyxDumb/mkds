/* Decompiled C draft; module arm9; ROM address 02010f24. No matching claim. */
#include "types.h"
#include "deps/02010f24_func_02010f24.h"

void func_02010f24(uint param_1,int param_2,int param_3,int param_4,int param_5,uint param_6)

{
  *(uint *)(iRam02010f4c + 0x9c) =
       param_6 | param_1 | param_2 << 4 | param_3 << 6 | param_4 << 0x18 | param_5 << 0x10;
  return;
}

