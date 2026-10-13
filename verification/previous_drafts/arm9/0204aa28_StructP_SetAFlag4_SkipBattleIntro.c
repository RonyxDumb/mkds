/* Decompiled C draft; module arm9; ROM address 0204aa28. No matching claim. */
#include "types.h"
#include "deps/0204aa28_StructP_SetAFlag4_SkipBattleIntro.h"

void StructP_SetAFlag4_SkipBattleIntro(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (*psRam0204aa58 == 2) {
    return;
  }
  uVar3 = *(uint *)(uRam0204aa5c & 0xfffffffc) >> (uRam0204aa5c & 3) * 8 |
          *(uint *)(uRam0204aa5c & 0xfffffffc) << (uRam0204aa5c & 3) * -8 + 0x20;
  uVar2 = uVar3 + 0x1c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(uVar3 + 0x1c) =
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffb | (param_1 & 1) << 2;
  return;
}

