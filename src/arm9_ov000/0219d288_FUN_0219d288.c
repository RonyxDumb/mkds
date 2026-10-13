/* Decompiled C draft; module arm9_ov000; ROM address 0219d288. No matching claim. */
#include "types.h"
#include "deps/0219d288_FUN_0219d288.h"

void FUN_0219d288(int param_1,int param_2,undefined4 param_3)

{
  code *pcVar1;
  
  if (*DAT_0219d2c0 != 0) {
    func_0x0214d168(param_1 + param_2 * 0xc,0);
    pcVar1 = *(code **)(*DAT_0219d2c0 + 0x3c);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(param_2,param_3,*(undefined4 *)(*DAT_0219d2c0 + 0x40));
    }
  }
  return;
}

