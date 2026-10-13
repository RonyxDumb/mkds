/* Decompiled C draft; module arm9; ROM address 0212a448. No matching claim. */
#include "types.h"
#include "deps/0212a448_func_0212a448.h"

void func_0212a448(void)

{
  undefined1 auStack_1e [30];
  
  Mem_CpuFill16(0,auStack_1e,0x16);
  CopyMemory16(*(int *)*puRam0212a480 + 0xc,auStack_1e,0x14);
  func_020ab7a4(auStack_1e);
  return;
}

