/* Decompiled C draft; module arm7; ROM address 0600f19c. No matching claim. */
#include "types.h"
#include "deps/0600f19c_FUN_0600f19c.h"

void FUN_0600f19c(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(DAT_0600f228 & 0xfffffffc) >> (DAT_0600f228 & 3) * 8 |
          *(uint *)(DAT_0600f228 & 0xfffffffc) << (DAT_0600f228 & 3) * -8 + 0x20;
  if (*(short *)(uVar3 + 0x1fc) == 0) {
    uVar1 = uVar3 + 0x304 & 3;
    uVar3 = *(uint *)(uVar3 + 0x304 & 0xfffffffc);
    iVar2 = thunk_FUN_037f9854(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,param_2,0);
    if (iVar2 == 0) {
      FUN_06009040(param_1,(*(uint *)(DAT_0600f228 & 0xfffffffc) >> (DAT_0600f228 & 3) * 8 |
                           *(uint *)(DAT_0600f228 & 0xfffffffc) << (DAT_0600f228 & 3) * -8 + 0x20) +
                           500,param_2);
    }
    else {
      FUN_06008e50(param_1,param_2);
    }
  }
  else {
    FUN_06009040(param_1,uVar3 + 500,param_2);
    FUN_06008a8c(2,0x13);
  }
  return;
}

