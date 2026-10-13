/* Decompiled C draft; module arm9_ov003; ROM address 021bf43c. No matching claim. */
#include "types.h"
#include "deps/021bf43c_FUN_021bf43c.h"

undefined4 FUN_021bf43c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  if (*DAT_021bf4b4 != '\0') {
    return 0;
  }
  FUN_021bf620(DAT_021bf4b8,DAT_021bf4bc);
  *DAT_021bf4c4 = DAT_021bf4c0;
  uVar1 = FUN_021d2288(1,0);
  uVar2 = FUN_021c250c((int *)(uintptr_t)(*DAT_021bf4c8),param_1,param_2,param_3);
  uVar3 = FUN_021bf4dc();
  FUN_021d2070(uVar1,*DAT_021bf4cc,DAT_021bf4cc[1],DAT_021bf4cc[2],DAT_021bf4cc[3],2,uVar3,uVar2);
  FUN_021d1fd0(uVar1);
  *DAT_021bf4b4 = '\x01';
  return 1;
}

