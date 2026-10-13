/* Decompiled C draft; module arm9; ROM address 020cb99c. No matching claim. */
#include "types.h"
#include "deps/020cb99c_GetActiveExecutionContextHeapHandle.h"

void GetActiveExecutionContextHeapHandle(void)

{
  GetActiveExecutionContext();
  ExecutionContext_GetHeapHandle();
  return;
}

