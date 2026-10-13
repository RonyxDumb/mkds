/* Decompiled C draft; module arm9_ov001; ROM address 02196514. No matching claim. */
#include "types.h"
#include "deps/02196514_FUN_02196514.h"

void FUN_02196514(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  ushort *puVar4;
  int iVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  short *psVar9;
  
  iVar8 = -1;
  FUN_02196cd0();
  bVar6 = true;
  bVar7 = false;
  psVar9 = (short *)(DAT_021966fc + 0x2e0);
  if ((*(short *)(DAT_021966fc + 0x2e0) == 0) && (*(ushort *)(DAT_02196700 + 0x2e0) < 5)) {
    bVar7 = true;
  }
  if ((!bVar7) && (*(short *)(DAT_021966fc + 0x2e0) == 0)) {
    bVar6 = false;
  }
  iVar3 = iVar8;
  if (bVar6) {
    iVar3 = func_0x0201ea84(*(undefined4 *)(*DAT_02196704 + 0x20),
                            *(undefined2 *)(DAT_02196708 + 0x2e0),
                            *(undefined2 *)(DAT_0219670c + 0x2e0));
  }
  bVar7 = false;
  bVar6 = false;
  sVar1 = *psVar9;
  if ((sVar1 == 0) && (*(ushort *)(DAT_02196700 + 0x2e0) < 5)) {
    bVar6 = true;
  }
  if (((!bVar6) && (*(short *)(DAT_02196710 + 0x2e0) == 0)) && (sVar1 != 0)) {
    bVar7 = true;
  }
  if (bVar7) {
    iVar8 = func_0x0201ea84(*(undefined4 *)(*DAT_02196704 + 0x20),
                            *(undefined2 *)(DAT_02196708 + 0x2e0),
                            *(undefined2 *)(DAT_0219670c + 0x2e0));
  }
  if (iVar3 != 0) {
    *(undefined4 *)(*DAT_02196704 + 0x88) = 0;
  }
  if (iVar3 != 1) {
    *(undefined4 *)(*DAT_02196704 + 0x8c) = 0;
  }
  puVar4 = (ushort *)(DAT_02196714 + 0x2e0);
  if ((*(ushort *)(DAT_02196714 + 0x2e0) & 2) == 0) {
    bVar7 = false;
    bVar6 = false;
    sVar1 = *psVar9;
    if ((sVar1 == 0) && (*(ushort *)(DAT_02196700 + 0x2e0) < 5)) {
      bVar6 = true;
    }
    if (((!bVar6) && (*(short *)(DAT_02196710 + 0x2e0) == 0)) && (sVar1 != 0)) {
      bVar7 = true;
    }
    if ((!bVar7) ||
       (iVar5 = func_0x02128210(*(undefined2 *)(DAT_02196708 + 0x2e0),
                                *(undefined2 *)(DAT_0219670c + 0x2e0)), iVar5 == 0)) {
      piVar2 = DAT_02196704;
      if ((iVar8 == 2) || ((*puVar4 & DAT_02196718) != 0)) {
        FUN_02196f80();
      }
      else {
        if (((iVar3 != 0) || (*(int *)(*DAT_02196704 + 0x88) == 0)) &&
           ((iVar8 != 0 || (*(int *)(*DAT_02196704 + 0x88) != 0)))) {
          if ((*(ushort *)(DAT_0219671c + 0x2e0) & 0x20) == 0) {
            if (((iVar3 != 1) || (*(int *)(*DAT_02196704 + 0x8c) == 0)) &&
               ((iVar8 != 1 || (*(int *)(*DAT_02196704 + 0x8c) != 0)))) {
              if ((*(ushort *)(DAT_0219671c + 0x2e0) & 0x10) == 0) goto LAB_021966de;
            }
            *(undefined4 *)(*DAT_02196704 + 0x70) = 0;
            *(undefined4 *)(*piVar2 + 0x7c) = 6;
            *(undefined4 *)(*piVar2 + 0x8c) = 1;
            FUN_02197010();
            func_0x0212ecc0(DAT_02196720,0,2);
            goto LAB_021966de;
          }
        }
        *(undefined4 *)(*DAT_02196704 + 0x70) = 1;
        *(undefined4 *)(*piVar2 + 0x78) = 6;
        *(undefined4 *)(*piVar2 + 0x88) = 1;
        FUN_02197010();
        func_0x0212ecc0(DAT_02196720,0,2);
      }
      goto LAB_021966de;
    }
  }
  FUN_02196fc4();
  *(undefined4 *)(*DAT_02196704 + 0x90) = 0;
  func_0x02128310();
LAB_021966de:
  iVar8 = FUN_02196c4c();
  if ((iVar8 != 0) && (iVar8 = FUN_02197210(), iVar8 != 0)) {
    FUN_02196e30();
  }
  return;
}

