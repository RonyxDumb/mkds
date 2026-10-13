/* Decompiled C draft; module arm9; ROM address 0210e888. No matching claim. */
#include "types.h"
#include "deps/0210e888_func_0210e888.h"

void func_0210e888(uint param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  func_0210e98c(param_1 >> 8 & 0xff,param_1 >> 0x10 & 0xff,param_1 >> 0x18,param_2);
  iVar2 = IsInRaceSceneNormalOrReplay();
  if (iVar2 != 0) {
    uVar3 = (*(uint *)(uRam0210e8f4 & 0xfffffffc) >> (uRam0210e8f4 & 3) * 8 |
            *(uint *)(uRam0210e8f4 & 0xfffffffc) << (uRam0210e8f4 & 3) * -8 + 0x20) + 8;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    LoadPerRaceModeResultSseqs(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
    return;
  }
  return;
}

