/* Decompiled C draft; module arm9_ov000; ROM address 0218d8dc. No matching claim. */
#include "types.h"
#include "deps/0218d8dc_FUN_0218d8dc.h"

undefined4 FUN_0218d8dc(int *param_1,code *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == (code *)0x0) {
    func_0x0213442c(DAT_0218d92c,DAT_0218d930,0,DAT_0218d934);
  }
  iVar1 = *param_1;
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return 0;
    }
    uVar2 = FUN_0218dbf8(param_1,iVar1);
    iVar3 = (*param_2)(uVar2,param_3);
  } while (iVar3 != 0);
  return uVar2;
}

