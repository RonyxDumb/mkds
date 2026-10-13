/* Decompiled C draft; module arm9; ROM address 020155d8. No matching claim. */
#include "types.h"
#include "deps/020155d8_func_020155d8.h"

uint func_020155d8(int param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if ((param_2 & 0x20000000) != 0) {
    return param_2 & 0xffff;
  }
  param_1 = param_1 + (param_2 & uRam0201577c);
  if ((param_2 & 0xc0000000) == 0) {
    return (uint)*(ushort *)(param_1 + param_3 * 2);
  }
  uVar1 = param_2 & uRam02015780;
  if ((param_2 & 0x40000000) == 0) {
    if ((param_3 & 3) == 0) {
      return (uint)*(ushort *)(param_1 + (param_3 >> 2) * 2);
    }
    if (uVar1 >> 0x10 < param_3) {
      return (uint)*(ushort *)((param_3 & 3) * 2 + param_1 + (uVar1 >> 0x12) * 2);
    }
    if ((param_3 & 1) != 0) {
      if ((param_3 & 2) == 0) {
        uVar1 = param_3 >> 2;
        param_3 = uVar1 + 1;
      }
      else {
        param_3 = param_3 >> 2;
        uVar1 = param_3 + 1;
      }
      uVar1 = (uint)*(ushort *)(param_1 + uVar1 * 2);
      uVar2 = (uint)*(ushort *)(param_1 + param_3 * 2);
      return uRam02015784 & (uRam02015784 & uVar1) * 3 + (uRam02015784 & uVar2) >> 2 & 0xffff |
             (uVar1 & 0x3e0) * 3 + (uVar2 & 0x3e0) >> 2 & 0x3e0;
    }
    param_3 = param_3 >> 2;
  }
  else {
    if ((param_3 & 1) == 0) {
      return (uint)*(ushort *)(param_1 + (param_3 & 0xfffffffe));
    }
    if (uVar1 >> 0x10 < param_3) {
      return (uint)*(ushort *)(param_1 + (uVar1 >> 0x11) * 2 + 2);
    }
    param_3 = param_3 >> 1;
  }
  uVar1 = (uint)*(ushort *)(param_1 + param_3 * 2);
  uVar2 = (uint)*(ushort *)(param_1 + param_3 * 2 + 2);
  return uRam02015784 & (uRam02015784 & uVar1) + (uRam02015784 & uVar2) >> 1 |
         (uVar1 & 0x3e0) + (uVar2 & 0x3e0) >> 1 & 0x3e0;
}

