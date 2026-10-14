/* Decompiled C draft; module arm9; ROM address 02025bf0. No matching claim. */
#include "types.h"
#include "deps/02025bf0_func_02025bf0.h"

void func_02025bf0(undefined4 param_1,int param_2,undefined4 param_3)

{
  short *psVar1;
  
  psVar1 = (short *)func_0201ea58(param_3,param_1);
  *(undefined4 *)(param_2 + 8) = 1;
  *(short *)(param_2 + 0xc) = (short)(((int)*psVar1 << 0x14) >> 0x14);
  *(short *)(param_2 + 0xe) = (short)(((int)psVar1[1] << 0x14) >> 0x14);
  return;
}

