/* Decompiled C draft; module arm9; ROM address 0203a05c. No matching claim. */
#include "types.h"
#include "deps/0203a05c_Scene_Race_PreSleep.h"

void Scene_Race_PreSleep(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = uRam0203a0d4;
  *(undefined4 *)
   ((*(uint *)(uRam0203a0d0 & 0xfffffffc) >> (uRam0203a0d0 & 3) * 8 |
    *(uint *)(uRam0203a0d0 & 0xfffffffc) << (uRam0203a0d0 & 3) * -8 + 0x20) + 0x54) = 0;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 == 0 && uVar2 << uVar1 * -8 + 0x20 == 0) {
    func_020b2e64(1);
  }
  func_02046e84();
  uVar2 = uRam0203a0d8;
  if (*(uint *)(uRam0203a0d8 & 0xfffffffc) >> (uRam0203a0d8 & 3) * 8 != 0 ||
      *(uint *)(uRam0203a0d8 & 0xfffffffc) << (uRam0203a0d8 & 3) * -8 + 0x20 != 0) {
    do {
      LoopFn_Some3D();
      LoopFn_RaceMenuOptions_from_thumb();
      LoopFn_Sound();
      LoopFn_Brightness();
      LoopFn_RaceMenuOptions2_from_thumb();
      LoopFn_DisplayConfig();
      uVar1 = uVar2 & 3;
      uVar3 = *(uint *)(uVar2 & 0xfffffffc);
    } while (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0);
    return;
  }
  return;
}

