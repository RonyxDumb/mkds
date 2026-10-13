/* Decompiled C draft; module arm7; ROM address 037fac14. No matching claim. */
#include "types.h"
#include "deps/037fac14_FUN_037fac14.h"

void FUN_037fac14(int param_1,int param_2)

{
  if (param_2 == 0) {
    FUN_037fb000();
  }
  if (param_1 != 0) {
    *(int *)(param_1 + 8) = param_2;
  }
  return;
}

