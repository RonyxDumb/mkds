/* Decompiled C draft; module arm7; ROM address 0600044c. No matching claim. */
#include "types.h"
#include "deps/0600044c_FUN_0600044c.h"

void FUN_0600044c(undefined2 *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  
  uVar1 = param_2 + 8 & 3;
  uVar2 = *(uint *)(param_2 + 8 & 0xfffffffc);
  *(uint *)(param_1 + 2) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
  param_1[4] = *(undefined2 *)(param_2 + 0xc);
  if (*(short *)(param_2 + 0x12) == 0) {
    bVar3 = 0;
  }
  else {
    bVar3 = 2;
  }
  if (*(short *)(param_2 + 0x14) == 0) {
    bVar5 = 0;
  }
  else {
    bVar5 = 4;
  }
  if (*(short *)(param_2 + 0x16) == 0) {
    bVar4 = 0;
  }
  else {
    bVar4 = 8;
  }
  *(byte *)((int)param_1 + 0xb) = bVar4 | bVar5 | *(short *)(param_2 + 0xe) != 0 | bVar3;
  *(char *)(param_1 + 5) = (char)*(undefined2 *)(param_2 + 4);
  *param_1 = 1;
  param_1[6] = *(undefined2 *)(param_2 + 0x34);
  param_1[7] = *(undefined2 *)(param_2 + 0x36);
  if (*(byte *)(param_1 + 5) != 0) {
    thunk_FUN_037fb390(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                       *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20,param_1 + 8,
                       *(byte *)(param_1 + 5) + 1 & 0xfffffffe);
  }
  return;
}

