/* Decompiled C draft; module arm9_ov000; ROM address 0219b9d4. No matching claim. */
#include "types.h"
#include "deps/0219b9d4_FUN_0219b9d4.h"

int FUN_0219b9d4(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*DAT_0219ba18 == 0) {
    return 0;
  }
  iVar3 = 0;
  piVar2 = DAT_0219ba1c;
  while ((*piVar2 == 0 || (iVar1 = FUN_0219887c(), param_1 != *(byte *)(iVar1 + 1)))) {
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    if (0x1f < iVar3) {
      return 0;
    }
  }
  return DAT_0219ba1c[iVar3];
}

