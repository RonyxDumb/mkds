/* Decompiled C draft; module arm9; ROM address 020ceb88. No matching claim. */
#include "types.h"
#include "deps/020ceb88_func_020ceb88.h"

void func_020ceb88(void)

{
  int iVar1;
  
  iVar1 = func_0211a7bc();
  if (iVar1 == 1) {
    iVar1 = func_020cebe4();
    if (iVar1 != 0) {
      iVar1 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar1 + 0xf0) = 2;
    }
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 0xf0) == 2) {
      iVar1 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar1 + 0xd0) = 0x2c;
      func_020ccc74(0x1d,0x1f);
    }
    else {
      func_020ccc74(0x11,0x1f);
    }
  }
  else if (iVar1 == 2) {
    func_020ccc74(0xf,0x1f);
  }
  return;
}

