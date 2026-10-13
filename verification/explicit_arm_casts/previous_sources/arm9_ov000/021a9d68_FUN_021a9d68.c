/* Decompiled C draft; module arm9_ov000; ROM address 021a9d68. No matching claim. */
#include "types.h"
#include "deps/021a9d68_FUN_021a9d68.h"

undefined1 FUN_021a9d68(int param_1)

{
  char cVar1;
  byte bVar2;
  char *pcVar3;
  undefined1 *puVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  uint local_1c [2];
  
  iVar8 = *(int *)(param_1 + 0xc);
  do {
    pcVar3 = (char *)FUN_021adfc8(local_1c,param_1);
    if (local_1c[0] == 0) {
      puVar4 = (undefined1 *)(iVar8 + DAT_021a9fdc);
      *puVar4 = 9;
      return *puVar4;
    }
  } while (local_1c[0] < 5);
  cVar1 = *pcVar3;
  if (cVar1 == -0x80) {
    if ((*(char *)(iVar8 + DAT_021a9fe0) == '\0') || (*(char *)(iVar8 + DAT_021a9fdc) != '\0')) {
      *(undefined1 *)(iVar8 + DAT_021a9fdc) = 9;
    }
    else {
      local_1c[0] = (uint)(byte)pcVar3[1];
      FUN_021adf30(2,param_1);
      pcVar3 = (char *)(*(code *)*DAT_021a9fe4)(local_1c[0]);
      if (pcVar3 == (char *)0x0) {
        puVar4 = (undefined1 *)(iVar8 + DAT_021a9fdc);
        *puVar4 = 9;
        return *puVar4;
      }
      iVar5 = FUN_021aa004(pcVar3,local_1c[0],param_1);
      if ((iVar5 == 0) && (*pcVar3 == '\x01')) {
        FUN_021aaa58(iVar8,pcVar3 + 1);
      }
      else {
        *(undefined1 *)(iVar8 + DAT_021a9fdc) = 9;
      }
      FUN_021abca0(iVar8 + DAT_021a9fe8,pcVar3,local_1c[0]);
      FUN_021ab728(iVar8 + DAT_021a9fec,pcVar3,local_1c[0]);
      (*(code *)*DAT_021a9ff0)(pcVar3);
    }
  }
  else {
    local_1c[0] = (uint)(byte)pcVar3[3] * 0x100 + (uint)(byte)pcVar3[4] + 5;
    iVar5 = (*(code *)*DAT_021a9fe4)();
    if (iVar5 == 0) {
      puVar4 = (undefined1 *)(iVar8 + DAT_021a9fdc);
      *puVar4 = 9;
      return *puVar4;
    }
    iVar6 = FUN_021aa004(iVar5,local_1c[0],param_1);
    if (iVar6 != 0) {
      (*(code *)*DAT_021a9ff0)(iVar5);
      puVar4 = (undefined1 *)(iVar8 + DAT_021a9fdc);
      *puVar4 = 9;
      return *puVar4;
    }
    if ((((byte)(*(char *)(iVar8 + DAT_021a9fdc) - 7U) < 2) && (cVar1 != '\x15')) ||
       ((cVar1 == '\x15' && (7 < local_1c[0])))) {
      local_1c[0] = FUN_021aa1e0(iVar8,iVar5);
    }
    pbVar9 = (byte *)(iVar5 + 5);
    uVar7 = local_1c[0] - 5;
    switch(cVar1) {
    case '\x14':
      local_1c[0] = uVar7;
      func_0x0214d168(iVar8 + DAT_021a9ff4,0,8);
      *(undefined1 *)(iVar8 + DAT_021a9fdc) = 7;
      uVar7 = local_1c[0];
      break;
    case '\x15':
      if (*pbVar9 == 2) {
        *(undefined1 *)(iVar8 + DAT_021a9fdc) = 9;
      }
      break;
    case '\x16':
      do {
        local_1c[0] = uVar7;
        bVar2 = *pbVar9;
        iVar6 = (uint)pbVar9[3] + (uint)pbVar9[1] * 0x10000 + (uint)pbVar9[2] * 0x100;
        pbVar10 = pbVar9 + 4;
        if (bVar2 < 0xc) {
          if (bVar2 < 0xb) {
            if ((bVar2 < 3) && (bVar2 != 0)) {
              if (bVar2 == 1) {
                if ((*(char *)(iVar8 + DAT_021a9fe0) != '\0') &&
                   (*(char *)(iVar8 + DAT_021a9fdc) == '\0')) {
                  FUN_021aa9ec(iVar8,pbVar10);
                }
              }
              else {
                if (bVar2 != 2) goto LAB_021a9f6e;
                FUN_021aab74(iVar8,pbVar10);
              }
            }
            else {
LAB_021a9f6e:
              *(undefined1 *)(iVar8 + DAT_021a9fdc) = 9;
            }
          }
          else {
            FUN_021aabf0(iVar8,pbVar10);
          }
        }
        else {
          if ((0x14 < bVar2) || (bVar2 < 0xe)) goto LAB_021a9f6e;
          if (bVar2 == 0xe) {
            *(undefined1 *)(iVar8 + DAT_021a9fdc) = 4;
          }
          else if (bVar2 == 0x10) {
            FUN_021aa5b0(iVar8,pbVar10);
          }
          else {
            if (bVar2 != 0x14) goto LAB_021a9f6e;
            FUN_021aa3b8(iVar8,pbVar10);
          }
        }
        iVar11 = iVar6 + 4;
        FUN_021abca0(iVar8 + DAT_021a9fe8,pbVar9,iVar11);
        FUN_021ab728(iVar8 + DAT_021a9fec,pbVar9,iVar11);
        pbVar9 = pbVar10 + iVar6;
        uVar7 = local_1c[0] - iVar11;
      } while ((uVar7 != 0) && (*(char *)(iVar8 + DAT_021a9fdc) != '\t'));
      break;
    case '\x17':
      *(int *)(iVar8 + DAT_021a9ff8) = iVar5;
      *(undefined4 *)(iVar8 + DAT_021a9ffc) = 5;
      *(uint *)(iVar8 + DAT_021aa000) = local_1c[0];
      return *(undefined1 *)(iVar8 + DAT_021a9fdc);
    }
    local_1c[0] = uVar7;
    (*(code *)*DAT_021a9ff0)(iVar5);
  }
  return *(undefined1 *)(iVar8 + DAT_021a9fdc);
}

