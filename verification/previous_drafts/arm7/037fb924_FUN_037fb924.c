/* Decompiled C draft; module arm7; ROM address 037fb924. No matching claim. */
#include "types.h"
#include "deps/037fb924_FUN_037fb924.h"

void FUN_037fb924(byte param_1,int param_2,int param_3,int param_4)

{
  *DAT_037fb958 =
       param_1 | ((*DAT_037fb958 & 0x80) != 0) << 7 | (byte)(param_4 << 5) | (byte)(param_3 << 4) |
                 (byte)(param_2 << 2);
  return;
}

