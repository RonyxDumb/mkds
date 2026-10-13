/* Decompiled C draft; module arm9; ROM address 020092a4. No matching claim. */
#include "types.h"
#include "deps/020092a4_func_020092a4.h"

void func_020092a4(void)

{
  Mem_CpuFastMemorySet(0,(undefined4 *)(uintptr_t)(*piRam020092c8),uRam020092cc);
  *(undefined2 *)(*piRam020092c8 + 0xc) = 1;
  return;
}

