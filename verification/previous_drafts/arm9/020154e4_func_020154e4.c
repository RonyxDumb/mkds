/* Decompiled C draft; module arm9; ROM address 020154e4. No matching claim. */
#include "types.h"
#include "deps/020154e4_func_020154e4.h"

uint func_020154e4(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if ((param_2 & 0x20000000) != 0) {
    return param_2 & 0xffff;
  }
  param_1 = param_1 + (param_2 & uRam020155d0);
  if ((param_2 & 0xc0000000) == 0) {
    return (uint)*(byte *)(param_1 + param_3);
  }
  uVar1 = param_2 & uRam020155d4;
  if ((param_2 & 0x40000000) == 0) {
    if ((param_3 & 3) == 0) {
      return (uint)*(byte *)(param_1 + (param_3 >> 2));
    }
    if (param_3 <= uVar1 >> 0x10) {
      if ((param_3 & 1) == 0) {
        return ((uint)*(byte *)(param_1 + (param_3 >> 2)) +
               (uint)*(byte *)(param_1 + (param_3 >> 2) + 1)) * 0x8000 >> 0x10;
      }
      if ((param_3 & 2) == 0) {
        uVar1 = param_3 >> 2;
        param_3 = uVar1 + 1;
      }
      else {
        param_3 = param_3 >> 2;
        uVar1 = param_3 + 1;
      }
      return ((uint)*(byte *)(param_1 + uVar1) * 3 + (uint)*(byte *)(param_1 + param_3)) * 0x4000 >>
             0x10;
    }
    return (uint)*(byte *)((param_3 & 3) + param_1 + (uVar1 >> 0x12));
  }
  if ((param_3 & 1) == 0) {
    return (uint)*(byte *)(param_1 + (param_3 >> 1));
  }
  if (param_3 <= uVar1 >> 0x10) {
    return ((uint)*(byte *)(param_1 + (param_3 >> 1)) +
           (uint)*(byte *)(param_1 + (param_3 >> 1) + 1)) * 0x8000 >> 0x10;
  }
  return (uint)*(byte *)(param_1 + (uVar1 >> 0x11) + 1);
}

