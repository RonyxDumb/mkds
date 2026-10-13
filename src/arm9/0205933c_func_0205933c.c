/* Decompiled C draft; module arm9; ROM address 0205933c. No matching claim. */
#include "types.h"
#include "deps/0205933c_func_0205933c.h"

void func_0205933c(void)

{
  int iVar1;
  
  iVar1 = func_0210e5e4(*(undefined4 *)(*piRam02059374 + iRam02059378),
                        *(undefined4 *)(*piRam02059374 + iRam0205937c));
  if (*psRam02059380 == 2) {
    MaybeReloadRacersSfx(0);
  }
  if (iVar1 == 0) {
    *(undefined1 *)(*piRam02059374 + iRam02059384) = 1;
  }
  return;
}

