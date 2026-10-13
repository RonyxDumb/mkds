/* Decompiled C draft; module arm9_ov003; ROM address 021cc948. No matching claim. */
#include "types.h"
#include "deps/021cc948_FUN_021cc948.h"

void FUN_021cc948(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  piVar1 = DAT_021cc970;
  *DAT_021cc970 = param_1 + param_2 * 0x20;
  piVar1[1] = param_3 * 0x20 + DAT_021cc974;
  FUN_021d3544(1,DAT_021cc978,0,0x78);
  return;
}

