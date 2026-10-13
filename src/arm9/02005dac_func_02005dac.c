/* Decompiled C draft; module arm9; ROM address 02005dac. No matching claim. */
#include "types.h"
#include "deps/02005dac_func_02005dac.h"

/* WARNING: Removing unreachable block (ram,0x02005dfc) */
/* WARNING: Removing unreachable block (ram,0x02006122) */

undefined4 func_02005dac(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  *(undefined1 *)(param_1 + DAT_0200613c + param_2 * 0x68) = 1;
  if (param_4 == 0) {
    return 0;
  }
  if (param_4 < 1) {
    func_020061d8(param_1,0xf,param_2,5);
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x02005e0a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*(code *)((int)&switchD_02005e0a::switchdataD_02005e0c + (int)(short)USHORT_02005e0e))();
  return uVar1;
}

