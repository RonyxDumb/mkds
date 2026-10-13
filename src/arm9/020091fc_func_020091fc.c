/* Decompiled C draft; module arm9; ROM address 020091fc. No matching claim. */
#include "types.h"
#include "deps/020091fc_func_020091fc.h"

undefined4 func_020091fc(int param_1)

{
  if (((*(byte *)(param_1 + 0x4b) & 2) != 0) && (*(short *)(param_1 + 0x40) == 1)) {
    return 1;
  }
  return 0;
}

