/* Decompiled C draft; module arm9; ROM address 020088dc. No matching claim. */
#include "types.h"
#include "deps/020088dc_func_020088dc.h"

uint func_020088dc(ushort *param_1,int param_2)

{
  ushort uVar1;
  uint uVar2;
  
  uVar2 = 0;
  for (param_2 = param_2 >> 1; 0 < param_2; param_2 = param_2 + -1) {
    uVar1 = *param_1;
    param_1 = param_1 + 1;
    uVar2 = uVar2 + uVar1;
  }
  uVar2 = (uVar2 >> 0x10) + (uVar2 & uRam02008904);
  return (uVar2 + (uVar2 >> 0x10) ^ uRam02008904) & 0xffff;
}

