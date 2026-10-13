/* Decompiled C draft; module arm9; ROM address 020cb170. No matching claim. */
#include "types.h"
#include "deps/020cb170_Maybe_check_0cb170.h"

undefined4 Maybe_check_0cb170(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

