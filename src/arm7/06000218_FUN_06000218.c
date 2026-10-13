/* Decompiled C draft; module arm7; ROM address 06000218. No matching claim. */
#include "types.h"
#include "deps/06000218_FUN_06000218.h"

void FUN_06000218(undefined1 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_06000248;
  iVar2 = 0;
  do {
    *(undefined1 *)(iVar1 + iVar2 + 0x1550) = param_1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  *(undefined4 *)(DAT_0600024c + 0x560) = 0;
  return;
}

