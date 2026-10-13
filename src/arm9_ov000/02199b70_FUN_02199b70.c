/* Decompiled C draft; module arm9_ov000; ROM address 02199b70. No matching claim. */
#include "types.h"
#include "deps/02199b70_FUN_02199b70.h"

undefined4 FUN_02199b70(int param_1)

{
  int iVar1;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    *(undefined4 *)(param_1 + 0xc) = 5;
    iVar1 = FUN_021982f4(param_1,0,0,0);
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_02199fa4();
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

