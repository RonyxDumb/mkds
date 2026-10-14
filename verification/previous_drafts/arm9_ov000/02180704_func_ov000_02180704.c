/* Decompiled C draft; module arm9_ov000; ROM address 02180704. No matching claim. */
#include "types.h"
#include "deps/02180704_func_ov000_02180704.h"

void func_ov000_02180704(void)

{
  if (*(code **)(*piRam02180720 + 0x28) != (code *)0x0) {
    (**(code **)(*piRam02180720 + 0x28))();
  }
  func_0x021258f0();
  return;
}

