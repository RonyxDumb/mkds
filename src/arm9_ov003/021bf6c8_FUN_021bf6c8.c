/* Decompiled C draft; module arm9_ov003; ROM address 021bf6c8. No matching claim. */
#include "types.h"
#include "deps/021bf6c8_FUN_021bf6c8.h"

void FUN_021bf6c8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 6;
  FUN_021bf698();
  iVar3 = 0;
  iVar2 = 0;
  do {
    uVar1 = FUN_021d1be4(0,iVar4,1);
    *(undefined4 *)(*DAT_021bf75c + iVar2) = uVar1;
    FUN_021d1790(*(undefined4 *)(*DAT_021bf75c + iVar2),0xffffffff,1);
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
    iVar4 = iVar4 + 1;
  } while (iVar3 < 4);
  FUN_021d17d4(*(undefined4 *)*DAT_021bf75c,0xffffffff,param_1,param_3);
  FUN_021d17d4(*(undefined4 *)(*DAT_021bf75c + 4),0xffffffff,param_2,param_3);
  FUN_021d17d4(*(undefined4 *)(*DAT_021bf75c + 8),0xffffffff,param_1,param_4);
  FUN_021d17d4(*(undefined4 *)(*DAT_021bf75c + 0xc),0xffffffff,param_2,param_4);
  return;
}

