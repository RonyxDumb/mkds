/* Decompiled C draft; module arm9; ROM address 0212a4bc. No matching claim. */
#include "types.h"
#include "deps/0212a4bc_func_0212a4bc.h"

void func_0212a4bc(void)

{
  undefined1 auStack_1e [30];
  
  Mem_CpuFill16(0,auStack_1e,0x1a);
  CopyMemory16(*piRam0212a4f0 + 0x2c,auStack_1e,0x18);
  func_020ab7a4(auStack_1e);
  return;
}

