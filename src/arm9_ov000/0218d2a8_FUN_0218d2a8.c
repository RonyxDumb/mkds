/* Decompiled C draft; module arm9_ov000; ROM address 0218d2a8. No matching claim. */
#include "types.h"
#include "deps/0218d2a8_FUN_0218d2a8.h"

int FUN_0218d2a8(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  
  iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 4)));
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      puVar2 = (undefined4 *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 4)),iVar4);
      uVar5 = *puVar2;
      iVar3 = FUN_0218b27c((undefined4 *)(uintptr_t)(uVar5));
      if ((param_2 == iVar3) && (iVar3 = FUN_0218b25c(uVar5), param_3 == iVar3)) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  return -1;
}

