/* Decompiled C draft; module arm9; ROM address 020ce83c. No matching claim. */
#include "types.h"
#include "deps/020ce83c_func_020ce83c.h"

void func_020ce83c(void)

{
  int iVar1;
  
  iVar1 = func_02117418();
  if (iVar1 == 1) {
    func_020ccc74(0xc,0x1f);
  }
  else if (iVar1 == 2) {
    func_020ccc74(10,0x1f);
  }
  else if (iVar1 == 3) {
    iVar1 = func_020ce8bc();
    if (iVar1 == 0) {
      func_020ccc74(0,0x1f);
    }
    else {
      func_020ccc74(0xe,0x1f);
    }
    func_020ce8a8(0);
    func_020ce894(1);
  }
  return;
}

