/* Decompiled C draft; module arm9; ROM address 02003670. No matching claim. */
#include "types.h"
#include "deps/02003670_Fs_File_DefaultOperation_FindPath.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

bool Fs_File_DefaultOperation_FindPath(int param_1)

{
  uint uVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  char cVar6;
  undefined4 uVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  char *pcVar14;
  undefined4 uStack_b8;
  undefined4 uStack_b4;
  undefined4 uStack_b0;
  int iStack_ac;
  int iStack_a8;
  undefined1 auStack_a4 [128];
  
  uVar1 = param_1 + 0x40U & 3;
  uVar8 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar10 = uVar8 >> uVar1 * 8;
  iVar2 = uVar8 << uVar1 * -8 + 0x20;
  uVar1 = param_1 + 0x3cU & 3;
  uVar8 = *(uint *)(param_1 + 0x3cU & 0xfffffffc);
  pcVar14 = (char *)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
  Fs_File_DoExecuteOperation(param_1,2);
  cVar6 = *pcVar14;
  if (cVar6 != '\0') {
    iVar12 = 0;
    iVar13 = iVar12;
    do {
      while( true ) {
        cVar3 = pcVar14[iVar13];
        iVar4 = iVar12;
        if (((cVar3 != '\0') && (cVar3 != '/')) && (cVar3 != '\\')) {
          iVar4 = 1;
        }
        if (iVar4 == 0) break;
        iVar13 = iVar13 + 1;
      }
      if ((cVar3 != '\0') || (iVar4 = 0, uVar10 != 0 || iVar2 != 0)) {
        iVar4 = 1;
      }
      if (iVar13 == 0) {
        return true;
      }
      if (cVar6 == '.') {
        if (iVar13 == 1) {
          pcVar14 = pcVar14 + 1;
        }
        else {
          if (iVar13 != 2 || pcVar14[1] != '.') goto LAB_0200376c;
          if (*(short *)(param_1 + 0x24) != 0) {
            uVar1 = param_1 + 0x2cU & 3;
            uVar8 = *(uint *)(param_1 + 0x2cU & 0xfffffffc);
            Fs_File_DoSeekDirectory(param_1,uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
          }
          pcVar14 = pcVar14 + 2;
        }
      }
      else {
LAB_0200376c:
        if (0x7f < iVar13) {
          return true;
        }
        *(undefined4 **)(param_1 + 0x30) = &uStack_b8;
        *(undefined4 *)(param_1 + 0x34) = 0;
        do {
          iVar5 = Fs_File_DoExecuteOperation(param_1,3);
          if (iVar5 != 0) {
            return true;
          }
        } while (((iVar4 != iStack_ac) || (iVar13 != iStack_a8)) ||
                (iVar5 = Fs_Strcasecmp(pcVar14,auStack_a4,iVar13), iVar5 != 0));
        if (iVar4 == 0) {
          if (uVar10 == 0 && iVar2 == 0) {
            uVar1 = param_1 + 0x44U & 3;
            uVar10 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
            puVar11 = (undefined4 *)(uVar10 >> uVar1 * 8 | uVar10 << uVar1 * -8 + 0x20);
            *puVar11 = uStack_b8;
            puVar11[1] = uStack_b4;
            return false;
          }
          return true;
        }
        *(undefined4 *)(param_1 + 0x30) = uStack_b8;
        *(undefined4 *)(param_1 + 0x34) = uStack_b4;
        *(undefined4 *)(param_1 + 0x38) = uStack_b0;
        pcVar14 = pcVar14 + iVar13;
        Fs_File_DoExecuteOperation(param_1,2);
      }
      pcVar14 = pcVar14 + (*pcVar14 != '\0');
      cVar6 = *pcVar14;
      iVar13 = iVar12;
    } while (cVar6 != '\0');
  }
  if (uVar10 != 0 || iVar2 != 0) {
    uVar1 = param_1 + 0x44U & 3;
    uVar8 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    puVar11 = (undefined4 *)(uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20);
    uVar7 = *(undefined4 *)(param_1 + 0x24);
    uVar9 = *(undefined4 *)(param_1 + 0x28);
    *puVar11 = *(undefined4 *)(param_1 + 0x20);
    puVar11[1] = uVar7;
    puVar11[2] = uVar9;
  }
  return uVar10 == 0 && iVar2 == 0;
}

