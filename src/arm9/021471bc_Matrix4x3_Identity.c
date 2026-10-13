/* Decompiled C draft; module arm9; ROM address 021471bc. No matching claim. */
#include "types.h"
#include "deps/021471bc_Matrix4x3_Identity.h"

undefined4 * Matrix4x3_Identity(undefined4 *param_1)

{
  *param_1 = 0x1000;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0x1000;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0x1000;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  return param_1 + 0xc;
}

