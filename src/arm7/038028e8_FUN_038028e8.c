/* Decompiled C draft; module arm7; ROM address 038028e8. No matching claim. */
#include "types.h"
#include "deps/038028e8_FUN_038028e8.h"

void FUN_038028e8(int param_1)

{
  if (param_1 == 1) {
    FUN_0380277c(0x10);
  }
  else if (param_1 == 2) {
    FUN_0380277c(0x20);
    FUN_038027a8(0x10);
  }
  else if (param_1 == 3) {
    FUN_038027a8(0x30);
  }
  else {
    FUN_037fb000();
  }
  *DAT_0380294c = param_1;
  return;
}

