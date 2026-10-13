/* Decompiled C draft; module arm9_ov000; ROM address 02196d84. No matching claim. */
#include "types.h"
#include "deps/02196d84_FUN_02196d84.h"

int FUN_02196d84(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*DAT_02196dec == 0) {
    return -1;
  }
  iVar3 = 0;
  iVar1 = FUN_0218dc44();
  if (0 < iVar1) {
    do {
      piVar2 = (int *)FUN_0218dbf8((int *)(uintptr_t)(*DAT_02196dec),iVar3);
      if (((*piVar2 == param_1) && (piVar2[1] == param_2)) && (piVar2[2] == param_3)) {
        return iVar3;
      }
      iVar3 = iVar3 + 1;
      iVar1 = FUN_0218dc44((undefined4 *)(uintptr_t)(*DAT_02196dec));
    } while (iVar3 < iVar1);
  }
  return -1;
}

