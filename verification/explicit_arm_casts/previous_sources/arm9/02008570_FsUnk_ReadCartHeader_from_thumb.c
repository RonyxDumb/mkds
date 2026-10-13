/* Decompiled C draft; module arm9; ROM address 02008570. No matching claim. */
#include "types.h"
#include "deps/02008570_FsUnk_ReadCartHeader_from_thumb.h"

int FsUnk_ReadCartHeader_from_thumb(undefined1 *param_1,int param_2,uint param_3)

{
  int *piVar1;
  bool bVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  int local_88;
  uint local_80;
  int local_7c;
  undefined4 *local_78;
  undefined4 *local_74;
  undefined4 local_6c;
  int local_68;
  int local_64;
  uint local_60;
  undefined1 auStack_5c [36];
  int local_38;
  int local_30;
  
  iVar5 = iRam0200884c;
  local_88 = 0;
  if (uRam02008848 <= param_3) {
    bVar2 = false;
    local_78 = (undefined4 *)0x0;
    local_74 = (undefined4 *)0x0;
    puVar7 = (undefined4 *)(param_2 + iRam0200884c);
    local_80 = param_3 - iRam0200884c;
    if (param_1 == (undefined1 *)0x0) {
      iVar5 = *(int *)(iRam02008854 + 0x80);
      if (*(int *)(iRam02008854 + 0x80) == 0) {
        iVar5 = iRam02008850;
      }
      bVar2 = true;
      Fs_File_Initialize(auStack_5c);
      uVar4 = Fs_FindArchiveByMountName(uRam02008858,3);
      Fs_File_OpenRaw(auStack_5c,uVar4,0,iVar5 + 0x88,0xffffffff);
      param_1 = auStack_5c;
      local_7c = local_30 - local_38;
      Mem_CpuCopy8(iRam02008854,param_2,iRam0200884c);
      *(uint *)(param_2 + 0x60) = *(uint *)(param_2 + 0x60) | uRam0200885c;
    }
    else {
      local_7c = *(int *)(param_1 + 0x2c) - *(int *)(param_1 + 0x24);
      iVar3 = Fs_File_Read(param_1,param_2,iRam0200884c);
      if (iVar3 < iVar5) {
        local_80 = 0;
      }
      iVar5 = *(int *)(param_2 + 0x80);
      if (*(int *)(param_2 + 0x80) == 0) {
        iVar5 = iRam02008850;
      }
    }
    if (local_80 < 0x88) {
      local_80 = 0;
    }
    else {
      Fs_File_Seek(param_1,local_7c + iVar5,0);
      Fs_File_Read(param_1,puVar7,0x88);
      puVar7 = puVar7 + 0x22;
      local_80 = local_80 - 0x88;
    }
    if (local_80 < 0x70) {
      local_80 = 0;
      puVar8 = puVar7;
    }
    else {
      MemsetSomeObject_from_thumb(puVar7);
      local_80 = local_80 - 0x70;
      func_0200ae60(puVar7,0,iRam0200884c,param_2,3);
      for (iVar5 = 0; (iVar5 < 3 && (*(char *)(*(int *)(param_1 + 8) + iVar5) != '\0'));
          iVar5 = iVar5 + 1) {
      }
      Mem_CpuCopy8(*(int *)(param_1 + 8),puVar7 + 4,iVar5);
      puVar7[5] = iVar5;
      puVar8 = puVar7 + 0x1c;
      local_78 = puVar7;
    }
    if (local_80 < 0x10) {
      local_80 = 0;
      puVar7 = puVar8;
    }
    else {
      *puVar8 = 0;
      puVar8[1] = *(int *)(param_2 + 0x20) + local_7c + *(int *)(param_1 + 0x24);
      puVar8[2] = *(int *)(param_2 + 0x30) + local_7c + *(int *)(param_1 + 0x24);
      local_80 = local_80 - 0x10;
      puVar7 = puVar8 + 4;
      local_74 = puVar8;
    }
    if (local_80 < (uint)(*(int *)(param_2 + 0x2c) + *(int *)(param_2 + 0x3c))) {
      if (uRam02008860 <= local_80) {
        iVar5 = *(int *)(param_1 + 0x24);
        iVar3 = local_74[1];
        Fs_File_Seek(param_1,iVar3 - iVar5,0);
        Fs_File_Read(param_1,puVar7,iRam02008864);
        func_0200ae60(local_78,iVar3,iRam02008864,puVar7,3);
        Fs_File_Seek(param_1,(iVar3 + iRam02008864) - iVar5,0);
        Fs_File_Read(param_1,(int)puVar7 + iRam02008864);
        func_0200ae60(local_78,iVar3 + iRam02008864,iRam02008864,(int)puVar7 + iRam02008864,2);
        Fs_File_Seek(param_1,(iVar3 + iRam02008868) - iVar5,0);
        Fs_File_Read(param_1,(int)puVar7 + iRam02008868,iRam02008864);
        func_0200ae60(local_78,iVar3 + iRam02008868,iRam02008864,(int)puVar7 + iRam02008868,2);
        local_88 = 1;
      }
    }
    else {
      iVar5 = *(int *)(param_1 + 0x24);
      Fs_File_Seek(param_1,local_74[1] - iVar5,0);
      Fs_File_Read(param_1,puVar7,*(undefined4 *)(param_2 + 0x2c));
      func_0200ae60(local_78,local_74[1],*(undefined4 *)(param_2 + 0x2c),puVar7,3);
      iVar3 = (int)puVar7 + *(int *)(param_2 + 0x2c);
      Fs_File_Seek(param_1,local_74[2] - iVar5,0);
      Fs_File_Read(param_1,iVar3,*(undefined4 *)(param_2 + 0x3c));
      func_0200ae60(local_78,local_74[2],*(undefined4 *)(param_2 + 0x3c),iVar3,3);
      local_88 = 1;
    }
    Fs_File_Seek(param_1,local_7c,0);
    if ((bVar2) && (Fs_File_Close(auStack_5c), local_88 != 0)) {
      piVar6 = (int *)*puRam0200886c;
      local_6c = *(undefined4 *)(param_2 + 0x20);
      local_68 = *(int *)(param_2 + 0x28) - *(int *)(param_2 + 0x20);
      local_64 = local_78[0x12] - *(int *)(param_2 + 0x20);
      local_60 = param_3;
      func_0200850c(&local_6c,uRam02008870,uRam02008874,1);
      if (piVar6[1] != 0) {
        do {
          func_0200850c(&local_6c,*piVar6,*piVar6 + piVar6[1],0);
          piVar1 = piVar6 + 3;
          piVar6 = piVar6 + 2;
        } while (*piVar1 != 0);
      }
      *(undefined4 *)(local_78[0x12] + (iRam02008878 - *(int *)(param_2 + 0x28))) = uRam0200887c;
    }
    if (local_88 != 0) {
      Arm_FlushRange(param_2,param_3);
    }
  }
  return local_88;
}

