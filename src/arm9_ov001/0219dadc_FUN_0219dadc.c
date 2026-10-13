/* Decompiled C draft; module arm9_ov001; ROM address 0219dadc. No matching claim. */
#include "types.h"
#include "deps/0219dadc_FUN_0219dadc.h"

void FUN_0219dadc(void)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  int iVar5;
  short *psVar6;
  ushort *puVar7;
  
  bVar4 = false;
  iVar5 = -1;
  bVar1 = false;
  psVar6 = (short *)(DAT_0219dd50 + 0x2e0);
  if ((*(short *)(DAT_0219dd50 + 0x2e0) == 0) && (*(ushort *)(DAT_0219dd54 + 0x2e0) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0219dd58 + 0x2e0) == 0)) &&
     (*(short *)(DAT_0219dd50 + 0x2e0) != 0)) {
    bVar4 = true;
  }
  if (bVar4) {
    iVar5 = func_0x0201ea84(*(undefined4 *)(*DAT_0219dd5c + 0x48),
                            *(undefined2 *)(DAT_0219dd60 + 0x2e0),
                            *(undefined2 *)(DAT_0219dd64 + 0x2e0));
  }
  puVar7 = (ushort *)(DAT_0219dd68 + 0x2e0);
  if ((*(ushort *)(DAT_0219dd68 + 0x2e0) & 2) == 0) {
    bVar4 = false;
    bVar1 = false;
    if ((*psVar6 == 0) && (*(ushort *)(DAT_0219dd54 + 0x2e0) < 5)) {
      bVar1 = true;
    }
    if (((!bVar1) && (*(short *)(DAT_0219dd58 + 0x2e0) == 0)) && (*psVar6 != 0)) {
      bVar4 = true;
    }
    if ((!bVar4) ||
       (iVar3 = func_0x02128210(*(undefined2 *)(DAT_0219dd60 + 0x2e0),
                                *(undefined2 *)(DAT_0219dd64 + 0x2e0)), iVar3 == 0)) {
      piVar2 = DAT_0219dd5c;
      if ((((*puVar7 & 1) == 0) || (*(int *)(*DAT_0219dd5c + 8) != 0)) && (iVar5 != 0)) {
        if (iVar5 == 1) {
          *(undefined4 *)(*DAT_0219dd5c + 8) = 1;
          *(int *)(*piVar2 + 0xc) = *(int *)(*piVar2 + 0xc) + 1;
          func_0x02105ac0();
        }
        else {
          iVar3 = func_0x020ae408(8,0x40);
          if (iVar3 != 0) {
            iVar3 = *(int *)(*DAT_0219dd5c + 8);
            if (0 < iVar3) {
              *(int *)(*DAT_0219dd5c + 8) = iVar3 + -1;
              func_0x02105ac0(0);
              goto LAB_0219dd2a;
            }
          }
          iVar3 = func_0x020ae408(8,0x80);
          if (iVar3 != 0) {
            iVar3 = *(int *)(*DAT_0219dd5c + 8);
            if (iVar3 < 1) {
              *(int *)(*DAT_0219dd5c + 8) = iVar3 + 1;
              func_0x02105ac0(0);
              goto LAB_0219dd2a;
            }
          }
          if ((*(int *)(*DAT_0219dd5c + 8) == 1) &&
             (iVar3 = func_0x020ae408(8,0x20), piVar2 = DAT_0219dd5c, iVar3 != 0)) {
            *(int *)(*DAT_0219dd5c + 0xc) = *(int *)(*DAT_0219dd5c + 0xc) + -1;
            *(undefined4 *)(*piVar2 + 0x28) = 6;
            func_0x02105ac0(1);
          }
          else if ((*(int *)(*DAT_0219dd5c + 8) == 1) &&
                  (iVar3 = func_0x020ae408(8,0x10), iVar3 != 0)) {
            *(int *)(*DAT_0219dd5c + 0xc) = *(int *)(*DAT_0219dd5c + 0xc) + 1;
            iVar5 = func_0x020ae408(8,0x10);
            if (iVar5 != 0) {
              *(undefined4 *)(*DAT_0219dd5c + 0x2c) = 6;
            }
            func_0x02105ac0(1);
          }
          else {
            piVar2 = DAT_0219dd5c;
            if (iVar5 == 2) {
              *(undefined4 *)(*DAT_0219dd5c + 8) = 1;
              *(int *)(*piVar2 + 0xc) = *(int *)(*piVar2 + 0xc) + -1;
              *(undefined4 *)(*piVar2 + 0x28) = 6;
              func_0x02105ac0();
            }
            else if (iVar5 == 3) {
              *(undefined4 *)(*DAT_0219dd5c + 8) = 1;
              *(int *)(*piVar2 + 0xc) = *(int *)(*piVar2 + 0xc) + 1;
              *(undefined4 *)(*piVar2 + 0x2c) = 6;
              func_0x02105ac0();
            }
          }
        }
      }
      else {
        if (*(int *)(*DAT_0219dd5c + 8) == 0) {
          *(undefined4 *)(*DAT_0219dd5c + 0x24) = 0;
        }
        piVar2 = DAT_0219dd5c;
        *(undefined4 *)(*DAT_0219dd5c + 4) = 4;
        *(undefined4 *)(*piVar2 + 0x20) = 6;
        *(undefined4 *)(*piVar2 + 8) = 0;
        *(undefined4 *)(*DAT_0219dd70 + 0x18) = 1;
        func_0x02105ac0(5);
      }
      goto LAB_0219dd2a;
    }
  }
  piVar2 = DAT_0219dd5c;
  *(undefined4 *)(*DAT_0219dd5c + 4) = 5;
  *(undefined4 *)(*piVar2 + 0x20) = 2;
  iVar5 = *piVar2;
  if (*(int *)(iVar5 + 0xc) == *(int *)(iVar5 + 0x10)) {
    func_0x02128310(0);
  }
  else {
    func_0x02128310(1);
  }
  if (*(int *)(*DAT_0219dd5c + 0xc) == 0) {
    *(byte *)(*(int *)*DAT_0219dd6c + 0x31) = *(byte *)(*(int *)*DAT_0219dd6c + 0x31) & 0xf7;
  }
  else {
    *(byte *)(*(int *)*DAT_0219dd6c + 0x31) = *(byte *)(*(int *)*DAT_0219dd6c + 0x31) | 8;
  }
  func_0x02056d40();
LAB_0219dd2a:
  if (*(int *)(*DAT_0219dd5c + 0xc) < 0) {
    *(undefined4 *)(*DAT_0219dd5c + 0xc) = 1;
  }
  if (1 < *(int *)(*DAT_0219dd5c + 0xc)) {
    *(undefined4 *)(*DAT_0219dd5c + 0xc) = 0;
  }
  return;
}

