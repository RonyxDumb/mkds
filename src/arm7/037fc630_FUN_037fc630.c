/* Decompiled C draft; module arm7; ROM address 037fc630. No matching claim. */
#include "types.h"
#include "deps/037fc630_FUN_037fc630.h"

void FUN_037fc630(int param_1,undefined4 param_2,undefined4 param_3,undefined1 param_4)

{
  *(undefined4 *)(param_1 + 0x50) = 0;
  *(undefined4 *)(param_1 + 0x48) = param_2;
  *(undefined4 *)(param_1 + 0x4c) = param_3;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined1 *)(param_1 + 0x22) = param_4;
  *(undefined2 *)(param_1 + 0x24) = 0x7f;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) & 0xfd;
  *(byte *)(param_1 + 3) = *(byte *)(param_1 + 3) | 4;
  *(undefined1 *)(param_1 + 8) = 0x3c;
  *(undefined1 *)(param_1 + 5) = 0x3c;
  *(undefined1 *)(param_1 + 9) = 0x7f;
  *(undefined1 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 0xc) = 0;
  *(undefined2 *)(param_1 + 6) = 0;
  *(undefined2 *)(param_1 + 0xe) = 0;
  *(undefined1 *)(param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 4) = 0x7f;
  *(undefined2 *)(param_1 + 0x32) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  FUN_037fcc70();
  FUN_037fcc54(param_1,0x7f);
  FUN_037fcc4c(param_1,0x7f);
  FUN_037fcc30(param_1,0x7f);
  FUN_037fc800((undefined1 *)(uintptr_t)(param_1 + 0x28));
  return;
}

