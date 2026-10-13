/* Decompiled C draft; module arm9; ROM address 0200c3fc. No matching claim. */
#include "types.h"
#include "deps/0200c3fc_func_0200c3fc.h"

void func_0200c3fc(int param_1)

{
  if (*piRam0200c428 != 0) {
    Mem_CpuFill8((uint *)(uintptr_t)(*piRam0200c428 + (param_1 + -1) * 0x20),0,0x1e);
    *(undefined4 *)(*piRam0200c428 + (param_1 + -1) * 4 + iRam0200c42c) = 0;
  }
  return;
}

