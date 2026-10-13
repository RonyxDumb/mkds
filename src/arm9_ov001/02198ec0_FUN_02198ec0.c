/* Decompiled C draft; module arm9_ov001; ROM address 02198ec0. No matching claim. */
#include "types.h"
#include "deps/02198ec0_FUN_02198ec0.h"

void FUN_02198ec0(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  ushort *puVar8;
  short *psVar9;
  
  iVar4 = *(int *)(*DAT_02199200 + 8);
  bVar6 = false;
  iVar7 = -1;
  bVar1 = false;
  psVar9 = (short *)(DAT_02199204 + 0x2e0);
  if ((*(short *)(DAT_02199204 + 0x2e0) == 0) && (*(ushort *)(DAT_02199208 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0219920c + 0x2e0) == 0)) &&
     (*(short *)(DAT_02199204 + 0x2e0) != 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    iVar7 = func_0x0201ea84(*(undefined4 *)(*DAT_02199200 + 0x7c),
                            *(undefined2 *)(DAT_02199210 + 0x2e0),
                            *(undefined2 *)(DAT_02199214 + 0x2e0));
  }
  puVar8 = (ushort *)(DAT_02199218 + 0x2e0);
  if ((*(ushort *)(DAT_02199218 + 0x2e0) & 2) == 0) {
    bVar6 = false;
    bVar1 = false;
    if ((*psVar9 == 0) && (*(ushort *)(DAT_02199208 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0219920c + 0x2e0) == 0)) && (*psVar9 != 0)) {
      bVar6 = true;
    }
    if ((!bVar6) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_02199210 + 0x2e0),
                                *(undefined2 *)(DAT_02199214 + 0x2e0)), iVar3 == 0)) {
      piVar2 = DAT_02199200;
      if ((((*puVar8 & 1) == 0) || (*(int *)(*DAT_02199200 + 8) != 2)) && (iVar7 != 2)) {
        if (iVar7 == 0) {
          *(undefined4 *)(*DAT_02199200 + 8) = 0;
          iVar7 = *piVar2;
          iVar3 = iVar7 + 0xc;
          iVar7 = *(int *)(iVar7 + 8) * 4;
          *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + 1;
          func_0x02105ac0(10);
        }
        else if (iVar7 == 1) {
          *(undefined4 *)(*DAT_02199200 + 8) = 1;
          iVar7 = *piVar2;
          iVar3 = iVar7 + 0xc;
          iVar7 = *(int *)(iVar7 + 8) * 4;
          *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + 1;
          func_0x02105ac0();
        }
        else {
          iVar3 = func_0x020ae408(8,0x40);
          piVar2 = DAT_02199200;
          if (iVar3 == 0) {
            iVar3 = func_0x020ae408(8,0x80);
            piVar2 = DAT_02199200;
            if ((iVar3 == 0) && ((*(int *)(*DAT_02199200 + 8) == 2 || ((*puVar8 & 1) == 0)))) {
              if ((*(int *)(*DAT_02199200 + 8) == 2) ||
                 (iVar3 = func_0x020ae408(8,0x20), piVar2 = DAT_02199200, iVar3 == 0)) {
                if ((*(int *)(*DAT_02199200 + 8) == 2) ||
                   (iVar3 = func_0x020ae408(8,0x10), iVar3 == 0)) {
                  piVar2 = DAT_02199200;
                  if (iVar7 == 3) {
                    *(undefined4 *)(*DAT_02199200 + 8) = 0;
                    iVar3 = *piVar2 + 0xc;
                    iVar7 = *(int *)(*piVar2 + 8) * 4;
                    *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + -1;
                    *(undefined4 *)(*piVar2 + *(int *)(*piVar2 + 8) * 8 + 0x40) = 6;
                    func_0x02105ac0(10);
                  }
                  else if (iVar7 == 4) {
                    *(undefined4 *)(*DAT_02199200 + 8) = 0;
                    iVar3 = *piVar2 + 0xc;
                    iVar7 = *(int *)(*piVar2 + 8) * 4;
                    *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + 1;
                    *(undefined4 *)(*piVar2 + *(int *)(*piVar2 + 8) * 8 + 0x44) = 6;
                    func_0x02105ac0(10);
                  }
                  else if (iVar7 == 5) {
                    *(undefined4 *)(*DAT_02199200 + 8) = 1;
                    iVar3 = *piVar2 + 0xc;
                    iVar7 = *(int *)(*piVar2 + 8) * 4;
                    *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + -1;
                    *(undefined4 *)(*piVar2 + *(int *)(*piVar2 + 8) * 8 + 0x40) = 6;
                    func_0x02105ac0();
                  }
                  else if (iVar7 == 6) {
                    *(undefined4 *)(*DAT_02199200 + 8) = 1;
                    iVar3 = *piVar2 + 0xc;
                    iVar7 = *(int *)(*piVar2 + 8) * 4;
                    *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + 1;
                    *(undefined4 *)(*piVar2 + *(int *)(*piVar2 + 8) * 8 + 0x44) = 6;
                    func_0x02105ac0();
                  }
                }
                else {
                  iVar3 = *DAT_02199200 + 0xc;
                  iVar7 = *(int *)(*DAT_02199200 + 8) * 4;
                  *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + 1;
                  iVar7 = func_0x020ae408(8,0x10);
                  if (iVar7 != 0) {
                    *(undefined4 *)(*DAT_02199200 + *(int *)(*DAT_02199200 + 8) * 8 + 0x44) = 6;
                  }
                  if (*(int *)(*DAT_02199200 + 8) == 0) {
                    func_0x02105ac0(10);
                  }
                  else {
                    func_0x02105ac0(1);
                  }
                }
              }
              else {
                iVar3 = *DAT_02199200 + 0xc;
                iVar7 = *(int *)(*DAT_02199200 + 8) * 4;
                *(int *)(iVar3 + iVar7) = *(int *)(iVar3 + iVar7) + -1;
                iVar7 = *piVar2;
                *(undefined4 *)(iVar7 + *(int *)(iVar7 + 8) * 8 + 0x40) = 6;
                if (*(int *)(*piVar2 + 8) == 0) {
                  func_0x02105ac0(10);
                }
                else {
                  func_0x02105ac0(1);
                }
              }
            }
            else {
              *(int *)(*DAT_02199200 + 8) = *(int *)(*DAT_02199200 + 8) + 1;
              if (2 < *(int *)(*piVar2 + 8)) {
                *(undefined4 *)(*piVar2 + 8) = 0;
              }
              func_0x02105ac0(0);
            }
          }
          else {
            *(int *)(*DAT_02199200 + 8) = *(int *)(*DAT_02199200 + 8) + -1;
            if (*(int *)(*piVar2 + 8) < 0) {
              *(undefined4 *)(*piVar2 + 8) = 2;
            }
            func_0x02105ac0(0);
          }
        }
      }
      else {
        FUN_021993b8();
        if (*(int *)(*DAT_02199200 + 0x10) == 0) {
          *(byte *)(*(int *)*DAT_0219921c + 0x31) = *(byte *)(*(int *)*DAT_0219921c + 0x31) & 0xef;
        }
        else {
          *(byte *)(*(int *)*DAT_0219921c + 0x31) = *(byte *)(*(int *)*DAT_0219921c + 0x31) | 0x10;
        }
        func_0x02056d40();
        if (*(int *)(*DAT_02199200 + 8) == 2) {
          *(undefined4 *)(*DAT_02199200 + 0x38) = 0;
        }
        piVar2 = DAT_02199200;
        *(undefined4 *)(*DAT_02199200 + 4) = 3;
        *(undefined4 *)(*piVar2 + 0x34) = 0;
        *(undefined4 *)(*piVar2 + 8) = 2;
        *(undefined4 *)(*piVar2 + 0x1c) = 1;
        func_0x0212b7e8();
        func_0x02105ac0(5);
      }
      goto LAB_02199244;
    }
  }
  piVar2 = DAT_02199200;
  *(undefined4 *)(*DAT_02199200 + 4) = 4;
  iVar3 = 0;
  *(undefined4 *)(*piVar2 + 0x34) = 0;
  iVar7 = 0;
  do {
    iVar5 = *piVar2 + iVar7;
    *(undefined4 *)(iVar5 + 0xc) = *(undefined4 *)(iVar5 + 0x14);
    iVar7 = iVar7 + 4;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 2);
  func_0x02128310(0);
LAB_02199244:
  if (*(int *)(*DAT_0219929c + 0xc) < 0) {
    *(undefined4 *)(*DAT_0219929c + 0xc) = 2;
  }
  if (2 < *(int *)(*DAT_0219929c + 0xc)) {
    *(undefined4 *)(*DAT_0219929c + 0xc) = 0;
  }
  if (*(int *)(*DAT_0219929c + 0x10) < 0) {
    *(undefined4 *)(*DAT_0219929c + 0x10) = 1;
  }
  if (1 < *(int *)(*DAT_0219929c + 0x10)) {
    *(undefined4 *)(*DAT_0219929c + 0x10) = 0;
  }
  if ((*(int *)(*DAT_0219929c + 8) == 2) && (iVar4 != 2)) {
    func_0x0212b7fc();
  }
  FUN_02199420();
  return;
}

