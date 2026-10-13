/* Decompiled C draft; module arm9; ROM address 0207b708. No matching claim. */
#include "types.h"
#include "deps/0207b708_CharacterKartContext_SetNsbtpAnimationProgress.h"

void CharacterKartContext_SetNsbtpAnimationProgress(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar5 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
  uVar1 = iRam0207b730 + param_2 * 4;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar5 + 0xc) = uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20;
  uVar1 = uVar5 + 0x1c & 3;
  uVar2 = *(uint *)(uVar5 + 0x1c & 0xfffffffc);
  uVar4 = uVar5 + 0xc & 3;
  uVar3 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
  uVar1 = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + (uint)*(ushort *)(uVar5 + 0x1a) * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  *(uint *)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) =
       uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  return;
}

