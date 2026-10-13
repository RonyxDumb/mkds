/* Decompiled C draft; module arm7; ROM address 0600f79c. No matching claim. */
#include "types.h"
#include "deps/0600f79c_FUN_0600f79c.h"

bool FUN_0600f79c(undefined4 param_1,undefined2 param_2)

{
  int iVar1;
  
  iVar1 = FUN_06009138((*(uint *)(DAT_0600f814 & 0xfffffffc) >> (DAT_0600f814 & 3) * 8 |
                       *(uint *)(DAT_0600f814 & 0xfffffffc) << (DAT_0600f814 & 3) * -8 + 0x20) +
                       0x188,0x18);
  if (iVar1 != 0) {
    *(undefined2 *)(iVar1 + 0xc) = 0x88;
    *(undefined2 *)(iVar1 + 0xe) = 4;
    FUN_0600a954(iVar1 + 0x10,param_1);
    *(undefined2 *)(iVar1 + 0x16) = param_2;
    FUN_0600f19c((*(uint *)(DAT_0600f814 & 0xfffffffc) >> (DAT_0600f814 & 3) * 8 |
                 *(uint *)(DAT_0600f814 & 0xfffffffc) << (DAT_0600f814 & 3) * -8 + 0x20) + 0x188,
                 iVar1);
  }
  else {
    FUN_06009360(1);
  }
  return iVar1 != 0;
}

