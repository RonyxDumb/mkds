/* Decompiled C draft; module arm9_ov000; ROM address 0219b998. No matching claim. */
#include "types.h"
#include "deps/0219b998_FUN_0219b998.h"

int FUN_0219b998(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = DAT_0219b9b0;
  do {
    if (*piVar2 == 0) {
      return iVar1;
    }
    piVar2 = piVar2 + 1;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  return -1;
}

