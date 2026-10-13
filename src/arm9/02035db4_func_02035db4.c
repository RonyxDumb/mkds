/* Decompiled C draft; module arm9; ROM address 02035db4. No matching claim. */
#include "types.h"
#include "deps/02035db4_func_02035db4.h"

undefined4 func_02035db4(int param_1)

{
  undefined4 extraout_r1;
  int iVar1;
  
  if (*(int *)(*piRam02035e20 + iRam02035e24) == 9) {
    iVar1 = func_020591bc();
    if (iVar1 == 1) {
      iVar1 = func_02035e44();
      if (iVar1 != 0) {
        func_02035e38();
      }
      *(undefined4 *)(*piRam02035e20 + iRam02035e24) = 10;
    }
  }
  else if (*(int *)(*piRam02035e20 + iRam02035e24) == 10) {
    if (param_1 != 0) {
      func_02035e30(param_1,1);
    }
    *(undefined4 *)(*piRam02035e20 + iRam02035e24) = 0xb;
  }
  iVar1 = *piRam02035e20;
  _s32_div_f(*(int *)(iVar1 + iRam02035e28) + 1,uRam02035e2c);
  *(undefined4 *)(iVar1 + iRam02035e28) = extraout_r1;
  return 0xffffffff;
}

