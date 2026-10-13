/* Decompiled C draft; module arm9; ROM address 0202ee20. No matching claim. */
#include "types.h"
#include "deps/0202ee20_func_0202ee20.h"

int func_0202ee20(int param_1,int param_2)

{
  return (int)*(short *)(*(int *)(*piRam0202ee38 + 8) + param_2 * 0x40 + 0xe) -
         (int)*(short *)(*(int *)(*piRam0202ee38 + 8) + param_1 * 0x40 + 0xe);
}

