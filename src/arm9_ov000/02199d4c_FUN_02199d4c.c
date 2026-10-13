/* Decompiled C draft; module arm9_ov000; ROM address 02199d4c. No matching claim. */
#include "types.h"
#include "deps/02199d4c_FUN_02199d4c.h"

undefined4 FUN_02199d4c(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_48 [32];
  undefined1 auStack_28 [32];
  
  if (*(int *)(param_1 + 0xc) != 2) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  if (0x1f < param_3) {
    FUN_02197b34(auStack_48);
    FUN_02197be0(auStack_28);
    FUN_02197b34(param_1 + 0x68,(int)(uintptr_t)(auStack_28));
    iVar1 = FUN_02198eb0(param_1,(undefined4)(uintptr_t)(auStack_48),(undefined4)(uintptr_t)(auStack_28));
    if (iVar1 == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0xc) = 3;
    return 1;
  }
  iVar1 = FUN_02199fa4();
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

