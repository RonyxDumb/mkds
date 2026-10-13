/* Decompiled C draft; module arm7; ROM address 0600f6b8. No matching claim. */
#include "types.h"
#include "deps/0600f6b8_FUN_0600f6b8.h"

bool FUN_0600f6b8(void)

{
  int iVar1;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_0600f71c & 0xfffffffc) >> (DAT_0600f71c & 3) * 8 |
                       *(uint *)(DAT_0600f71c & 0xfffffffc) << (DAT_0600f71c & 3) * -8 + 0x20) +
                       0x188,0x10);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xc) = 0x8c;
    *(undefined2 *)(iVar1 + 0xe) = 0;
    FUN_0600f19c((*(uint *)(DAT_0600f71c & 0xfffffffc) >> (DAT_0600f71c & 3) * 8 |
                 *(uint *)(DAT_0600f71c & 0xfffffffc) << (DAT_0600f71c & 3) * -8 + 0x20) + 0x188);
  }
  else {
    FUN_06009360(1);
  }
  return iVar1 != 0;
}

