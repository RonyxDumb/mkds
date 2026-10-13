/* Decompiled C draft; module arm9; ROM address 02124a98. No matching claim. */
#include "types.h"
#include "deps/02124a98_CellBank_ResetSomeMetatileObjectsMode_from_thumb.h"

void CellBank_ResetSomeMetatileObjectsMode_from_thumb
               (int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  ushort *puVar3;
  ushort *puVar4;
  int iVar5;
  
  puVar3 = (ushort *)
           CellBank_GetMetatileEntry(param_3,*(uint *)(param_4 + param_1 * 8 + 0xc) & 0xffff);
  uVar2 = uRam02124ae0;
  uVar1 = uRam02124adc;
  puVar4 = *(ushort **)(puVar3 + 2);
  iVar5 = 0;
  if (*puVar3 != 0) {
    do {
      *puVar4 = *puVar4 & (ushort)uVar2;
      if (param_2 != 0) {
        *puVar4 = *puVar4 | (ushort)uVar1;
      }
      puVar4 = puVar4 + 3;
      iVar5 = iVar5 + 1;
    } while (iVar5 < (int)(uint)*puVar3);
  }
  return;
}

