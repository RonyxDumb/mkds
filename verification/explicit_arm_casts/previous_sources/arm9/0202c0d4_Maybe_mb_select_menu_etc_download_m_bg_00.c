/* Decompiled C draft; module arm9; ROM address 0202c0d4. No matching claim. */
#include "types.h"
#include "deps/0202c0d4_Maybe_mb_select_menu_etc_download_m_bg_00.h"

void Maybe_mb_select_menu_etc_download_m_bg_00(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  bool bVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int local_44;
  undefined1 auStack_3c [40];
  
  iVar4 = iRam0202c43c;
  piVar7 = piRam0202c438;
  iVar9 = *piRam0202c438;
  *(undefined4 *)(iVar9 + iRam0202c43c) = param_1;
  *(undefined4 *)(*piVar7 + iRam0202c440) = param_2;
  if (*(int *)(*piVar7 + iRam0202c444) != 0) {
    *(undefined4 *)(*piVar7 + 0x40) = uRam0202c448;
    func_02025f80(*piVar7 + iRam0202c44c,0,10,0x40,0);
    piVar7 = piRam0202c438;
    iVar4 = *(int *)(*piRam0202c438 + iVar4);
    if (iVar4 == 0) {
      *(undefined4 *)(*piRam0202c438 + 0x48) = 1;
      *(undefined4 *)(*piVar7 + 0x44) = 0;
      *(undefined4 *)(*piVar7 + iRam0202c450) = 1;
      CopyMemory16(*(int *)*puRam0202c454 + 0xc,*piVar7 + 0x60 + *(int *)(*piVar7 + 0x44) * 0x2c,
                   0x14);
      func_0202c8dc();
    }
    else if (iVar4 == 1) {
      bVar8 = true;
      iVar4 = *(int *)(*piRam0202c458 + 4);
      if ((iVar4 != 8) && (iVar4 != 9)) {
        bVar8 = false;
      }
      if (bVar8) {
        uVar12 = Math_CountPopulation(*(undefined1 *)(*piRam0202c458 + iRam0202c45c));
      }
      else {
        uVar12 = 0;
      }
      *(uint *)(*piRam0202c438 + 0x48) = uVar12 & 0xff;
      piVar7 = (int *)*piRam0202c458;
      if (*piVar7 == 2) {
        uVar12 = (uint)*(ushort *)((int)piVar7 + iRam0202c460);
      }
      else {
        uVar12 = 0;
      }
      *(uint *)(*piRam0202c438 + 0x44) =
           (uint)*(ushort *)((int)piVar7 + iRam0202c464 + ((uVar12 << 0x10) >> 0xd));
      iVar11 = 0;
      iVar4 = *(int *)(*piRam0202c438 + 0x48);
      if (0 < iVar4) {
        iVar5 = 0;
        iVar13 = 0;
        local_44 = 0;
        do {
          iVar4 = GetGlobalCA_from_thumb();
          *(undefined4 *)(iVar4 + iVar5 + 8) = 0;
          Mem_CpuFill16(0,*piRam0202c438 + 0x60 + iVar13,0x16);
          uVar12 = (uint)*(ushort *)
                          (*piRam0202c458 + ((uint)(iVar11 << 0x10) >> 0xf) + iRam0202c468);
          iVar4 = local_44;
          if (uVar12 != uRam0202c46c) {
            iVar4 = *piRam0202c458 + iRam0202c470 + iRam0202c474 * uVar12;
          }
          CopyMemory16(iVar4,*piRam0202c438 + 0x60 + iVar13,0x14);
          iVar5 = iVar5 + 0x18;
          iVar13 = iVar13 + 0x2c;
          iVar11 = iVar11 + 1;
          iVar4 = *(int *)(*piRam0202c438 + 0x48);
        } while (iVar11 < iVar4);
      }
      for (; iVar4 < 8; iVar4 = iVar4 + 1) {
        func_0202cc18(iVar4,0);
      }
      func_0202c8dc();
      iVar11 = iRam0202c47c;
      iVar4 = iRam0202c478;
      piVar7 = piRam0202c438;
      iVar13 = 0;
      iVar5 = 0;
      do {
        *(undefined4 *)(*piVar7 + iVar5 + iVar4) = 0;
        iVar10 = *piVar7 + iVar5;
        *(undefined4 *)(iVar10 + iVar11) = *(undefined4 *)(iVar10 + iVar4);
        iVar5 = iVar5 + 4;
        iVar13 = iVar13 + 1;
      } while (iVar13 < 8);
    }
    else if (iVar4 == 2) {
      uVar6 = func_020295d0();
      *(undefined4 *)(*piRam0202c438 + 0x48) = uVar6;
      uVar6 = func_020295e4();
      *(undefined4 *)(*piRam0202c438 + 0x44) = uVar6;
      uVar12 = 0;
      iVar13 = *piRam0202c438;
      iVar4 = *(int *)(iVar13 + 0x48);
      piVar7 = piRam0202c438;
      iVar11 = iRam0202c480;
      if (0 < iVar4) {
        iVar5 = 0;
        do {
          Mem_CpuFill16(0,iVar13 + 0x60 + iVar5,0x16);
          iVar4 = func_02122734(uVar12 & 0xff);
          if (-1 < iVar4) {
            iVar4 = *piRam0202c438;
            uVar3 = func_02122734(uVar12 & 0xff);
            uVar6 = GetSomeBTKNickname(uVar3);
            CopyMemory16(uVar6,iVar4 + 0x60 + iVar5,0x14);
          }
          iVar5 = iVar5 + 0x2c;
          uVar12 = uVar12 + 1;
          iVar13 = *piRam0202c438;
          iVar4 = *(int *)(iVar13 + 0x48);
          piVar7 = piRam0202c438;
          iVar11 = iRam0202c480;
        } while ((int)uVar12 < iVar4);
      }
      for (; piRam0202c438 = piVar7, iRam0202c480 = iVar11, iVar4 < 8; iVar4 = iVar4 + 1) {
        func_0202cc18(iVar4,0);
        piVar7 = piRam0202c438;
        iVar11 = iRam0202c480;
      }
      iVar4 = 0;
      iVar13 = 0;
      iVar5 = 0;
      do {
        *(undefined4 *)(*piVar7 + iVar13 + iVar11) = 0;
        iVar2 = iRam0202c47c;
        iVar10 = iRam0202c478;
        piVar1 = piRam0202c438;
        iVar13 = iVar13 + 4;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      iVar4 = 0;
      do {
        *(undefined4 *)(*piVar1 + iVar4 + iVar10) = 0;
        iVar11 = *piVar1 + iVar4;
        *(undefined4 *)(iVar11 + iVar2) = *(undefined4 *)(iVar11 + iVar10);
        iVar4 = iVar4 + 4;
        iVar5 = iVar5 + 1;
      } while (iVar5 < 8);
    }
  }
  piVar7 = piRam0202c484;
  iVar4 = *(int *)(*piRam0202c438 + iRam0202c440);
  if (iVar4 == 2) {
    iVar4 = 0;
    iVar11 = 0;
    do {
      *(undefined4 *)(*(int *)(iVar9 + 0x18) + (uint)*(ushort *)(*piVar7 + iVar11 + 4) * 0x40) = 0;
      piVar1 = piRam0202c484;
      iVar11 = iVar11 + 6;
      iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    if ((*(int *)(*piRam0202c438 + iRam0202c43c) == 1) &&
       (iVar4 = *(int *)(*piRam0202c438 + 0x48), iVar4 < 8)) {
      iVar13 = iVar4 * 0x18;
      iVar11 = iVar4 * 6;
      do {
        iVar5 = GetGlobalCA_from_thumb();
        func_02025c48(*(undefined2 *)(*piVar1 + iVar11 + 2),
                      *(undefined2 *)(*piRam0202c488 + *(int *)(iVar5 + iVar13) * 2),
                      *(undefined4 *)(iVar9 + 0xc));
        *(undefined4 *)(*(int *)(iVar9 + 0x18) + (uint)*(ushort *)(*piVar1 + iVar11 + 2) * 0x40) = 1
        ;
        iVar13 = iVar13 + 0x18;
        iVar11 = iVar11 + 6;
        iVar4 = iVar4 + 1;
      } while (iVar4 < 8);
    }
    *puRam0202c48c = *puRam0202c48c & 0x43 | (ushort)uRam0202c490;
    *puRam0202c494 = *puRam0202c494 & 0x43 | (ushort)uRam0202c498;
    if (*psRam0202c49c == 2) {
      func_020258d4(0,auStack_3c,uRam0202c4a8,uRam0202c4ac,uRam0202c4a0,0,uRam0202c4a4);
      func_020258d4(0,auStack_3c,uRam0202c4b4,uRam0202c4b8,uRam0202c4b0,1,uRam0202c4a4);
    }
    else {
      func_020258d4(0,auStack_3c,uRam0202c4c4,uRam0202c4c8,uRam0202c4bc,0,uRam0202c4c0);
      func_020258d4(0,auStack_3c,uRam0202c4d0,uRam0202c4d4,uRam0202c4cc,1,uRam0202c4c0);
    }
  }
  else if (iVar4 == 1) {
    func_02025f14(*piRam0202c438 + iRam0202c4d8,0);
  }
  iVar4 = iRam0202c450;
  piVar7 = piRam0202c438;
  if (*(int *)(*piRam0202c438 + iRam0202c4dc) != 0) {
    iVar11 = 0;
    do {
      if ((iVar11 < *(int *)(*piVar7 + 0x48)) || (*(int *)(*piVar7 + iVar4) != 0)) {
        func_0202cb68(iVar11);
      }
      iVar11 = iVar11 + 1;
    } while (iVar11 < 8);
    *(undefined4 *)(*piRam0202c624 + iRam0202c628) = 0;
  }
  AllocateReserveTEQSub
            (0x13,0,*(undefined4 *)(*(int *)*piRam0202c624 + 0x14),
             *(undefined4 *)(*(int *)*piRam0202c624 + 0x10));
  AllocateReserveTEQSub(0xe,0,*(undefined4 *)(*(int *)(iVar9 + 4) + 0xc),uRam0202c62c);
  AllocateReserveTEQSub(0xe,iRam0202c630,*(int *)(*(int *)(iVar9 + 4) + 0xc) + iRam0202c630,0x40);
  if (*psRam0202c634 != 2) {
    func_02124748(*(undefined2 *)(iRam0202c63c + *(int *)(*piRam0202c624 + iRam0202c638) * 2),
                  *(undefined4 *)(iVar9 + 0x24),*(undefined4 *)(iVar9 + 0x1c),
                  *(undefined4 *)(iVar9 + 0x28),0,0x19,*(undefined4 *)(iVar9 + 8),
                  *(undefined4 *)(iVar9 + 0xc));
    func_02025f14(*piRam0202c624 + iRam0202c640,0);
  }
  uVar6 = func_0202cca0();
  func_02025c6c(uVar6,*(undefined2 *)(*piRam0202c644 + *(int *)(*piRam0202c624 + 0x44) * 6),
                *(undefined4 *)(iVar9 + 0xc));
  piVar7 = piRam0202c624;
  iVar4 = 0;
  iVar11 = 0;
  do {
    func_0202c884(iVar4,*piVar7 + 0x60 + iVar11);
    iVar11 = iVar11 + 0x2c;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  func_02025f80(*piRam0202c624 + iRam0202c648,3,10,0x60,0);
  piVar7 = piRam0202c624;
  uVar6 = 0;
  *(undefined4 *)(*piRam0202c624 + iRam0202c64c) = 0;
  iVar4 = *piVar7;
  if ((*(int *)(iVar4 + iRam0202c638) != 2) && (*(int *)(iVar4 + iRam0202c650) != 0)) {
    uVar6 = 1;
  }
  *(undefined4 *)(iVar4 + iRam0202c654) = uVar6;
  iVar4 = func_0202cc78();
  *(undefined4 *)(*(int *)(iVar9 + 0x18) + iVar4 * 0x40) =
       *(undefined4 *)(*piRam0202c624 + iRam0202c654);
  iVar11 = func_0202cc8c();
  *(undefined4 *)(*(int *)(iVar9 + 0x18) + iVar11 * 0x40) =
       *(undefined4 *)(*(int *)(iVar9 + 0x18) + iVar4 * 0x40);
  *(undefined4 *)(*piRam0202c624 + iRam0202c658) = 0;
  return;
}

