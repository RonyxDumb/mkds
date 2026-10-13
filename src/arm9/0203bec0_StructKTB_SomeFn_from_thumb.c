/* Decompiled C draft; module arm9; ROM address 0203bec0. No matching claim. */
#include "types.h"
#include "deps/0203bec0_StructKTB_SomeFn_from_thumb.h"

void StructKTB_SomeFn_from_thumb(undefined1 *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  *param_1 = 0;
  param_1[1] = 0;
  do {
    *(undefined4 *)(param_1 + uVar1 * 4 + 4) = 0xffffffff;
    *(undefined4 *)(param_1 + uVar1 * 4 + 0x24) = 0xffffffff;
    uVar1 = uVar1 + 1 & 0xff;
  } while (uVar1 < 8);
  return;
}

