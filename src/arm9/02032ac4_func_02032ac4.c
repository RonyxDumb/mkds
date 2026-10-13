/* Decompiled C draft; module arm9; ROM address 02032ac4. No matching claim. */
#include "types.h"
#include "deps/02032ac4_func_02032ac4.h"

void func_02032ac4(int param_1)

{
  ushort uVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  uint uVar6;
  int *piVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int local_30;
  
  iVar11 = DAT_02032e38;
  piVar2 = DAT_02032e30;
  iVar8 = *DAT_02032e30;
  if (*(int *)(iVar8 + DAT_02032e34) == 0) {
    *(undefined4 *)(*(int *)(iVar8 + 0x60) + (*(ushort *)(iVar8 + 0xce) + 1) * 0x40) = 0;
    uVar6 = (uint)*(ushort *)(*piVar2 + 0xce);
    *(undefined4 *)(*(int *)(iVar8 + 0x60) + uVar6 * 0x40) =
         *(undefined4 *)(*(int *)(iVar8 + 0x60) + (uVar6 + 1) * 0x40);
  }
  else {
    iVar9 = *(int *)(iVar8 + DAT_02032e38);
    if (iVar9 == 0) {
      local_30 = 0;
    }
    else {
      *(int *)(iVar8 + DAT_02032e38) = iVar9 + -1;
      iVar9 = *piVar2;
      local_30 = _s32_div_f(*(int *)(iVar9 + iVar11) + 0x3c,0x3c);
      *(uint *)(*(int *)(iVar8 + 0x60) + (uint)*(ushort *)(iVar9 + 0xce) * 0x40) =
           (uint)(9 < local_30);
      if (*(int *)(*DAT_02032e30 + DAT_02032e38) == 0) {
        NNSi_MaybeSndPlayerStartSeq(DAT_02032e3c,0,0x51);
      }
      else {
        _s32_div_f(*(int *)(*DAT_02032e30 + DAT_02032e38) + 0x3c,0x3c);
        if ((extraout_r1 == 0) && (local_30 < 5)) {
          NNSi_MaybeSndPlayerStartSeq(DAT_02032e3c,0,0x50);
        }
      }
    }
    uVar3 = *(undefined4 *)(iVar8 + 0x54);
    uVar4 = *(undefined4 *)(iVar8 + 0x50);
    iVar11 = *DAT_02032e30;
    uVar5 = _s32_div_f(local_30,10);
    _s32_div_f(uVar5,10);
    func_02124748((uint)*(ushort *)(iVar11 + 0xcc) + extraout_r1_00,uVar4,
                  *(undefined4 *)(iVar8 + 0x48),uVar3,0,*(undefined2 *)(iVar11 + 0xce),uVar4,uVar3);
    uVar3 = *(undefined4 *)(iVar8 + 0x54);
    uVar4 = *(undefined4 *)(iVar8 + 0x50);
    iVar11 = *DAT_02032e30;
    _s32_div_f(local_30,10);
    func_02124748((uint)*(ushort *)(iVar11 + 0xcc) + extraout_r1_01,uVar4,
                  *(undefined4 *)(iVar8 + 0x48),uVar3,0,*(ushort *)(iVar11 + 0xce) + 1,uVar4,uVar3);
  }
  iVar11 = *DAT_02032e30;
  switch(*(undefined4 *)(iVar11 + DAT_02032e40)) {
  case 0:
    *(int *)(iVar11 + DAT_02032e44) = *(int *)(iVar11 + DAT_02032e44) + 1;
    iVar11 = func_020546d8();
    if (iVar11 == 1) {
      *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 1;
    }
    break;
  case 1:
    *(int *)(iVar11 + DAT_02032e44) = *(int *)(iVar11 + DAT_02032e44) + 1;
    iVar11 = func_02054754();
    if (iVar11 == 1) {
      *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 2;
    }
    break;
  case 2:
    iVar9 = func_0210f714();
    iVar11 = DAT_02032e44;
    piVar2 = DAT_02032e30;
    *(int *)(*DAT_02032e30 + DAT_02032e44) = *(int *)(*DAT_02032e30 + DAT_02032e44) + 1;
    piVar7 = (int *)(*piVar2 + iVar11);
    if (iVar9 < *piVar7) {
      *piVar7 = 0;
      *(undefined4 *)(*piVar2 + DAT_02032e40) = 3;
    }
    break;
  case 3:
    switch(*(undefined4 *)(iVar11 + 0xe0)) {
    case 0:
      iVar11 = GetDirectInputUnitIndex();
      if ((*(ushort *)(DAT_02032e48 + iVar11 * 0x5c) & 1) != 0) {
        NNSi_MaybeSndPlayerStartSeq(DAT_02032e3c,0,5);
        if (param_1 != 0) {
          *(undefined2 *)(param_1 + 4) = 1;
        }
        *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 7;
      }
      break;
    case 1:
    case 2:
      if ((*(ushort *)(DAT_02032e48 + 0x2e0) & 1) != 0) {
        func_02033d9c();
        *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 4;
        NNSi_MaybeSndPlayerStartSeq(DAT_02032e3c,0,5);
      }
      break;
    case 3:
      iVar11 = func_02033dfc();
      if (iVar11 == 0) {
        iVar11 = GetDirectInputUnitIndex();
        if (((*(ushort *)(DAT_02032e48 + iVar11 * 0x5c) & 1) != 0) ||
           (iVar11 = func_02033dd0(), iVar11 != 0)) {
          func_02033d9c();
          NNSi_MaybeSndPlayerStartSeq(DAT_02032e3c,0,5);
          *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 4;
        }
      }
      else {
        func_02121dec(1);
        *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 5;
      }
    }
    break;
  case 4:
    iVar11 = *(int *)(iVar11 + 0xe0);
    if ((iVar11 == 1) || (iVar11 == 2)) {
      iVar11 = func_02127788();
      if (iVar11 != 0) {
        iVar11 = func_02127794();
        piVar2 = DAT_02032e50;
        if (iVar11 == -1) {
          *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 3;
        }
        else if (iVar11 == 0) {
          if (*(int *)(*DAT_02032e4c + 0x1c) << 0x1d < 0) {
            *(undefined4 *)(*DAT_02032e50 + 0x74) = 3;
            *(undefined4 *)(*piVar2 + 8) = 4;
            if (param_1 != 0) {
              *(undefined2 *)(param_1 + 4) = 6;
            }
          }
          else {
            *(undefined4 *)(*DAT_02032e50 + 8) = 4;
            if (param_1 != 0) {
              *(undefined2 *)(param_1 + 4) = 1;
            }
          }
          *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 7;
        }
        else if (iVar11 == 1) {
          *(ushort *)(*DAT_02032e54 + DAT_02032e58) =
               *(ushort *)(*DAT_02032e54 + DAT_02032e58) | 0x80;
          *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 6;
        }
        func_021277e4();
      }
    }
    else if ((iVar11 == 3) &&
            ((iVar11 = func_02127788(), iVar11 != 0 || (iVar11 = func_02033dfc(), iVar11 != 0)))) {
      iVar11 = func_02127794();
      if (iVar11 == -1) {
        *(undefined4 *)(*DAT_02032f8c + DAT_02032f90) = 3;
      }
      else if (iVar11 == 0) {
        *(undefined4 *)(*DAT_02032e30 + DAT_02032e40) = 5;
        func_02121dec(1);
      }
      else if (iVar11 == 1) {
        func_02121dec(0);
        *(undefined4 *)(*DAT_02032f88 + 0x1c) = 1;
        if (param_1 != 0) {
          *(undefined2 *)(param_1 + 4) = 0xc;
        }
        *(undefined4 *)(*DAT_02032f8c + DAT_02032f90) = 7;
      }
      func_021277e4();
    }
    break;
  case 5:
    iVar11 = func_02121c78();
    if (iVar11 != 0) {
      iVar11 = func_02121c78();
      if (iVar11 == 1) {
        *(undefined4 *)(*DAT_02032f88 + 0x1c) = 2;
      }
      else if (iVar11 == 2) {
        *(undefined4 *)(*DAT_02032f88 + 0x1c) = 1;
      }
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 0xc;
      }
      *(undefined4 *)(*DAT_02032f8c + DAT_02032f90) = 7;
    }
    break;
  case 6:
    iVar11 = func_02054f58();
    if (iVar11 == 1) {
      if (param_1 != 0) {
        *(undefined2 *)(param_1 + 4) = 0;
      }
      *(undefined4 *)(*DAT_02032f8c + DAT_02032f90) = 7;
    }
  }
  func_020a2558();
  func_020a23cc();
  iVar12 = 0;
  iVar11 = 0;
  iVar9 = 0;
  do {
    iVar10 = *DAT_02032f8c + iVar11;
    func_02124c30(*(undefined4 *)(iVar10 + 0x54),*(undefined4 *)(iVar10 + 0x50),
                  *(undefined4 *)(iVar10 + 0x5c),*(undefined4 *)(*DAT_02032f8c + iVar9 + 0xb8),
                  *(undefined4 *)(iVar10 + 0x60));
    iVar11 = iVar11 + 0x1c;
    iVar9 = iVar9 + 4;
    iVar12 = iVar12 + 1;
  } while (iVar12 < 2);
  uVar1 = *(ushort *)(*(int *)(iVar8 + 0x70) + 6);
  iVar11 = 0;
  do {
    iVar10 = iVar11 + (uint)uVar1;
    iVar12 = iVar10 * 0x40;
    iVar9 = *(int *)(iVar8 + 0x7c) + iVar12;
    *(short *)(iVar9 + 6) = *(short *)(iVar9 + 6) + 1;
    func_02124100(iVar11,0xe,*(undefined4 *)(iVar8 + 0x78),*(undefined4 *)(iVar8 + 0x7c),
                  *(undefined4 *)(iVar8 + 0x70));
    func_02124bc8(iVar10,*(undefined4 *)(iVar8 + 0x70),*(undefined4 *)(iVar8 + 0x6c),
                  *(undefined4 *)(iVar8 + 0x78),*(undefined4 *)(*DAT_02032f8c + 0xbc),
                  *(undefined4 *)(iVar8 + 0x7c));
    func_02124100(iVar11,0xf,*(undefined4 *)(iVar8 + 0x78),*(undefined4 *)(iVar8 + 0x7c),
                  *(undefined4 *)(iVar8 + 0x70));
    iVar12 = *(int *)(iVar8 + 0x7c) + iVar12;
    *(short *)(iVar12 + 6) = *(short *)(iVar12 + 6) + -1;
    iVar11 = iVar11 + 1;
  } while (iVar11 < 8);
  NavigationContext_OnSceneUpdate_from_thumb();
  return;
}

