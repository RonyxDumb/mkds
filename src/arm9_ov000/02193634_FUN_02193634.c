/* Decompiled C draft; module arm9_ov000; ROM address 02193634. No matching claim. */
#include "types.h"
#include "deps/02193634_FUN_02193634.h"

undefined4 FUN_02193634(int param_1,int param_2,int param_3)

{
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  
  if (((param_1 == 0) && (param_2 == 0)) && (param_3 == 0)) {
    return 1;
  }
  if (((-1 < param_1) && (-1 < param_2)) && (-1 < param_3)) {
    switch(param_2) {
    case 0:
      if (param_1 != 0) {
        return 0;
      }
      break;
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 0xc:
      if (0x1f < param_1) {
        return 0;
      }
      break;
    case 2:
      func_0x02133068(param_3,4);
      if (((extraout_r1 == 0) && (func_0x02133068(param_3,100), extraout_r1_00 != 0)) ||
         (func_0x02133068(param_3,DAT_0219373c), extraout_r1_01 == 0)) {
        if (0x1d < param_1) {
          return 0;
        }
      }
      else if (0x1c < param_1) {
        return 0;
      }
      break;
    case 4:
    case 6:
    case 9:
    case 0xb:
      if (0x1e < param_1) {
        return 0;
      }
      break;
    default:
      return 0;
    }
    if (param_3 < DAT_02193740) {
      return 0;
    }
    if (DAT_02193744 < param_3) {
      return 0;
    }
    if (param_3 == DAT_02193744) {
      if (6 < param_2) {
        return 0;
      }
      if ((param_2 == 6) && (6 < param_1)) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}

