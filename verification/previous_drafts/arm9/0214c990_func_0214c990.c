/* Decompiled C draft; module arm9; ROM address 0214c990. No matching claim. */
#include "types.h"
#include "deps/0214c990_func_0214c990.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0214c990(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4,
                  code *param_5,undefined4 param_6)

{
  MIi_CheckDma0SourceAddress(param_1,param_2,param_4,0);
  if (param_4 != 0) {
    MI_WaitDma(param_1);
    if (param_5 == (code *)0x0) {
      func_01ffff38(param_1,param_2,param_3,param_4 >> 2 | 0x84000000);
      return;
    }
    OSi_EnterDmaCallback(param_1,param_5,param_6);
    func_01ffff38(param_1,param_2,param_3,param_4 >> 2 | 0xc4000000);
    return;
  }
  if (param_5 != (code *)0x0) {
    (*param_5)(param_6);
    return;
  }
  return;
}

