/* Decompiled C draft; module arm9; ROM address 0210bc8c. No matching claim. */
#include "types.h"
#include "deps/0210bc8c_StructMQRacerEntry_MaybeInsertChildEntry.h"

undefined4 StructMQRacerEntry_MaybeInsertChildEntry(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  param_2 = param_2 + (uint)*(ushort *)(param_1 + 10);
  uVar2 = param_2 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    *(int *)(param_2 + 8) = param_1;
    IntrusiveListWrapper_InsertLast();
    return 1;
  }
  return 0;
}

