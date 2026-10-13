/* Decompiled C draft; module arm9; ROM address 02046be8. No matching claim. */
#include "types.h"
#include "deps/02046be8_StateDualHandler_Create.h"

void StateDualHandler_Create
               (undefined4 *param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4)

{
  param_1[2] = param_4;
  *param_1 = param_2;
  *(undefined2 *)(param_1 + 3) = param_3;
  param_1[1] = 0;
  *(undefined2 *)((int)param_1 + 0x12) = 1;
  *(undefined2 *)((int)param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 4) = 0;
  return;
}

