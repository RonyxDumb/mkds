/* Decompiled C draft; module arm9_ov000; ROM address 02199ad8. No matching claim. */
#include "types.h"
#include "deps/02199ad8_FUN_02199ad8.h"

undefined4 FUN_02199ad8(int param_1)

{
  int iVar1;
  
  iVar1 = FUN_02198b8c();
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = FUN_02199fb0(param_1,2,*(int *)(param_1 + 0xc) != 6);
  if (iVar1 == 0) {
    return 0;
  }
  return 1;
}

