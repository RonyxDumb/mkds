/* Decompiled C draft; module arm9_ov000; ROM address 02196480. No matching claim. */
#include "types.h"
#include "deps/02196480_FUN_02196480.h"

int FUN_02196480(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  undefined1 auStack_38 [36];
  
  if (param_5 == 0) {
    param_5 = DAT_021964dc;
  }
  iVar1 = FUN_02193c20(param_1,param_3,0xc9,(undefined4 *)(uintptr_t)(param_2));
  if (iVar1 == 0) {
    func_0x02135014((undefined4)(uintptr_t)(auStack_38),DAT_021964e0,1,param_4);
    iVar1 = FUN_02190968(param_1,param_3,(undefined4)(uintptr_t)(auStack_38));
    if ((iVar1 == 0) && (iVar1 = FUN_02193b88(param_1,param_3,param_5,0xffffffff), iVar1 == 0)) {
      iVar1 = 0;
    }
  }
  return iVar1;
}

