/* Decompiled C draft; module arm9_ov000; ROM address 0218d300. No matching claim. */
#include "types.h"
#include "deps/0218d300_FUN_0218d300.h"

int FUN_0218d300(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*(undefined4 *)(param_1 + 4)));
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      piVar2 = (int *)FUN_0218dbf8((int *)(uintptr_t)(*(undefined4 *)(param_1 + 4)),iVar3);
      if (param_2 == *piVar2) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return -1;
}

