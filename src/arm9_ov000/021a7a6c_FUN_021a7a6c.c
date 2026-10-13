/* Decompiled C draft; module arm9_ov000; ROM address 021a7a6c. No matching claim. */
#include "types.h"
#include "deps/021a7a6c_FUN_021a7a6c.h"

int FUN_021a7a6c(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 100);
  uVar1 = func_0x0200fca0();
  iVar2 = *(int *)(iVar3 + 0xf8);
  if (iVar2 != 0) {
    *(undefined4 *)(iVar3 + 0xf8) = 0;
    FUN_021adf00(iVar2);
  }
  func_0x0200fcb4(uVar1);
  return iVar2;
}

