/* Decompiled C draft; module arm9_ov000; ROM address 0218d7bc. No matching claim. */
#include "types.h"
#include "deps/0218d7bc_FUN_0218d7bc.h"

undefined4 FUN_0218d7bc(undefined4 param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  *(undefined1 *)(param_3 + 1) = 2;
  *(ushort *)(param_3 + 2) =
       (ushort)((param_2 & 0xffff) >> 8) | (ushort)((param_2 & 0xffff) << 8) & (ushort)DAT_0218d814;
  uVar1 = FUN_0218e374();
  *(undefined4 *)(param_3 + 4) = uVar1;
  if (*(int *)(param_3 + 4) == -1) {
    iVar2 = FUN_021a8f84(param_1);
    if (iVar2 == 0) {
      return 0;
    }
    *(undefined4 *)(param_3 + 4) = *(undefined4 *)**(undefined4 **)(iVar2 + 0xc);
  }
  return 1;
}

