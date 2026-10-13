/* Decompiled C draft; module arm9_ov003; ROM address 021cf93c. No matching claim. */
#include "types.h"
#include "deps/021cf93c_FUN_021cf93c.h"

void FUN_021cf93c(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  FUN_021cf36c(2);
  iVar1 = func_0x02009cc8(param_2);
  if (iVar1 != 0) {
    FUN_021cf36c(7);
    return;
  }
  iVar1 = FUN_021cf8ac((int *)(uintptr_t)(param_1));
  if (iVar1 == 0) {
    func_0x0200fd1c();
  }
  return;
}

