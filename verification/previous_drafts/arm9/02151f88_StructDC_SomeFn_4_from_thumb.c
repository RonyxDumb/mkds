/* Decompiled C draft; module arm9; ROM address 02151f88. No matching claim. */
#include "types.h"
#include "deps/02151f88_StructDC_SomeFn_4_from_thumb.h"

undefined4 StructDC_SomeFn_4_from_thumb(undefined4 param_1)

{
  int iVar1;
  undefined1 auStack_20 [24];
  
  iVar1 = StructDW_SomeFn_from_thumb((undefined4 *)(void *)(auStack_20));
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = StructDW_SomeFn_0_from_thumb((undefined4)(uintptr_t)(auStack_20),param_1);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}

