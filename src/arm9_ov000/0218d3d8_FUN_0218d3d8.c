/* Decompiled C draft; module arm9_ov000; ROM address 0218d3d8. No matching claim. */
#include "types.h"
#include "deps/0218d3d8_FUN_0218d3d8.h"

int FUN_0218d3d8(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = FUN_0218b30c(*param_1,*(undefined4 *)(*DAT_0218d420 + DAT_0218d424),DAT_0218d428);
  uVar2 = FUN_0218b30c(*param_2,*(undefined4 *)(*DAT_0218d420 + DAT_0218d424),DAT_0218d428);
  iVar3 = func_0x02142368(uVar1,uVar2);
  if (*(int *)(*DAT_0218d420 + DAT_0218d42c) == 0) {
    iVar3 = -iVar3;
  }
  return iVar3;
}

