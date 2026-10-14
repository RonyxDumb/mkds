/* Decompiled C draft; module arm9; ROM address 020ace68. No matching claim. */
#include "types.h"
#include "deps/020ace68_Maybe_check_0ace68.h"

undefined4 Maybe_check_0ace68(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

