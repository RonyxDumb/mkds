/* Decompiled C draft; module arm9; ROM address 02087458. No matching claim. */
#include "types.h"
#include "deps/02087458_StructAERSubSub_SomeFn_1_from_thumb.h"

void StructAERSubSub_SomeFn_1_from_thumb(uint *param_1,undefined4 param_2,int param_3,int param_4)

{
  switch(*param_1 >> 0x14 & 7) {
  case 0:
    param_4 = 8;
    break;
  case 1:
    param_4 = 0x11;
    break;
  case 2:
    param_4 = 0x21;
    break;
  case 3:
    param_4 = 0x41;
    break;
  case 4:
    param_4 = 0x80;
    break;
  case 5:
    param_4 = DAT_020874fc;
    break;
  case 6:
    param_4 = DAT_02087500;
    break;
  case 7:
    param_4 = DAT_02087504;
  }
  switch(*param_1 >> 0x17 & 7) {
  case 0:
    param_3 = 8;
    break;
  case 1:
    param_3 = 0x11;
    break;
  case 2:
    param_3 = 0x21;
    break;
  case 3:
    param_3 = 0x41;
    break;
  case 4:
    param_3 = 0x80;
    break;
  case 5:
    param_3 = DAT_020874fc;
    break;
  case 6:
    param_3 = DAT_02087500;
    break;
  case 7:
    param_3 = DAT_02087504;
  }
  param_1[7] = param_4 << 0xc;
  param_1[8] = param_3 << 0xc;
  return;
}

