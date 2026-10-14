/* Decompiled C draft; module arm9; ROM address 020b2ac8. No matching claim. */
#include "types.h"
#include "deps/020b2ac8_Maybe_check_0b2ac8.h"

undefined4 Maybe_check_0b2ac8(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

