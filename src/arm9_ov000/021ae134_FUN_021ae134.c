/* Decompiled C draft; module arm9_ov000; ROM address 021ae134. No matching claim. */
#include "types.h"
#include "deps/021ae134_FUN_021ae134.h"

undefined4 FUN_021ae134(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(DAT_021ae168 + 4) + 0xa4);
  if (iVar1 == 0) {
    return 1;
  }
  if (*(char *)(iVar1 + 9) != '\0') {
    uVar2 = FUN_021a943c();
    return uVar2;
  }
  uVar2 = FUN_021ae16c();
  return uVar2;
}

