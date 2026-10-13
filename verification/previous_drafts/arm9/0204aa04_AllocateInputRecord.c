/* Decompiled C draft; module arm9; ROM address 0204aa04. No matching claim. */
#include "types.h"
#include "deps/0204aa04_AllocateInputRecord.h"

void AllocateInputRecord(undefined4 *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = Mem_AllocateHeap(param_2,uRam0204aa24);
  *param_1 = uVar1;
  return;
}

