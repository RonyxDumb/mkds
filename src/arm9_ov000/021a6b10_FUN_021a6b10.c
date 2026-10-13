/* Decompiled C draft; module arm9_ov000; ROM address 021a6b10. No matching claim. */
#include "types.h"
#include "deps/021a6b10_FUN_021a6b10.h"

int FUN_021a6b10(void)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  iVar1 = FUN_021a5b30();
  func_0x0200fca0();
  if (((iVar1 != 0) && (*(int *)(iVar1 + DAT_021a6b48) == 9)) &&
     (*(char *)(iVar1 + DAT_021a6b4c) == '\0')) {
    iVar2 = iVar1 + DAT_021a6b50;
  }
  func_0x0200fcb4();
  return iVar2;
}

