/* Decompiled C draft; module arm9_ov000; ROM address 02184f1c. No matching claim. */
#include "types.h"
#include "deps/02184f1c_FUN_02184f1c.h"

void FUN_02184f1c(void)

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
  psVar7 = (short *)(DAT_02185094 + 0x2e0);
  if ((*(short *)(DAT_02185094 + 0x2e0) == 0) && (*(ushort *)(DAT_02185098 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0218509c + 0x2e0) == 0)) &&
     (*(short *)(DAT_02185094 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    uVar6 = func_0x0201ea84(*(undefined4 *)(*DAT_021850a0 + 0x30),
                            *(undefined2 *)(DAT_021850a4 + 0x2e0),
                            *(undefined2 *)(DAT_021850a8 + 0x2e0));
  }
  puVar8 = (ushort *)(DAT_021850ac + 0x2e0);
  if ((*(ushort *)(DAT_021850ac + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar7 == 0) && (*(ushort *)(DAT_02185098 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0218509c + 0x2e0) == 0)) && (*psVar7 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_021850a4 + 0x2e0),
                                *(undefined2 *)(DAT_021850a8 + 0x2e0)), iVar3 == 0)) {
      if (((*puVar8 & 1) == 0) && (1 < uVar6)) {
        iVar3 = func_0x020ae408(8,0x40);
        if (iVar3 != 0) {
          iVar3 = *(int *)(*DAT_021850a0 + 8);
          if (0 < iVar3) {
            *(int *)(*DAT_021850a0 + 8) = iVar3 + -1;
            func_0x02105ac0(0);
            return;
          }
        }
        iVar3 = func_0x020ae408(8,0x80);
        if (iVar3 != 0) {
          iVar3 = *(int *)(*DAT_021850a0 + 8);
          if (iVar3 < 1) {
            *(int *)(*DAT_021850a0 + 8) = iVar3 + 1;
            func_0x02105ac0(0);
          }
        }
        return;
      }
      iVar3 = *DAT_021850a0;
      iVar5 = *(int *)(iVar3 + 8);
      if ((*puVar8 & 1) == 0) {
        if (uVar6 == 0) {
          *(undefined4 *)(iVar3 + 8) = 0;
        }
        else if (uVar6 == 1) {
          *(undefined4 *)(iVar3 + 8) = 1;
        }
      }
      piVar2 = DAT_021850a0;
      *(undefined4 *)(*DAT_021850a0 + 4) = 4;
      iVar3 = *piVar2;
      if (*(int *)(iVar3 + 8) == 0) {
        *(undefined4 *)(iVar3 + 0x10) = 0xb;
      }
      else if (*(int *)(iVar3 + 8) == 1) {
        *(undefined4 *)(iVar3 + 0x10) = 9;
      }
      if (*(int *)(*DAT_021850a0 + 8) == iVar5) {
        *(undefined4 *)(*DAT_021850a0 + 0x14) = 0;
      }
      func_0x02105ac0(5);
      return;
    }
  }
  piVar2 = DAT_021850a0;
  *(undefined4 *)(*DAT_021850a0 + 4) = 5;
  *(undefined4 *)(*piVar2 + 0x10) = 1;
  func_0x02128310(0);
  return;
}

