/* Decompiled C draft; module arm9; ROM address 0210e680. No matching claim. */
#include "types.h"
#include "deps/0210e680_Maybe_data_Sound_sound_data.h"

undefined4 Maybe_data_Sound_sound_data(void)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  
  Sound_MaybeSetActiveSdat(uRam0210e874);
  iVar2 = Sound_ReadSdatFromPathImplV2
                    (uRam0210e87c,uRam0210e880,
                     *(uint *)(uRam0210e878 & 0xfffffffc) >> (uRam0210e878 & 3) * 8 |
                     *(uint *)(uRam0210e878 & 0xfffffffc) << (uRam0210e878 & 3) * -8 + 0x20,0);
  SetGlobalSdatUsed(1);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = Sound_LoadSarc(1,*(uint *)(uRam0210e878 & 0xfffffffc) >> (uRam0210e878 & 3) * 8 |
                           *(uint *)(uRam0210e878 & 0xfffffffc) << (uRam0210e878 & 3) * -8 + 0x20);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = Sound_GetSarcInfoEntry(1);
  uVar4 = Sound_GetSarcInfoEntry(0);
  uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  uVar7 = *(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20;
  uVar5 = Sound_MaybeGetRawFilePointer(uVar3);
  Sound_SetFileFatDynamicOffsetField(uVar7,uVar5);
  Sound_SetFileFatDynamicOffsetField(uVar3,0);
  iVar2 = iRam0210e884;
  uVar3 = iRam0210e884 + 0x40U & 3;
  uVar4 = *(uint *)(iRam0210e884 + 0x40U & 0xfffffffc);
  uVar6 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  uVar3 = uRam0210e878 & 3;
  uVar4 = *(uint *)(uRam0210e878 & 0xfffffffc);
  *(uint *)(iRam0210e884 + 0x40) = uVar6 + 1;
  *(uint *)(iVar2 + uVar6 * 4) = uVar7;
  iVar2 = Sound_LoadSwar(0x3e,uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20);
  if (iVar2 == 0) {
    return 0;
  }
  uVar3 = Sound_GetSwarInfoEntry(0x3e);
  uVar4 = Sound_GetSwarInfoEntry(0x3d);
  uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
          *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
  uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
          *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xffffff;
  uVar5 = Sound_MaybeGetRawFilePointer(uVar3);
  Sound_SetFileFatDynamicOffsetField(uVar4,uVar5);
  Sound_SetFileFatDynamicOffsetField(uVar3,0);
  iVar2 = iRam0210e884;
  uVar3 = iRam0210e884 + 0x40U & 3;
  uVar6 = *(uint *)(iRam0210e884 + 0x40U & 0xfffffffc);
  uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  *(uint *)(iRam0210e884 + 0x40) = uVar3 + 1;
  *(uint *)(iVar2 + uVar3 * 4) = uVar4;
  iVar2 = Sound_LoadSwar(1,*(uint *)(uRam0210e878 & 0xfffffffc) >> (uRam0210e878 & 3) * 8 |
                           *(uint *)(uRam0210e878 & 0xfffffffc) << (uRam0210e878 & 3) * -8 + 0x20);
  if (iVar2 == 0) {
    bVar1 = false;
  }
  else {
    iVar2 = Sound_LoadSbnkWithFlags
                      (0,2,*(uint *)(uRam0210e878 & 0xfffffffc) >> (uRam0210e878 & 3) * 8 |
                           *(uint *)(uRam0210e878 & 0xfffffffc) << (uRam0210e878 & 3) * -8 + 0x20);
    if (iVar2 == 0) {
      bVar1 = false;
    }
    else {
      iVar2 = Sound_LoadSarc(0,*(uint *)(uRam0210e878 & 0xfffffffc) >> (uRam0210e878 & 3) * 8 |
                               *(uint *)(uRam0210e878 & 0xfffffffc) <<
                               (uRam0210e878 & 3) * -8 + 0x20);
      if (iVar2 == 0) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
  }
  if (!bVar1) {
    return 0;
  }
  iVar2 = func_0210ed20(1,1);
  if (iVar2 == 0) {
    return 0;
  }
  func_02108950(iVar2);
  func_0210e4c8();
  return 1;
}

