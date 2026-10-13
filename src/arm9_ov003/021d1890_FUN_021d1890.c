/* Decompiled C draft; module arm9_ov003; ROM address 021d1890. No matching claim. */
#include "types.h"
#include "deps/021d1890_FUN_021d1890.h"

void FUN_021d1890(int param_1,int param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  
  uVar2 = DAT_021d18ec;
  uVar1 = DAT_021d18e8;
  puVar3 = *(uint **)(param_1 + 8);
  if (-1 < param_2) {
    puVar3[param_2 * 2] = puVar3[param_2 * 2] & DAT_021d18e8 | param_3 << 10;
    *(ushort *)(puVar3 + param_2 * 2 + 1) =
         (ushort)puVar3[param_2 * 2 + 1] & (ushort)DAT_021d18ec | (ushort)(param_4 << 0xc);
    return;
  }
  iVar4 = 0;
  if (*(char *)(param_1 + 0xc) != '\0') {
    do {
      *puVar3 = *puVar3 & uVar1 | param_3 << 10;
      *(ushort *)(puVar3 + 1) = (ushort)puVar3[1] & (ushort)uVar2 | (ushort)(param_4 << 0xc);
      puVar3 = puVar3 + 2;
      iVar4 = iVar4 + 1;
    } while (iVar4 < (int)(uint)*(byte *)(param_1 + 0xc));
  }
  return;
}

