/* Decompiled C draft; module arm9; ROM address 0201808c. No matching claim. */
#include "types.h"
#include "deps/0201808c_Mem_Frame_Allocate.h"

void Mem_Frame_Allocate(int param_1,int param_2,int param_3)

{
  if (param_2 == 0) {
    param_2 = 1;
  }
  if (-1 < param_3) {
    Mem_Frame_AllocFromHead();
    return;
  }
  Mem_Frame_AllocFromTail(param_1 + 0x24,param_2 + 3U & 0xfffffffc,-param_3);
  return;
}

