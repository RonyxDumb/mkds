/* Decompiled C draft; module arm7; ROM address 0600f720. No matching claim. */
#include "types.h"
#include "deps/0600f720_FUN_0600f720.h"

bool FUN_0600f720(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_0600f798 & 0xfffffffc) >> (DAT_0600f798 & 3) * 8 |
                       *(uint *)(DAT_0600f798 & 0xfffffffc) << (DAT_0600f798 & 3) * -8 + 0x20) +
                       0x188,0x16);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xc) = 0x8b;
    *(undefined2 *)(iVar1 + 0xe) = 3;
    FUN_0600a954((undefined2 *)(uintptr_t)(iVar1 + 0x10),(undefined2 *)(uintptr_t)(param_1));
    FUN_0600f19c((*(uint *)(DAT_0600f798 & 0xfffffffc) >> (DAT_0600f798 & 3) * 8 |
                 *(uint *)(DAT_0600f798 & 0xfffffffc) << (DAT_0600f798 & 3) * -8 + 0x20) + 0x188,
                 iVar1);
  }
  else {
    FUN_06009360(1);
  }
  return iVar1 != 0;
}

