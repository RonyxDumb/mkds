/* Decompiled C draft; module arm9; ROM address 02112b30. No matching claim. */
#include "types.h"
#include "deps/02112b30_func_02112b30.h"

void func_02112b30(void)

{
  int iVar1;
  
  iVar1 = Bright_IsBothScreensFadedIn();
  if (iVar1 != 0) {
    func_021134b8();
  }
  return;
}

