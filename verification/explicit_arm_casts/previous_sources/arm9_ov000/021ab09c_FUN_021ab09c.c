/* Decompiled C draft; module arm9_ov000; ROM address 021ab09c. No matching claim. */
#include "types.h"
#include "deps/021ab09c_FUN_021ab09c.h"

undefined4 FUN_021ab09c(int param_1,undefined4 *param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar6;
  byte *pbVar7;
  undefined4 *puVar8;
  int local_24;
  byte *local_18;
  
  local_18 = (byte *)*param_2 + 1;
  bVar1 = *(byte *)*param_2;
  iVar2 = FUN_021ab4f8(&local_18);
  pbVar7 = local_18;
  if ((iVar2 < 0) || (DAT_021ab3cc < iVar2)) {
    return 1;
  }
  switch(bVar1 & 0x1f) {
  default:
    if (bVar1 == 0xa0) {
      pbVar7 = local_18 + iVar2;
      while (local_18 < pbVar7) {
        iVar2 = FUN_021ab09c(param_1,&local_18,param_3 + 1,0,param_5);
        if (iVar2 != 0) {
          return 1;
        }
      }
    }
    else {
      local_18 = local_18 + iVar2;
    }
    break;
  case 2:
    if (*(char *)(param_1 + DAT_021ab3d0) != '\0') {
      if (param_4 == 0) {
        bVar1 = *local_18;
        while (bVar1 == 0) {
          iVar2 = iVar2 + -1;
          bVar1 = local_18[1];
          local_18 = local_18 + 1;
        }
        if (param_5 == 0) {
          if (iVar2 <= DAT_021ab3d4) {
            func_0x0214d1fc(local_18,param_1 + DAT_021ab3d8,iVar2);
            *(int *)(param_1 + DAT_021ab3dc) = iVar2;
          }
        }
        else if (param_5 == 2) {
          *(int *)(param_1 + DAT_021ab3e0) = iVar2;
          *(byte **)(param_1 + DAT_021ab3e4) = local_18;
        }
      }
      else if (param_4 == 1) {
        bVar1 = *local_18;
        while (bVar1 == 0) {
          iVar2 = iVar2 + -1;
          bVar1 = local_18[1];
          local_18 = local_18 + 1;
        }
        if (param_5 == 0) {
          if (iVar2 < 9) {
            func_0x0214d1fc(local_18,param_1 + DAT_021ab3e8,iVar2);
            *(int *)(param_1 + DAT_021ab3ec) = iVar2;
          }
        }
        else if (param_5 == 2) {
          *(int *)(param_1 + DAT_021ab3f0) = iVar2;
          *(byte **)(param_1 + DAT_021ab3f4) = local_18;
        }
      }
    }
    local_18 = local_18 + iVar2;
    break;
  case 3:
    if ((param_3 == 1) && (param_5 != 2)) {
      *(byte **)(param_1 + DAT_021ab3f8) = local_18 + 1;
      *(int *)(param_1 + DAT_021ab3fc) = iVar2 + -1;
    }
    if (*(char *)(param_1 + DAT_021ab3d0) == '\0') {
      local_18 = local_18 + iVar2;
    }
    else {
      local_18 = local_18 + 1;
      iVar2 = FUN_021ab09c(param_1,&local_18,param_3,0,param_5);
      if (iVar2 != 0) {
        return 1;
      }
      *(undefined1 *)(param_1 + DAT_021ab3d0) = 0;
    }
    break;
  case 6:
    local_24 = 0;
    puVar8 = DAT_021ab400;
    do {
      uVar3 = *puVar8;
      uVar4 = func_0x0213a434();
      iVar6 = func_0x02134d30(pbVar7,uVar3,uVar4);
      if (iVar6 == 0) {
        switch(local_24) {
        case 1:
        case 2:
          if (param_5 == 0) {
            *(int *)(param_1 + DAT_021ab404) = local_24;
          }
          *(char *)(param_1 + DAT_021ab3d0) = (char)local_24;
          break;
        case 3:
        case 4:
          if (param_5 != 2) {
            *(int *)(param_1 + DAT_021ab408) = local_24;
          }
          break;
        case 5:
          if (param_5 != 2) {
            *(char *)(param_1 + DAT_021ab40c) = (char)local_24;
          }
        }
        break;
      }
      puVar8 = puVar8 + 1;
      local_24 = local_24 + 1;
    } while (local_24 < 6);
    local_18 = local_18 + iVar2;
    break;
  case 0xc:
  case 0x13:
  case 0x14:
  case 0x16:
    if (param_5 != 2) {
      if (*(char *)(param_1 + DAT_021ab410) == '\0') {
        FUN_021ab4b0(param_1 + DAT_021ab41c,local_18,iVar2);
      }
      else {
        FUN_021ab4b0(param_1 + DAT_021ab414,local_18,iVar2);
        if ((*(char *)(param_1 + DAT_021ab40c) == '\x05') && (iVar2 < 0x50)) {
          func_0x0214d1fc(local_18,param_1 + DAT_021ab418,iVar2);
          *(undefined1 *)(param_1 + iVar2 + DAT_021ab418) = 0;
        }
      }
    }
    *(undefined1 *)(param_1 + DAT_021ab40c) = 0;
    local_18 = local_18 + iVar2;
    break;
  case 0x10:
    if (((param_3 == 0) && (param_4 == 0)) && (param_5 != 2)) {
      *(byte **)(param_1 + DAT_021ab428) = local_18;
    }
    pbVar7 = local_18 + iVar2;
    iVar2 = 0;
    while (local_18 < pbVar7) {
      iVar6 = FUN_021ab09c(param_1,&local_18,param_3 + 1,iVar2,param_5);
      iVar2 = iVar2 + 1;
      if (iVar6 != 0) {
        return 1;
      }
    }
    if (((param_3 == 1) && (param_4 == 0)) && (param_5 != 2)) {
      *(byte **)(param_1 + DAT_021ab42c) = local_18;
    }
    break;
  case 0x11:
    pbVar7 = local_18 + iVar2;
    while (local_18 < pbVar7) {
      iVar2 = FUN_021ab09c(param_1,&local_18,param_3 + 1,0,param_5);
      if (iVar2 != 0) {
        return 1;
      }
    }
    break;
  case 0x17:
  case 0x18:
    if (param_5 != 2) {
      uVar5 = FUN_021ab448(local_18);
      if (param_4 == 0) {
        if (uVar5 <= *(uint *)(param_1 + DAT_021ab420)) {
          *(undefined1 *)(param_1 + DAT_021ab424) = 1;
        }
      }
      else if (uVar5 < *(uint *)(param_1 + DAT_021ab420)) {
        *(undefined1 *)(param_1 + DAT_021ab424) = 0;
      }
    }
    local_18 = local_18 + iVar2;
    *(undefined1 *)(param_1 + DAT_021ab410) = 1;
  }
  *param_2 = local_18;
  return 0;
}

