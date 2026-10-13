/* Decompiled C draft; module arm9; ROM address 02099278. No matching claim. */
#include "types.h"
#include "deps/02099278_func_02099278.h"

void func_02099278(int param_1)

{
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam020992a8;
  func_020d2398();
  func_020d28e0(param_1);
  return;
}

