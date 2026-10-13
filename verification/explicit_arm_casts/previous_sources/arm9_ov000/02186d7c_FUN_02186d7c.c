/* Decompiled C draft; module arm9_ov000; ROM address 02186d7c. No matching claim. */
#include "types.h"
#include "deps/02186d7c_FUN_02186d7c.h"

void FUN_02186d7c(int param_1)

{
  undefined1 uVar1;
  bool bVar2;
  longlong lVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined4 uVar8;
  int *piVar9;
  uint uVar10;
  uint uVar11;
  int *piVar12;
  int iVar13;
  bool bVar14;
  longlong lVar15;
  longlong lVar16;
  undefined8 uVar17;
  uint local_70;
  undefined4 local_60;
  undefined4 local_5c;
  uint local_3c;
  undefined1 auStack_38 [36];
  
  bVar2 = false;
  iVar13 = param_1 + DAT_021870e4;
  piVar12 = (int *)(param_1 + DAT_021870e8);
  local_70 = *(uint *)(param_1 + 0x20);
  if ((int)local_70 < 1) {
    local_70 = DAT_021870ec;
  }
  func_0x0214d168(param_1 + 0xb4,0,100);
  *(undefined4 *)(param_1 + 0xf0) = DAT_021870f0;
  *(undefined4 *)(param_1 + 0xf4) = *(undefined4 *)(param_1 + DAT_021870f4);
  *(undefined4 *)(param_1 + 0xfc) = DAT_021870f8;
  *(undefined4 *)(param_1 + 0x100) = *(undefined4 *)(param_1 + DAT_021870fc);
  FUN_021ae304(param_1 + 0xb4);
  iVar4 = FUN_021acef8(*(undefined4 *)(param_1 + 0xa8));
  if (iVar4 == 0) {
    *(undefined4 *)(param_1 + 0x24) = 2;
    return;
  }
  FUN_021ae270();
  if (*(int *)(param_1 + 0xb0) == 1) {
    func_0x0214d168(iVar13,0,DAT_02187100);
    *(undefined4 *)(iVar13 + DAT_02187108) = DAT_02187104;
    *(undefined4 *)(iVar13 + DAT_0218710c) = *(undefined4 *)(param_1 + 0xa8);
    *(int *)(param_1 + 0xc0) = iVar13;
    FUN_021ab594(DAT_02187110,0xb);
    FUN_021a9200(1);
    uVar6 = DAT_02187114;
  }
  else {
    uVar6 = 0x50;
  }
  FUN_021ae290(0,uVar6 & 0xffff,iVar4);
  lVar15 = func_0x0200f5ac();
  lVar3 = CONCAT44(local_5c,local_60);
  if (*(int *)(param_1 + 0xb0) == 1) {
    func_0x0201000c(auStack_38);
    FUN_021a9c5c(auStack_38,0x20);
    lVar3 = lVar15;
  }
  iVar13 = FUN_021ae134();
  if (iVar13 != 0) {
    *(undefined4 *)(param_1 + 0x24) = 3;
    FUN_021ae258();
    FUN_021ae2f4();
    return;
  }
  piVar9 = (int *)(param_1 + DAT_02187118);
  *(int *)(param_1 + DAT_0218711c) = *piVar9;
  iVar4 = *piVar9;
  iVar13 = func_0x0213a434(iVar4);
  puVar5 = (uint *)(param_1 + DAT_02187120);
  *puVar5 = iVar4 + iVar13;
  uVar6 = *puVar5;
  uVar10 = *(uint *)(param_1 + DAT_0218711c);
  uVar11 = (int)local_70 >> 0x1f;
  if (uVar10 < uVar6) {
    do {
      if (*DAT_02187124 == 0) {
        *(undefined4 *)(param_1 + 0x24) = 5;
        goto LAB_0218720a;
      }
      local_3c = uVar6 - uVar10;
      if ((int)DAT_02187128 < (int)local_3c) {
        local_3c = DAT_02187128;
      }
      local_3c = FUN_021adbf4(*(undefined4 *)(param_1 + DAT_0218711c),local_3c);
      if ((int)local_3c < 1) {
        *(undefined4 *)(param_1 + 0x24) = 5;
        goto LAB_0218720a;
      }
      FUN_021adb80();
      lVar16 = func_0x0200f5ac();
      uVar6 = (uint)(lVar16 - lVar15);
      uVar17 = func_0x02132e40(uVar6 * 0x40,
                               (int)((ulonglong)(lVar16 - lVar15) >> 0x20) * 0x40 | uVar6 >> 0x1a,
                               DAT_0218712c,0);
      uVar6 = (uint)((ulonglong)uVar17 >> 0x20);
      if (uVar11 <= uVar6 && (uint)((uint)uVar17 <= local_70) <= uVar11 - uVar6) {
        *(undefined4 *)(param_1 + 0x24) = 4;
        goto LAB_0218720a;
      }
      if (*(int *)(param_1 + 0xb0) == 1) {
        uVar6 = (uint)(lVar16 - lVar3);
        uVar17 = func_0x02132e40(uVar6 * 0x40,
                                 (int)((ulonglong)(lVar16 - lVar3) >> 0x20) * 0x40 | uVar6 >> 0x1a,
                                 DAT_0218712c,0);
        iVar13 = (int)((ulonglong)uVar17 >> 0x20);
        bVar14 = (uint)uVar17 <= DAT_02187130;
        if ((uint)bVar14 <= (uint)-iVar13) {
          func_0x0201000c(auStack_38,-(uint)!bVar14 - iVar13);
          FUN_021a9c5c(auStack_38,0x20);
          lVar3 = lVar16;
        }
      }
      *(uint *)(param_1 + DAT_0218711c) = *(int *)(param_1 + DAT_0218711c) + local_3c;
      iVar13 = FUN_02187230(param_1);
      if (iVar13 == 0) {
        *(undefined4 *)(param_1 + 0x24) = 7;
        goto LAB_0218720a;
      }
      uVar6 = *(uint *)(param_1 + DAT_02187120);
      uVar10 = *(uint *)(param_1 + DAT_0218711c);
    } while (uVar10 < uVar6);
  }
  FUN_02186a10(param_1,param_1 + DAT_02187118);
  func_0x0200ed34(param_1 + DAT_02187134);
  if (*(int *)(param_1 + 0xc) == 0) {
    iVar13 = FUN_02186a38(param_1,param_1 + DAT_021870e8,*(undefined4 *)(param_1 + 0x10));
    if (iVar13 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
      func_0x0200ecc4(param_1 + DAT_02187134);
      goto LAB_0218720a;
    }
  }
  else {
    piVar9 = (int *)(param_1 + DAT_021870e8);
    *piVar9 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + DAT_02187138) = *piVar9;
    *(int *)(param_1 + DAT_0218713c) = *piVar9 + *(int *)(param_1 + 0x10);
    *(undefined4 *)(param_1 + DAT_02187140) = *(undefined4 *)(param_1 + 0x10);
  }
  piVar12[1] = *piVar12;
  piVar12[2] = *piVar12 + piVar12[3];
  func_0x0200ecc4(param_1 + DAT_02187134);
  do {
    if (*DAT_02187124 == 0) {
      *(undefined4 *)(param_1 + 0x24) = 5;
      goto LAB_0218720a;
    }
    func_0x0200ed34(param_1 + DAT_02187134);
    if (piVar12[2] - 1U <= (uint)piVar12[1]) {
      func_0x0200ecc4(param_1 + DAT_02187134);
      goto LAB_021871ee;
    }
    local_3c = FUN_021adbac();
    if (0 < (int)local_3c) {
      iVar13 = FUN_021adf78(&local_3c);
      if (iVar13 == 0) {
        func_0x0200ecc4(param_1 + DAT_02187134);
        goto LAB_021871ee;
      }
      uVar10 = (piVar12[2] + -1) - piVar12[1];
      uVar6 = local_3c;
      if ((int)uVar10 <= (int)local_3c) {
        uVar6 = uVar10;
      }
      func_0x0214d1fc(iVar13,piVar12[1],uVar6);
      piVar12[1] = piVar12[1] + uVar6;
      *(undefined1 *)piVar12[1] = 0;
      if (!bVar2) {
        iVar4 = *piVar12;
        iVar13 = func_0x02139f70(iVar4,DAT_02187144);
        if (iVar13 != 0) {
          bVar2 = true;
          iVar13 = func_0x02139f70(iVar4,DAT_02187144);
          *(int *)(param_1 + DAT_02187148) = iVar13 + 4;
          iVar13 = func_0x02139f70(*piVar12,DAT_0218714c);
          if (iVar13 != 0) {
            iVar4 = func_0x0213a434(DAT_0218714c);
            puVar7 = (undefined1 *)func_0x02139f70(iVar13 + iVar4,DAT_02187150);
            uVar1 = *puVar7;
            *puVar7 = 0;
            uVar8 = func_0x0213bf90(iVar13 + iVar4);
            *(undefined4 *)(param_1 + DAT_02187154) = uVar8;
            *puVar7 = uVar1;
          }
        }
      }
      if (uVar6 < local_3c) {
        FUN_021adf00();
        func_0x0200ecc4(param_1 + DAT_02187134);
        goto LAB_021871ee;
      }
      FUN_021adf00(uVar6);
    }
    if ((int)local_3c < 0) {
      func_0x0200ecc4(param_1 + DAT_02187134);
LAB_021871ee:
      FUN_021ae094();
      FUN_021ae048();
      FUN_021ae258();
      FUN_021ae2f4();
      *(undefined4 *)(param_1 + 0x24) = 8;
      return;
    }
    if (((0 < *(int *)(param_1 + DAT_02187154)) && (0 < (int)local_3c)) &&
       ((uint)(*(int *)(param_1 + DAT_02187148) + *(int *)(param_1 + DAT_02187154)) <=
        (uint)piVar12[1])) {
      func_0x0200ecc4(param_1 + DAT_02187134);
      goto LAB_021871ee;
    }
    lVar16 = func_0x0200f5ac();
    uVar6 = (uint)(lVar16 - lVar15);
    uVar17 = func_0x02132e40(uVar6 * 0x40,
                             (int)((ulonglong)(lVar16 - lVar15) >> 0x20) * 0x40 | uVar6 >> 0x1a,
                             DAT_02187224,0);
    uVar6 = (uint)((ulonglong)uVar17 >> 0x20);
    if (uVar11 <= uVar6 && (uint)((uint)uVar17 <= local_70) <= uVar11 - uVar6) {
      *(undefined4 *)(param_1 + 0x24) = 6;
      func_0x0200ecc4(param_1 + DAT_02187228);
      goto LAB_0218720a;
    }
    if (*(int *)(param_1 + 0xb0) == 1) {
      uVar6 = (uint)(lVar16 - lVar3);
      uVar17 = func_0x02132e40(uVar6 * 0x40,
                               (int)((ulonglong)(lVar16 - lVar3) >> 0x20) * 0x40 | uVar6 >> 0x1a,
                               DAT_02187224,0);
      iVar13 = (int)((ulonglong)uVar17 >> 0x20);
      bVar14 = (uint)uVar17 <= DAT_0218722c;
      if ((uint)bVar14 <= (uint)-iVar13) {
        func_0x0201000c(auStack_38,-(uint)!bVar14 - iVar13);
        FUN_021a9c5c(auStack_38,0x20);
        lVar3 = lVar16;
      }
    }
    func_0x0200ecc4(param_1 + DAT_02187228);
    iVar13 = FUN_02187230(param_1);
  } while (iVar13 != 0);
  *(undefined4 *)(param_1 + 0x24) = 7;
LAB_0218720a:
  FUN_021ae094();
  FUN_021ae048();
  FUN_021ae258();
  FUN_021ae2f4();
  return;
}

