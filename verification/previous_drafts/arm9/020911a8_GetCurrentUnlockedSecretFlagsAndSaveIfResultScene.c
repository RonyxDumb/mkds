/* Decompiled C draft; module arm9; ROM address 020911a8. No matching claim. */
#include "types.h"
#include "deps/020911a8_GetCurrentUnlockedSecretFlagsAndSaveIfResultScene.h"

undefined4 GetCurrentUnlockedSecretFlagsAndSaveIfResultScene(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  iVar2 = GetCurrentSceneId();
  if (iVar2 == 10) {
    uVar4 = GetCurrentUnlockedSecretFlags();
    WriteSaveDataSectionHeaderToSaveData_from_thumb();
    WaitForWorkerTask();
    uVar3 = (*(uint *)(uRam020911f0 & 0xfffffffc) >> (uRam020911f0 & 3) * 8 |
            *(uint *)(uRam020911f0 & 0xfffffffc) << (uRam020911f0 & 3) * -8 + 0x20) + 0xc;
    uVar1 = uVar3 & 3;
    uVar3 = *(uint *)(uVar3 & 0xfffffffc);
    if (uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0) {
      func_02145d38();
    }
  }
  return uVar4;
}

