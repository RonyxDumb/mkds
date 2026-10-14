/* Decompiled C draft; module arm9; ROM address 020365bc. No matching claim. */
#include "types.h"
#include "deps/020365bc_SetExecuteStart.h"

void SetExecuteStart(undefined4 param_1)

{
  ExecutionContext_SetFunction(uRam020365e8,param_1);
  ExecutionContext_Execute(uRam020365e8,uRam020365ec);
  return;
}

