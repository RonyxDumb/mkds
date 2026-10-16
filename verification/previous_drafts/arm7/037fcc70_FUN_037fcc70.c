/* Decompiled C draft; module arm7; ROM address 037fcc70. No matching claim. */
#include "types.h"
#include "deps/037fcc70_FUN_037fcc70.h"

void FUN_037fcc70(int param_1,int param_2)

{
  if (param_2 < 0x6d) {
    *(char *)(param_1 + 0x1c) = -1 - (char)param_2;
  }
  else {
    *(undefined1 *)(param_1 + 0x1c) = *(undefined1 *)(DAT_037fcc90 + (0x7f - param_2));
  }
  return;
}

