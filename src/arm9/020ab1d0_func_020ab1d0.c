/* Decompiled C draft; module arm9; ROM address 020ab1d0. No matching claim. */
#include "types.h"
#include "deps/020ab1d0_func_020ab1d0.h"

uint func_020ab1d0(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(DAT_020ab294 + 0x2c);
  if (iVar2 != 0) {
    if (param_1 == 0) {
      return 0;
    }
    if ((param_1 <= *(ushort *)(iVar2 + 0xc)) || (param_1 == DAT_020ab298)) {
      if (*(int *)(iVar2 + 8) == DAT_020ab29c) {
        if ((int)param_1 < 9) {
          switch(param_1) {
          case 1:
            return 8;
          case 2:
            return 10;
          case 3:
            return DAT_020ab2a0;
          case 4:
            return 6;
          case 5:
            return 7;
          case 6:
            return 0x10;
          case 7:
            return 0x11;
          case 8:
            return 0x12;
          }
        }
        else if (param_1 == DAT_020ab298) {
          return 0x13;
        }
      }
      else {
        switch(param_1) {
        case 1:
          return 8;
        case 2:
          return 10;
        case 3:
          return 0x20;
        case 4:
          return 4;
        case 5:
          return 5;
        }
      }
    }
    if ((param_1 < 0x100) &&
       (uVar1 = (uint)*(ushort *)
                       (*(int *)(DAT_020ab294 + 0x30) +
                       ((param_1 - *(ushort *)(iVar2 + 0xc)) + -1) * 2), 0x20 < uVar1)) {
      return uVar1;
    }
  }
  return 0;
}

