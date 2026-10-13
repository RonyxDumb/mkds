/* Decompiled C draft; module arm7; ROM address 03803530. No matching claim. */
#include "types.h"
#include "deps/03803530_FUN_03803530.h"

void FUN_03803530(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = DAT_03803568;
  iVar2 = 0;
  *(undefined4 *)(DAT_03803568 + 0x20) = 0;
  do {
    *(undefined2 *)(iVar1 + iVar2 * 2) = 0;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x10);
  *DAT_0380356c = *DAT_0380356c & 0xff7f;
  return;
}

