/* Decompiled C draft; module arm9; ROM address 02114298. No matching claim. */
#include "types.h"
#include "deps/02114298_func_02114298.h"

void func_02114298(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined1 auStack_20 [20];
  
  func_020608fc(*(ushort *)(*(int *)(*piRam021142d0 + 4) + param_1 * 2) & 0xff,(undefined4)(uintptr_t)(auStack_20));
  Mem_CpuFill8((uint *)(uintptr_t)(param_2),0,param_3);
  CopyMemory16((int)(uintptr_t)(auStack_20),param_2,0x14);
  return;
}

