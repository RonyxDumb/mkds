/* Decompiled C draft; module arm9_ov003; ROM address 021d1790. No matching claim. */
#include "types.h"
#include "deps/021d1790_FUN_021d1790.h"

void FUN_021d1790(int param_1,int param_2,int param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar1 = (ushort)DAT_021d17d0;
  if (-1 < param_2) {
    *(ushort *)(iVar3 + 4 + param_2 * 8) =
         *(ushort *)(iVar3 + 4 + param_2 * 8) & uVar1 | (ushort)(param_3 << 10);
    return;
  }
  iVar2 = 0;
  if (*(char *)(param_1 + 0xc) != '\0') {
    do {
      *(ushort *)(iVar3 + 4) = *(ushort *)(iVar3 + 4) & uVar1 | (ushort)(param_3 << 10);
      iVar3 = iVar3 + 8;
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*(byte *)(param_1 + 0xc));
  }
  return;
}

