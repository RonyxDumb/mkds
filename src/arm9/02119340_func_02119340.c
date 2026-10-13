/* Decompiled C draft; module arm9; ROM address 02119340. No matching claim. */
#include "types.h"
#include "deps/02119340_func_02119340.h"

void func_02119340(void)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  uint uVar6;
  short *psVar7;
  ushort *puVar8;
  
  uVar6 = 0xffffffff;
  func_02119d78();
  bVar5 = false;
  bVar4 = false;
  psVar7 = (short *)(iRam02119504 + 0x2e0);
  if ((*(short *)(iRam02119504 + 0x2e0) == 0) && (*(ushort *)(iRam02119508 + 0x2e0) < 5)) {
    bVar4 = true;
  }
  if (((!bVar4) && (*(short *)(iRam0211950c + 0x2e0) == 0)) &&
     (*(short *)(iRam02119504 + 0x2e0) != 0)) {
    bVar5 = true;
  }
  if (bVar5) {
    uVar6 = func_0201ea84(*(undefined4 *)(*piRam02119510 + 0x14),
                          *(undefined2 *)(iRam02119514 + 0x2e0),
                          *(ushort *)(iRam02119518 + 0x2e0) + 0x20);
  }
  puVar8 = (ushort *)(iRam0211951c + 0x2e0);
  if ((*(ushort *)(iRam0211951c + 0x2e0) & 2) == 0) {
    bVar5 = false;
    bVar4 = false;
    if ((*psVar7 == 0) && (*(ushort *)(iRam02119508 + 0x2e0) < 5)) {
      bVar4 = true;
    }
    if (((!bVar4) && (*(short *)(iRam0211950c + 0x2e0) == 0)) && (*psVar7 != 0)) {
      bVar5 = true;
    }
    if ((!bVar5) ||
       (iVar3 = func_02128210(*(undefined2 *)(iRam02119514 + 0x2e0),
                              *(undefined2 *)(iRam02119518 + 0x2e0)), iVar3 == 0)) {
      if (uVar6 < 4) {
        sVar1 = *(short *)(iRam02119524 + uVar6 * 2);
        if (*(short *)(*piRam02119510 + 0x50) == sVar1) {
          *(undefined4 *)(*piRam02119510 + 0x54) = 0;
        }
        *(short *)(*piRam02119510 + 0x50) = sVar1;
        func_02119ba8();
        return;
      }
      if (uVar6 == 4) {
        func_02119ba8();
        return;
      }
      if ((*puVar8 & 1) != 0) {
        func_02119ba8();
        *(undefined4 *)(*piRam02119510 + 0x54) = 0;
        return;
      }
      iVar3 = func_020ae408(8,0x40);
      piVar2 = piRam02119510;
      if (iVar3 != 0) {
        *(short *)(*piRam02119510 + 0x50) = *(short *)(*piRam02119510 + 0x50) + -1;
        if (*(short *)(*piVar2 + 0x50) < 0) {
          *(undefined2 *)(*piVar2 + 0x50) = 3;
        }
        if (*psRam02119520 == 2) {
          return;
        }
        NNSi_MaybeSndPlayerStartSeq(uRam02119528,0,0);
        return;
      }
      iVar3 = func_020ae408(8,0x80);
      piVar2 = piRam02119510;
      if (iVar3 == 0) {
        return;
      }
      *(short *)(*piRam02119510 + 0x50) = *(short *)(*piRam02119510 + 0x50) + 1;
      if (3 < *(short *)(*piVar2 + 0x50)) {
        *(undefined2 *)(*piVar2 + 0x50) = 0;
      }
      if (*psRam02119520 == 2) {
        return;
      }
      NNSi_MaybeSndPlayerStartSeq(uRam02119528,0,0);
      return;
    }
  }
  iVar3 = func_02119dfc();
  if (iVar3 != 0) {
    return;
  }
  if (*psRam02119520 == 2) {
    func_021281c8(0xffffffff);
  }
  else {
    func_021281c8(0xe);
  }
  func_021199f8();
  *(undefined4 *)(*piRam02119510 + 0x6c) = 2;
  func_02128310(0);
  return;
}

