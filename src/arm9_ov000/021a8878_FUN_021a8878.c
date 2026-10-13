/* Decompiled C draft; module arm9_ov000; ROM address 021a8878. No matching claim. */
#include "types.h"
#include "deps/021a8878_FUN_021a8878.h"

undefined4 FUN_021a8878(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = FUN_021a8830();
  puVar1 = DAT_021a88a4;
  if (iVar2 == 0) {
    return 0xffffffd9;
  }
  *DAT_021a88a4 = param_1;
  puVar1[1] = param_2;
  return 0;
}

