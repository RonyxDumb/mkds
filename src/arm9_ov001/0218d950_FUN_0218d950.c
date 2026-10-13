/* Decompiled C draft; module arm9_ov001; ROM address 0218d950. No matching claim. */
#include "types.h"
#include "deps/0218d950_FUN_0218d950.h"

void FUN_0218d950(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  FUN_02187218(param_1,1,0);
  FUN_02188d64(param_1,*(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x88),
               *(undefined4 *)(*(int *)(param_1 + 0xa0) + 0x8c));
  iVar2 = *(int *)(param_1 + 0xa8) * *(int *)(*(int *)(param_1 + 0xa0) + 0xd0);
  if (iVar2 < 1) {
    uVar1 = func_0x02132440(iVar2 * 0x1000);
    func_0x021329f8(uVar1,DAT_0218d9c4);
  }
  else {
    uVar1 = func_0x02132440(iVar2 * 0x1000);
    func_0x02131234(DAT_0218d9c4,uVar1);
  }
  iVar2 = *(int *)(*(int *)(param_1 + DAT_0218d9c8) + 0x1c);
  uVar1 = func_0x021322c8();
  *(undefined4 *)(iVar2 + 0xc) = uVar1;
  **(undefined4 **)(*(int *)(iVar2 + 0x1c) + (uint)*(ushort *)(iVar2 + 0x1a) * 4) =
       *(undefined4 *)(iVar2 + 0xc);
  return;
}

