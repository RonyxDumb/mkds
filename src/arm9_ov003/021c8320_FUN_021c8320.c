/* Decompiled C draft; module arm9_ov003; ROM address 021c8320. No matching claim. */
#include "types.h"
#include "deps/021c8320_FUN_021c8320.h"

void FUN_021c8320(undefined4 param_1)

{
  int iVar1;
  
  FUN_021cce38();
  FUN_021bf698();
  if (*DAT_021c83a8 < 7) {
    *DAT_021c83a8 = 0;
  }
  else {
    *DAT_021c83a8 = *DAT_021c83a8 - 6;
  }
  iVar1 = func_0x02147cd8(*DAT_021c83a8,0x1d);
  if (iVar1 == 0x17) {
    FUN_021c8b94();
    return;
  }
  if (0x17 < iVar1) {
    *DAT_021c83a8 = *DAT_021c83a8 + (0x1d - (short)iVar1);
    iVar1 = 0;
  }
  FUN_021c85a0();
  if (iVar1 == 0) {
    func_0x02133068((uint)*DAT_021c83a8 * 0x37,0x91);
    thunk_FUN_021cca74();
    FUN_021cce48();
    FUN_021c812c();
    *(undefined4 *)(*DAT_021c83ac + 0x38) = 0;
    FUN_021d34c8(0,param_1);
  }
  return;
}

