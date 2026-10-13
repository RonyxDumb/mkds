/* Decompiled C draft; module arm9; ROM address 021249a8. No matching claim. */
#include "types.h"
#include "deps/021249a8_func_021249a8.h"

void func_021249a8(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  ushort *puVar2;
  int iVar3;
  int iVar4;
  
  puVar2 = (ushort *)
           CellBank_GetMetatileEntry((ushort *)(uintptr_t)(param_3),*(uint *)(param_4 + param_1 * 8 + 0xc) & 0xffff);
  uVar1 = uRam021249ec;
  iVar3 = *(int *)(puVar2 + 2);
  iVar4 = 0;
  if (*puVar2 != 0) {
    do {
      *(ushort *)(iVar3 + 4) = *(ushort *)(iVar3 + 4) & (ushort)uVar1;
      *(ushort *)(iVar3 + 4) = *(ushort *)(iVar3 + 4) | (ushort)(param_2 << 10);
      iVar3 = iVar3 + 6;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*puVar2);
  }
  return;
}

