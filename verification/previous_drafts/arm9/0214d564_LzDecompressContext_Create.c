/* Decompiled C draft; module arm9; ROM address 0214d564. No matching claim. */
#include "types.h"
#include "deps/0214d564_LzDecompressContext_Create.h"

void LzDecompressContext_Create(undefined4 *param_1,undefined4 param_2,uint param_3)

{
  *param_1 = param_2;
  param_1[1] = (*(uint *)(param_3 & 0xfffffffc) >> (param_3 & 3) * 8 |
               *(uint *)(param_3 & 0xfffffffc) << (param_3 & 3) * -8 + 0x20) >> 8;
  *(undefined1 *)((int)param_1 + 0xb) = 0;
  *(undefined1 *)(param_1 + 3) = 0;
  *(undefined1 *)((int)param_1 + 0xd) = 0;
  *(undefined1 *)((int)param_1 + 0xe) = 0;
  *(undefined2 *)(param_1 + 2) = 0;
  *(undefined1 *)((int)param_1 + 10) = 0;
  return;
}

