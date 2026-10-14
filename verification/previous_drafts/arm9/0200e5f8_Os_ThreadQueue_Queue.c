/* Decompiled C draft; module arm9; ROM address 0200e5f8. No matching claim. */
#include "types.h"
#include "deps/0200e5f8_Os_ThreadQueue_Queue.h"

void Os_ThreadQueue_Queue(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  while ((uVar5 != 0 &&
         (uVar2 = uVar5 + 0x70 & 3, uVar4 = *(uint *)(uVar5 + 0x70 & 0xfffffffc),
         uVar3 = param_2 + 0x70 & 3, uVar1 = *(uint *)(param_2 + 0x70 & 0xfffffffc),
         (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) <=
         (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20)))) {
    if (uVar5 == param_2) {
      return;
    }
    uVar2 = uVar5 + 0x80 & 3;
    uVar5 = *(uint *)(uVar5 + 0x80 & 0xfffffffc);
    uVar5 = uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20;
  }
  if (uVar5 != 0) {
    uVar2 = uVar5 + 0x7c & 3;
    uVar3 = *(uint *)(uVar5 + 0x7c & 0xfffffffc);
    uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      *param_1 = param_2;
    }
    else {
      *(uint *)(uVar2 + 0x80) = param_2;
    }
    *(uint *)(param_2 + 0x7c) = uVar2;
    *(uint *)(param_2 + 0x80) = uVar5;
    *(uint *)(uVar5 + 0x7c) = param_2;
    return;
  }
  uVar5 = (uint)(param_1 + 1) & 3;
  uVar2 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  if (uVar5 == 0) {
    *param_1 = param_2;
  }
  else {
    *(uint *)(uVar5 + 0x80) = param_2;
  }
  *(uint *)(param_2 + 0x7c) = uVar5;
  *(undefined4 *)(param_2 + 0x80) = 0;
  param_1[1] = param_2;
  return;
}

