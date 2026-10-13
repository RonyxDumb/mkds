/* Decompiled C draft; module arm9; ROM address 0203aacc. No matching claim. */
#include "types.h"
#include "deps/0203aacc_Scene_Race_Finalize.h"

void Scene_Race_Finalize(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  bool bVar6;
  undefined4 uVar7;
  
  uVar5 = uRam0203abd4;
  uVar1 = (*(uint *)(uRam0203abd0 & 0xfffffffc) >> (uRam0203abd0 & 3) * 8 |
          *(uint *)(uRam0203abd0 & 0xfffffffc) << (uRam0203abd0 & 3) * -8 + 0x20) + 8;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20) == 5) {
    bVar6 = false;
    uVar1 = *(uint *)(uRam0203abd4 & 0xfffffffc) >> (uRam0203abd4 & 3) * 8 |
            *(uint *)(uRam0203abd4 & 0xfffffffc) << (uRam0203abd4 & 3) * -8 + 0x20;
    if ((uVar1 != 0) &&
       (uVar4 = uVar1 + 0x1f30 & 3, uVar2 = *(uint *)(uVar1 + 0x1f30 & 0xfffffffc),
       uVar2 >> uVar4 * 8 != 0 || uVar2 << uVar4 * -8 + 0x20 != 0)) {
      bVar6 = true;
    }
    if (bVar6) {
      *(undefined4 *)(uVar1 + 0x1f38) = 0;
      uVar1 = uVar5 & 3;
      uVar4 = *(uint *)(uVar5 & 0xfffffffc);
      uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
      *(undefined2 *)(uVar1 + 0x18) = 4;
      *(undefined2 *)(uVar1 + 0x1a) = 1;
    }
  }
  uVar5 = *(uint *)(uRam0203abd0 & 0xfffffffc) >> (uRam0203abd0 & 3) * 8 |
          *(uint *)(uRam0203abd0 & 0xfffffffc) << (uRam0203abd0 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0xc & 3;
  uVar4 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) == 6) {
    uVar1 = uVar5 + 8 & 3;
    uVar4 = *(uint *)(uVar5 + 8 & 0xfffffffc);
    uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    uVar7 = 0x18;
    if (uVar1 == 0) {
      if ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) == 0x36) {
        uVar7 = 0x19;
      }
    }
    else if (uVar1 == 4) {
      uVar7 = 0x1a;
    }
    iVar3 = CheckSavedSecretFlag_from_thumb(uVar7);
    if (iVar3 == 0) {
      SetSavedSecretFlag_from_thumb(uVar7);
      WriteSaveDataSectionHeaderToSaveData_from_thumb();
      WaitForWorkerTask();
      uVar1 = (*(uint *)(uRam0203abd8 & 0xfffffffc) >> (uRam0203abd8 & 3) * 8 |
              *(uint *)(uRam0203abd8 & 0xfffffffc) << (uRam0203abd8 & 3) * -8 + 0x20) + 0xc;
      uVar4 = uVar1 & 3;
      uVar1 = *(uint *)(uVar1 & 0xfffffffc);
      if (uVar1 >> uVar4 * 8 != 0 || uVar1 << uVar4 * -8 + 0x20 != 0) {
        func_02145d38();
      }
    }
  }
  ResetGlobal59C4Sub();
  ResetRaceMenuOptions_from_thumb();
  ResetAA();
  func_020af86c();
  ResetGlobalAA04();
  func_02053e54();
  DisposeOverlayManagerHeap();
  return;
}

