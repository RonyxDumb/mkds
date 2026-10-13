/* Decompiled C draft; module arm9; ROM address 020ce928. No matching claim. */
#include "types.h"
#include "deps/020ce928_func_020ce928.h"

void func_020ce928(void)

{
  int iVar1;
  
  iVar1 = func_0211a7bc();
  if (iVar1 == 1) {
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 0xf0) == 2) {
      iVar1 = GetGlobalCA_from_thumb();
      *(undefined4 *)(iVar1 + 0xd0) = 0x14;
      func_020ccc74(0x1d,0x1f);
    }
    else {
      func_020ccc74(0xb,0x1f);
    }
  }
  else if (iVar1 == 2) {
    func_020ccc74(9,0x1f);
  }
  return;
}

