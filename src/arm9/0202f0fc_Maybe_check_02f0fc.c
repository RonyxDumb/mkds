/* Decompiled C draft; module arm9; ROM address 0202f0fc. No matching claim. */
#include "types.h"
#include "deps/0202f0fc_Maybe_check_02f0fc.h"

undefined4 Maybe_check_02f0fc(int param_1)

{
  if ((*(short *)(param_1 + 0xc) == 0) && (*(short *)(param_1 + 4) != 0)) {
    return 1;
  }
  return 0;
}

