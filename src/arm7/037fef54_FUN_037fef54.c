/* Decompiled C draft; module arm7; ROM address 037fef54. No matching claim. */
#include "types.h"
#include "deps/037fef54_FUN_037fef54.h"

void FUN_037fef54(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = DAT_037fefb8;
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 0x24;
    *(byte *)(iVar2 + iVar1) = *(byte *)(iVar2 + iVar1) & 0xfe;
    *(char *)(iVar2 + iVar1 + 1) = (char)iVar3;
    iVar1 = DAT_037fefbc;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x10);
  iVar2 = 0;
  do {
    *(byte *)(iVar1 + iVar2 * 0x40) = *(byte *)(iVar1 + iVar2 * 0x40) & 0xfe;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 0x20);
  return;
}

