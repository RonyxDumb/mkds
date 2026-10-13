/* Decompiled C draft; module arm7; ROM address 060096e4. No matching claim. */
#include "types.h"
#include "deps/060096e4_FUN_060096e4.h"

void FUN_060096e4(ushort *param_1,int param_2)

{
  if (((uint)param_1 & 1) == 0) {
    *param_1 = *param_1 & 0xff00 | (ushort)param_2 & 0xff;
  }
  else {
    *(ushort *)((int)param_1 + -1) = *(ushort *)((int)param_1 + -1) & 0xff | (ushort)(param_2 << 8);
  }
  return;
}

