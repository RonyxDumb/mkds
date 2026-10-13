/* Decompiled C draft; module arm9; ROM address 02115204. No matching claim. */
#include "types.h"
#include "deps/02115204_func_02115204.h"

void func_02115204(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  int iVar6;
  bool bVar7;
  bool bVar8;
  uint uVar9;
  short *psVar10;
  
  uVar9 = 0xffffffff;
  func_02116084();
  func_02115fd4();
  iVar3 = func_02116870();
  bVar7 = true;
  bVar8 = false;
  psVar10 = (short *)(iRam0211550c + 0x2e0);
  if ((*(short *)(iRam0211550c + 0x2e0) == 0) && (*(ushort *)(iRam02115510 + 0x2e0) < 5)) {
    bVar8 = true;
  }
  if ((!bVar8) && (*(short *)(iRam0211550c + 0x2e0) == 0)) {
    bVar7 = false;
  }
  uVar4 = uVar9;
  if (bVar7) {
    uVar4 = func_0201ea84(*(undefined4 *)(*piRam02115514 + 0x34),
                          *(undefined2 *)(iRam02115518 + 0x2e0),
                          *(undefined2 *)(iRam0211551c + 0x2e0));
  }
  bVar8 = false;
  bVar7 = false;
  sVar1 = *psVar10;
  if ((sVar1 == 0) && (*(ushort *)(iRam02115510 + 0x2e0) < 5)) {
    bVar7 = true;
  }
  if (((!bVar7) && (*(short *)(iRam02115520 + 0x2e0) == 0)) && (sVar1 != 0)) {
    bVar8 = true;
  }
  if (bVar8) {
    uVar9 = func_0201ea84(*(undefined4 *)(*piRam02115514 + 0x34),
                          *(undefined2 *)(iRam02115518 + 0x2e0),
                          *(undefined2 *)(iRam0211551c + 0x2e0));
  }
  if (uVar4 != 5) {
    *(undefined4 *)(*piRam02115514 + 0x98) = 0;
  }
  if (uVar4 != 6) {
    *(undefined4 *)(*piRam02115514 + 0x9c) = 0;
  }
  puVar5 = (ushort *)(iRam02115524 + 0x2e0);
  if ((*(ushort *)(iRam02115524 + 0x2e0) & 2) == 0) {
    bVar8 = false;
    bVar7 = false;
    sVar1 = *psVar10;
    if ((sVar1 == 0) && (*(ushort *)(iRam02115510 + 0x2e0) < 5)) {
      bVar7 = true;
    }
    if (((!bVar7) && (*(short *)(iRam02115520 + 0x2e0) == 0)) && (sVar1 != 0)) {
      bVar8 = true;
    }
    if ((!bVar8) ||
       (iVar6 = func_02128210(*(undefined2 *)(iRam02115518 + 0x2e0),
                              *(undefined2 *)(iRam0211551c + 0x2e0)), iVar6 == 0)) {
      if (((uVar4 == 5) && (*(int *)(*piRam02115514 + 0x98) != 0)) ||
         (((uVar9 == 5 && (*(int *)(*piRam02115514 + 0x98) == 0)) ||
          ((*(ushort *)(iRam02115528 + 0x2e0) & 0x20) != 0)))) {
        iVar3 = func_0211606c();
        piVar2 = piRam02115514;
        if (iVar3 != 0) {
          return;
        }
        if (*(int *)(*(int *)(*piRam02115514 + 0x3c) + iRam0211552c) == 0) {
          return;
        }
        *(undefined4 *)(*piRam02115514 + 0x78) = 1;
        *(undefined4 *)(*piVar2 + 0x90) = 6;
        *(undefined4 *)(*piVar2 + 0x98) = 1;
        func_02115df8();
        NNSi_MaybeSndPlayerStartSeq(uRam02115530,0,2);
        return;
      }
      if ((((uVar4 == 6) && (*(int *)(*piRam02115514 + 0x9c) != 0)) ||
          ((uVar9 == 6 && (*(int *)(*piRam02115514 + 0x9c) == 0)))) ||
         ((*(ushort *)(iRam02115528 + 0x2e0) & 0x10) != 0)) {
        iVar3 = func_0211606c();
        piVar2 = piRam02115514;
        if (iVar3 != 0) {
          return;
        }
        if (*(int *)(*(int *)(*piRam02115514 + 0x3c) + iRam02115534) == 0) {
          return;
        }
        *(undefined4 *)(*piRam02115514 + 0x78) = 0;
        *(undefined4 *)(*piVar2 + 0x94) = 6;
        *(undefined4 *)(*piVar2 + 0x9c) = 1;
        func_02115df8();
        NNSi_MaybeSndPlayerStartSeq(uRam02115530,0,2);
        return;
      }
      if (uVar9 < 5) {
        sVar1 = *(short *)(iRam02115538 + uVar9 * 2);
        iVar6 = (int)sVar1;
        if (iVar6 != *(short *)(*piRam02115514 + 0x74)) {
          iVar3 = func_02116844(iVar6);
          if (iVar3 == 0) {
            return;
          }
          *(short *)(*piRam02115514 + 0x74) = sVar1;
          NNSi_MaybeSndPlayerStartSeq(uRam02115530,0,0);
          return;
        }
        iVar3 = func_02114398(iVar3 + iVar6 & 0xffff);
        if (iVar3 == 0) {
          iVar3 = func_0211606c();
          if (iVar3 != 0) {
            return;
          }
          func_02115d90();
          return;
        }
        iVar3 = func_0211606c();
        if (iVar3 != 0) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(uRam02115530,0,0x16);
        return;
      }
      if ((*puVar5 & 1) == 0) {
        iVar3 = func_020ae408(8,0x40);
        if (iVar3 != 0) {
          func_02116174();
          return;
        }
        iVar3 = func_020ae408(8,0x80);
        if (iVar3 == 0) {
          return;
        }
        func_021161d0();
        return;
      }
      iVar3 = func_02114398(iVar3 + *(short *)(*piRam02115514 + 0x74) & 0xffff);
      if (iVar3 != 0) {
        iVar3 = func_0211606c();
        if (iVar3 != 0) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(uRam02115530,0,0x16);
        return;
      }
      iVar3 = func_0211606c();
      if (iVar3 != 0) {
        return;
      }
      func_02115d90();
      return;
    }
  }
  iVar3 = func_0211606c();
  if (iVar3 != 0) {
    return;
  }
  func_02115c8c();
  *(undefined4 *)(*piRam02115514 + 0xa0) = 3;
  func_02128310(0);
  return;
}

