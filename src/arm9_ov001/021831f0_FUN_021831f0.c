/* Decompiled C draft; module arm9_ov001; ROM address 021831f0. No matching claim. */
#include "types.h"
#include "deps/021831f0_FUN_021831f0.h"

void FUN_021831f0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != (int *)0x0) {
    iVar2 = 0;
    for (iVar3 = 0;
        (iVar2 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar1 = *(int *)(*param_1 + iVar3), iVar1 != 0)); iVar3 = iVar3 + 4) {
      if (*(int *)(*DAT_02183274 + 8) == 4) {
        FUN_02181b8c(iVar1);
      }
      FUN_021870e4((int)(uintptr_t)(param_1),iVar1,DAT_0218327c,DAT_02183280,DAT_02183278);
      FUN_021870b0((int)(uintptr_t)(param_1),iVar1,DAT_02183284);
      FUN_0218875c(iVar1,*(undefined4 *)(*(int *)(iVar1 + 0xa0) + 8),
                   *(undefined4 *)(*(int *)(iVar1 + 0xa0) + 0xc),0);
      FUN_021888a4(iVar1,0,DAT_02183288);
      FUN_02188200(iVar1,DAT_0218328c);
      *(undefined4 *)(iVar1 + DAT_02183290) = 2;
      iVar2 = iVar2 + 1;
    }
  }
  return;
}

