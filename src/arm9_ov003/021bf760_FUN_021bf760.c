/* Decompiled C draft; module arm9_ov003; ROM address 021bf760. No matching claim. */
#include "types.h"
#include "deps/021bf760_FUN_021bf760.h"

void FUN_021bf760(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  
  FUN_021bf698();
  iVar4 = 0;
  puVar3 = (undefined1 *)(DAT_021bf7d4 + param_1 * 2);
  iVar2 = 0;
  do {
    uVar1 = FUN_021d1be4(0,*puVar3,1);
    *(undefined4 *)(*DAT_021bf7d8 + iVar2) = uVar1;
    FUN_021d1790(*(undefined4 *)(*DAT_021bf7d8 + iVar2),0xffffffff,1);
    puVar3 = puVar3 + 1;
    iVar2 = iVar2 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  FUN_021d17d4(*(undefined4 *)*DAT_021bf7d8,0xffffffff,param_2,param_4);
  FUN_021d17d4(*(undefined4 *)(*DAT_021bf7d8 + 4),0xffffffff,param_3,param_4);
  return;
}

