/* Decompiled C draft; module arm9; ROM address 02079a3c. No matching claim. */
#include "types.h"
#include "deps/02079a3c_StructAD00Sub_Initialize_from_thumb.h"

void StructAD00Sub_Initialize_from_thumb(undefined4 *param_1)

{
  *param_1 = 0xffffffff;
  param_1[1] = 0xffffffff;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  StructAD00SubSub_Create_from_thumb(param_1 + 9);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  *(undefined2 *)(param_1 + 0x1a) = 0;
  param_1[0x2b] = 0;
  param_1[0x2c] = 0;
  *(undefined2 *)((int)param_1 + 0x6e) = 0;
  *(undefined2 *)(param_1 + 0x1b) = *(undefined2 *)((int)param_1 + 0x6e);
  *(undefined2 *)((int)param_1 + 0x6a) = *(undefined2 *)(param_1 + 0x1b);
  *(undefined2 *)(param_1 + 0x1d) = 0;
  *(undefined2 *)((int)param_1 + 0x72) = *(undefined2 *)(param_1 + 0x1d);
  *(undefined2 *)(param_1 + 0x1c) = *(undefined2 *)((int)param_1 + 0x72);
  *(undefined2 *)((int)param_1 + 0x7a) = 0;
  *(undefined2 *)(param_1 + 0x1e) = *(undefined2 *)((int)param_1 + 0x7a);
  *(undefined2 *)((int)param_1 + 0x76) = *(undefined2 *)(param_1 + 0x1e);
  *(undefined2 *)(param_1 + 0x20) = 0;
  *(undefined2 *)((int)param_1 + 0x7e) = *(undefined2 *)(param_1 + 0x20);
  *(undefined2 *)(param_1 + 0x1f) = *(undefined2 *)((int)param_1 + 0x7e);
  *(undefined2 *)((int)param_1 + 0x86) = 0;
  *(undefined2 *)(param_1 + 0x21) = *(undefined2 *)((int)param_1 + 0x86);
  *(undefined2 *)((int)param_1 + 0x82) = *(undefined2 *)(param_1 + 0x21);
  *(undefined2 *)(param_1 + 0x23) = 0;
  *(undefined2 *)((int)param_1 + 0x8a) = *(undefined2 *)(param_1 + 0x23);
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)((int)param_1 + 0x8a);
  *(undefined2 *)((int)param_1 + 0x92) = 0;
  *(undefined2 *)(param_1 + 0x24) = *(undefined2 *)((int)param_1 + 0x92);
  *(undefined2 *)((int)param_1 + 0x8e) = *(undefined2 *)(param_1 + 0x24);
  *(undefined2 *)(param_1 + 0x25) = 0;
  return;
}

