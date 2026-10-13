/* Decompiled C draft; module arm9; ROM address 020cec24. No matching claim. */
#include "types.h"
#include "deps/020cec24_func_020cec24.h"

void func_020cec24(void)

{
  int iVar1;
  
  iVar1 = func_02026120();
  if (iVar1 != 1) {
    if (iVar1 == 2) {
      func_020ccc74(0xe,0x1f);
      return;
    }
    if (iVar1 != 3) {
      return;
    }
  }
  func_020ccc74(0x10,0x1f);
  return;
}

