/* Decompiled C draft; module arm9; ROM address 0214a390. No matching claim. */
#include "types.h"
#include "deps/0214a390_UpdateBldcntBldalphaBldy.h"

void UpdateBldcntBldalphaBldy
               (ushort *param_1,ushort param_2,int param_3,ushort param_4,int param_5,int param_6)

{
  if (-1 < param_6) {
    param_2 = param_2 | 0x80;
  }
  param_1[1] = param_4 | (ushort)(param_5 << 8);
  if (-1 >= param_6) {
    *param_1 = param_2 | 0xc0 | (ushort)(param_3 << 8);
    param_1[2] = -(ushort)param_6;
    return;
  }
  *param_1 = param_2 | (ushort)(param_3 << 8);
  param_1[2] = (ushort)param_6;
  return;
}

