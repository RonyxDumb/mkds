/* Decompiled C draft; module arm9_ov003; ROM address 021c5b34. No matching claim. */
#include "types.h"
#include "deps/021c5b34_FUN_021c5b34.h"

void FUN_021c5b34(int param_1,int param_2)

{
  ushort uVar1;
  int *piVar2;
  int *piVar3;
  
  piVar3 = DAT_021c5b88;
  piVar2 = (int *)*DAT_021c5b88;
  if (param_1 < (int)(uint)*(byte *)((int)piVar2 + 0x51)) {
    uVar1 = (ushort)DAT_021c5b8c;
    *(ushort *)(piVar2[param_2 + 4] + 4) =
         *(ushort *)(piVar2[param_2 + 4] + 4) & uVar1 |
         *(ushort *)((int)piVar2 + (uint)*(byte *)(*piVar2 + param_1 * 0x2a + 0x28) * 2 + 0x42);
    piVar3 = (int *)*piVar3;
    *(ushort *)(piVar3[param_2 + 9] + 4) =
         *(ushort *)(piVar3[param_2 + 9] + 4) & uVar1 |
         *(ushort *)((int)piVar3 + (uint)*(ushort *)(*piVar3 + param_1 * 0x2a + 0x26) * 2 + 0x48);
  }
  return;
}

