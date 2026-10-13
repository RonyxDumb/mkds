/* Decompiled C draft; module arm7; ROM address 0600a450. No matching claim. */
#include "types.h"
#include "deps/0600a450_FUN_0600a450.h"

undefined4 FUN_0600a450(void)

{
  short sVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(DAT_0600a498 & 0xfffffffc) >> (DAT_0600a498 & 3) * 8 |
          *(uint *)(DAT_0600a498 & 0xfffffffc) << (DAT_0600a498 & 3) * -8 + 0x20;
  sVar1 = *(short *)(uVar2 + 0x330);
  if (sVar1 == 0) {
    if ((*(ushort *)(uVar2 + 0x3a4) & 1) != 0) {
      return 10;
    }
  }
  else if (sVar1 == 1) {
    return 10;
  }
  return 0x14;
}

