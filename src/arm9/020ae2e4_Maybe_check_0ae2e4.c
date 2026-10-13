/* Decompiled C draft; module arm9; ROM address 020ae2e4. No matching claim. */
#include "types.h"
#include "deps/020ae2e4_Maybe_check_0ae2e4.h"

undefined4 Maybe_check_0ae2e4(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

