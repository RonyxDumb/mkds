/* Decompiled C draft; module arm9_ov001; ROM address 0219cba0. No matching claim. */
#include "types.h"
#include "deps/0219cba0_FUN_0219cba0.h"

void FUN_0219cba0(void)

{
  bool bVar1;
  int *piVar2;
  byte *pbVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  ushort *puVar8;
  short *psVar9;
  
  bVar4 = false;
  uVar6 = 0xffffffff;
  iVar7 = -4;
  bVar1 = false;
  psVar9 = (short *)(DAT_0219cd88 + 0x2e0);
  if ((*(short *)(DAT_0219cd88 + 0x2e0) == 0) && (*(ushort *)(DAT_0219cd8c + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0219cd90 + 0x2e0) == 0)) &&
     (*(short *)(DAT_0219cd88 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar6 = func_0x0201ea84(*(undefined4 *)(*DAT_0219cd94 + DAT_0219cd98),
                            *(undefined2 *)(DAT_0219cd9c + 0x2e0),
                            *(undefined2 *)(DAT_0219cda0 + 0x2e0));
  }
  iVar5 = 0;
  pbVar3 = DAT_0219cda4;
  do {
    if (uVar6 == *pbVar3) {
      iVar7 = iVar5;
    }
    pbVar3 = pbVar3 + 1;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 6);
  puVar8 = (ushort *)(DAT_0219cda8 + 0x2e0);
  if ((*(ushort *)(DAT_0219cda8 + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar9 == 0) && (*(ushort *)(DAT_0219cd8c + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0219cd90 + 0x2e0) == 0)) && (*psVar9 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar5 = func_0x02128210(*(undefined2 *)(DAT_0219cd9c + 0x2e0),
                                *(undefined2 *)(DAT_0219cda0 + 0x2e0)), iVar5 == 0)) {
      if (((*puVar8 & 1) == 0) && (iVar7 == -4)) {
        iVar7 = func_0x020ae408(8,0x40);
        piVar2 = DAT_0219cd94;
        if (iVar7 != 0) {
          *(int *)(*DAT_0219cd94 + 8) = *(int *)(*DAT_0219cd94 + 8) + -1;
          if (*(int *)(*piVar2 + 8) < 0) {
            *(undefined4 *)(*piVar2 + 8) = 5;
          }
          *(undefined4 *)(*DAT_0219cd94 + 0x10) = 6;
          func_0x02105ac0(0);
          return;
        }
        iVar7 = func_0x020ae408(8,0x80);
        piVar2 = DAT_0219cd94;
        if (iVar7 != 0) {
          *(int *)(*DAT_0219cd94 + 8) = *(int *)(*DAT_0219cd94 + 8) + 1;
          if (5 < *(int *)(*piVar2 + 8)) {
            *(undefined4 *)(*piVar2 + 8) = 0;
          }
          *(undefined4 *)(*DAT_0219cd94 + 0x10) = 6;
          func_0x02105ac0(0);
        }
        return;
      }
      iVar5 = *(int *)(*DAT_0219cd94 + 8);
      if ((*puVar8 & 1) == 0) {
        *(int *)(*DAT_0219cd94 + 8) = iVar7;
      }
      if (*(int *)(*DAT_0219cd94 + 8) == iVar5) {
        *(undefined4 *)(*DAT_0219cd94 + 0x20) = 0;
      }
      piVar2 = DAT_0219cd94;
      *(undefined4 *)(*DAT_0219cd94 + 0x28) = *(undefined4 *)(*DAT_0219cd94 + 8);
      *(undefined4 *)(*piVar2 + 4) = 3;
      *(undefined4 *)(*piVar2 + 0x10) = 6;
      func_0x02105ac0(5);
      return;
    }
  }
  piVar2 = DAT_0219cd94;
  if (*(int *)(*DAT_0219cdac + 8) == 2) {
    *(undefined4 *)(*DAT_0219cd94 + 4) = 4;
    func_0x02128310(0);
    *(undefined4 *)(*DAT_0219cd94 + 0x2c) = 0;
    return;
  }
  *(undefined4 *)(*DAT_0219cd94 + 4) = 6;
  *(undefined4 *)(*piVar2 + 0x28) = 0xfffffffd;
  if (*(int *)(*DAT_0219cdb0 + 0x20) == 0) {
    func_0x02128310(0);
    *(undefined4 *)(*DAT_0219cd94 + 0x2c) = 0;
    return;
  }
  func_0x02128310(1);
  *(undefined4 *)(*DAT_0219cd94 + 0x2c) = 1;
  return;
}

