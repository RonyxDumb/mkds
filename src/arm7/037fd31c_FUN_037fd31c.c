/* Decompiled C draft; module arm7; ROM address 037fd31c. No matching claim. */
#include "types.h"
#include "deps/037fd31c_FUN_037fd31c.h"

void FUN_037fd31c(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = DAT_037fd370;
  iVar3 = 0;
  do {
    iVar2 = iVar1 + iVar3 * 0x54;
    *(char *)(iVar1 + iVar3 * 0x54) = (char)iVar3;
    *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 7;
    *(byte *)(iVar2 + 3) = *(byte *)(iVar2 + 3) & 0xfe;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  *DAT_037fd374 = 0;
  *DAT_037fd378 = 0;
  return;
}

