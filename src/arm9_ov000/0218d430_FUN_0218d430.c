/* Decompiled C draft; module arm9_ov000; ROM address 0218d430. No matching claim. */
#include "types.h"
#include "deps/0218d430_FUN_0218d430.h"

int FUN_0218d430(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = FUN_0218b30c(*param_1,*(undefined4 *)(*DAT_0218d478 + DAT_0218d47c),DAT_0218d480);
  uVar2 = FUN_0218b30c(*param_2,*(undefined4 *)(*DAT_0218d478 + DAT_0218d47c),DAT_0218d480);
  iVar3 = func_0x0213a074(uVar1,uVar2);
  if (*(int *)(*DAT_0218d478 + DAT_0218d484) == 0) {
    iVar3 = -iVar3;
  }
  return iVar3;
}

