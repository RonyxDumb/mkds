/* Decompiled C draft; module arm9_ov000; ROM address 02199878. No matching claim. */
#include "types.h"
#include "deps/02199878_FUN_02199878.h"

void FUN_02199878(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = 0;
  iVar6 = *param_2;
  iVar1 = param_2[1];
  FUN_0218da5c((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),param_3);
  iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)));
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      piVar3 = (int *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 0x5c)),iVar4);
      if (iVar6 < *piVar3) {
        *piVar3 = *piVar3 - iVar1;
        if (iVar5 <= *piVar3 + piVar3[1]) {
          iVar5 = *piVar3 + piVar3[1];
        }
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  FUN_02197d20((int *)(uintptr_t)(param_1 + 0x44),iVar6,iVar1);
  return;
}

