/* Decompiled C draft; module arm9; ROM address 020a10f0. No matching claim. */
#include "types.h"
#include "deps/020a10f0_MaybeUpdateDriverBalloonShineCount.h"

void MaybeUpdateDriverBalloonShineCount(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = (*(uint *)(uRam020a1150 & 0xfffffffc) >> (uRam020a1150 & 3) * 8 |
          *(uint *)(uRam020a1150 & 0xfffffffc) << (uRam020a1150 & 3) * -8 + 0x20) + 0x4c;
  uVar2 = iVar3 + param_1 * 0x70;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(iVar3 + param_1 * 0x70) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2;
  if (0 < param_2) {
    func_020a1b6c();
    return;
  }
  if (param_2 < 0) {
    func_020a19f8();
    return;
  }
  return;
}

