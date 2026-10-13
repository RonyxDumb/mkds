/* Decompiled C draft; module arm9_ov000; ROM address 0218c9d4. No matching claim. */
#include "types.h"
#include "deps/0218c9d4_FUN_0218c9d4.h"

void FUN_0218c9d4(int param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar3 = 0;
    iVar1 = FUN_0218dc44();
    if (0 < iVar1) {
      do {
        puVar2 = (undefined4 *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 8)),iVar3);
        FUN_0218d0e4(param_1,*puVar2);
        iVar3 = iVar3 + 1;
        iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 8)));
      } while (iVar3 < iVar1);
    }
    FUN_0218dc48((int *)(uintptr_t)(*(undefined4 *)(param_1 + 8)));
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return;
}

