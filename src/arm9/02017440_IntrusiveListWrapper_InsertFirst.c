/* Decompiled C draft; module arm9; ROM address 02017440. No matching claim. */
#include "types.h"
#include "deps/02017440_IntrusiveListWrapper_InsertFirst.h"

void IntrusiveListWrapper_InsertFirst(int *param_1,int param_2)

{
  ushort uVar1;
  
  if (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 == 0 &&
      *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 == 0) {
    IntrusiveListWrapper_InsertFirstItem();
    return;
  }
  uVar1 = *(ushort *)((int)param_1 + 10);
  *(undefined4 *)(param_2 + (uint)uVar1) = 0;
  *(uint *)(param_2 + (uint)uVar1 + 4) =
       *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  *(int *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
           *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) +
          (uint)*(ushort *)((int)param_1 + 10)) = param_2;
  *param_1 = param_2;
  *(short *)(param_1 + 2) = (short)param_1[2] + 1;
  return;
}

