/* Decompiled C draft; module arm9_ov000; ROM address 0218d134. No matching claim. */
#include "types.h"
#include "deps/0218d134_FUN_0218d134.h"

undefined4 FUN_0218d134(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  undefined4 local_18;
  undefined4 local_14;
  
  local_18 = param_2;
  uVar1 = FUN_0218b3f4();
  puVar2 = (undefined4 *)FUN_0218de28((int *)(uintptr_t)(uVar1),(undefined4)(uintptr_t)(&local_18));
  if (puVar2 != (undefined4 *)0x0) {
    puVar2[1] = puVar2[1] + 1;
    return *puVar2;
  }
  local_18 = FUN_0218e880(param_2);
  local_14 = 1;
  uVar1 = FUN_0218b3f4(param_1);
  FUN_0218def0((int *)(uintptr_t)(uVar1),(undefined4)(uintptr_t)(&local_18));
  return local_18;
}

