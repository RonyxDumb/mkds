/* Decompiled C draft; module arm7; ROM address 037fc420. No matching claim. */
#include "types.h"
#include "deps/037fc420_FUN_037fc420.h"

void FUN_037fc420(int param_1,int param_2,undefined4 param_3,undefined2 param_4,int param_5,
                 int param_6,byte param_7)

{
  (&DAT_04000508)[param_1] =
       param_7 | (byte)(param_2 << 3) | (param_5 == 0) << 2 | (byte)(param_6 << 1);
  *(undefined4 *)(param_1 * 8 + 0x4000510) = param_3;
  *(undefined2 *)(param_1 * 8 + 0x4000514) = param_4;
  return;
}

