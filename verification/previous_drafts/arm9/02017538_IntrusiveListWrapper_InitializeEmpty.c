/* Decompiled C draft; module arm9; ROM address 02017538. No matching claim. */
#include "types.h"
#include "deps/02017538_IntrusiveListWrapper_InitializeEmpty.h"

void IntrusiveListWrapper_InitializeEmpty(undefined4 *param_1,undefined2 param_2)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined2 *)((int)param_1 + 10) = param_2;
  return;
}

