/* Decompiled C draft; module arm9_ov003; ROM address 021c9058. No matching claim. */
#include "types.h"
#include "deps/021c9058_FUN_021c9058.h"

void FUN_021c9058(uint param_1)

{
  int iVar1;
  
  iVar1 = FUN_021cdb6c();
  if (*(byte *)(iVar1 + 0xf6) != param_1) {
    *(char *)(*DAT_021c9080 + 0x43) = (char)param_1;
    FUN_021cdb44(param_1);
    FUN_021c8b94();
  }
  return;
}

