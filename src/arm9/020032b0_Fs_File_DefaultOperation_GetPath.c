/* Decompiled C draft; module arm9; ROM address 020032b0. No matching claim. */
#include "types.h"
#include "deps/020032b0_Fs_File_DefaultOperation_GetPath.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined4 Fs_File_DefaultOperation_GetPath(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar6;
  uint uVar7;
  short sVar8;
  uint uVar9;
  uint uVar10;
  undefined1 auStack_104 [4];
  uint local_100;
  int local_f8;
  uint uStack_f4;
  undefined1 auStack_f0 [128];
  undefined1 auStack_70 [8];
  uint local_68;
  ushort uStack_4c;
  uint local_44;
  undefined1 *local_40;
  undefined4 local_3c;
  uint uVar5;
  
  uVar6 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  uVar5 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  Fs_File_Initialize((undefined4 *)(void *)(auStack_70));
  uVar6 = param_1 + 8U & 3;
  uVar4 = *(uint *)(param_1 + 8U & 0xfffffffc);
  local_68 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  if (((uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20) & 0x20) == 0) {
    uVar6 = param_1 + 0x20U & 3;
    uVar4 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar6 = uVar4 >> uVar6 * 8 | uVar4 << uVar6 * -8 + 0x20;
    if (*(short *)(param_1 + 0x38) == 0) {
      uVar10 = 0;
      uVar9 = 0;
      uVar4 = 0x10000;
      do {
        Fs_File_DoSeekDirectory((int)(uintptr_t)(auStack_70),uVar10);
        local_40 = auStack_104;
        if (uVar10 == 0) {
          uVar9 = local_44;
        }
        local_3c = 1;
        iVar1 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
        while (iVar1 == 0) {
          if ((local_f8 == 0) && (local_100 == uVar6)) {
            uVar4 = (uint)uStack_4c;
            break;
          }
          iVar1 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
        }
      } while ((uVar4 == 0x10000) && (uVar10 = uVar10 + 1, uVar10 < uVar9));
    }
    else {
      uVar4 = (uint)*(ushort *)(param_1 + 0x3a);
    }
  }
  else {
    uVar4 = (uint)*(ushort *)(param_1 + 0x24);
    uVar6 = 0x10000;
  }
  if (uVar4 == 0x10000) {
    *(undefined2 *)(param_1 + 0x38) = 0;
    return 1;
  }
  if (*(short *)(param_1 + 0x38) == 0) {
    uVar9 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
            *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
    if (uVar9 < 0x100) {
      iVar1 = 1;
    }
    else if (uVar9 < 0xff01) {
      iVar1 = 2;
    }
    else {
      iVar1 = 3;
    }
    if (uVar6 != 0x10000) {
      uVar9 = uStack_f4;
    }
    iVar1 = iVar1 + 2;
    if (uVar6 != 0x10000) {
      iVar1 = iVar1 + uVar9;
    }
    sVar8 = (short)iVar1;
    if (uVar4 != 0) {
      Fs_File_DoSeekDirectory((int)(uintptr_t)(auStack_70),uVar4);
      uVar9 = uVar4;
      do {
        Fs_File_DoSeekDirectory((int)(uintptr_t)(auStack_70),local_44);
        local_40 = auStack_104;
        local_3c = 1;
        iVar2 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
        while (iVar2 == 0) {
          if ((local_f8 != 0) && ((local_100 & 0xffff) == uVar9)) {
            iVar1 = iVar1 + uStack_f4 + 1;
            break;
          }
          iVar2 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
        }
        sVar8 = (short)iVar1;
        uVar9 = (uint)uStack_4c;
      } while (uVar9 != 0);
    }
    *(short *)(param_1 + 0x38) = sVar8 + 1;
    *(short *)(param_1 + 0x3a) = (short)uVar4;
  }
  uVar9 = param_1 + 0x30U & 3;
  uVar10 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
  uVar9 = uVar10 >> uVar9 * 8 | uVar10 << uVar9 * -8 + 0x20;
  if (uVar9 == 0) {
    return 0;
  }
  uVar7 = (uint)*(ushort *)(param_1 + 0x38);
  uVar10 = param_1 + 0x34U & 3;
  uVar3 = *(uint *)(param_1 + 0x34U & 0xfffffffc);
  if ((uVar3 >> uVar10 * 8 | uVar3 << uVar10 * -8 + 0x20) < uVar7) {
    return 1;
  }
  uVar10 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
           *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
  if (uVar10 < 0x100) {
    iVar1 = 1;
  }
  else if (uVar10 < 0xff01) {
    iVar1 = 2;
  }
  else {
    iVar1 = 3;
  }
  Mem_CpuCopy8((ushort *)(uintptr_t)(uVar5),(uint *)(uintptr_t)(uVar9),iVar1);
  Mem_CpuCopy8((ushort *)(uintptr_t)(uRam0200366c),(uint *)(uintptr_t)(uVar9 + iVar1),2);
  Fs_File_DoSeekDirectory((int)(uintptr_t)(auStack_70),uVar4);
  if (uVar6 == 0x10000) {
    *(undefined1 *)(uVar9 + uVar7 + -1) = 0;
    iVar1 = -1;
  }
  else {
    local_40 = auStack_104;
    local_3c = 0;
    iVar1 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
    if (iVar1 == 0) {
      do {
        if ((local_f8 == 0) && (local_100 == uVar6)) break;
        iVar1 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
      } while (iVar1 == 0);
    }
    iVar1 = uStack_f4 + 1;
    Mem_CpuCopy8((ushort *)(void *)(auStack_f0),(uint *)(uintptr_t)((uVar9 + uVar7) - iVar1),iVar1);
    iVar1 = -iVar1;
  }
  iVar1 = uVar7 + iVar1;
  if (uVar4 != 0) {
    do {
      Fs_File_DoSeekDirectory((int)(uintptr_t)(auStack_70),local_44);
      local_3c = 0;
      *(undefined1 *)(uVar9 + iVar1 + -1) = 0x2f;
      iVar1 = iVar1 + -1;
      local_40 = auStack_104;
      iVar2 = Fs_File_DoExecuteOperation((int)(uintptr_t)(auStack_70),3);
      while (uVar6 = uStack_f4, iVar2 == 0) {
        if ((local_f8 != 0) && ((local_100 & 0xffff) == uVar4)) {
          Mem_CpuCopy8(auStack_f0,(uVar9 + iVar1) - uStack_f4,uStack_f4);
          iVar1 = iVar1 - uVar6;
          break;
        }
        iVar2 = Fs_File_DoExecuteOperation(auStack_70,3);
      }
      uVar4 = (uint)uStack_4c;
    } while (uVar4 != 0);
  }
  return 0;
}

