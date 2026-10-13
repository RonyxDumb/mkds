/* Decompiled C draft; module arm9; ROM address 0212d238. No matching claim. */
#include "types.h"
#include "deps/0212d238_Sound_SetFileFatDynamicOffsetField.h"

void Sound_SetFileFatDynamicOffsetField(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0212d250 & 0xfffffffc) >> (uRam0212d250 & 3) * 8 |
          *(uint *)(uRam0212d250 & 0xfffffffc) << (uRam0212d250 & 3) * -8 + 0x20) + 0x84;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(undefined4 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_1 * 0x10 + 0x14) =
       param_2;
  return;
}

