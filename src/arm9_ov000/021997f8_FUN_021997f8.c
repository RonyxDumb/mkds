/* Decompiled C draft; module arm9_ov000; ROM address 021997f8. No matching claim. */
#include "types.h"
#include "deps/021997f8_FUN_021997f8.h"

void FUN_021997f8(int param_1)

{
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0x90) == 0) {
    *(undefined4 *)(param_1 + 0x90) = 1;
    uVar1 = FUN_0218e8c4();
    *(undefined4 *)(param_1 + 0x94) = uVar1;
  }
  return;
}

