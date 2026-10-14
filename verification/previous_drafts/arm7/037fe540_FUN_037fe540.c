/* Decompiled C draft; module arm7; ROM address 037fe540. No matching claim. */
#include "types.h"
#include "deps/037fe540_FUN_037fe540.h"

void FUN_037fe540(byte *param_1)

{
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  param_1[0x27] = 0;
  param_1[0x28] = 0;
  param_1[0x29] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 0;
  *param_1 = *param_1 | 2;
  *param_1 = *param_1 & 0xfb;
  *param_1 = *param_1 & 0xf7;
  *param_1 = *param_1 & 0xef;
  *param_1 = *param_1 & 0xdf;
  *param_1 = *param_1 | 0x40;
  *param_1 = *param_1 & 0x7f;
  param_1[0x3b] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[0x12] = 0x40;
  param_1[4] = 0x7f;
  param_1[5] = 0x7f;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[6] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0xff;
  param_1[0xf] = 0xff;
  param_1[0x10] = 0xff;
  param_1[0x11] = 0xff;
  param_1[1] = 0x7f;
  param_1[7] = 2;
  param_1[0x14] = 0x3c;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x13] = 0;
  *(short *)(param_1 + 0x1e) = (short)DAT_037fe630;
  FUN_037fc800(param_1 + 0x18);
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x3c] = 0;
  param_1[0x3d] = 0;
  param_1[0x3e] = 0;
  param_1[0x3f] = 0;
  return;
}

