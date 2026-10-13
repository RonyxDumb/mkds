/* Decompiled C draft; module arm9; ROM address 0213377c. No matching claim. */
#include "types.h"
#include "deps/0213377c_func_0213377c.h"

uint func_0213377c(undefined4 param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint *puVar1;
  uint uVar2;
  uint unaff_r5;
  
  if (((param_4 & 0x400000) != 0) || ((param_2 & 0x80000000) == 0)) {
    return unaff_r5;
  }
  param_2 = param_2 + (0xfffffffe < unaff_r5);
  if (param_2 * 2 < 0xffe00000) {
    return unaff_r5 + 1;
  }
  puVar1 = (uint *)GetAlphaFlagsRef();
  uVar2 = *(uint *)((uint)puVar1 & 0xfffffffc) >> ((uint)puVar1 & 3) * 8 |
          *(uint *)((uint)puVar1 & 0xfffffffc) << ((uint)puVar1 & 3) * -8 + 0x20;
  if ((uVar2 & 0x400) == 0) {
    *puVar1 = uVar2 | 0x14;
    return unaff_r5 + 1;
  }
  uVar2 = func_0213412c(0,param_2 & 0x80000000 | 0x1ff00000,uRam02133d94);
  return uVar2;
}

