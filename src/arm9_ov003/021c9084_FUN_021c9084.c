/* Decompiled C draft; module arm9_ov003; ROM address 021c9084. No matching claim. */
#include "types.h"
#include "deps/021c9084_FUN_021c9084.h"

void FUN_021c9084(uint param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_021cdb6c();
  if (*(byte *)(iVar1 + 0xf5) != param_1) {
    if (param_1 == 0) {
      *(undefined1 *)(*DAT_021c90d8 + 0x43) = *(undefined1 *)(iVar1 + 0xf6);
      uVar2 = 0;
    }
    else if (*(char *)(*DAT_021c90d8 + 0x43) == '\0') {
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
    }
    FUN_021cdb58(param_1);
    FUN_021cdb44(uVar2);
    FUN_021c8b94();
  }
  return;
}

