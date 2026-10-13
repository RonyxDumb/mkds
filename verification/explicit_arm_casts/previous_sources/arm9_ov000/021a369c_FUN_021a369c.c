/* Decompiled C draft; module arm9_ov000; ROM address 021a369c. No matching claim. */
#include "types.h"
#include "deps/021a369c_FUN_021a369c.h"

int FUN_021a369c(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = (*(code *)*DAT_021a36e8)(param_1,param_4,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_2 != 0) {
    func_0x0214d1fc(param_2,iVar1,param_4);
    (*(code *)*DAT_021a36ec)(param_1,param_2,param_3);
  }
  return iVar1;
}

