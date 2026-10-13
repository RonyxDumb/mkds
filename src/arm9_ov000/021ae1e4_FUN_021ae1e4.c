/* Decompiled C draft; module arm9_ov000; ROM address 021ae1e4. No matching claim. */
#include "types.h"
#include "deps/021ae1e4_FUN_021ae1e4.h"

void FUN_021ae1e4(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae210 + 4) + 0xa4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 9) != '\0') {
      FUN_021a9534();
      return;
    }
    FUN_021ae228();
  }
  return;
}

