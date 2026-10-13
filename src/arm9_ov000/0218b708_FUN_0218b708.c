/* Decompiled C draft; module arm9_ov000; ROM address 0218b708. No matching claim. */
#include "types.h"
#include "deps/0218b708_FUN_0218b708.h"

void FUN_0218b708(undefined4 param_1,int param_2,int *param_3,int param_4)

{
  if (param_2 == 0) {
    (**(code **)(param_4 + DAT_0218b774))(param_4,1,param_3,*(undefined4 *)(param_4 + DAT_0218b770))
    ;
  }
  else if (param_2 == 1) {
    (**(code **)(param_4 + DAT_0218b774))(param_4,2,param_3,*(undefined4 *)(param_4 + DAT_0218b770))
    ;
  }
  else if (param_2 == 2) {
    (**(code **)(param_4 + DAT_0218b774))(param_4,4,param_3,*(undefined4 *)(param_4 + DAT_0218b770))
    ;
  }
  if (((param_3 != (int *)0x0) && (*param_3 == *(int *)(param_4 + DAT_0218b778))) &&
     ((short)param_3[1] == *(short *)(param_4 + DAT_0218b77c))) {
    *(int *)(param_4 + DAT_0218b778) = 0;
  }
  return;
}

