/* Decompiled C draft; module arm9_ov000; ROM address 02181b4c. No matching claim. */
#include "types.h"
#include "deps/02181b4c_FUN_02181b4c.h"

void FUN_02181b4c(void)

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
  psVar7 = (short *)(DAT_02181d04 + 0x2e0);
  if ((*(short *)(DAT_02181d04 + 0x2e0) == 0) && (*(ushort *)(DAT_02181d08 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_02181d0c + 0x2e0) == 0)) &&
     (*(short *)(DAT_02181d04 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar6 = func_0x0201ea84(*(undefined4 *)(*DAT_02181d10 + 0x30),
                            *(undefined2 *)(DAT_02181d14 + 0x2e0),
                            *(undefined2 *)(DAT_02181d18 + 0x2e0));
  }
  puVar8 = (ushort *)(DAT_02181d1c + 0x2e0);
  if ((*(ushort *)(DAT_02181d1c + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar7 == 0) && (*(ushort *)(DAT_02181d08 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_02181d0c + 0x2e0) == 0)) && (*psVar7 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_02181d14 + 0x2e0),
                                *(undefined2 *)(DAT_02181d18 + 0x2e0)), iVar3 == 0)) {
      if (((*puVar8 & 1) != 0) || (uVar6 < 3)) {
        iVar3 = *DAT_02181d10;
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
        if (*(int *)(*DAT_02181d10 + 8) == iVar5) {
          *(undefined4 *)(*DAT_02181d10 + 0x18) = 0;
        }
        piVar2 = DAT_02181d10;
        *(undefined4 *)(*DAT_02181d10 + 4) = 4;
        iVar5 = *piVar2;
        iVar3 = *(int *)(iVar5 + 8);
        if (iVar3 == 0) {
          iVar3 = func_0x0211fd68();
          if (iVar3 == 1) {
            *(undefined4 *)(*DAT_02181d10 + 0x10) = 2;
          }
          else {
            *(undefined4 *)(*DAT_02181d10 + 0x10) = 0;
          }
        }
        else if (iVar3 == 1) {
          *(undefined4 *)(iVar5 + 0x10) = 8;
        }
        else if (iVar3 == 2) {
          *(undefined4 *)(iVar5 + 0x10) = 0xd;
        }
        func_0x02105ac0(5);
        return;
      }
      iVar3 = func_0x020ae408(8,0x40);
      piVar2 = DAT_02181d10;
      if (iVar3 != 0) {
        *(int *)(*DAT_02181d10 + 8) = *(int *)(*DAT_02181d10 + 8) + -1;
        if (*(int *)(*piVar2 + 8) < 0) {
          *(undefined4 *)(*piVar2 + 8) = 2;
        }
        func_0x02105ac0(0);
        return;
      }
      iVar3 = func_0x020ae408(8,0x80);
      piVar2 = DAT_02181d10;
      if (iVar3 == 0) {
        return;
      }
      *(int *)(*DAT_02181d10 + 8) = *(int *)(*DAT_02181d10 + 8) + 1;
      if (2 < *(int *)(*piVar2 + 8)) {
        *(undefined4 *)(*piVar2 + 8) = 0;
      }
      func_0x02105ac0(0);
      return;
    }
  }
  piVar2 = DAT_02181d10;
  *(undefined4 *)(*DAT_02181d10 + 4) = 5;
  *(undefined4 *)(*piVar2 + 0x10) = 10;
  if (*(int *)(*piVar2 + 0x10) != 10) {
    return;
  }
  func_0x02128310(1);
  return;
}

