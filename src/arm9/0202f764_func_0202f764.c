/* Decompiled C draft; module arm9; ROM address 0202f764. No matching claim. */
#include "types.h"
#include "deps/0202f764_func_0202f764.h"

undefined4 func_0202f764(int param_1)

{
  undefined2 uVar1;
  undefined2 uVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  bool bVar9;
  int iVar10;
  int iVar11;
  undefined4 local_34;
  int local_2c;
  
  local_34 = 0xffffffff;
  iVar4 = GetDirectInputUnitIndex();
  piVar8 = DAT_0202fac8;
  iVar5 = *DAT_0202fac8;
  if ((*(int *)(iVar5 + 0x9c) == 0) &&
     (*(int *)(iVar5 + 0x94) = *(int *)(iVar5 + 0x94) + 1, 0x78 < *(int *)(*piVar8 + 0x94))) {
    iVar11 = 0;
    iVar10 = 0;
    do {
      iVar6 = func_0202f14c();
      Mem_CpuFill16(0,iVar6 + 4 + iVar10,0x16);
      iVar10 = iVar10 + 0x16;
      iVar11 = iVar11 + 1;
    } while (iVar11 < 4);
    *(undefined4 *)(*DAT_0202fac8 + 0x9c) = 1;
  }
  if (*(int *)(*DAT_0202fac8 + 0x4c) != -1) {
    func_0202fd2c();
  }
  piVar8 = DAT_0202fac8;
  iVar10 = *DAT_0202fac8;
  switch(*(undefined4 *)(iVar10 + 0x4c)) {
  case 0:
    iVar4 = Bright_IsBothScreensFadedIn();
    if (iVar4 != 0) {
      if (*(int *)(*DAT_0202fac8 + 0x8c) == 0) {
        func_02128374();
        uVar7 = Bmg_GetRawStringPointer_from_thumb(*(undefined4 *)(*DAT_0202fac8 + 0xa0),7);
        TextSystem_DisplayProgressDialog_TopScreen_from_thumb(uVar7,0,0,1,0,0,0);
      }
      piVar8 = DAT_0202fac8;
      *(int *)(*DAT_0202fac8 + 0x8c) = *(int *)(*DAT_0202fac8 + 0x8c) + 1;
      iVar4 = *(int *)(*piVar8 + 0x8c);
      if (iVar4 < 10) {
        uVar7 = ComputeValueInterpolation_from_thumb(1,0xffffff40,0,iVar4,10);
        *(undefined4 *)(*DAT_0202fac8 + 0x90) = uVar7;
      }
      else {
        *(undefined4 *)(*piVar8 + 0x8c) = 0;
        *(undefined4 *)(*piVar8 + 0x90) = 0;
        *(undefined4 *)(*piVar8 + 0x4c) = 1;
      }
      func_02030200();
    }
    break;
  case 1:
    iVar10 = 0;
    local_2c = -1;
    bVar9 = false;
    bVar3 = false;
    iVar11 = iVar4 * 0x5c;
    if ((*(short *)(DAT_0202facc + iVar11) == 0) && (*(ushort *)(DAT_0202fad0 + iVar11) < 5)) {
      bVar3 = true;
    }
    if (((!bVar3) && (*(short *)(DAT_0202fad4 + iVar11) == 0)) &&
       (*(short *)(DAT_0202facc + iVar11) != 0)) {
      bVar9 = true;
    }
    if (bVar9) {
      uVar1 = *(undefined2 *)(DAT_0202fad8 + iVar11);
      uVar2 = *(undefined2 *)(DAT_0202fadc + iVar11);
      iVar10 = func_02128210(uVar1,uVar2);
      local_2c = func_0201ea84(*(undefined4 *)(iVar5 + 0x34),uVar1,uVar2);
    }
    if ((*(ushort *)(DAT_0202fae0 + iVar11) & 1) == 0) {
      if (((*(ushort *)(DAT_0202fae0 + iVar11) & 2) == 0) && (iVar10 == 0)) {
        iVar10 = func_020ae408(iVar4,0x40);
        piVar8 = DAT_0202fac8;
        if (iVar10 == 0) {
          iVar4 = func_020ae408(iVar4,0x80);
          piVar8 = DAT_0202fac8;
          if (iVar4 == 0) {
            if (local_2c == 0xc) {
              NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0x4e);
              func_0203003c(*(int *)(*DAT_0202fac8 + 0x48) != 4);
              piVar8 = DAT_0202fac8;
              *(undefined4 *)(*DAT_0202fac8 + 0x98) = 0;
              *(undefined4 *)(*piVar8 + 0x4c) = 2;
              *(undefined4 *)(*piVar8 + 0x48) = 4;
              *(undefined4 *)(*piVar8 + 0x88) = 1;
            }
            else {
              iVar4 = 0;
              iVar10 = 0;
              do {
                iVar11 = func_02030274(local_2c,iVar4);
                if (iVar11 != 0) {
                  iVar11 = *(int *)(*piVar8 + 0x48);
                  iVar6 = *piVar8 + iVar10;
                  if ((*(int *)(iVar6 + 0x58) == 0) || (6 < *(int *)(iVar6 + 0x60))) {
                    NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0x4f);
                  }
                  else {
                    Sound_MaybeSetActiveSdat(DAT_0202faf0);
                    NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,2);
                    Sound_MaybeSetActiveSdat(DAT_0202faf4);
                    *(int *)(*piVar8 + 0x48) = iVar4;
                    func_0203003c(iVar11 != iVar4);
                    *(undefined4 *)(*piVar8 + 0x98) = 0;
                    *(undefined4 *)(*piVar8 + 0x4c) = 2;
                    *(undefined4 *)(*piVar8 + 0x88) = 1;
                  }
                }
                iVar10 = iVar10 + 0xc;
                iVar4 = iVar4 + 1;
              } while (iVar4 < 4);
            }
          }
          else {
            *(int *)(*DAT_0202fac8 + 0x48) = *(int *)(*DAT_0202fac8 + 0x48) + 1;
            if (4 < *(int *)(*piVar8 + 0x48)) {
              *(undefined4 *)(*piVar8 + 0x48) = 0;
            }
            func_0203003c(1);
            NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0);
          }
        }
        else {
          *(int *)(*DAT_0202fac8 + 0x48) = *(int *)(*DAT_0202fac8 + 0x48) + -1;
          if (*(int *)(*piVar8 + 0x48) < 0) {
            *(undefined4 *)(*piVar8 + 0x48) = 4;
          }
          func_0203003c(1);
          NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0);
        }
      }
      else {
        if (param_1 != 0) {
          *(undefined2 *)(param_1 + 4) = 0;
        }
        *(undefined4 *)(*DAT_0202fac8 + 0x4c) = 3;
        func_02128310(1);
      }
    }
    else {
      iVar4 = func_0203023c();
      piVar8 = DAT_0202fac8;
      if (iVar4 == 0) {
        NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0x4f);
      }
      else {
        *(undefined4 *)(*DAT_0202fac8 + 0x88) = 1;
        *(undefined4 *)(*piVar8 + 0x4c) = 2;
        *(undefined4 *)(*piVar8 + 0x98) = 0;
        func_0203003c();
        if (*(int *)(*DAT_0202fac8 + 0x48) == 4) {
          NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,0x4e);
        }
        else {
          piVar8 = (int *)*DAT_0202fae8;
          if (piVar8 == (int *)0x0) {
            iVar4 = 0;
          }
          else {
            iVar4 = *piVar8;
          }
          if (iVar4 == 2) {
            *(ushort *)((int)piVar8 + DAT_0202faec) = *(ushort *)((int)piVar8 + DAT_0202faec) | 1;
          }
          Sound_MaybeSetActiveSdat(DAT_0202faf0);
          NNSi_MaybeSndPlayerStartSeq(DAT_0202fae4,0,2);
          Sound_MaybeSetActiveSdat(DAT_0202faf4);
        }
      }
    }
    break;
  case 2:
    *(int *)(iVar10 + 0x98) = *(int *)(iVar10 + 0x98) + 1;
    if (4 < *(int *)(*piVar8 + 0x98)) {
      *(undefined4 *)(*piVar8 + 0x98) = 0;
      func_0203003c(1);
      iVar4 = *DAT_0202fbc4;
      if ((*(int *)(iVar4 + 0x48) < 4) &&
         (*(int *)(iVar4 + *(int *)(iVar4 + 0x48) * 0xc + 0x58) == 0)) {
        *(undefined4 *)(iVar4 + 0x4c) = 1;
      }
      else {
        *(undefined4 *)(iVar4 + 0x4c) = 3;
        TextSystem_CloseDialog_from_thumb();
      }
    }
    break;
  case 3:
    *(int *)(iVar10 + 0x8c) = *(int *)(iVar10 + 0x8c) + 1;
    iVar4 = *(int *)(*piVar8 + 0x8c);
    if (iVar4 < 10) {
      uVar7 = ComputeValueInterpolation_from_thumb(1,0,0xffffff40,iVar4,10);
      *(undefined4 *)(*DAT_0202fbc4 + 0x90) = uVar7;
    }
    else {
      *(undefined4 *)(*piVar8 + 0x8c) = 0;
      *(undefined4 *)(*piVar8 + 0x90) = 0;
      *(undefined4 *)(*piVar8 + 0x4c) = 4;
    }
    func_02030200();
    break;
  case 4:
    if (*(int *)(iVar10 + 0x50) == 0xb) {
      local_34 = *(undefined4 *)(iVar10 + 0x54);
    }
  }
  if (*(int *)(*DAT_0202fbc4 + 0x4c) != 4) {
    func_02124c30(*(undefined4 *)(iVar5 + 0x30),*(undefined4 *)(iVar5 + 0x2c),
                  *(undefined4 *)(iVar5 + 0x38),*(undefined4 *)(*DAT_0202fbc4 + 0x44),
                  *(undefined4 *)(iVar5 + 0x3c));
  }
  return local_34;
}

