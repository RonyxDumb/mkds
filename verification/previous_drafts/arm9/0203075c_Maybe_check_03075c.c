/* Decompiled C draft; module arm9; ROM address 0203075c. No matching claim. */
#include "types.h"
#include "deps/0203075c_Maybe_check_03075c.h"

undefined4 Maybe_check_03075c(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

