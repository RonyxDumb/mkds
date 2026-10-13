/* Decompiled C draft; module arm9_ov003; ROM address 021bca90. No matching claim. */
#include "types.h"
#include "deps/021bca90_FUN_021bca90.h"

void FUN_021bca90(byte *param_1,byte *param_2,byte *param_3)

{
  *param_3 = *param_1 ^ *param_2;
  param_3[1] = param_1[1] ^ param_2[1];
  param_3[2] = param_1[2] ^ param_2[2];
  param_3[3] = param_1[3] ^ param_2[3];
  param_3[4] = param_1[4] ^ param_2[4];
  param_3[5] = param_1[5] ^ param_2[5];
  param_3[6] = param_1[6] ^ param_2[6];
  param_3[7] = param_1[7] ^ param_2[7];
  return;
}

