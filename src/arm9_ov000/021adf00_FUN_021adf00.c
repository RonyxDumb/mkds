/* Decompiled C draft; module arm9_ov000; ROM address 021adf00. No matching claim. */
#include "types.h"
#include "deps/021adf00_FUN_021adf00.h"

void FUN_021adf00(void)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(DAT_021adf2c + 4) + 0xa4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 9) != '\0') {
      FUN_021a9394();
      return;
    }
    FUN_021adf30();
  }
  return;
}

