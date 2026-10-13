/* Decompiled C draft; module arm9; ROM address 020ec504. No matching claim. */
#include "types.h"
#include "deps/020ec504_func_020ec504.h"

void func_020ec504(int param_1)

{
  undefined2 uVar1;
  
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020ec534;
  uVar1 = func_020d5344((int)*(short *)(param_1 + 100));
  *(undefined2 *)(param_1 + 100) = uVar1;
  return;
}

