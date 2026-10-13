/* Decompiled C draft; module arm9; ROM address 02151a64. No matching claim. */
#include "types.h"
#include "deps/02151a64_StructDCSub_SomeFn_from_thumb.h"

undefined4 StructDCSub_SomeFn_from_thumb(int param_1)

{
  int iVar1;
  undefined1 auStack_10 [8];
  
  if (*(byte *)(param_1 + 0xe7) == 0xff) {
    return 1;
  }
  if (2 < *(byte *)(param_1 + 0xe7)) {
    return 0;
  }
  iVar1 = StructDCInner_HasAnyUnk_from_thumb(param_1 + 0x40);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = StructDC_SomeFn_6(param_1 + 0xc0,uRam02151b34,4);
  if (iVar1 != 0) {
    iVar1 = FUN_02151620((byte *)(uintptr_t)(param_1 + 0xc4));
    if (iVar1 == 0) {
      return 0;
    }
    if (0x20 < *(byte *)(param_1 + 0xd0)) {
      return 0;
    }
    func_021516b0(*(byte *)(param_1 + 0xd0),(int)(uintptr_t)(auStack_10));
    iVar1 = func_02151640(param_1 + 0xc0,(undefined4)(uintptr_t)(auStack_10));
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = StructDC_SomeFn_6(param_1 + 200,uRam02151b34,4);
  if (((iVar1 != 0) && (iVar1 = FUN_02151620((byte *)(uintptr_t)(param_1 + 200)), iVar1 == 0)) &&
     (iVar1 = FUN_02151620((byte *)(uintptr_t)(param_1 + 0xcc)), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

