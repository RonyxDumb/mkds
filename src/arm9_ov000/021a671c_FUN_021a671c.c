/* Decompiled C draft; module arm9_ov000; ROM address 021a671c. No matching claim. */
#include "types.h"
#include "deps/021a671c_FUN_021a671c.h"

void FUN_021a671c(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021a5b30();
  if (((iVar1 != 0) && (*(char *)(iVar1 + DAT_021a6780) == '\0')) &&
     (*(short *)(param_1 + 0x3c) == 0)) {
    iVar2 = FUN_021a6614(param_1 + 4);
    if (iVar2 == 0) {
      iVar2 = FUN_021a669c();
    }
    if ((iVar2 == 0) && (*(int *)(iVar1 + DAT_021a6784) == 1)) {
      iVar2 = FUN_021a666c();
    }
    if (iVar2 != 0) {
      *(undefined2 *)(iVar2 + 2) = param_2;
      func_0x0214d0a8((undefined4 *)(uintptr_t)(param_1),(undefined4 *)(uintptr_t)(iVar2 + 0x10),0xc0);
      FUN_021a6558(iVar2);
    }
  }
  return;
}

