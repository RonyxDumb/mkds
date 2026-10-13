/* Decompiled C draft; module arm9; ROM address 0211b224. No matching claim. */
#include "types.h"
#include "deps/0211b224_func_0211b224.h"

void func_0211b224(void)

{
  int iVar1;
  
  iVar1 = Bright_IsBothScreensFadedIn();
  if (iVar1 != 0) {
    func_0211bad8();
  }
  return;
}

