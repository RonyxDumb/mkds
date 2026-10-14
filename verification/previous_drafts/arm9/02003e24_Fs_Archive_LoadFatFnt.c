/* Decompiled C draft; module arm9; ROM address 02003e24. No matching claim. */
#include "types.h"
#include "deps/02003e24_Fs_Archive_LoadFatFnt.h"

uint Fs_Archive_LoadFatFnt(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_5c [72];
  
  uVar9 = param_1 + 0x30U & 3;
  uVar5 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  uVar1 = param_1 + 0x38U & 3;
  uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
  uVar9 = (uVar5 >> uVar9 * 8 | uVar5 << uVar9 * -8 + 0x20) +
          (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x3f & 0xffffffe0;
  if (uVar9 <= param_3) {
    uVar7 = param_2 + 0x1fU & 0xffffffe0;
    Fs_File_Initialize((undefined4 *)(void *)(auStack_5c));
    uVar1 = param_1 + 0x2cU & 3;
    uVar3 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
    uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = param_1 + 0x30U & 3;
    uVar5 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    iVar4 = Fs_File_OpenRaw((int)(uintptr_t)(auStack_5c),param_1,uVar3,
                            uVar3 + (uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20),0xffffffff);
    if (iVar4 != 0) {
      uVar1 = param_1 + 0x30U & 3;
      uVar3 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
      iVar4 = Fs_File_Read(auStack_5c,uVar7,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      if (iVar4 < 0) {
        uVar1 = param_1 + 0x30U & 3;
        uVar3 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
        Mem_CpuFill8((uint *)(uintptr_t)(uVar7),0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      }
      Fs_File_Close((int)(uintptr_t)(auStack_5c));
    }
    *(uint *)(param_1 + 0x2c) = uVar7;
    uVar1 = param_1 + 0x30U & 3;
    uVar10 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    uVar3 = param_1 + 0x34U & 3;
    uVar5 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
    uVar5 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = param_1 + 0x38U & 3;
    uVar6 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
    iVar8 = uVar7 + (uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
    iVar4 = Fs_File_OpenRaw((int)(uintptr_t)(auStack_5c),param_1,uVar5,
                            uVar5 + (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20),0xffffffff);
    if (iVar4 != 0) {
      uVar1 = param_1 + 0x38U & 3;
      uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
      iVar4 = Fs_File_Read(auStack_5c,iVar8,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      if (iVar4 < 0) {
        uVar1 = param_1 + 0x38U & 3;
        uVar3 = *(uint *)(param_1 + 0x38U & 0xfffffffc);
        Mem_CpuFill8((uint *)(uintptr_t)(iVar8),0,uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
      }
      Fs_File_Close((int)(uintptr_t)(auStack_5c));
    }
    *(int *)(param_1 + 0x34) = iVar8;
    uVar2 = uRam02003f4c;
    *(int *)(param_1 + 0x44) = param_2;
    *(undefined4 *)(param_1 + 0x50) = uVar2;
    uVar1 = param_1 + 0x1cU & 3;
    uVar3 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    *(uint *)(param_1 + 0x1c) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 4;
  }
  return uVar9;
}

