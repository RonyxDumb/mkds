/* Decompiled C draft; module arm9_ov001; ROM address 0218d9cc. No matching claim. */
#include "types.h"
#include "deps/0218d9cc_FUN_0218d9cc.h"

void FUN_0218d9cc(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = (int *)func_0x02100138(DAT_0218da14);
  if (piVar1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0;
        (iVar4 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar2 = *(int *)(*piVar1 + iVar3), iVar2 != 0)); iVar3 = iVar3 + 4) {
      FUN_02188e24(iVar2,*(int *)(iVar2 + 0xa8) * 0xf,DAT_0218da18);
      iVar4 = iVar4 + 1;
    }
  }
  FUN_0218da1c(param_1);
  return;
}

