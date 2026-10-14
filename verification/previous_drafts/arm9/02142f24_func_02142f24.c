/* Decompiled C draft; module arm9; ROM address 02142f24. No matching claim. */
#include "types.h"
#include "deps/02142f24_func_02142f24.h"

void func_02142f24(undefined4 *param_1,ushort *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int iVar7;
  byte *pbVar8;
  byte *pbVar9;
  byte *pbVar10;
  uint uVar11;
  byte *pbVar12;
  byte local_98 [4];
  undefined4 local_94;
  undefined4 local_90 [32];
  
  pbVar9 = local_98;
  pbVar10 = local_98;
  pbVar12 = local_98;
  pbVar8 = local_98;
  if (param_2[0x1e] != 0) {
    local_98[0] = 0;
    iVar7 = 8;
    do {
      uVar2 = *(undefined4 *)pbVar9;
      uVar4 = *(undefined4 *)((int)pbVar9 + 4);
      uVar5 = *(undefined4 *)((int)pbVar9 + 8);
      uVar6 = *(undefined4 *)((int)pbVar9 + 0xc);
      pbVar9 = (byte *)((int)pbVar9 + 0x10);
      *param_1 = uVar2;
      param_1[1] = uVar4;
      param_1[2] = uVar5;
      param_1[3] = uVar6;
      param_1 = param_1 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    *param_1 = *(undefined4 *)pbVar9;
    return;
  }
  local_98[0] = (byte)param_2[0x1f];
  if (local_98[0] == 0) {
    iVar7 = 8;
    do {
      uVar2 = *(undefined4 *)pbVar10;
      uVar4 = *(undefined4 *)((int)pbVar10 + 4);
      uVar5 = *(undefined4 *)((int)pbVar10 + 8);
      uVar6 = *(undefined4 *)((int)pbVar10 + 0xc);
      pbVar10 = (byte *)((int)pbVar10 + 0x10);
      *param_1 = uVar2;
      param_1[1] = uVar4;
      param_1[2] = uVar5;
      param_1[3] = uVar6;
      param_1 = param_1 + 4;
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
    *param_1 = *(undefined4 *)pbVar10;
    return;
  }
  if (0x10 < local_98[0]) {
    local_98[0] = 0x10;
  }
  uVar1 = *param_2;
  uVar3 = 0;
  param_2 = param_2 + 0x20;
  iVar7 = 0;
  if (local_98[0] != 0) {
    do {
      *(char *)(local_90 + iVar7 * 2 + -1) = (char)*param_2;
      *(undefined1 *)((int)local_90 + iVar7 * 8 + -3) = *(undefined1 *)((int)param_2 + 1);
      local_90[iVar7 * 2] = param_2 + 1;
      uVar11 = *(byte *)((int)local_90 + iVar7 * 8 + -3) + 2 & 0xff;
      uVar3 = uVar3 + uVar11 & 0xff;
      if (((uint)uVar1 * 2 - 0x40 & 0xff) < uVar3) {
        local_98[0] = 0;
        iVar7 = 8;
        do {
          uVar2 = *(undefined4 *)pbVar12;
          uVar4 = *(undefined4 *)((int)pbVar12 + 4);
          uVar5 = *(undefined4 *)((int)pbVar12 + 8);
          uVar6 = *(undefined4 *)((int)pbVar12 + 0xc);
          pbVar12 = (byte *)((int)pbVar12 + 0x10);
          *param_1 = uVar2;
          param_1[1] = uVar4;
          param_1[2] = uVar5;
          param_1[3] = uVar6;
          param_1 = param_1 + 4;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        *param_1 = *(undefined4 *)pbVar12;
        return;
      }
      iVar7 = iVar7 + 1;
      param_2 = (ushort *)((int)param_2 + uVar11);
    } while (iVar7 < (int)(uint)local_98[0]);
  }
  iVar7 = 8;
  do {
    uVar2 = *(undefined4 *)pbVar8;
    uVar4 = *(undefined4 *)((int)pbVar8 + 4);
    uVar5 = *(undefined4 *)((int)pbVar8 + 8);
    uVar6 = *(undefined4 *)((int)pbVar8 + 0xc);
    pbVar8 = (byte *)((int)pbVar8 + 0x10);
    *param_1 = uVar2;
    param_1[1] = uVar4;
    param_1[2] = uVar5;
    param_1[3] = uVar6;
    param_1 = param_1 + 4;
    iVar7 = iVar7 + -1;
  } while (iVar7 != 0);
  *param_1 = *(undefined4 *)pbVar8;
  return;
}

