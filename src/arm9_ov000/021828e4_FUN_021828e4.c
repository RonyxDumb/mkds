/* Decompiled C draft; module arm9_ov000; ROM address 021828e4. No matching claim. */
#include "types.h"
#include "deps/021828e4_FUN_021828e4.h"

void FUN_021828e4(void)

{
  ushort uVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  int iVar9;
  ushort *puVar10;
  short *psVar11;
  
  iVar4 = *DAT_02182c1c;
  iVar6 = *(int *)(iVar4 + 8);
  iVar7 = *(int *)(iVar4 + 0xc);
  bVar8 = false;
  iVar9 = -1;
  bVar2 = false;
  psVar11 = (short *)(DAT_02182c20 + 0x2e0);
  if ((*(short *)(DAT_02182c20 + 0x2e0) == 0) && (*(ushort *)(DAT_02182c24 + 0x2e0) < 5)) {
    bVar2 = true;
  }
  if (((!bVar2) && (*(short *)(DAT_02182c28 + 0x2e0) == 0)) &&
     (*(short *)(DAT_02182c20 + 0x2e0) != 0)) {
    bVar8 = true;
  }
  if (bVar8) {
    iVar9 = func_0x0201ea84(*(undefined4 *)(iVar4 + DAT_02182c2c),
                            *(undefined2 *)(DAT_02182c30 + 0x2e0),
                            *(undefined2 *)(DAT_02182c34 + 0x2e0));
  }
  puVar10 = (ushort *)(DAT_02182c38 + 0x2e0);
  if ((*(ushort *)(DAT_02182c38 + 0x2e0) & 2) == 0) {
    bVar8 = false;
    bVar2 = false;
    if ((*psVar11 == 0) && (*(ushort *)(DAT_02182c24 + 0x2e0) < 5)) {
      bVar2 = true;
    }
    if (((!bVar2) && (*(short *)(DAT_02182c28 + 0x2e0) == 0)) && (*psVar11 != 0)) {
      bVar8 = true;
    }
    if ((!bVar8) ||
       (iVar4 = func_0x02128210(*(undefined2 *)(DAT_02182c30 + 0x2e0),
                                *(undefined2 *)(DAT_02182c34 + 0x2e0)), iVar4 == 0)) {
      piVar3 = DAT_02182c1c;
      uVar1 = *puVar10;
      if ((((uVar1 & 1) == 0) || (*(int *)(*DAT_02182c1c + 8) != 2)) && (iVar9 != 2)) {
        if ((((uVar1 & 1) == 0) || (*(int *)(*DAT_02182c1c + 8) != 0)) && (iVar9 != 0)) {
          if (iVar9 == 1) {
            *(undefined4 *)(*DAT_02182c1c + 8) = 1;
            *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
            func_0x02105ac0();
          }
          else {
            iVar4 = func_0x020ae408(8,0x40);
            piVar3 = DAT_02182c1c;
            if (iVar4 == 0) {
              iVar4 = func_0x020ae408(8,0x80);
              piVar3 = DAT_02182c1c;
              if ((iVar4 == 0) && ((*(int *)(*DAT_02182c1c + 8) != 1 || ((*puVar10 & 1) == 0)))) {
                if ((*(int *)(*DAT_02182c1c + 8) == 1) &&
                   (iVar4 = func_0x020ae408(8,0x20), piVar3 = DAT_02182c1c, iVar4 != 0)) {
                  *(int *)(*DAT_02182c1c + 0xc) = *(int *)(*DAT_02182c1c + 0xc) + -1;
                  *(undefined4 *)(*piVar3 + 0x2c) = 6;
                  func_0x02105ac0(1);
                }
                else if ((*(int *)(*DAT_02182c1c + 8) == 1) &&
                        (iVar4 = func_0x020ae408(8,0x10), iVar4 != 0)) {
                  *(int *)(*DAT_02182c1c + 0xc) = *(int *)(*DAT_02182c1c + 0xc) + 1;
                  iVar4 = func_0x020ae408(8,0x10);
                  if (iVar4 != 0) {
                    *(undefined4 *)(*DAT_02182c1c + 0x30) = 6;
                  }
                  func_0x02105ac0(1);
                }
                else {
                  piVar3 = DAT_02182c1c;
                  if (iVar9 == 3) {
                    *(undefined4 *)(*DAT_02182c1c + 8) = 1;
                    *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + -1;
                    *(undefined4 *)(*piVar3 + 0x2c) = 6;
                    func_0x02105ac0();
                  }
                  else if (iVar9 == 4) {
                    *(undefined4 *)(*DAT_02182c1c + 8) = 1;
                    *(int *)(*piVar3 + 0xc) = *(int *)(*piVar3 + 0xc) + 1;
                    *(undefined4 *)(*piVar3 + 0x30) = 6;
                    func_0x02105ac0();
                  }
                }
              }
              else {
                *(int *)(*DAT_02182c1c + 8) = *(int *)(*DAT_02182c1c + 8) + 1;
                if (2 < *(int *)(*piVar3 + 8)) {
                  *(undefined4 *)(*piVar3 + 8) = 0;
                }
                func_0x02105ac0(0);
              }
            }
            else {
              *(int *)(*DAT_02182c1c + 8) = *(int *)(*DAT_02182c1c + 8) + -1;
              if (*(int *)(*piVar3 + 8) < 0) {
                *(undefined4 *)(*piVar3 + 8) = 2;
              }
              func_0x02105ac0(0);
            }
          }
        }
        else {
          *(undefined4 *)(*DAT_02182c1c + 4) = 5;
          if (*(int *)(*piVar3 + 8) == 0) {
            *(undefined4 *)(*piVar3 + 0x24) = 0;
          }
          piVar3 = DAT_02182c1c;
          *(undefined4 *)(*DAT_02182c1c + 0x20) = 0xe;
          *(undefined4 *)(*piVar3 + 8) = 0;
          *(undefined4 *)(*DAT_02182c40 + 0x50) = 0;
          func_0x02125fc0();
          func_0x02105ac0(5);
          *(undefined1 *)(*DAT_02182c40 + 0x54) =
               *(undefined1 *)(DAT_02182c3c + *(int *)(*DAT_02182c1c + 0xc));
          func_0x0211fe44();
        }
      }
      else {
        *(undefined4 *)(*DAT_02182c1c + 4) = 5;
        if (*(int *)(*piVar3 + 8) == 2) {
          *(undefined4 *)(*piVar3 + 0x24) = 0;
        }
        piVar3 = DAT_02182c1c;
        *(undefined4 *)(*DAT_02182c1c + 0x20) = 3;
        *(undefined4 *)(*piVar3 + 8) = 2;
        *(undefined1 *)(*DAT_02182c40 + 0x54) =
             *(undefined1 *)(DAT_02182c3c + *(int *)(*piVar3 + 0xc));
        if ((*(ushort *)(DAT_02182c44 + 0x2e0) & DAT_02182c48) != 0) {
          func_ov000_02180638(1);
        }
        func_ov000_02180650(*(undefined4 *)(*DAT_02182c1c + 0xc));
        func_0x02105ac0(5);
      }
      goto LAB_02182ba6;
    }
  }
  piVar3 = DAT_02182c1c;
  *(undefined4 *)(*DAT_02182c1c + 4) = 6;
  *(undefined4 *)(*piVar3 + 0x20) = 1;
  func_0x02128310();
  *(undefined4 *)(*DAT_02182c1c + 0x28) = 1;
  func_0x02125fc0();
LAB_02182ba6:
  if (*(int *)(*DAT_02182c1c + 0xc) < 0) {
    *(undefined4 *)(*DAT_02182c1c + 0xc) = 3;
  }
  if (3 < *(int *)(*DAT_02182c1c + 0xc)) {
    *(undefined4 *)(*DAT_02182c1c + 0xc) = 0;
  }
  if (iVar7 != *(int *)(*DAT_02182c1c + 0xc)) {
    uVar5 = func_ov000_02180668();
    iVar4 = *DAT_02182c1c;
    uVar5 = func_0x020b3f7c(*(undefined4 *)(iVar4 + DAT_02182c4c),uVar5);
    func_0x0212426c(1,*(undefined1 *)(DAT_02182c58 + 1),
                    *(undefined4 *)(*DAT_02182c1c + DAT_02182c5c),uVar5,
                    *(undefined4 *)(iVar4 + DAT_02182c50),*(undefined4 *)(iVar4 + DAT_02182c54));
  }
  if ((*(int *)(*DAT_02182c1c + 8) == 2) && (iVar6 != 2)) {
    func_0x0212b7fc();
  }
  return;
}

