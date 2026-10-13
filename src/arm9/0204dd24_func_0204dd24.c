/* Decompiled C draft; module arm9; ROM address 0204dd24. No matching claim. */
#include "types.h"
#include "deps/0204dd24_func_0204dd24.h"

undefined4 func_0204dd24(undefined4 param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = DAT_0204df40;
  piVar2 = DAT_0204df3c;
  iVar3 = *DAT_0204df3c;
  iVar5 = *(int *)(iVar3 + 0xc);
  if (iVar5 < 0x1e) {
    if (iVar5 < 0x1d) {
      if ((iVar5 < 0xb) && (6 < iVar5)) {
        if (iVar5 == 7) {
          *(undefined4 *)(iVar3 + 0x10) = 0;
        }
        else if ((iVar5 == 10) &&
                (*(short *)(iVar3 + DAT_0204df40) = *(short *)(iVar3 + DAT_0204df40) + 1,
                DAT_0204df44 < *(ushort *)(*piVar2 + iVar4))) {
          func_02050e60(5);
          return 3;
        }
      }
    }
    else {
      iVar4 = func_020501b0();
      if (iVar4 == 0) {
        func_02050e60(5);
      }
      iVar4 = func_0204ff14(param_1,0);
      if (iVar4 == 0) {
        func_02050e60(5);
      }
      else {
        func_0204e074();
      }
    }
  }
  else if (iVar5 == 0x1e) {
    *(short *)(iVar3 + DAT_0204df40) = *(short *)(iVar3 + DAT_0204df40) + 1;
    if (DAT_0204df44 < *(ushort *)(*piVar2 + iVar4)) {
      func_02050e60(5);
    }
    else {
      iVar4 = func_0204e3f0();
      if (iVar4 != -1) {
        *(char *)(*DAT_0204df3c + DAT_0204df48) = (char)iVar4;
        func_0204e074();
      }
    }
  }
  iVar4 = *DAT_0204df3c;
  if (*(int *)(iVar4 + 0x10) != 0) {
    return 0;
  }
  iVar3 = *(int *)(iVar4 + 0xc);
  if (iVar3 < 0x1f) {
    if (0x1d < iVar3) {
      func_0204e074();
      return 0;
    }
    if (0x1a < iVar3) {
      if (iVar3 != 0x1c) {
        return 0;
      }
      *(undefined2 *)(iVar4 + DAT_0204df40) = 0;
      func_0204e474();
      return 0;
    }
    if (iVar3 < 0x1a) {
      switch(iVar3) {
      default:
        return 0;
      case 1:
        goto switchD_0204de10_caseD_1;
      case 2:
        goto switchD_0204de10_caseD_2;
      case 7:
        *(ushort *)(iVar4 + DAT_0204df4c) = *(ushort *)(iVar4 + DAT_0204df4c) | 0x40;
        func_02051e98();
        return 0;
      case 9:
        func_0204e4d8();
        return 0;
      case 10:
        func_02051a24();
        return 0;
      case 0xb:
        *(undefined4 *)(iVar4 + 4) = 6;
        func_02059878();
        return 1;
      }
    }
  }
  else {
    if (0x20 < iVar3) {
      switch(iVar3) {
      case 0x21:
        if ((int)*(char *)(iVar4 + DAT_0204df48) == 0xffffffff) {
          func_0204e03c(param_1);
          return 0;
        }
        func_0204e03c((int)*(char *)(iVar4 + DAT_0204df48) & 0xffff);
        return 0;
      case 0x22:
        goto switchD_0204de50_caseD_22;
      case 0x23:
        StructZE_StateFn_28_29_30_33_34_35_from_thumb();
        return 0;
      case 0x24:
        func_02051d24(0,0,0,DAT_0204df58,0);
        return 0;
      default:
        return 0;
      }
    }
    if (iVar3 < 0x20) {
      if (iVar3 != 0x1f) {
        return 0;
      }
      uVar1 = *(ushort *)(iVar4 + DAT_0204df40);
      if (uVar1 < 0x3c) {
        *(ushort *)(iVar4 + DAT_0204df40) = uVar1 + 1;
        return 0;
      }
      *(undefined4 *)(iVar4 + 0xc) = 0x20;
      return 0;
    }
  }
  func_02052ecc();
  return 0;
switchD_0204de10_caseD_1:
  *(undefined2 *)(iVar4 + DAT_0204df40) = 0;
switchD_0204de10_caseD_2:
  if (*DAT_0204df54 == 2) {
    func_0204df90();
    return 0;
  }
  func_02051d24(0,0,0,DAT_0204df58,0);
  return 0;
switchD_0204de50_caseD_22:
  if (*(int *)(iVar4 + DAT_0204df50) == 0) {
    return 2;
  }
  if ((int)*(char *)(iVar4 + DAT_0204df48) == 0xffffffff) {
    func_0204dfe0(param_1);
    return 0;
  }
  func_0204dfe0((int)*(char *)(iVar4 + DAT_0204df48) & 0xffff);
  return 0;
}

