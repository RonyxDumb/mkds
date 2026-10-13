/* Decompiled C draft; module arm9_ov001; ROM address 0219a5bc. No matching claim. */
#include "types.h"
#include "deps/0219a5bc_FUN_0219a5bc.h"

void FUN_0219a5bc(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  uint uVar5;
  short *psVar6;
  ushort *puVar7;
  
  bVar4 = false;
  uVar5 = 0xffffffff;
  bVar1 = false;
  psVar6 = (short *)(DAT_0219a740 + 0x2e0);
  if ((*(short *)(DAT_0219a740 + 0x2e0) == 0) && (*(ushort *)(DAT_0219a744 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0219a748 + 0x2e0) == 0)) &&
     (*(short *)(DAT_0219a740 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar5 = func_0x0201ea84(*(undefined4 *)(*DAT_0219a74c + 0x14),
                            *(undefined2 *)(DAT_0219a750 + 0x2e0),
                            *(undefined2 *)(DAT_0219a754 + 0x2e0));
  }
  puVar7 = (ushort *)(DAT_0219a758 + 0x2e0);
  if ((*(ushort *)(DAT_0219a758 + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar6 == 0) && (*(ushort *)(DAT_0219a744 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0219a748 + 0x2e0) == 0)) && (*psVar6 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_0219a750 + 0x2e0),
                                *(undefined2 *)(DAT_0219a754 + 0x2e0)), iVar3 == 0)) {
      if (uVar5 < 3) {
        iVar3 = *(int *)(DAT_0219a75c + uVar5 * 4);
        if (*(int *)(*(int *)(*DAT_0219a74c + 0x1c) +
                    (uint)*(ushort *)(DAT_0219a760 + iVar3 * 2) * 0x40) != 0) {
          if (*(int *)(*DAT_0219a74c + 0x40) == iVar3) {
            FUN_0219af90();
            *(int *)(*DAT_0219a74c + 0x40) = iVar3;
          }
          else {
            FUN_0219af90();
            piVar2 = DAT_0219a74c;
            *(int *)(*DAT_0219a74c + 0x40) = iVar3;
            FUN_0219afc8(*(undefined4 *)(*piVar2 + 0x40));
          }
          FUN_0219ae10();
          return;
        }
      }
      else {
        if ((*puVar7 & 1) != 0) {
          FUN_0219af90(*(undefined4 *)(*DAT_0219a74c + 0x40));
          FUN_0219ae10();
          return;
        }
        iVar3 = func_0x020ae408(8,0x40);
        if (iVar3 != 0) {
          FUN_0219af90(*(undefined4 *)(*DAT_0219a74c + 0x40));
          FUN_0219ad10();
          FUN_0219afc8(*(undefined4 *)(*DAT_0219a74c + 0x40));
          return;
        }
        iVar3 = func_0x020ae408(8,0x80);
        if (iVar3 != 0) {
          FUN_0219af90(*(undefined4 *)(*DAT_0219a74c + 0x40));
          FUN_0219ad3c();
          FUN_0219afc8(*(undefined4 *)(*DAT_0219a74c + 0x40));
        }
      }
      return;
    }
  }
  func_0x021281c8(0xf);
  FUN_0219adfc();
  *(undefined4 *)(*DAT_0219a74c + 0x44) = 5;
  func_0x02128310(1);
  return;
}

