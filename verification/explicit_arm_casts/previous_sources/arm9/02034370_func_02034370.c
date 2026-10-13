/* Decompiled C draft; module arm9; ROM address 02034370. No matching claim. */
#include "types.h"
#include "deps/02034370_func_02034370.h"

undefined4 func_02034370(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  int *piVar4;
  short *psVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  uint uVar16;
  undefined4 local_270;
  int local_26c;
  int local_268;
  short *local_260;
  byte local_240;
  byte local_23f;
  byte local_23e [2];
  undefined1 auStack_23c [20];
  undefined2 local_228;
  uint local_224;
  uint local_220;
  uint local_21c;
  undefined1 auStack_218 [2];
  undefined1 uStack_216;
  undefined1 uStack_215;
  undefined1 auStack_214 [512];
  
  iVar6 = *(int *)(*DAT_020346f8 + 0x80);
  iVar7 = GetDirectInputUnitIndex();
  local_26c = 0;
  local_270 = 0xffffffff;
  local_268 = -1;
  iVar13 = *DAT_020346f8;
  func_02025edc(iVar13 + DAT_020346fc);
  piVar4 = DAT_020346f8;
  iVar14 = *DAT_020346f8;
  switch(*(undefined4 *)(iVar14 + 0x94)) {
  case 0:
    iVar6 = Bright_IsBothScreensFadedIn();
    if (iVar6 == 0) {
      func_02128374();
      func_02035378();
      func_02025f14(*DAT_020346f8 + DAT_020346fc,0);
      *(undefined4 *)(*DAT_020346f8 + 0x94) = 1;
    }
    break;
  case 1:
    if (*(int *)(iVar14 + DAT_020346fc) == 1) {
      *(undefined4 *)(iVar14 + 0x94) = 2;
    }
    else {
      func_02034fec();
    }
    break;
  case 2:
    iVar14 = func_02054c98(0,0);
    if (iVar14 == 0) {
      if (*(int *)(*DAT_020346f8 + DAT_0203470c) == 0) {
        iVar14 = TextSystem_IsDialogFinished_from_thumb();
        if (iVar14 != 0) {
          func_02035378();
        }
        piVar4 = DAT_020346f8;
        uVar16 = 0;
        *(undefined4 *)(*DAT_020346f8 + DAT_02034710) = 0;
        psVar5 = DAT_02034714;
        iVar14 = 0;
        local_260 = DAT_02034714;
        do {
          iVar8 = func_0204ebb8(uVar16 & 0xff,auStack_23c,&local_240,&local_23f,local_23e,
                                &uStack_216,&uStack_215,auStack_218);
          if (iVar8 == 0) {
            func_02025f14(*piVar4 + 200 + iVar14,2);
            *(undefined4 *)(*piVar4 + iVar14 + 0xc4) = 0;
          }
          else {
            local_220 = (uint)local_240;
            local_224 = (uint)local_23f;
            local_21c = (uint)local_23e[0];
            *(int *)(*piVar4 + DAT_02034710) = *(int *)(*piVar4 + DAT_02034710) + 1;
            if ((*(int *)(*piVar4 + iVar14 + 0xc4) == 0) ||
               (iVar8 = func_02034e68(*piVar4 + 0x9c + iVar14,auStack_23c), iVar8 != 0)) {
              uVar11 = func_02025d74(local_21c);
              local_228 = 0;
              func_0212426c(1,(int)*local_260,*(undefined4 *)(iVar13 + 0x5c),auStack_23c,
                            *(undefined4 *)(iVar13 + 0x54),*(undefined4 *)(iVar13 + 0x60));
              uVar11 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*piVar4 + 0x88),uVar11);
              func_0212426c(1,(int)psVar5[(uVar16 + 4) * 4],*(undefined4 *)(iVar13 + 0x5c),uVar11,
                            *(undefined4 *)(iVar13 + 0x54),*(undefined4 *)(iVar13 + 0x60));
              MIi_CpuCopyFast(auStack_23c,*piVar4 + 0x9c + iVar14,0x28);
              *(undefined4 *)(*piVar4 + iVar14 + 0xc4) = 1;
              func_02025f14(*piVar4 + 200 + iVar14,0);
              if (*(uint *)(*piVar4 + 0x80) == uVar16) {
                func_02034f60();
              }
              Sound_MaybeSetActiveSdat(DAT_02034700);
              NNSi_MaybeSndPlayerStartSeq(DAT_02034704,0,7);
              Sound_MaybeSetActiveSdat(DAT_02034708);
            }
          }
          iVar14 = iVar14 + 0x3c;
          local_260 = local_260 + 4;
          uVar16 = uVar16 + 1;
        } while ((int)uVar16 < 4);
        func_02035114();
        bVar15 = false;
        bVar3 = false;
        iVar14 = iVar7 * 0x5c;
        if ((*(short *)(DAT_02034718 + iVar14) == 0) && (*(ushort *)(DAT_0203471c + iVar14) < 5)) {
          bVar3 = true;
        }
        if (((!bVar3) && (*(short *)(DAT_02034720 + iVar14) == 0)) &&
           (*(short *)(DAT_02034718 + iVar14) != 0)) {
          bVar15 = true;
        }
        if (bVar15) {
          uVar1 = *(undefined2 *)(DAT_02034724 + iVar14);
          uVar2 = *(undefined2 *)(DAT_02034728 + iVar14);
          local_26c = func_02128210(uVar1,uVar2);
          local_268 = func_0201ea84(*(undefined4 *)(iVar13 + 0x58),uVar1,uVar2);
        }
        if ((local_268 < 0) || (*(int *)(*DAT_020346f8 + local_268 * 0x3c + 0xc4) == 0)) {
          if (((*(ushort *)(DAT_0203472c + iVar14) & 1) == 0) ||
             (*(int *)(*DAT_020346f8 + 0x80) < 0)) {
            if (((*(ushort *)(DAT_0203472c + iVar14) & 2) == 0) && (local_26c == 0)) {
              iVar13 = func_020ae408(iVar7,0x40);
              if (iVar13 == 0) {
                iVar7 = func_020ae408(iVar7,0x80);
                if (iVar7 != 0) {
                  if (*(int *)(*DAT_02034ab8 + DAT_02034abc) == 2) {
                    func_02035280(0);
                  }
                  else if (2 < *(int *)(*DAT_02034ab8 + DAT_02034abc)) {
                    func_02035280(1);
                  }
                }
              }
              else if (*(int *)(*DAT_02034ab8 + DAT_02034abc) == 2) {
                func_020352fc(0);
              }
              else if (2 < *(int *)(*DAT_02034ab8 + DAT_02034abc)) {
                func_020352fc(1);
              }
            }
            else {
              *(undefined4 *)(*DAT_020346f8 + 0x94) = 0xc;
              func_02128310(0);
            }
          }
          else {
            func_020351c8();
            func_02035228(0);
            NNSi_MaybeSndPlayerStartSeq(DAT_02034704,0,5);
            func_021282c8();
            piVar4 = DAT_020346f8;
            *(undefined4 *)(*DAT_020346f8 + DAT_0203470c) = 1;
            *(undefined4 *)(*piVar4 + 0x90) = 0;
            *(undefined4 *)(*piVar4 + 0x94) = 3;
          }
        }
        else {
          func_020351c8();
          func_02035228(*(int *)(*DAT_020346f8 + 0x80) != local_268);
          *(int *)(*DAT_020346f8 + 0x80) = local_268;
          NNSi_MaybeSndPlayerStartSeq(DAT_02034704,0,5);
          func_021282c8();
          piVar4 = DAT_020346f8;
          *(undefined4 *)(*DAT_020346f8 + DAT_0203470c) = 1;
          *(undefined4 *)(*piVar4 + 0x90) = 0;
          *(undefined4 *)(*piVar4 + 0x94) = 3;
        }
      }
    }
    else if (iVar14 == 1) {
      Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_020346f8 + 0x88),0xf);
      TextSystem_DisplayProgressDialog_Simple_from_thumb();
      Sound_MaybeSetActiveSdat(DAT_02034700);
      NNSi_MaybeSndPlayerStartSeq(DAT_02034704,0,9);
      Sound_MaybeSetActiveSdat(DAT_02034708);
      *(undefined4 *)(*DAT_020346f8 + 0x94) = 5;
    }
    if (iVar6 != *(int *)(*DAT_02034ab8 + 0x80)) {
      func_02034f60();
      func_02034ef0();
    }
    break;
  case 3:
    *(int *)(iVar14 + 0x90) = *(int *)(iVar14 + 0x90) + 1;
    if (5 < *(int *)(*piVar4 + 0x90)) {
      func_02035228(1);
      piVar4 = DAT_02034ab8;
      *(undefined4 *)(*DAT_02034ab8 + 0x90) = 0;
      *(undefined4 *)(*piVar4 + 0x94) = 4;
    }
    break;
  case 4:
    iVar6 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar6 != 0) {
      iVar6 = TextSystem_IsButton2Focused_from_thumb();
      if (iVar6 == 0) {
        func_0204ece0(*(uint *)(*DAT_02034ab8 + 0x80) & 0xffff);
      }
      else {
        func_02128374();
        *(undefined4 *)(*DAT_02034ab8 + DAT_02034ac0) = 0;
      }
      TextSystem_CloseDialog_from_thumb();
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 2;
    }
    break;
  case 5:
    iVar6 = func_02054b44();
    if (iVar6 == 1) {
      func_0204f5e4();
      uVar11 = func_0202ddd8();
      func_0204ee4c(0,uVar11);
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 6;
    }
    else if (iVar6 == 2) {
      func_020353a4();
    }
    break;
  case 6:
    iVar6 = func_02054938();
    if (iVar6 == 1) {
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 7;
    }
    else if (iVar6 == 2) {
      func_020353a4();
    }
    break;
  case 7:
    iVar6 = func_02054f58();
    if (iVar6 == 1) {
      func_0204f804();
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 8;
    }
    break;
  case 8:
    iVar6 = func_0202da44(*(undefined4 *)(iVar14 + *(int *)(iVar14 + 0x80) * 0x3c + 0xbc));
    if (iVar6 == 0) {
      iVar6 = func_0202dd9c();
      if (iVar6 == 10) {
        TextSystem_CloseDialog_from_thumb();
        piVar4 = DAT_02034ab8;
        *(undefined4 *)(*DAT_02034ab8 + 0x98) = 2;
        *(undefined4 *)(*piVar4 + 0x94) = 0xd;
        func_02025f14(*piVar4 + DAT_02034acc);
      }
      else {
        uVar11 = func_0202d9fc();
        *(undefined4 *)(*DAT_02034ab8 + 0x8c) = uVar11;
        iVar6 = func_0202ddd8();
        *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe | 1;
        uVar11 = func_0202ddd8();
        func_020566a8(*(uint *)(*DAT_02034ab8 + 0x8c) & 0xff,uVar11);
        Sound_MaybeSetActiveSdat(DAT_02034ad0);
        NNSi_MaybeSndPlayerStartSeq(DAT_02034ad4,0,10);
        Sound_MaybeSetActiveSdat(DAT_02034ad8);
        *(undefined4 *)(*DAT_02034ab8 + 0x94) = 0xb;
      }
    }
    else {
      uVar11 = func_02025d74(*(undefined4 *)
                              (*DAT_02034ab8 + *(int *)(*DAT_02034ab8 + 0x80) * 0x3c + 0xbc));
      uVar12 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x88),0x55);
      uVar9 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x84),0);
      uVar10 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x84),1);
      uVar11 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x88),uVar11);
      MaybeHandleBmgFormatting_from_thumb(uVar11,uVar12,auStack_214,DAT_02034ac8);
      TextSystem_SetButtonPressSseqId_from_thumb(0,0xffffffff);
      TextSystem_DisplayDoubleButtonDialog_from_thumb(auStack_214,uVar9,uVar10,1,0,1,1,0);
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 9;
    }
    break;
  case 9:
    iVar6 = TextSystem_GetAnotherValue_from_thumb();
    if ((iVar6 != 0) && (iVar6 = TextSystem_IsButton2Focused_from_thumb(), iVar6 == 0)) {
      Sound_MaybeSetActiveSdat(DAT_02034ad0);
      NNSi_MaybeSndPlayerStartSeq(DAT_02034ad4,0,10);
      Sound_MaybeSetActiveSdat(DAT_02034ad8);
    }
    iVar6 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar6 != 0) {
      TextSystem_CloseDialog_from_thumb();
      iVar6 = TextSystem_IsButton2Focused_from_thumb();
      if (iVar6 == 0) {
        uVar11 = func_0202d990(*(undefined4 *)
                                (*DAT_02034ab8 + *(int *)(*DAT_02034ab8 + 0x80) * 0x3c + 0xbc));
        *(undefined4 *)(*DAT_02034ab8 + 0x8c) = uVar11;
        iVar6 = func_0202ddd8();
        *(uint *)(iVar6 + 8) = *(uint *)(iVar6 + 8) & 0xfffffffe | 1;
        uVar11 = func_0202ddd8();
        func_020566a8(*(uint *)(*DAT_02034ab8 + 0x8c) & 0xff,uVar11);
        *(undefined4 *)(*DAT_02034ab8 + 0x94) = 0xb;
      }
      else {
        *(undefined4 *)(*DAT_02034ab8 + 0x94) = 10;
      }
    }
    break;
  case 10:
    iVar6 = TextSystem_IsDialogFinished_from_thumb();
    if (iVar6 != 0) {
      uVar11 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x88),0x54);
      uVar12 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034ab8 + 0x84),4);
      TextSystem_SetButtonPressSseqId_from_thumb(0,5);
      TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar11,uVar12);
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 0xe;
    }
    break;
  case 0xb:
    if (*(char *)(*DAT_02034adc + 0x28) == '\0') {
      if (*(int *)(*DAT_02034ae0 + 0xc) == 0) {
        iVar6 = 0;
      }
      else {
        iVar6 = *(int *)(*DAT_02034ae0 + 0x10);
      }
    }
    else {
      iVar6 = 1;
    }
    if (iVar6 != 0) {
      uVar11 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(iVar14 + 0x88),0x10);
      uVar12 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_02034be4 + 0x84),4);
      TextSystem_SetButtonPressSseqId_from_thumb(0,5);
      TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar11,uVar12);
      *(undefined4 *)(*DAT_02034be4 + 0x94) = 0xe;
    }
    break;
  case 0xc:
    iVar6 = func_02054f58();
    if (iVar6 == 1) {
      func_0204f804();
      *(undefined4 *)(*DAT_02034ac4 + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_02034ab8 + 0x94) = 0x10;
    }
    break;
  case 0xd:
    if (*(int *)(iVar14 + DAT_02034bf0) == 3) {
      local_270 = *(undefined4 *)(iVar14 + 0x98);
      *(undefined4 *)(iVar14 + 0x94) = 0x10;
    }
    else {
      func_02034fec();
    }
    break;
  case 0xe:
    iVar6 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar6 != 0) {
      *(undefined4 *)(*DAT_02034bec + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_02034be4 + 0x94) = 0x10;
    }
    break;
  case 0xf:
    iVar6 = TextSystem_JustFadedIn_from_thumb();
    if (iVar6 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_02034be8,0,0x15);
    }
    iVar6 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    piVar4 = DAT_02034be4;
    if (iVar6 != 0) {
      *(undefined4 *)(*DAT_02034be4 + 0x90) = 0;
      *(undefined4 *)(*piVar4 + 0x94) = 0xc;
      TextSystem_CloseDialog_from_thumb();
    }
  }
  func_02035060();
  func_02054aa0();
  piVar4 = DAT_02034be4;
  iVar13 = 0;
  iVar7 = 0;
  iVar6 = 0;
  do {
    iVar14 = *piVar4 + 0x2c + iVar7;
    func_02124c30(*(undefined4 *)(iVar14 + 0xc),*(undefined4 *)(iVar14 + 8),
                  *(undefined4 *)(iVar14 + 0x14),*(undefined4 *)(*piVar4 + iVar6 + 0x24),
                  *(undefined4 *)(iVar14 + 0x18));
    iVar7 = iVar7 + 0x1c;
    iVar6 = iVar6 + 4;
    iVar13 = iVar13 + 1;
  } while (iVar13 < 2);
  return local_270;
}

