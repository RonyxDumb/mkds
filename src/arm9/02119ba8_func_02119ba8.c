/* Decompiled C draft; module arm9; ROM address 02119ba8. No matching claim. */
#include "types.h"
#include "deps/02119ba8_func_02119ba8.h"

void func_02119ba8(void)

{
  int *piVar1;
  
  piVar1 = piRam02119bd0;
  *(undefined4 *)(*piRam02119bd0 + 0x38) = 4;
  *(undefined4 *)(*piVar1 + 0x3c) = 0;
  if (*psRam02119bd4 != 2) {
    NNSi_MaybeSndPlayerStartSeq(uRam02119bd8,0,5);
  }
  return;
}

