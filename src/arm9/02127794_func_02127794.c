/* Decompiled C draft; module arm9; ROM address 02127794. No matching claim. */
#include "types.h"
#include "deps/02127794_func_02127794.h"

undefined4 func_02127794(void)

{
  if (*(int *)(*piRam021277a8 + 0x20) != 0) {
    return 0xffffffff;
  }
  return *(undefined4 *)(*piRam021277a8 + 0x18);
}

