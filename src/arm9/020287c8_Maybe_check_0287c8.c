/* Decompiled C draft; module arm9; ROM address 020287c8. No matching claim. */
#include "types.h"
#include "deps/020287c8_Maybe_check_0287c8.h"

undefined4 Maybe_check_0287c8(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

