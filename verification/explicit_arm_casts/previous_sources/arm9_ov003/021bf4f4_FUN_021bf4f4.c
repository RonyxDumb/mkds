/* Decompiled C draft; module arm9_ov003; ROM address 021bf4f4. No matching claim. */
#include "types.h"
#include "deps/021bf4f4_FUN_021bf4f4.h"

void FUN_021bf4f4(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  uVar1 = FUN_021d2288(0,0);
  uVar2 = FUN_021c2530(*DAT_021bf564,param_2);
  uVar3 = FUN_021bf4dc();
  FUN_021d2070(uVar1,*DAT_021bf568,DAT_021bf568[1],DAT_021bf568[2],DAT_021bf568[3],2,uVar3,uVar2);
  iVar4 = FUN_021c20d0();
  iVar5 = FUN_021c20d0();
  FUN_021d214c(uVar1,*(undefined2 *)(DAT_021bf570 + iVar4 * 4),
               *(undefined2 *)(DAT_021bf574 + iVar5 * 4),2,DAT_021bf56c,param_1);
  FUN_021d1fd0(uVar1);
  return;
}

