/* Decompiled C draft; module arm9; ROM address 02030ea4. No matching claim. */
#include "types.h"
#include "deps/02030ea4_func_02030ea4.h"

undefined4 func_02030ea4(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  bool bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  undefined4 local_20;
  int local_1c;
  
  local_20 = 0xffffffff;
  iVar5 = GetDirectInputUnitIndex();
  iVar6 = *DAT_020311c4;
  iVar11 = *(int *)(iVar6 + 0x74);
  if (0 < *(int *)(iVar6 + 0x9c)) {
    *(int *)(iVar6 + 0x9c) = *(int *)(iVar6 + 0x9c) + -1;
  }
  func_02031960();
  iVar7 = *(int *)(*DAT_020311c4 + 0x94);
  if ((((iVar7 != 0) && (iVar7 != 3)) && (iVar7 != 4)) && ((iVar7 != 5 && (iVar7 != 6)))) {
    piVar10 = (int *)*DAT_020311c8;
    if (piVar10 == (int *)0x0) {
      iVar7 = 0;
    }
    else {
      iVar7 = *piVar10;
    }
    if (iVar7 == 1) {
      if ((*(ushort *)((int)piVar10 + DAT_020311cc) & 0x40) == 0) {
        uVar8 = (uint)*(byte *)(piVar10 + 0x21);
      }
      else {
        uVar8 = (uint)*(byte *)((int)piVar10 + DAT_020311d0);
      }
    }
    else {
      uVar8 = 0;
    }
    *(uint *)(*DAT_020311c4 + 0x74) = uVar8;
    if (*(int *)(*DAT_020311c4 + 0x74) != iVar11) {
      func_02031f5c();
      if (iVar11 < *(int *)(*DAT_020311c4 + 0x74)) {
        Sound_MaybeSetActiveSdat(DAT_020311d4);
        NNSi_MaybeSndPlayerStartSeq(DAT_020311d8,0,2);
        Sound_MaybeSetActiveSdat(DAT_020311dc);
      }
      else {
        Sound_MaybeSetActiveSdat(DAT_020311d4);
        NNSi_MaybeSndPlayerStartSeq(DAT_020311d8,0,3);
        Sound_MaybeSetActiveSdat(DAT_020311dc);
      }
    }
  }
  func_02031b6c();
  func_02031ba4();
  func_0212b80c();
  iVar11 = DAT_020311e4;
  piVar10 = DAT_020311c4;
  if ((*(int *)(*DAT_020311c4 + DAT_020311e0) != 0) &&
     (piVar9 = (int *)(*DAT_020311c4 + DAT_020311e4), *piVar9 = *piVar9 + 1,
     0x96 < *(int *)(*piVar10 + iVar11))) {
    func_02108ddc();
    *(undefined4 *)(*DAT_020311c4 + DAT_020311e0) = 0;
  }
  piVar10 = DAT_020311c4;
  iVar11 = *DAT_020311c4;
  switch(*(undefined4 *)(iVar11 + 0x94)) {
  case 0:
    iVar5 = func_02031268();
    if (iVar5 != 0) {
      *(undefined4 *)(*DAT_020311c4 + 0x94) = 1;
      *(undefined4 *)(*(int *)(iVar6 + 0x58) + DAT_020311e8) = 1;
      func_02031b30();
    }
    break;
  case 1:
    local_1c = 0;
    iVar11 = -1;
    bVar4 = false;
    iVar5 = iVar5 * 0x5c;
    bVar3 = bVar4;
    if ((*(short *)(DAT_020311ec + iVar5) == 0) && (*(ushort *)(DAT_020311f0 + iVar5) < 5)) {
      bVar3 = true;
    }
    if (((!bVar3) && (*(short *)(DAT_020311f4 + iVar5) == 0)) &&
       (*(short *)(DAT_020311ec + iVar5) != 0)) {
      bVar4 = true;
    }
    if (bVar4) {
      uVar1 = *(undefined2 *)(DAT_020311f8 + iVar5);
      uVar2 = *(undefined2 *)(DAT_020311fc + iVar5);
      local_1c = func_02128210(uVar1,uVar2);
      iVar11 = func_0201ea84(*(undefined4 *)(iVar6 + 0x50),uVar1,uVar2);
    }
    piVar10 = DAT_020311c4;
    if ((((*(ushort *)(DAT_02031200 + iVar5) & 1) == 0) && (iVar11 != 0)) ||
       ((*(int *)(*DAT_020311c4 + 0x74) < 1 || (*(int *)(*DAT_020311c4 + 0xd0) != 1)))) {
      if (((*(ushort *)(DAT_02031200 + iVar5) & 2) != 0) || (local_1c != 0)) {
        *(undefined4 *)(*DAT_020311c4 + 0x6c) = 1;
        *(undefined4 *)(*piVar10 + 0x94) = 3;
        *(undefined4 *)(*piVar10 + 0x7c) = 1;
        TextSystem_CloseDialog_from_thumb();
        func_02128310(0);
        Sound_MaybeSetActiveSdat(DAT_020311d4);
        NNSi_MaybeSndPlayerStartSeq(DAT_020311d8,0,5);
        Sound_MaybeSetActiveSdat(DAT_020311dc);
      }
    }
    else {
      func_02031b30(0);
      func_021282c8();
      func_0212b7e8();
      Sound_MaybeSetActiveSdat(DAT_020311d4);
      NNSi_MaybeSndPlayerStartSeq(DAT_020311d8,0,6);
      Sound_MaybeSetActiveSdat(DAT_020311dc);
      piVar10 = DAT_020311c4;
      *(undefined4 *)(*DAT_020311c4 + 0x78) = 1;
      *(undefined4 *)(*piVar10 + DAT_020311e0) = 1;
      *(undefined4 *)(*piVar10 + 0x94) = 2;
    }
    break;
  case 2:
    *(int *)(iVar11 + 0x98) = *(int *)(iVar11 + 0x98) + 1;
    if ((4 < *(int *)(*piVar10 + 0x98)) &&
       (func_02031b30(1), piVar10 = DAT_02031204, *(int *)(*DAT_020311c4 + 0x70) == 0xb)) {
      *(undefined4 *)(*DAT_02031204 + 4) = 1;
      *(undefined4 *)(*piVar10 + 8) = 4;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      piVar10 = DAT_020311c4;
      *(undefined4 *)(*DAT_020311c4 + 0x98) = 0;
      *(undefined4 *)(*piVar10 + 0x94) = 7;
    }
    break;
  case 3:
    if (*(int *)(iVar11 + 0x70) == 0xb) {
      func_02025f14(iVar11 + 0xa0,2);
      func_02025f14(*DAT_020311c4 + 0xb0,2);
      func_02025f14(*DAT_020311c4 + 0xc0,2);
      *(undefined4 *)(*DAT_020311c4 + 0x94) = 4;
    }
    break;
  case 4:
    iVar5 = func_02031250();
    if (iVar5 != 0) {
      *(undefined4 *)(*DAT_020311c4 + 0x94) = 6;
    }
    break;
  case 5:
    iVar5 = TextSystem_JustFadedIn_from_thumb();
    if (iVar5 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_020311d8,0,0x15);
    }
    iVar5 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar5 != 0) {
      TextSystem_CloseDialog_from_thumb();
      piVar10 = DAT_020311c4;
      *(undefined4 *)(*DAT_020311c4 + 0x6c) = 0;
      *(undefined4 *)(*piVar10 + 0x94) = 3;
    }
    break;
  case 6:
    local_20 = *(undefined4 *)(iVar11 + 0x6c);
  }
  func_02031208();
  return local_20;
}

