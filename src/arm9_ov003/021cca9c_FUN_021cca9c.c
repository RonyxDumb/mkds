/* Decompiled C draft; module arm9_ov003; ROM address 021cca9c. No matching claim. */
#include "types.h"
#include "deps/021cca9c_FUN_021cca9c.h"

void FUN_021cca9c(undefined4 param_1,short *param_2)

{
  int *piVar1;
  
  piVar1 = DAT_021ccb14;
  *param_2 = *(short *)(*DAT_021ccb14 + 0x10);
  param_2[2] = *param_2 + 0xc;
  switch(param_1) {
  case 1:
    param_2[1] = *(short *)(*piVar1 + 0x12) + (ushort)*(byte *)(*piVar1 + 0x1a);
    param_2[3] = param_2[1] + (ushort)*(byte *)(DAT_021ccb18 + (uint)*(byte *)(*piVar1 + 0x1b));
    return;
  case 2:
    param_2[1] = *(short *)(*piVar1 + 0x12) + -0xd;
    param_2[3] = *(short *)(*piVar1 + 0x12);
    return;
  case 3:
    param_2[1] = *(short *)(*piVar1 + 0x12) + (ushort)*(byte *)(*piVar1 + 0x19);
    param_2[3] = param_2[1] + 0xd;
    return;
  case 4:
    param_2[1] = *(short *)(*piVar1 + 0x12);
    param_2[3] = param_2[1] + (ushort)*(byte *)(*piVar1 + 0x19);
  }
  return;
}

