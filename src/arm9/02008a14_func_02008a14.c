/* Decompiled C draft; module arm9; ROM address 02008a14. No matching claim. */
#include "types.h"
#include "deps/02008a14_func_02008a14.h"

void func_02008a14(void)

{
  int *piVar1;
  
  if (*(short *)(*piRam02008a44 + 6) != 0) {
    if ((code *)*puRam02008a48 != (code *)0x0) {
      (*(code *)*puRam02008a48)();
    }
    piVar1 = piRam02008a44;
    *(undefined2 *)(*piRam02008a44 + 0xc) = 1;
    *(undefined2 *)(*piVar1 + 6) = 0;
    *(undefined2 *)(*piVar1 + 10) = 0;
  }
  return;
}

