/* Decompiled C draft; module arm9_ov000; ROM address 021a6ce4. No matching claim. */
#include "types.h"
#include "deps/021a6ce4_FUN_021a6ce4.h"

undefined4 FUN_021a6ce4(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = func_0x0200fca0();
  iVar2 = FUN_021a5b30();
  uVar3 = 0;
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + DAT_021a6d18) == 9) {
      uVar3 = FUN_021a6c68();
    }
  }
  func_0x0200fcb4(uVar1);
  return uVar3;
}

