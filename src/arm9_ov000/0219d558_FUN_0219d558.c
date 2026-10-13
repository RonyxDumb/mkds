/* Decompiled C draft; module arm9_ov000; ROM address 0219d558. No matching claim. */
#include "types.h"
#include "deps/0219d558_FUN_0219d558.h"

undefined4 FUN_0219d558(int param_1,int param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  
  if ((*DAT_0219d5ac != 0) && (piVar1 = *(int **)(*DAT_0219d5ac + 4), piVar1 != (int *)0x0)) {
    if (param_1 == -1) {
      param_1 = *(int *)(*piVar1 + DAT_0219d5b0);
    }
    if (param_2 == 0) {
      param_2 = *piVar1 + DAT_0219d5b4;
    }
    if (param_3 == 0) {
      param_3 = *piVar1 + DAT_0219d5b8;
    }
    uVar2 = FUN_0218e974(piVar1,param_1,param_2,param_3);
    return uVar2;
  }
  return 0;
}

