/* Decompiled C draft; module arm9; ROM address 0203abdc. No matching claim. */
#include "types.h"
#include "deps/0203abdc_Scene_Race_Initialize.h"

void Scene_Race_Initialize(void)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  GetActiveExecutionContext();
  uVar2 = ExecutionContext_GetHeapHandle();
  CreateRegionHeapHandleForOverlay1();
  uVar3 = (*(uint *)(uRam0203ad50 & 0xfffffffc) >> (uRam0203ad50 & 3) * 8 |
          *(uint *)(uRam0203ad50 & 0xfffffffc) << (uRam0203ad50 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20;
  if ((uVar3 == 3) || (uVar3 == 5)) {
    MaybeInitializeSomeWirelessShit();
  }
  else {
    SomeVramConfig();
    func_02053e74();
  }
  func_02062860();
  SetActiveExecutionContextHeapGroupId_from_thumb(7);
  InitializeGlobalAA04(uVar2);
  SetGlobalDisplayConfigForDisplayMode(uVar2);
  func_020431e4();
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  InitializeGlobalTD();
  SetActiveExecutionContextHeapGroupId_from_thumb(5);
  LoadRaceOptionMenus_from_thumb();
  Maybe_race_m_b();
  uVar3 = (*(uint *)(uRam0203ad50 & 0xfffffffc) >> (uRam0203ad50 & 3) * 8 |
          *(uint *)(uRam0203ad50 & 0xfffffffc) << (uRam0203ad50 & 3) * -8 + 0x20) + 0xc;
  uVar6 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  if ((uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) != 3) {
    func_020af99c();
  }
  SetActiveExecutionContextHeapGroupId_from_thumb(8);
  uVar3 = *(uint *)(uRam0203ad50 & 0xfffffffc) >> (uRam0203ad50 & 3) * 8 |
          *(uint *)(uRam0203ad50 & 0xfffffffc) << (uRam0203ad50 & 3) * -8 + 0x20;
  iVar4 = (int)*(char *)(uVar3 + 0x57);
  if (((iVar4 == 0) &&
      (uVar6 = uVar3 + 8 & 3, uVar5 = *(uint *)(uVar3 + 8 & 0xfffffffc),
      (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) == 4)) &&
     ((*(ushort *)(uVar3 + 0x44) & 0x10) != 0)) {
    iVar4 = 1;
  }
  func_02043a9c(iVar4);
  SetActiveExecutionContextHeapGroupId_from_thumb(9);
  uVar6 = *(uint *)(uRam0203ad50 & 0xfffffffc) >> (uRam0203ad50 & 3) * 8 |
          *(uint *)(uRam0203ad50 & 0xfffffffc) << (uRam0203ad50 & 3) * -8 + 0x20;
  uVar3 = uVar6 + 8;
  uVar5 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20;
  if (uVar3 == 2) {
    uVar6 = uVar6 + 0x18;
    uVar3 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    if (uVar6 >> uVar3 * 8 == 0 && uVar6 << uVar3 * -8 + 0x20 == 0) {
      GetActiveExecutionContext();
      ExecutionContext_GetHeapHandle();
      CreateGlobal59C4Sub();
      return;
    }
    return;
  }
  if (uVar3 != 5) {
    return;
  }
  bVar1 = false;
  uVar3 = *(uint *)(uRam0203ad54 & 0xfffffffc) >> (uRam0203ad54 & 3) * 8 |
          *(uint *)(uRam0203ad54 & 0xfffffffc) << (uRam0203ad54 & 3) * -8 + 0x20;
  if ((uVar3 != 0) &&
     (uVar6 = uVar3 + 0x1f30 & 3, uVar5 = *(uint *)(uVar3 + 0x1f30 & 0xfffffffc),
     uVar5 >> uVar6 * 8 != 0 || uVar5 << uVar6 * -8 + 0x20 != 0)) {
    bVar1 = true;
  }
  if (bVar1) {
    *(undefined4 *)(uVar3 + 0x1f38) = 1;
    uVar3 = *(uint *)(uRam0203ad54 & 0xfffffffc) >> (uRam0203ad54 & 3) * 8 |
            *(uint *)(uRam0203ad54 & 0xfffffffc) << (uRam0203ad54 & 3) * -8 + 0x20;
    *(undefined2 *)(uVar3 + 0x18) = 5;
    *(undefined2 *)(uVar3 + 0x1a) = 1;
    return;
  }
  return;
}

