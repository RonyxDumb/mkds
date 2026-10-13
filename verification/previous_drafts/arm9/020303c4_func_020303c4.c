/* Decompiled C draft; module arm9; ROM address 020303c4. No matching claim. */
#include "types.h"
#include "deps/020303c4_func_020303c4.h"

void func_020303c4(void)

{
  func_0204f7f4();
  Mem_DestroyHeap(*(undefined4 *)(*piRam020303e4 + 0x3c));
  *piRam020303e4 = 0;
  return;
}

