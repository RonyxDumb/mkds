/* Decompiled C draft; module arm9; ROM address 021240d4. No matching claim. */
#include "types.h"
#include "deps/021240d4_func_021240d4.h"

int func_021240d4(int param_1,undefined4 param_2,int param_3,int param_4)

{
  return (int)(*(ushort *)
                (*(int *)(*(int *)(*(int *)((uint)*(ushort *)(param_4 + 6) * 0x40 +
                                            param_3 + param_1 * 0x40 + 0x3c) + 0x44) + 4) + 4) &
              uRam021240fc) >> 10;
}

