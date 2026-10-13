/* Decompiled C draft; module arm9_ov001; ROM address 02193774. No matching claim. */
#include "types.h"
#include "deps/02193774_FUN_02193774.h"

void FUN_02193774(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  short *psVar7;
  ushort *puVar8;
  
  bVar4 = false;
  uVar6 = 0xffffffff;
  bVar1 = false;
  psVar7 = (short *)(DAT_02193908 + 0x2e0);
  if ((*(short *)(DAT_02193908 + 0x2e0) == 0) && (*(ushort *)(DAT_0219390c + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_02193910 + 0x2e0) == 0)) &&
     (*(short *)(DAT_02193908 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar6 = func_0x0201ea84(*(undefined4 *)(*DAT_02193914 + 0x34),
                            *(undefined2 *)(DAT_02193918 + 0x2e0),
                            *(undefined2 *)(DAT_0219391c + 0x2e0));
  }
  puVar8 = (ushort *)(DAT_02193920 + 0x2e0);
  if ((*(ushort *)(DAT_02193920 + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar7 == 0) && (*(ushort *)(DAT_0219390c + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_02193910 + 0x2e0) == 0)) && (*psVar7 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_02193918 + 0x2e0),
                                *(undefined2 *)(DAT_0219391c + 0x2e0)), iVar3 == 0)) {
      if (((*puVar8 & 1) == 0) && (2 < uVar6)) {
        iVar3 = func_0x020ae408(8,0x40);
        piVar2 = DAT_02193914;
        if (iVar3 == 0) {
          iVar3 = func_0x020ae408(8,0x80);
          piVar2 = DAT_02193914;
          if (iVar3 != 0) {
            *(int *)(*DAT_02193914 + 8) = *(int *)(*DAT_02193914 + 8) + 1;
            if (2 < *(int *)(*piVar2 + 8)) {
              *(undefined4 *)(*piVar2 + 8) = 0;
            }
            func_0x02105ac0(0);
          }
          return;
        }
        *(int *)(*DAT_02193914 + 8) = *(int *)(*DAT_02193914 + 8) + -1;
        if (*(int *)(*piVar2 + 8) < 0) {
          *(undefined4 *)(*piVar2 + 8) = 2;
        }
        func_0x02105ac0(0);
        return;
      }
      iVar3 = *DAT_02193914;
      iVar5 = *(int *)(iVar3 + 8);
      if ((*puVar8 & 1) == 0) {
        if (uVar6 == 0) {
          *(undefined4 *)(iVar3 + 8) = 0;
        }
        else if (uVar6 == 1) {
          *(undefined4 *)(iVar3 + 8) = 1;
        }
        else if (uVar6 == 2) {
          *(undefined4 *)(iVar3 + 8) = 2;
        }
      }
      piVar2 = DAT_02193914;
      *(undefined4 *)(*DAT_02193914 + 4) = 4;
      iVar3 = *piVar2;
      if (*(int *)(iVar3 + 8) == 0) {
        *(undefined4 *)(iVar3 + 0x10) = 1;
      }
      else if (*(int *)(iVar3 + 8) == 1) {
        *(undefined4 *)(iVar3 + 0x10) = 2;
      }
      if (*(int *)(*DAT_02193914 + 8) == iVar5) {
        *(undefined4 *)(*DAT_02193914 + 0x14) = 0;
      }
      func_0x02105ac0(5);
      return;
    }
  }
  piVar2 = DAT_02193914;
  *(undefined4 *)(*DAT_02193914 + 4) = 5;
  *(undefined4 *)(*piVar2 + 0x10) = 4;
  func_0x02128310(1);
  return;
}

