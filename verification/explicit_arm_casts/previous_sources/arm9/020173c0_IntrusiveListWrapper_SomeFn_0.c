/* Decompiled C draft; module arm9; ROM address 020173c0. No matching claim. */
#include "types.h"
#include "deps/020173c0_IntrusiveListWrapper_SomeFn_0.h"

void IntrusiveListWrapper_SomeFn_0(uint param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar3;
  uint uVar2;
  
  if (param_2 == 0) {
    IntrusiveListWrapper_InsertLast(param_1,param_3);
    return;
  }
  if (param_2 ==
      (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)) {
    IntrusiveListWrapper_InsertFirst(param_1,param_3);
    return;
  }
  uVar3 = (uint)*(ushort *)(param_1 + 10);
  uVar2 = param_2 + uVar3 & 3;
  uVar1 = *(uint *)(param_2 + uVar3 & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  *(uint *)(param_3 + uVar3) = uVar2;
  *(uint *)(param_3 + uVar3 + 4) = param_2;
  *(int *)(uVar2 + uVar3 + 4) = param_3;
  *(int *)(param_2 + *(ushort *)(param_1 + 10)) = param_3;
  *(short *)(param_1 + 8) = *(short *)(param_1 + 8) + 1;
  return;
}

