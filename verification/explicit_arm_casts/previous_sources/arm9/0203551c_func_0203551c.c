/* Decompiled C draft; module arm9; ROM address 0203551c. No matching claim. */
#include "types.h"
#include "deps/0203551c_func_0203551c.h"

undefined4 func_0203551c(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  bool bVar7;
  int iVar8;
  int iVar9;
  
  iVar3 = GetDirectInputUnitIndex();
  iVar9 = 0;
  func_02025edc(*DAT_020357a8 + 0x90);
  bVar7 = false;
  bVar1 = false;
  iVar3 = iVar3 * 0x5c;
  if ((*(short *)(DAT_020357ac + iVar3) == 0) && (*(ushort *)(DAT_020357b0 + iVar3) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_020357b4 + iVar3) == 0)) &&
     (*(short *)(DAT_020357ac + iVar3) != 0)) {
    bVar7 = true;
  }
  if (bVar7) {
    iVar9 = func_02128210(*(undefined2 *)(DAT_020357b8 + iVar3),
                          *(undefined2 *)(DAT_020357bc + iVar3));
  }
  iVar4 = *DAT_020357a8;
  switch(*(undefined4 *)(iVar4 + 0x8c)) {
  case 0:
    if (*(int *)(iVar4 + 0x90) == 1) {
      *(undefined4 *)(iVar4 + 0x8c) = 1;
    }
    else {
      func_02035b0c();
    }
    break;
  case 1:
    iVar4 = TextSystem_IsDialogFinished_from_thumb();
    if (iVar4 != 0) {
      func_02035c14();
    }
    func_0202e4b0();
    iVar4 = func_0202e4a4();
    if (*(int *)(*DAT_020357a8 + 0x80) != iVar4) {
      *(int *)(*DAT_020357a8 + 0x80) = iVar4;
      func_02035a9c();
    }
    iVar4 = func_0202e468();
    if (iVar4 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_020357c0,0,5);
    }
    iVar4 = func_0202e47c();
    if (iVar4 == 0) {
      if (((*(ushort *)(DAT_020357c4 + iVar3) & 2) != 0) || (iVar9 != 0)) {
        uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_020357a8 + 0x88),0x54);
        uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_020357a8 + 0x84),4);
        TextSystem_SetButtonPressSseqId_from_thumb(0,5);
        TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar5,uVar6);
        func_02128310(1);
        piVar2 = DAT_020357a8;
        *(undefined4 *)(*DAT_020357a8 + 0xa0) = 0;
        *(undefined4 *)(*piVar2 + 0x8c) = 4;
      }
    }
    else {
      func_02035b78();
      func_021282c8();
      *(undefined4 *)(*DAT_020357a8 + 0x8c) = 2;
    }
    break;
  case 2:
    iVar3 = TextSystem_GetAnotherValue_from_thumb();
    if ((iVar3 != 0) && (iVar3 = TextSystem_IsButton2Focused_from_thumb(), iVar3 == 0)) {
      Sound_MaybeSetActiveSdat(DAT_020357c8);
      NNSi_MaybeSndPlayerStartSeq(DAT_020357c0,0,10);
      Sound_MaybeSetActiveSdat(DAT_020357cc);
    }
    iVar3 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar3 != 0) {
      iVar3 = TextSystem_IsButton2Focused_from_thumb();
      if (iVar3 == 0) {
        iVar3 = func_0202ddd8();
        *(uint *)(iVar3 + 8) = *(uint *)(iVar3 + 8) & 0xfffffffe | 1;
        uVar5 = func_0202ddd8();
        func_020566a8(*(uint *)(*DAT_020357a8 + 0x80) & 0xff,uVar5);
        *(undefined4 *)(*DAT_020357a8 + 0x8c) = 3;
      }
      else {
        func_02128374();
        *(undefined4 *)(*DAT_020357a8 + 0x8c) = 1;
      }
      TextSystem_CloseDialog_from_thumb();
    }
    break;
  case 3:
    if (*(char *)(*DAT_020357d0 + 0x28) == '\0') {
      if (*(int *)(*DAT_020357d4 + 0xc) == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(*DAT_020357d4 + 0x10);
      }
    }
    else {
      iVar3 = 1;
    }
    if (iVar3 != 0) {
      uVar5 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar4 + 0x88),0x10);
      uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_020357a8 + 0x84),4);
      TextSystem_SetButtonPressSseqId_from_thumb(0,5);
      TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar5,uVar6);
      piVar2 = DAT_020357a8;
      *(undefined4 *)(*DAT_020357a8 + 0xa0) = 0;
      *(undefined4 *)(*piVar2 + 0x8c) = 4;
    }
    break;
  case 4:
    iVar3 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar3 != 0) {
      *(undefined4 *)(*DAT_020357d8 + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_020357a8 + 0x8c) = 5;
    }
  }
  piVar2 = DAT_020357a8;
  iVar4 = 0;
  iVar9 = 0;
  iVar3 = 0;
  do {
    iVar8 = *piVar2 + 0x2c + iVar9;
    func_02124c30(*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 8),
                  *(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(*piVar2 + iVar3 + 0x24),
                  *(undefined4 *)(iVar8 + 0x18));
    iVar9 = iVar9 + 0x1c;
    iVar3 = iVar3 + 4;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return 0xffffffff;
}

