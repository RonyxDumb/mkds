/* Decompiled C draft; module arm9; ROM address 02046bcc. No matching claim. */
#include "types.h"
#include "deps/02046bcc_StateDualHandler_SetState.h"

void StateDualHandler_SetState(int param_1,undefined2 param_2)

{
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined2 *)(param_1 + 0x12) = 1;
  *(undefined2 *)(param_1 + 0xe) = param_2;
  *(undefined2 *)(param_1 + 0x10) = param_2;
  return;
}

