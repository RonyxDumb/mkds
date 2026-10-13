/* Decompiled C draft; module arm9_ov000; ROM address 021a6b54. No matching claim. */
#include "types.h"
#include "deps/021a6b54_FUN_021a6b54.h"

void FUN_021a6b54(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = FUN_021a5b30();
  if ((((iVar1 != 0) && (*(int *)(iVar1 + DAT_021a6b9c) == 9)) &&
      (*(char *)(iVar1 + DAT_021a6ba0) != '\x01')) &&
     ((iVar2 = FUN_021a6908(DAT_021a6ba4), iVar2 != 0 &&
      (iVar1 = func_0x02144438(DAT_021a6ba8,iVar1 + DAT_021a6bac,iVar1 + DAT_021a6bb0,0), iVar1 != 2
      )))) {
    FUN_021a68dc(DAT_021a6ba4);
  }
  return;
}

