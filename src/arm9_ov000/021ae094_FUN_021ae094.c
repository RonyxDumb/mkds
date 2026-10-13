/* Decompiled C draft; module arm9_ov000; ROM address 021ae094. No matching claim. */
#include "types.h"
#include "deps/021ae094_FUN_021ae094.h"

void FUN_021ae094(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae0c0 + 4) + 0xa4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 9) != '\0') {
      FUN_021a9228();
      return;
    }
    FUN_021ae0c4();
  }
  return;
}

