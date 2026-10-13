/* Decompiled C draft; module arm9_ov000; ROM address 0218d528. No matching claim. */
#include "types.h"
#include "deps/0218d528_FUN_0218d528.h"

int FUN_0218d528(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar3 = *param_2;
  iVar1 = FUN_0218b2a8(*param_1,*(undefined4 *)(*DAT_0218d568 + DAT_0218d56c),0);
  iVar2 = FUN_0218b2a8(uVar3,*(undefined4 *)(*DAT_0218d568 + DAT_0218d56c),0);
  iVar1 = iVar1 - iVar2;
  if (*(int *)(*DAT_0218d568 + DAT_0218d570) == 0) {
    iVar1 = -iVar1;
  }
  return iVar1;
}

