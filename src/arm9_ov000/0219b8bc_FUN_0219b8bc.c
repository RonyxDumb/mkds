/* Decompiled C draft; module arm9_ov000; ROM address 0219b8bc. No matching claim. */
#include "types.h"
#include "deps/0219b8bc_FUN_0219b8bc.h"

undefined4 FUN_0219b8bc(uint param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = 0;
  piVar2 = DAT_0219b8ec;
  while ((*piVar2 == 0 || (iVar1 = FUN_0219887c(), param_1 != *(byte *)(iVar1 + 1)))) {
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 1;
    if (0x1f < iVar3) {
      return 0;
    }
  }
  return 1;
}

