/* Decompiled C draft; module arm9; ROM address 020231e4. No matching claim. */
#include "types.h"
#include "deps/020231e4_func_020231e4.h"

int func_020231e4(uint param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (param_1 & 1) + ((param_1 & 2) >> 1);
  iVar2 = (param_2 & 1) + ((param_2 & 2) >> 1);
  return (iVar1 + ((param_1 & 4) >> 2)) * (iVar2 + ((param_2 & 4) >> 2)) +
         (param_1 >> 3) * (((param_2 & 4) >> 2) + iVar2 * 2) +
         (param_2 >> 3) * (((param_1 & 4) >> 2) + iVar1 * 2) + (param_1 >> 3) * (param_2 >> 3);
}

