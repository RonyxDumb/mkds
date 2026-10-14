/* Decompiled C draft; module arm9; ROM address 0201694c. No matching claim. */
#include "types.h"
#include "deps/0201694c_StructTEQ_IsCounterEmpty.h"

bool StructTEQ_IsCounterEmpty(int param_1)

{
  return *(short *)(param_1 + 0xc) == 0;
}

