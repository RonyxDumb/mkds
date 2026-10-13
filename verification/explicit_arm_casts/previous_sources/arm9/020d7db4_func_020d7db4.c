/* Decompiled C draft; module arm9; ROM address 020d7db4. No matching claim. */
#include "types.h"
#include "deps/020d7db4_func_020d7db4.h"

void func_020d7db4(int *param_1,undefined2 param_2,int param_3)

{
  *(undefined2 *)(param_1 + 2) = param_2;
  func_020d7e44((uint)*(ushort *)(param_1 + 2),
                *(int *)(*piRam020d7df0 + 8) + (uint)*(ushort *)(param_1 + 2) * 4);
  *param_1 = *piRam020d7df4 + (uint)*(ushort *)(param_1 + 2) * 0xc;
  param_1[1] = param_3;
  func_020d90a8(param_1,0,1);
  return;
}

