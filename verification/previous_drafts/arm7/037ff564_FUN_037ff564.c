/* Decompiled C draft; module arm7; ROM address 037ff564. No matching claim. */
#include "types.h"
#include "deps/037ff564_FUN_037ff564.h"

void FUN_037ff564(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_037ff58c;
  iVar3 = 0;
  do {
    iVar2 = iVar1 + iVar3 * 0x40;
    *(undefined1 *)(iVar2 + 0xf80) = 0;
    *(undefined1 *)(iVar2 + 0xf81) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  return;
}

