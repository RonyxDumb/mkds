/* Decompiled C draft; module arm9; ROM address 020cec88. No matching claim. */
#include "types.h"
#include "deps/020cec88_func_020cec88.h"

void func_020cec88(void)

{
  int iVar1;
  
  iVar1 = func_02032280();
  if (iVar1 == 1) {
    iVar1 = GetGlobalCA_from_thumb();
    if (*(int *)(iVar1 + 200) == 2) {
      func_020ccc74(0xf,0x1f);
    }
    else if (*(int *)(iVar1 + 200) == 3) {
      func_020ccc74(8,0x1f);
    }
  }
  else if (iVar1 == 2) {
    func_020ccc74(0,0x1f);
  }
  else if (iVar1 == 3) {
    func_020ccc74(0x1b,0x1f);
  }
  return;
}

