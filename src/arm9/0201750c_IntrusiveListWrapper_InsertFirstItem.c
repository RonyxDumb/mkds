/* Decompiled C draft; module arm9; ROM address 0201750c. No matching claim. */
#include "types.h"
#include "deps/0201750c_IntrusiveListWrapper_InsertFirstItem.h"

void IntrusiveListWrapper_InsertFirstItem(int *param_1,int param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)((int)param_1 + 10);
  *(undefined4 *)(param_2 + (uint)uVar1 + 4) = 0;
  *(undefined4 *)(param_2 + (uint)uVar1) = 0;
  *param_1 = param_2;
  param_1[1] = param_2;
  *(short *)(param_1 + 2) = (short)param_1[2] + 1;
  return;
}

