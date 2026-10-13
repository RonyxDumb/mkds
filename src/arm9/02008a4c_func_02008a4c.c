/* Decompiled C draft; module arm9; ROM address 02008a4c. No matching claim. */
#include "types.h"
#include "deps/02008a4c_func_02008a4c.h"

void func_02008a4c(uint param_1)

{
  int *piVar1;
  
  if (*(short *)(*piRam02008a8c + 6) == 0) {
    if ((code *)*puRam02008a90 != (code *)0x0) {
      (*(code *)*puRam02008a90)(*piRam02008a8c + iRam02008a94 + iRam02008a98 * param_1);
    }
    piVar1 = piRam02008a8c;
    *(undefined2 *)(*piRam02008a8c + 0xc) = 0x16;
    *(short *)(*piVar1 + 6) = (short)(1 << (param_1 & 0xff));
    *(short *)(*piVar1 + 8) = (short)uRam02008a9c;
  }
  return;
}

