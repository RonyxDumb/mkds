/* Decompiled C draft; module arm9; ROM address 021052fc. No matching claim. */
#include "types.h"
#include "deps/021052fc_func_021052fc.h"

void func_021052fc(int param_1)

{
  *(short *)(param_1 + 0xa0) = *(short *)(param_1 + 0xa0) + 1;
  if (299 < *(ushort *)(param_1 + 0xa0)) {
    *(undefined2 *)(param_1 + 0xa0) = 0;
  }
  *(short *)(param_1 + 0xa2) = *(short *)(param_1 + 0xa2) + 1;
  if (0x81 < *(ushort *)(param_1 + 0xa2)) {
    *(undefined2 *)(param_1 + 0xa2) = 0;
  }
  return;
}

