/* Decompiled C draft; module arm7; ROM address 060097b8. No matching claim. */
#include "types.h"
#include "deps/060097b8_FUN_060097b8.h"

void FUN_060097b8(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3 + 1U & 0xfffffffe;
  if (DAT_06009834 < param_2 + uVar1) {
    iVar2 = uVar1 - (DAT_06009834 - param_2);
    uVar1 = DAT_06009834 - param_2;
  }
  else {
    iVar2 = 0;
  }
  thunk_FUN_037fb230(param_2,param_1,uVar1);
  if (iVar2 != 0) {
    thunk_FUN_037fb230((param_2 + uVar1) -
                       (uint)*(ushort *)
                              ((*(uint *)(DAT_06009838 & 0xfffffffc) >> (DAT_06009838 & 3) * 8 |
                               *(uint *)(DAT_06009838 & 0xfffffffc) <<
                               (DAT_06009838 & 3) * -8 + 0x20) + 0x3de),param_1 + uVar1,iVar2);
  }
  return;
}

