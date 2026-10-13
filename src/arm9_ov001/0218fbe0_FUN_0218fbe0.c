/* Decompiled C draft; module arm9_ov001; ROM address 0218fbe0. No matching claim. */
#include "types.h"
#include "deps/0218fbe0_FUN_0218fbe0.h"

void FUN_0218fbe0(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    for (iVar3 = 0; iVar3 < (int)(uint)*(ushort *)(param_1 + 1); iVar3 = iVar3 + 1) {
      iVar2 = *(int *)(*param_1 + iVar4);
      if (iVar2 == 0) break;
      iVar1 = func_0x02062ec4();
      if (iVar1 == 0) {
        FUN_0218ff64(iVar2);
      }
      else {
        *(int *)(iVar2 + 8) = *(int *)(iVar2 + 8) + *(int *)(*(int *)(iVar2 + 0xa0) + 0x80);
        FUN_0218fef8(iVar2);
      }
      FUN_0219246c(iVar2);
      FUN_02188200(iVar2,DAT_0218fc44);
      iVar4 = iVar4 + 4;
    }
  }
  func_0x020a2314(DAT_0218fc48);
  return;
}

