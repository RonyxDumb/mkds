/* Decompiled C draft; module arm9_ov003; ROM address 021c82b4. No matching claim. */
#include "types.h"
#include "deps/021c82b4_FUN_021c82b4.h"

void FUN_021c82b4(undefined4 param_1)

{
  ushort *puVar1;
  int iVar2;
  
  FUN_021cce38();
  FUN_021bf698();
  puVar1 = DAT_021c8318;
  *DAT_021c8318 = *DAT_021c8318 + 6;
  iVar2 = func_0x02147cd8(*puVar1,0x1d);
  if (5 < iVar2) {
    FUN_021c85a0();
    return;
  }
  *DAT_021c8318 = *DAT_021c8318 - (short)iVar2;
  FUN_021c8b94();
  func_0x02133068((uint)*DAT_021c8318 * 0x37,0x91);
  thunk_FUN_021cca74();
  FUN_021cce48();
  FUN_021c812c();
  *(undefined4 *)(*DAT_021c831c + 0x38) = 0;
  FUN_021d34c8(0,param_1);
  return;
}

