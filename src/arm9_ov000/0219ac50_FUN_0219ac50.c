/* Decompiled C draft; module arm9_ov000; ROM address 0219ac50. No matching claim. */
#include "types.h"
#include "deps/0219ac50_FUN_0219ac50.h"

void FUN_0219ac50(void)

{
  int *piVar1;
  
  piVar1 = (int *)FUN_0219b1f8();
  if (piVar1 != (int *)0x0) {
    if (*piVar1 != -1) {
      FUN_0218e53c();
    }
    *piVar1 = -1;
    piVar1[4] = 4;
  }
  return;
}

