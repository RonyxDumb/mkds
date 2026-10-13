/* Decompiled C draft; module arm9_ov000; ROM address 021a6fc0. No matching claim. */
#include "types.h"
#include "deps/021a6fc0_FUN_021a6fc0.h"

undefined4 FUN_021a6fc0(undefined4 param_1,int param_2)

{
  undefined4 local_38;
  undefined1 auStack_34 [4];
  undefined1 auStack_30 [36];
  
  if (*(char *)(param_2 + 0xd) == '\0') {
    *(undefined4 *)(param_2 + 8) = 0;
    local_38 = FUN_021a7008();
  }
  else {
    func_0x0200eb90((uint *)(void *)(auStack_30),(uint)(uintptr_t)(auStack_34),1);
    *(undefined1 **)(param_2 + 8) = auStack_30;
    FUN_021a7008(param_1,param_2);
    func_0x0200ea3c((int)(uintptr_t)(auStack_30),&local_38,1);
  }
  return local_38;
}

