/* Decompiled C draft; module arm9; ROM address 0210ed20. No matching claim. */
#include "types.h"
#include "deps/0210ed20_func_0210ed20.h"

bool func_0210ed20(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  
  if (param_2 == 0) {
    iVar1 = Sound_LoadSwar(0,*(uint *)(uRam0210ef28 & 0xfffffffc) >> (uRam0210ef28 & 3) * 8 |
                             *(uint *)(uRam0210ef28 & 0xfffffffc) << (uRam0210ef28 & 3) * -8 + 0x20)
    ;
    if (iVar1 == 0) {
      return false;
    }
    iVar1 = Sound_LoadSwar(0x50,*(uint *)(uRam0210ef28 & 0xfffffffc) >> (uRam0210ef28 & 3) * 8 |
                                *(uint *)(uRam0210ef28 & 0xfffffffc) <<
                                (uRam0210ef28 & 3) * -8 + 0x20);
    if (iVar1 == 0) {
      return false;
    }
  }
  else {
    iVar1 = Sound_LoadSwar(0x61,*(uint *)(uRam0210ef28 & 0xfffffffc) >> (uRam0210ef28 & 3) * 8 |
                                *(uint *)(uRam0210ef28 & 0xfffffffc) <<
                                (uRam0210ef28 & 3) * -8 + 0x20);
    if (iVar1 == 0) {
      return false;
    }
    uVar2 = Sound_GetSwarInfoEntry(0x61);
    uVar3 = Sound_GetSwarInfoEntry(0);
    uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0xffffff;
    uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
    uVar4 = Sound_MaybeGetRawFilePointer(uVar2);
    Sound_SetFileFatDynamicOffsetField(uVar3,uVar4);
    Sound_SetFileFatDynamicOffsetField(uVar2,0);
    iVar1 = iRam0210ef2c;
    uVar2 = iRam0210ef2c + 0x40U & 3;
    uVar6 = *(uint *)(iRam0210ef2c + 0x40U & 0xfffffffc);
    uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    *(uint *)(iRam0210ef2c + 0x40) = uVar2 + 1;
    *(uint *)(iVar1 + uVar2 * 4) = uVar3;
    iVar1 = Sound_LoadSwar(0x62,*(uint *)(uRam0210ef28 & 0xfffffffc) >> (uRam0210ef28 & 3) * 8 |
                                *(uint *)(uRam0210ef28 & 0xfffffffc) <<
                                (uRam0210ef28 & 3) * -8 + 0x20);
    if (iVar1 == 0) {
      return false;
    }
    uVar2 = Sound_GetSwarInfoEntry(0x62);
    uVar3 = Sound_GetSwarInfoEntry(0x50);
    uVar2 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
            *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) & 0xffffff;
    uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
    uVar4 = Sound_MaybeGetRawFilePointer(uVar2);
    Sound_SetFileFatDynamicOffsetField(uVar3,uVar4);
    Sound_SetFileFatDynamicOffsetField(uVar2,0);
    iVar1 = iRam0210ef2c;
    uVar2 = iRam0210ef2c + 0x40U & 3;
    uVar6 = *(uint *)(iRam0210ef2c + 0x40U & 0xfffffffc);
    uVar2 = uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20;
    *(uint *)(iRam0210ef2c + 0x40) = uVar2 + 1;
    *(uint *)(iVar1 + uVar2 * 4) = uVar3;
  }
  uVar3 = Sound_GetSbnkInfoEntry(0);
  iVar1 = Sound_MaybeGetRawFilePointer
                    (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                     *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20);
  uVar2 = uRam0210ef30;
  iVar7 = 0;
  do {
    if (*(ushort *)(uVar3 + iVar7 * 2 + 4) != uVar2) {
      uVar6 = Sound_GetSwarInfoEntry();
      if (uVar6 == 0) break;
      iVar5 = Sound_MaybeGetRawFilePointer
                        ((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                         *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) & 0xffffff);
      if ((iVar1 != 0) && (iVar5 != 0)) {
        func_02021cd4(iVar1,iVar7);
      }
    }
    iVar7 = iVar7 + 1;
  } while (iVar7 < 4);
  iVar1 = LoadGroupById(param_1);
  return iVar1 != 0;
}

