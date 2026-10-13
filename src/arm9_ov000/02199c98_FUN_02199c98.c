/* Decompiled C draft; module arm9_ov000; ROM address 02199c98. No matching claim. */
#include "types.h"
#include "deps/02199c98_FUN_02199c98.h"

undefined4 FUN_02199c98(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined1 auStack_30 [36];
  
  if (*(int *)(param_1 + 0xc) != 0) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  if (param_3 < 0x40) {
    iVar1 = FUN_02199fa4();
    if (iVar1 != 0) {
      return 1;
    }
    return 0;
  }
  iVar1 = FUN_02197b08(param_2,param_1 + 0x68);
  if (iVar1 != 0) {
    FUN_02197b34((int)(uintptr_t)(auStack_30),param_2 + 0x20);
    iVar1 = FUN_02198e44(param_1,(undefined4)(uintptr_t)(auStack_30),*(undefined4 *)(param_1 + 0x38),
                         *(undefined4 *)(param_1 + 0x3c));
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x38) != 0) {
      FUN_021a3668();
      *(undefined4 *)(param_1 + 0x38) = 0;
    }
    *(undefined4 *)(param_1 + 0xc) = 1;
    return 1;
  }
  iVar1 = FUN_02199fa4(param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

