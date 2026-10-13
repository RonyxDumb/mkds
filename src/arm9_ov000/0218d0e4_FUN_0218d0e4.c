/* Decompiled C draft; module arm9_ov000; ROM address 0218d0e4. No matching claim. */
#include "types.h"
#include "deps/0218d0e4_FUN_0218d0e4.h"

void FUN_0218d0e4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_18 [3];
  
  local_18[0] = param_2;
  uVar1 = FUN_0218b3f4();
  iVar2 = FUN_0218de28((int *)(uintptr_t)(uVar1),(undefined4)(uintptr_t)(local_18));
  if (iVar2 == 0) {
    func_0x0213442c(DAT_0218d12c,DAT_0218d130,0,0xf4);
  }
  else {
    *(int *)(iVar2 + 4) = *(int *)(iVar2 + 4) + -1;
    if (*(int *)(iVar2 + 4) == 0) {
      uVar1 = FUN_0218b3f4(param_1);
      FUN_0218de8c((int *)(uintptr_t)(uVar1),(undefined4)(uintptr_t)(local_18));
    }
  }
  return;
}

