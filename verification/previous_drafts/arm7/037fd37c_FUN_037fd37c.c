/* Decompiled C draft; module arm7; ROM address 037fd37c. No matching claim. */
#include "types.h"
#include "deps/037fd37c_FUN_037fd37c.h"

int FUN_037fd37c(void)

{
  byte bVar1;
  int iVar2;
  
  iVar2 = 0;
  while( true ) {
    if (0x1f < iVar2) {
      return -1;
    }
    bVar1 = *(byte *)(DAT_037fd3bc + iVar2 * 0x40);
    if (-1 < (int)((uint)bVar1 << 0x1f)) break;
    iVar2 = iVar2 + 1;
  }
  *(byte *)(DAT_037fd3bc + iVar2 * 0x40) = bVar1 & 0xfe | 1;
  return iVar2;
}

