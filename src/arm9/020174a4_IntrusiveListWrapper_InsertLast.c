/* Decompiled C draft; module arm9; ROM address 020174a4. No matching claim. */
#include "types.h"
#include "deps/020174a4_IntrusiveListWrapper_InsertLast.h"

void IntrusiveListWrapper_InsertLast(uint param_1,int param_2)

{
  uint uVar1;
  ushort uVar2;
  uint uVar3;
  
  if (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 == 0 &&
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20 == 0) {
    IntrusiveListWrapper_InsertFirstItem();
    return;
  }
  uVar2 = *(ushort *)(param_1 + 10);
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(uint *)(param_2 + (uint)uVar2) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_2 + (uint)uVar2 + 4) = 0;
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *(int *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + (uint)*(ushort *)(param_1 + 10) + 4)
       = param_2;
  *(int *)(param_1 + 4) = param_2;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
  return;
}

