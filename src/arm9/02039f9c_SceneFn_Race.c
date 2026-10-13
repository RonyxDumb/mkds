/* Decompiled C draft; module arm9; ROM address 02039f9c. No matching claim. */
#include "types.h"
#include "deps/02039f9c_SceneFn_Race.h"

undefined4 SceneFn_Race(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  uStack_28 = *puRam0203a044;
  uStack_24 = puRam0203a044[1];
  uStack_20 = puRam0203a044[2];
  uStack_1c = puRam0203a044[3];
  uStack_18 = puRam0203a044[4];
  uStack_14 = puRam0203a044[5];
  local_10 = puRam0203a044[6];
  uStack_c = puRam0203a044[7];
  PrepareRace();
  uVar3 = *(uint *)(uRam0203a048 & 0xfffffffc) >> (uRam0203a048 & 3) * 8 |
          *(uint *)(uRam0203a048 & 0xfffffffc) << (uRam0203a048 & 3) * -8 + 0x20;
  uVar2 = uVar3 + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    uStack_c = 1;
  }
  uVar3 = uVar3 + 0xc;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar2 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar2 == 5) {
    local_10 = 0x78003c;
  }
  else if (uVar2 == 6) {
    local_10 = 0x780001;
  }
  if (*psRam0203a04c != 2) {
    MaybeReloadRacersSfx(1);
  }
  OnSceneLoop(param_1,&uStack_28);
  return 0;
}

