/* Decompiled C draft; module arm9_ov000; ROM address 0218a950. No matching claim. */
#include "types.h"
#include "deps/0218a950_FUN_0218a950.h"

void FUN_0218a950(int param_1)

{
  if (*(int *)(param_1 + 0x10) != 0) {
    FUN_0218aa14((int *)(uintptr_t)(param_1),0);
    FUN_0218a9bc(param_1);
    if (0 < *(int *)(param_1 + 0x1c)) {
      FUN_0218a98c(param_1);
    }
    if (*(int *)(param_1 + 0x10) == 0) {
      (**(code **)(param_1 + 0x44))(param_1,2,0,*(undefined4 *)(param_1 + 0x48));
    }
  }
  return;
}

