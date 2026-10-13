/* Decompiled C draft; module arm9_ov003; ROM address 021c5994. No matching claim. */
#include "types.h"
#include "deps/021c5994_FUN_021c5994.h"

void FUN_021c5994(undefined4 param_1)

{
  ushort *puVar1;
  int iVar2;
  
  FUN_021cce38();
  FUN_021bf698();
  puVar1 = DAT_021c5a04;
  *DAT_021c5a04 = *DAT_021c5a04 + 4;
  iVar2 = func_0x02147cd8(*puVar1,0x1c);
  if (3 < iVar2) {
    FUN_021c5aa4();
    return;
  }
  *DAT_021c5a04 = *DAT_021c5a04 - (short)iVar2;
  FUN_021c5c68();
  func_0x02147d30((uint)*(byte *)(*DAT_021c5a08 + 0x53) * (uint)*DAT_021c5a04,
                  *(undefined2 *)(*DAT_021c5a08 + 0x40));
  thunk_FUN_021cca74();
  FUN_021cce48();
  FUN_021c590c();
  *(undefined4 *)(*DAT_021c5a08 + 0x38) = 0;
  FUN_021d34c8(0,param_1);
  return;
}

