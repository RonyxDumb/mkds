/* Decompiled C draft; module arm9; ROM address 02022438. No matching claim. */
#include "types.h"
#include "deps/02022438_func_02022438.h"

void func_02022438(int param_1)

{
  Mem_CpuFill16(0,param_1 + 4,0x18);
  *(undefined4 *)(param_1 + 4) = 0x1000;
  *(undefined4 *)(param_1 + 8) = 0x1000;
  return;
}

