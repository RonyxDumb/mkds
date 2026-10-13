/* Decompiled C draft; module arm9_ov001; ROM address 021942f8. No matching claim. */
#include "types.h"
#include "deps/021942f8_FUN_021942f8.h"

void FUN_021942f8(void)

{
  short sVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  int iVar7;
  short *psVar8;
  
  iVar7 = -1;
  FUN_02194f20();
  bVar2 = true;
  bVar6 = false;
  psVar8 = (short *)(DAT_021944bc + 0x2e0);
  if ((*(short *)(DAT_021944bc + 0x2e0) == 0) && (*(ushort *)(DAT_021944c0 + 0x2e0) < 5)) {
    bVar6 = true;
  }
  if ((!bVar6) && (*(short *)(DAT_021944bc + 0x2e0) == 0)) {
    bVar2 = false;
  }
  iVar4 = iVar7;
  if (bVar2) {
    iVar4 = func_0x0201ea84(*(undefined4 *)(*DAT_021944c4 + 0x20),
                            *(undefined2 *)(DAT_021944c8 + 0x2e0),
                            *(undefined2 *)(DAT_021944cc + 0x2e0));
  }
  bVar6 = false;
  bVar2 = false;
  sVar1 = *psVar8;
  if ((sVar1 == 0) && (*(ushort *)(DAT_021944c0 + 0x2e0) < 5)) {
    bVar2 = true;
  }
  if (((!bVar2) && (*(short *)(DAT_021944d0 + 0x2e0) == 0)) && (sVar1 != 0)) {
    bVar6 = true;
  }
  if (bVar6) {
    iVar7 = func_0x0201ea84(*(undefined4 *)(*DAT_021944c4 + 0x20),
                            *(undefined2 *)(DAT_021944c8 + 0x2e0),
                            *(undefined2 *)(DAT_021944cc + 0x2e0));
  }
  if (iVar4 != 0) {
    *(undefined4 *)(*DAT_021944c4 + 0x88) = 0;
  }
  if (iVar4 != 1) {
    *(undefined4 *)(*DAT_021944c4 + 0x8c) = 0;
  }
  if ((*(ushort *)(DAT_021944d4 + 0x2e0) & 2) == 0) {
    bVar6 = false;
    bVar2 = false;
    sVar1 = *psVar8;
    if ((sVar1 == 0) && (*(ushort *)(DAT_021944c0 + 0x2e0) < 5)) {
      bVar2 = true;
    }
    if (((!bVar2) && (*(short *)(DAT_021944d0 + 0x2e0) == 0)) && (sVar1 != 0)) {
      bVar6 = true;
    }
    if ((!bVar6) ||
       (iVar5 = func_0x02128210(*(undefined2 *)(DAT_021944c8 + 0x2e0),
                                *(undefined2 *)(DAT_021944cc + 0x2e0)), iVar5 == 0)) {
      piVar3 = DAT_021944c4;
      if (((iVar4 != 0) || (*(int *)(*DAT_021944c4 + 0x88) == 0)) &&
         (((iVar7 != 0 || (*(int *)(*DAT_021944c4 + 0x88) != 0)) &&
          ((*(ushort *)(DAT_021944d8 + 0x2e0) & 0x20) == 0)))) {
        if ((((iVar4 == 1) && (*(int *)(*DAT_021944c4 + 0x8c) != 0)) ||
            ((iVar7 == 1 && (*(int *)(*DAT_021944c4 + 0x8c) == 0)))) ||
           ((*(ushort *)(DAT_021944d8 + 0x2e0) & 0x10) != 0)) {
          *(undefined4 *)(*DAT_021944c4 + 0x7c) = 0;
          *(undefined4 *)(*piVar3 + 0x84) = 6;
          *(undefined4 *)(*piVar3 + 0x8c) = 1;
          FUN_02194a0c();
          func_0x0212ecc0(DAT_021944dc,0,2);
        }
        return;
      }
      *(undefined4 *)(*DAT_021944c4 + 0x7c) = 1;
      *(undefined4 *)(*piVar3 + 0x80) = 6;
      *(undefined4 *)(*piVar3 + 0x88) = 1;
      FUN_02194a0c();
      func_0x0212ecc0(DAT_021944dc,0,2);
      return;
    }
  }
  FUN_021949c0();
  *(undefined4 *)(*DAT_021944c4 + 0x90) = 0;
  func_0x02128310();
  return;
}

