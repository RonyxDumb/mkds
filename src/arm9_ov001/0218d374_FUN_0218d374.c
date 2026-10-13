/* Decompiled C draft; module arm9_ov001; ROM address 0218d374. No matching claim. */
#include "types.h"
#include "deps/0218d374_FUN_0218d374.h"

void FUN_0218d374(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  FUN_02187218(param_1,8,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x78),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x7c));
  FUN_02188c90(param_1);
  FUN_02188cec(param_1,0);
  piVar1 = (int *)func_0x02100138(DAT_0218d3e8);
  if (piVar1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar4 = 0;
        (iVar3 < (int)(uint)*(ushort *)(piVar1 + 1) &&
        (iVar2 = *(int *)(*piVar1 + iVar4), iVar2 != 0)); iVar4 = iVar4 + 4) {
      FUN_02187218(iVar2,1,0);
      FUN_02188d64(iVar2,*(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0x78),
                   *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0x7c));
      iVar3 = iVar3 + 1;
    }
  }
  return;
}

