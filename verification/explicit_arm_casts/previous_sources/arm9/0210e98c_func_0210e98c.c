/* Decompiled C draft; module arm9; ROM address 0210e98c. No matching claim. */
#include "types.h"
#include "deps/0210e98c_func_0210e98c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

bool func_0210e98c(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = param_1;
  if (((param_1 == 0xff) && (iVar2 = param_2, param_2 == 0xff)) &&
     (iVar2 = param_3, param_3 == 0xff)) {
    return true;
  }
  uVar1 = func_02108950(iVar2);
  iVar2 = func_0210e3ec(uVar1,param_1,param_2);
  if (iVar2 != 0) {
    return true;
  }
  func_02108950(0);
  func_0210e434();
  iVar2 = iRam0210ed18;
  iVar6 = 0;
  uVar4 = iRam0210ed18 + 0x40U & 3;
  uVar3 = *(uint *)(iRam0210ed18 + 0x40U & 0xfffffffc);
  if (0 < (int)(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20)) {
    do {
      uVar4 = iVar2 + iVar6 * 4;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      Sound_SetFileFatDynamicOffsetField(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20,0);
      uVar4 = iVar2 + 0x40;
      uVar3 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20));
  }
  iVar2 = iRam0210ed18;
  iVar6 = 0;
  do {
    *(undefined4 *)(iVar2 + iVar6 * 4) = 0;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 0x10);
  *(undefined4 *)(iVar2 + 0x40) = 0;
  iVar2 = 0;
  if (param_4 != 0) {
    if (param_1 == 0xf) {
      iVar2 = Sound_LoadSwar(0x34,*(uint *)(uRam0210ed1c & 0xfffffffc) >> (uRam0210ed1c & 3) * 8 |
                                  *(uint *)(uRam0210ed1c & 0xfffffffc) <<
                                  (uRam0210ed1c & 3) * -8 + 0x20);
      if (iVar2 == 0) {
        return false;
      }
      uVar4 = Sound_GetSwarInfoEntry(0x34);
      uVar3 = Sound_GetSwarInfoEntry(0x33);
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xffffff;
      uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
      uVar1 = Sound_MaybeGetRawFilePointer(uVar4);
      Sound_SetFileFatDynamicOffsetField(uVar3,uVar1);
      Sound_SetFileFatDynamicOffsetField(uVar4,0);
      iVar2 = iRam0210ed18;
      uVar4 = iRam0210ed18 + 0x40U & 3;
      uVar5 = *(uint *)(iRam0210ed18 + 0x40U & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(iRam0210ed18 + 0x40) = uVar4 + 1;
      *(uint *)(iVar2 + uVar4 * 4) = uVar3;
    }
    else if (param_1 == 0x2b) {
      iVar2 = Sound_LoadSwar(100,*(uint *)(uRam0210ed1c & 0xfffffffc) >> (uRam0210ed1c & 3) * 8 |
                                 *(uint *)(uRam0210ed1c & 0xfffffffc) <<
                                 (uRam0210ed1c & 3) * -8 + 0x20);
      if (iVar2 == 0) {
        return false;
      }
      uVar4 = Sound_GetSwarInfoEntry(100);
      uVar3 = Sound_GetSwarInfoEntry(0x58);
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xffffff;
      uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
      uVar1 = Sound_MaybeGetRawFilePointer(uVar4);
      Sound_SetFileFatDynamicOffsetField(uVar3,uVar1);
      Sound_SetFileFatDynamicOffsetField(uVar4,0);
      iVar2 = iRam0210ed18;
      uVar4 = iRam0210ed18 + 0x40U & 3;
      uVar5 = *(uint *)(iRam0210ed18 + 0x40U & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(iRam0210ed18 + 0x40) = uVar4 + 1;
      *(uint *)(iVar2 + uVar4 * 4) = uVar3;
    }
    else if (param_1 == 0x4a) {
      iVar2 = Sound_LoadSwar(99,*(uint *)(uRam0210ed1c & 0xfffffffc) >> (uRam0210ed1c & 3) * 8 |
                                *(uint *)(uRam0210ed1c & 0xfffffffc) <<
                                (uRam0210ed1c & 3) * -8 + 0x20);
      if (iVar2 == 0) {
        return false;
      }
      uVar4 = Sound_GetSwarInfoEntry(99);
      uVar3 = Sound_GetSwarInfoEntry(0x31);
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xffffff;
      uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
      uVar1 = Sound_MaybeGetRawFilePointer(uVar4);
      Sound_SetFileFatDynamicOffsetField(uVar3,uVar1);
      Sound_SetFileFatDynamicOffsetField(uVar4,0);
      iVar2 = iRam0210ed18;
      uVar4 = iRam0210ed18 + 0x40U & 3;
      uVar5 = *(uint *)(iRam0210ed18 + 0x40U & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(iRam0210ed18 + 0x40) = uVar4 + 1;
      *(uint *)(iVar2 + uVar4 * 4) = uVar3;
    }
    iVar2 = param_2;
    if (param_2 == 0x10) {
      iVar2 = Sound_LoadSwar(0x13,*(uint *)(uRam0210ed1c & 0xfffffffc) >> (uRam0210ed1c & 3) * 8 |
                                  *(uint *)(uRam0210ed1c & 0xfffffffc) <<
                                  (uRam0210ed1c & 3) * -8 + 0x20);
      if (iVar2 == 0) {
        return false;
      }
      uVar4 = Sound_GetSwarInfoEntry(0x13);
      uVar3 = Sound_GetSwarInfoEntry(0x12);
      uVar4 = (*(uint *)(uVar4 & 0xfffffffc) >> (uVar4 & 3) * 8 |
              *(uint *)(uVar4 & 0xfffffffc) << (uVar4 & 3) * -8 + 0x20) & 0xffffff;
      uVar3 = (*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
              *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) & 0xffffff;
      uVar1 = Sound_MaybeGetRawFilePointer(uVar4);
      Sound_SetFileFatDynamicOffsetField(uVar3,uVar1);
      Sound_SetFileFatDynamicOffsetField(uVar4,0);
      iVar2 = iRam0210ed18;
      uVar4 = iRam0210ed18 + 0x40U & 3;
      uVar5 = *(uint *)(iRam0210ed18 + 0x40U & 0xfffffffc);
      uVar4 = uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20;
      *(uint *)(iRam0210ed18 + 0x40) = uVar4 + 1;
      *(uint *)(iVar2 + uVar4 * 4) = uVar3;
    }
  }
  uVar1 = func_02108950(iVar2);
  iVar2 = func_0210e33c(uVar1,param_1,param_2,param_3);
  return iVar2 != 0;
}

