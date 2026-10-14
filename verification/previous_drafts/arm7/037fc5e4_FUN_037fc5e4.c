/* Decompiled C draft; module arm7; ROM address 037fc5e4. No matching claim. */
#include "types.h"
#include "deps/037fc5e4_FUN_037fc5e4.h"

void FUN_037fc5e4(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x10) = DAT_037fc62c;
  *(undefined1 *)(param_1 + 2) = 0;
  *(undefined4 *)(param_1 + 0x34) = param_2;
  FUN_037fc7f0(param_1 + 0x28);
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 2;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfe | 1;
  return;
}

