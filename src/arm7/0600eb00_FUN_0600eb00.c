/* Decompiled C draft; module arm7; ROM address 0600eb00. No matching claim. */
#include "types.h"
#include "deps/0600eb00_FUN_0600eb00.h"

void FUN_0600eb00(uint param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = FUN_0600e918();
  if (iVar1 == 0x40) {
    uVar2 = *(uint *)(DAT_0600eb3c & 0xfffffffc) >> (DAT_0600eb3c & 3) * 8 |
            *(uint *)(DAT_0600eb3c & 0xfffffffc) << (DAT_0600eb3c & 3) * -8 + 0x20;
    *(ushort *)(uVar2 + 0x530) = *(ushort *)(uVar2 + 0x530) & ~(ushort)(1 << (param_1 & 0xff));
  }
  return;
}

