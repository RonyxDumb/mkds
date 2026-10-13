/* Decompiled C draft; module arm9; ROM address 02105504. No matching claim. */
#include "types.h"
#include "deps/02105504_IsInRaceSceneNormalOrReplay.h"

undefined4 IsInRaceSceneNormalOrReplay(void)

{
  uint uVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar5 = 0;
  iVar3 = GetCurrentSceneId();
  if (iVar3 == 2) {
    bVar2 = true;
    uVar4 = (*(uint *)(uRam0210554c & 0xfffffffc) >> (uRam0210554c & 3) * 8 |
            *(uint *)(uRam0210554c & 0xfffffffc) << (uRam0210554c & 3) * -8 + 0x20) + 0xc;
    uVar1 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar4 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    if ((uVar4 != 0) && (uVar4 != 2)) {
      bVar2 = false;
    }
    if (bVar2) {
      uVar5 = 1;
    }
  }
  return uVar5;
}

