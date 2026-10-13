/* Decompiled C draft; module arm9_ov003; ROM address 021c5a0c. No matching claim. */
#include "types.h"
#include "deps/021c5a0c_FUN_021c5a0c.h"

void FUN_021c5a0c(undefined4 param_1)

{
  int iVar1;
  
  FUN_021cce38();
  FUN_021bf698();
  if (*DAT_021c5a9c < 5) {
    *DAT_021c5a9c = 0;
  }
  else {
    *DAT_021c5a9c = *DAT_021c5a9c - 4;
  }
  iVar1 = func_0x02147cd8(*DAT_021c5a9c,0x1c);
  if (iVar1 == 0x18) {
    FUN_021c5c68();
    return;
  }
  if (0x18 < iVar1) {
    *DAT_021c5a9c = *DAT_021c5a9c + (0x1c - (short)iVar1);
    iVar1 = 0;
  }
  FUN_021c5aa4();
  if (iVar1 == 0) {
    func_0x02147d30((uint)*(byte *)(*DAT_021c5aa0 + 0x53) * (uint)*DAT_021c5a9c,
                    *(undefined2 *)(*DAT_021c5aa0 + 0x40));
    thunk_FUN_021cca74();
    FUN_021cce48();
    FUN_021c590c();
    *(undefined4 *)(*DAT_021c5aa0 + 0x38) = 0;
    FUN_021d34c8(0,param_1);
  }
  return;
}

