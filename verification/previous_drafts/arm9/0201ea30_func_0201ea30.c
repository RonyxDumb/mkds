/* Decompiled C draft; module arm9; ROM address 0201ea30. No matching claim. */
#include "types.h"
#include "deps/0201ea30_func_0201ea30.h"

int func_0201ea30(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < (int)(uint)*(ushort *)(param_1 + 6))) {
    return param_1 + 8 + param_2 * 8;
  }
  return 0;
}

