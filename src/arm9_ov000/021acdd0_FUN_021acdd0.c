/* Decompiled C draft; module arm9_ov000; ROM address 021acdd0. No matching claim. */
#include "types.h"
#include "deps/021acdd0_FUN_021acdd0.h"

void FUN_021acdd0(ushort *param_1,ushort *param_2,uint param_3,int param_4)

{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  
  iVar4 = 0;
  puVar2 = param_1;
  puVar3 = param_2;
  if (0 < param_4) {
    do {
      uVar1 = *puVar3;
      *puVar2 = (ushort)(param_3 + uVar1);
      param_3 = param_3 + uVar1 >> 0x10;
      if (param_3 == 0) break;
      iVar4 = iVar4 + 1;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (iVar4 < param_4);
  }
  if ((param_1 != param_2) && (iVar4 = iVar4 + 1, iVar4 < param_4)) {
    param_2 = param_2 + iVar4;
    param_1 = param_1 + iVar4;
    do {
      *param_1 = *param_2;
      param_2 = param_2 + 1;
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 1;
    } while (iVar4 < param_4);
  }
  return;
}

