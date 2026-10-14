/* Decompiled C draft; module arm9; ROM address 0201804c. No matching claim. */
#include "types.h"
#include "deps/0201804c_Mem_ResetFrameHeap.h"

void Mem_ResetFrameHeap(undefined4 param_1,uint param_2)

{
  if ((param_2 & 1) != 0) {
    Mem_Frame_ResetFromHead();
  }
  if ((param_2 & 2) != 0) {
    Mem_Frame_ResetFromTail(param_1);
    return;
  }
  return;
}

