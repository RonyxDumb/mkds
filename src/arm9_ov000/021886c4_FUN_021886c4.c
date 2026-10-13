/* Decompiled C draft; module arm9_ov000; ROM address 021886c4. No matching claim. */
#include "types.h"
#include "deps/021886c4_FUN_021886c4.h"

undefined4 FUN_021886c4(uint param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)FUN_02188584(1);
  if ((*(byte *)(puVar1 + 2) & param_1) == 0) {
    *(byte *)(puVar1 + 2) = *(byte *)(puVar1 + 2) | (byte)param_1;
    uVar2 = (*(code *)*puVar1)(param_1,param_2);
    return uVar2;
  }
  return 0;
}

