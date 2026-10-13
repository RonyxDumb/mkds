/* Decompiled C draft; module arm9; ROM address 0212d6c4. No matching claim. */
#include "types.h"
#include "deps/0212d6c4_Sound_ReadSdatFromOpenedFile.h"

undefined4 Sound_ReadSdatFromOpenedFile(int param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  iVar1 = Fs_File_Seek(param_1 + 0x34,0,0);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = Fs_File_Read(param_1 + 0x34,param_1,0x30);
  if (iVar1 != 0x30) {
    return 0;
  }
  if (param_2 != 0) {
    uVar5 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar2 = Sound_Context_Allocate
                      (param_2,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,uRam0212d8d4,param_1)
    ;
    *(undefined4 *)(param_1 + 0x8c) = uVar2;
    uVar5 = param_1 + 0x8cU & 3;
    uVar3 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
    if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
      return 0;
    }
    uVar5 = param_1 + 0x18U & 3;
    uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    iVar1 = Fs_File_Seek(param_1 + 0x34,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,0);
    if (iVar1 == 0) {
      return 0;
    }
    uVar5 = param_1 + 0x8cU & 3;
    uVar4 = *(uint *)(param_1 + 0x8cU & 0xfffffffc);
    uVar3 = param_1 + 0x1cU & 3;
    uVar6 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar3 = Fs_File_Read(param_1 + 0x34,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,
                         uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar5 = param_1 + 0x1cU & 3;
    uVar4 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    if (uVar3 != (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
      return 0;
    }
    uVar5 = param_1 + 0x24U & 3;
    uVar3 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar2 = Sound_Context_Allocate
                      (param_2,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,uRam0212d8d8,param_1)
    ;
    *(undefined4 *)(param_1 + 0x84) = uVar2;
    uVar5 = param_1 + 0x84U & 3;
    uVar3 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
      return 0;
    }
    uVar5 = param_1 + 0x20U & 3;
    uVar3 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    iVar1 = Fs_File_Seek(param_1 + 0x34,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,0);
    if (iVar1 == 0) {
      return 0;
    }
    uVar5 = param_1 + 0x84U & 3;
    uVar4 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    uVar3 = param_1 + 0x24U & 3;
    uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    uVar3 = Fs_File_Read(param_1 + 0x34,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,
                         uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
    uVar5 = param_1 + 0x24U & 3;
    uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    if (uVar3 != (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
      return 0;
    }
    if ((param_3 != 0) &&
       (uVar5 = param_1 + 0x14U & 3, uVar3 = *(uint *)(param_1 + 0x14U & 0xfffffffc),
       uVar5 = uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20, uVar5 != 0)) {
      uVar2 = Sound_Context_Allocate(param_2,uVar5,uRam0212d8dc,param_1);
      *(undefined4 *)(param_1 + 0x88) = uVar2;
      uVar5 = param_1 + 0x88U & 3;
      uVar3 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
      if (uVar3 >> uVar5 * 8 == 0 && uVar3 << uVar5 * -8 + 0x20 == 0) {
        return 0;
      }
      uVar5 = param_1 + 0x10U & 3;
      uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
      iVar1 = Fs_File_Seek(param_1 + 0x34,uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,0);
      if (iVar1 == 0) {
        return 0;
      }
      uVar5 = param_1 + 0x88U & 3;
      uVar4 = *(uint *)(param_1 + 0x88U & 0xfffffffc);
      uVar3 = param_1 + 0x14U & 3;
      uVar6 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      uVar3 = Fs_File_Read(param_1 + 0x34,uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20,
                           uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
      uVar5 = param_1 + 0x14U & 3;
      uVar4 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      if (uVar3 != (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) {
        return 0;
      }
    }
  }
  return 1;
}

