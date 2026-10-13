/* Decompiled C draft; module arm9_ov000; ROM address 0219b1f8. No matching claim. */
#include "types.h"
#include "deps/0219b1f8_FUN_0219b1f8.h"

int FUN_0219b1f8(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if (*DAT_0219b23c == 0) {
    return 0;
  }
  iVar3 = 0;
  iVar2 = FUN_0218dc44();
  piVar1 = DAT_0219b23c;
  if (0 < iVar2) {
    do {
      iVar2 = FUN_0218dbf8((int *)(uintptr_t)(*piVar1),iVar3);
      if (*(int *)(iVar2 + 8) == param_1) {
        return iVar2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = FUN_0218dc44((undefined4 *)(uintptr_t)(*piVar1));
    } while (iVar3 < iVar2);
  }
  return 0;
}

