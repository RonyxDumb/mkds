/* Decompiled C draft; module arm9; ROM address 0202cdf4. No matching claim. */
#include "types.h"
#include "deps/0202cdf4_func_0202cdf4.h"

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 func_0202cdf4(int param_1)

{
  bool bVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  int iVar9;
  
  iVar4 = GetDirectInputUnitIndex();
  iVar9 = 0;
  func_02025edc(*DAT_0202d158 + 0xcc);
  bVar2 = false;
  bVar1 = false;
  iVar4 = iVar4 * 0x5c;
  if ((*(short *)(DAT_0202d15c + iVar4) == 0) && (*(ushort *)(DAT_0202d160 + iVar4) < 5)) {
    bVar1 = true;
  }
  if (((!bVar1) && (*(short *)(DAT_0202d164 + iVar4) == 0)) &&
     (*(short *)(DAT_0202d15c + iVar4) != 0)) {
    bVar2 = true;
  }
  if (bVar2) {
    iVar9 = func_02128210(*(undefined2 *)(DAT_0202d168 + iVar4),
                          *(undefined2 *)(DAT_0202d16c + iVar4));
  }
  piVar3 = DAT_0202d158;
  iVar5 = *DAT_0202d158;
  switch(*(undefined4 *)(iVar5 + 0xb0)) {
  case 0:
    iVar4 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar4 != 0) {
      *(undefined4 *)(*DAT_0202d170 + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0xe;
    }
    break;
  case 1:
    iVar4 = Bright_IsBothScreensFadedIn();
    if (iVar4 == 0) {
      iVar4 = func_0202ddc4();
      if (iVar4 == 0) {
        uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_0202d158 + 0xac),0x53);
        uVar6 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_0202d158 + 0xa8),4);
        TextSystem_DisplaySingleButtonDialog_Simple_from_thumb(uVar7,uVar6);
        *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0;
      }
      else {
        func_0202d6a0();
        func_0202d674();
        func_02128374();
        func_02025f14(*DAT_0202d158 + 0xcc,0);
        *(undefined4 *)(*DAT_0202d158 + 0xb0) = 2;
      }
    }
    break;
  case 2:
    if (*(int *)(iVar5 + 0xcc) == 1) {
      *(undefined4 *)(iVar5 + 0xb4) = 0;
      *(undefined4 *)(*piVar3 + 0xb0) = 3;
    }
    else {
      func_0202d554();
    }
    break;
  case 3:
    iVar5 = TextSystem_IsDialogIdle_from_thumb();
    if (iVar5 != 0) {
      func_0202e4b0();
      iVar5 = func_0202e4a4();
      if (*(int *)(*DAT_0202d158 + 0xa4) != iVar5) {
        *(int *)(*DAT_0202d158 + 0xa4) = iVar5;
        func_0202d6a0();
      }
      iVar5 = func_0202e468();
      if (iVar5 != 0) {
        Sound_MaybeSetActiveSdat(DAT_0202d174);
        NNSi_MaybeSndPlayerStartSeq(DAT_0202d178,0,7);
        Sound_MaybeSetActiveSdat(DAT_0202d17c);
      }
      iVar5 = func_0202e47c();
      if (iVar5 == 0) {
        if (((*(ushort *)(DAT_0202d180 + iVar4) & 2) != 0) || (iVar9 != 0)) {
          *(undefined4 *)(*DAT_0202d170 + 8) = 5;
          if (param_1 != 0) {
            *(undefined2 *)(param_1 + 4) = 1;
          }
          *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0xe;
          func_02128310(0);
        }
      }
      else {
        func_0202d5c0();
        func_02108c1c();
        *(undefined4 *)(*DAT_0202d158 + 0xb0) = 4;
      }
    }
    break;
  case 4:
    iVar4 = *DAT_0202d184;
    if (*(int *)(iVar4 + 0xc) == 0) {
      iVar9 = 0;
    }
    else {
      iVar9 = *(int *)(iVar4 + 0x10);
    }
    if ((iVar9 == 0) && (*(int *)(iVar4 + 4) == 0)) {
      iVar4 = func_0202dd80(*(undefined4 *)(iVar5 + 0xa4));
      if (iVar4 == 0) {
        uVar7 = func_0202ddec();
        uVar6 = func_0202ddd8();
        func_0203bf04(uVar7,uVar6);
      }
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 5;
    }
    break;
  case 5:
    uVar7 = func_0202ddd8();
    iVar4 = func_02054c98(1,uVar7);
    if (iVar4 == 1) {
      func_0204f5e4();
      uVar7 = func_0202ddd8();
      func_0204eeac(uVar7,DAT_0202d188);
      func_02128374();
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 6;
    }
    break;
  case 6:
    if (((*(ushort *)(DAT_0202d180 + iVar4) & 2) == 0) && (iVar9 == 0)) {
      iVar4 = func_0204eb08(iVar5 + 0xb8);
      if (iVar4 != 0) {
        func_021282c8();
        func_02108c04();
        Sound_MaybeSetActiveSdat(DAT_0202d174);
        NNSi_MaybeSndPlayerStartSeq(DAT_0202d178,0,9);
        Sound_MaybeSetActiveSdat(DAT_0202d17c);
        func_0202d5f8(0xb,0);
        *(undefined4 *)(*DAT_0202d158 + 0xb0) = 7;
      }
    }
    else {
      func_02128310(0);
      func_021281c8(0xf);
      func_02108c04();
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0xb;
    }
    break;
  case 7:
    iVar4 = func_0205465c();
    if (iVar4 == 1) {
      Sound_MaybeSetActiveSdat(DAT_0202d174);
      NNSi_MaybeSndPlayerStartSeq(DAT_0202d178,0,10);
      Sound_MaybeSetActiveSdat(DAT_0202d17c);
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 10;
    }
    else if (iVar4 == 2) {
      func_0202d82c();
    }
    break;
  case 8:
    iVar4 = TextSystem_JustFadedIn_from_thumb();
    if (iVar4 != 0) {
      NNSi_MaybeSndPlayerStartSeq(DAT_0202d178,0,0x15);
    }
    iVar4 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar4 != 0) {
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 9;
    }
    break;
  case 9:
    iVar4 = func_02054f58();
    if (iVar4 == 1) {
      func_0204f804();
      *(undefined4 *)(*DAT_0202d170 + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0xe;
    }
    break;
  case 10:
    iVar4 = func_02054f58();
    if (iVar4 == 1) {
      func_0204f804();
      func_0202d5f8(0xc,1);
      *(undefined4 *)(*DAT_0202d158 + 0xb0) = 0xd;
    }
    break;
  case 0xb:
    iVar4 = func_02054f58();
    if (iVar4 == 1) {
      func_0204f804();
      func_0202d674();
      *(undefined4 *)(*DAT_0202d208 + 0xb0) = 3;
    }
    break;
  case 0xd:
    iVar4 = TextSystem_WasAnyDialogButtonPressed_from_thumb();
    if (iVar4 != 0) {
      *(undefined4 *)(*_Maybe_TimeAttack_ghost_send_m + 8) = 5;
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 1;
      }
      *(undefined4 *)(*DAT_0202d208 + 0xb0) = 0xe;
    }
  }
  func_02054aa0();
  piVar3 = DAT_0202d208;
  iVar5 = 0;
  iVar9 = 0;
  iVar4 = 0;
  do {
    iVar8 = *piVar3 + 0x50 + iVar9;
    func_02124c30(*(undefined4 *)(iVar8 + 0xc),*(undefined4 *)(iVar8 + 8),
                  *(undefined4 *)(iVar8 + 0x14),*(undefined4 *)(*piVar3 + iVar4 + 0x48),
                  *(undefined4 *)(iVar8 + 0x18));
    iVar9 = iVar9 + 0x1c;
    iVar4 = iVar4 + 4;
    iVar5 = iVar5 + 1;
  } while (iVar5 < 2);
  return 0xffffffff;
}

