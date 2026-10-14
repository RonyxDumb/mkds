/* Decompiled C draft; module arm9; ROM address 020608fc. No matching claim. */
#include "types.h"
#include "deps/020608fc_func_020608fc.h"

undefined4 func_020608fc(undefined4 param_1,undefined4 param_2)

{
  undefined1 auStack_30 [14];
  undefined1 auStack_22 [20];
  byte local_e;
  
  GlobalZ_GetOI(param_1,(int)(uintptr_t)(auStack_30));
  if ((int)((uint)local_e << 0x1f) < 0) {
    Mem_CpuCopy8((ushort *)(void *)(auStack_22),(uint *)(uintptr_t)(param_2),0x14);
    return 1;
  }
  return 0;
}

