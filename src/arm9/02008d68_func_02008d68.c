/* Decompiled C draft; module arm9; ROM address 02008d68. No matching claim. */
#include "types.h"
#include "deps/02008d68_func_02008d68.h"

void func_02008d68(int param_1)

{
  int iVar1;
  
  iVar1 = iRam02008dac * param_1;
  if (*(char *)(*piRam02008db0 + 5) != *(char *)(*piRam02008db4 + iVar1 + iRam02008db8)) {
    func_0200895c();
    func_02008a4c(param_1);
    *(undefined1 *)(*piRam02008db4 + iVar1 + iRam02008db8) = *(undefined1 *)(*piRam02008db0 + 5);
  }
  return;
}

