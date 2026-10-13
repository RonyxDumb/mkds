/* Decompiled C draft; module arm9; ROM address 0200c65c. No matching claim. */
#include "types.h"
#include "deps/0200c65c_Fifo13Handler_1_from_thumb.h"

void Fifo13Handler_1_from_thumb(undefined4 param_1,uint param_2)

{
  int iVar1;
  
  if ((param_2 & 0x3f) == 0x11) {
    iVar1 = 0;
    if ((code *)*puRam0200c68c != (code *)0x0) {
      iVar1 = (*(code *)*puRam0200c68c)();
    }
    if (iVar1 != 0) {
      func_0200c648();
      return;
    }
  }
  else {
    Os_Terminate();
  }
  return;
}

