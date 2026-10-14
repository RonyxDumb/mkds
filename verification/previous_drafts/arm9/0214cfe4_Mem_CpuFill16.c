/* Decompiled C draft; module arm9; ROM address 0214cfe4. No matching claim. */
#include "types.h"
#include "deps/0214cfe4_Mem_CpuFill16.h"

void Mem_CpuFill16(undefined2 param_1,int param_2,int param_3)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 < param_3; iVar1 = iVar1 + 2) {
    *(undefined2 *)(param_2 + iVar1) = param_1;
  }
  return;
}

