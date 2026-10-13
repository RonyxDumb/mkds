/* Decompiled C draft; module arm9; ROM address 02035e64. No matching claim. */
#include "types.h"
#include "deps/02035e64_func_02035e64.h"

undefined4 func_02035e64(int param_1)

{
  undefined4 extraout_r1;
  int iVar1;
  
  if (*(int *)(*piRam02035ed0 + iRam02035ed4) == 9) {
    iVar1 = func_02058f20();
    if (iVar1 == 1) {
      iVar1 = func_02035e44();
      if (iVar1 != 0) {
        func_02035e38();
      }
      *(undefined4 *)(*piRam02035ed0 + iRam02035ed4) = 10;
    }
  }
  else if (*(int *)(*piRam02035ed0 + iRam02035ed4) == 10) {
    if (param_1 != 0) {
      func_02035e30(param_1,10);
    }
    *(undefined4 *)(*piRam02035ed0 + iRam02035ed4) = 0xb;
  }
  iVar1 = *piRam02035ed0;
  _s32_div_f(*(int *)(iVar1 + iRam02035ed8) + 1,uRam02035edc);
  *(undefined4 *)(iVar1 + iRam02035ed8) = extraout_r1;
  return 0xffffffff;
}

