/* Decompiled C draft; module arm9_ov000; ROM address 02199554. No matching claim. */
#include "types.h"
#include "deps/02199554_FUN_02199554.h"

undefined4 FUN_02199554(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 7) {
    return 1;
  }
  iVar1 = FUN_02199fb0(param_1,2,*(int *)(param_1 + 0xc) != 6);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}

