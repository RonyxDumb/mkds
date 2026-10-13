/* Decompiled C draft; module arm9_ov001; ROM address 0218cb14. No matching claim. */
#include "types.h"
#include "deps/0218cb14_FUN_0218cb14.h"

void FUN_0218cb14(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar3 = 0;
    for (iVar4 = 0;
        (iVar3 < (int)(uint)*(ushort *)(param_1 + 1) &&
        (iVar2 = *(int *)(*param_1 + iVar4), iVar2 != 0)); iVar4 = iVar4 + 4) {
      if (*(int *)(*DAT_0218cbac + 8) == 4) {
        FUN_02181b8c(iVar2);
      }
      FUN_021870e4(param_1,iVar2,DAT_0218cbb4,DAT_0218cbb8,DAT_0218cbb0);
      FUN_021870b0(param_1,iVar2,DAT_0218cbbc);
      FUN_0219b2e8(*(undefined4 *)(iVar2 + DAT_0218cbc0),DAT_0218cbc4);
      uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + 0xc);
      FUN_0218875c(iVar2,*(undefined4 *)(*(int *)(iVar2 + 0xa0) + 8),uVar1,uVar1);
      FUN_021888a4(iVar2,DAT_0218cbc8,DAT_0218cbcc);
      FUN_02188200(iVar2,DAT_0218cbd0);
      FUN_021881f4(iVar2,DAT_0218cbd4);
      *(undefined4 *)(iVar2 + 0xa8) = *(undefined4 *)(*(int *)(iVar2 + 0xa0) + DAT_0218cbd8);
      iVar3 = iVar3 + 1;
    }
  }
  return;
}

