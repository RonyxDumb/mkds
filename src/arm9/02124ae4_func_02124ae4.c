/* Decompiled C draft; module arm9; ROM address 02124ae4. No matching claim. */
#include "types.h"
#include "deps/02124ae4_func_02124ae4.h"

undefined4 func_02124ae4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  iVar1 = CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_2),*(uint *)(param_3 + param_1 * 8 + 0xc) & 0xffff);
  if ((int)(**(ushort **)(iVar1 + 4) & uRam02124b18) >> 10 == 1) {
    return 1;
  }
  return 0;
}

