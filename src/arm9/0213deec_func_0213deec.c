/* Decompiled C draft; module arm9; ROM address 0213deec. No matching claim. */
#include "types.h"
#include "deps/0213deec_func_0213deec.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

short * func_0213deec(int param_1,int param_2,int param_3,uint param_4,undefined4 param_5,
                     int param_6,int param_7)

{
  uint uVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  short *psVar6;
  short *psVar7;
  int unaff_r8;
  undefined4 uVar8;
  int unaff_r11;
  longlong lVar9;
  int iStack_48;
  uint uStack_44;
  
  lVar9 = CONCAT44(param_2,param_1);
  uVar1 = param_4 >> 0x18;
  bVar2 = false;
  iVar4 = 0;
  psVar6 = (short *)(param_3 + -2);
  *psVar6 = 0;
  uStack_44 = param_4 >> 8 & 0xff;
  if (((param_2 == 0 && param_1 == 0) && (param_7 == 0)) &&
     ((uVar1 == 0 || (MKDS_SLICE_2(param_5,2) != 0x6f)))) {
    return psVar6;
  }
  if (MKDS_SLICE_2(param_5,2) < 0x6a) {
    if (MKDS_SLICE_2(param_5,2) < 0x69) {
      if (MKDS_SLICE_2(param_5,2) < 0x59) {
        lVar9 = CONCAT44(param_2,param_1);
        if (MKDS_SLICE_2(param_5,2) != 0x58) goto LAB_0213e044;
        goto LAB_0213e038;
      }
      if (MKDS_SLICE_2(param_5,2) != 100) goto LAB_0213e044;
    }
    unaff_r11 = 0;
    unaff_r8 = 10;
    lVar9 = CONCAT44(param_2,param_1);
    if (param_2 < 0) {
      bVar2 = true;
      lVar9 = CONCAT44(-(param_2 + (uint)(param_1 != 0)),-param_1);
    }
  }
  else {
    if (MKDS_SLICE_2(param_5,2) < 0x70) {
      lVar9 = CONCAT44(param_2,param_1);
      if (MKDS_SLICE_2(param_5,2) == 0x6f) {
        unaff_r11 = 0;
        uStack_44 = 0;
        unaff_r8 = 8;
        lVar9 = CONCAT44(param_2,param_1);
      }
      goto LAB_0213e044;
    }
    lVar9 = CONCAT44(param_2,param_1);
    if ((0x78 < MKDS_SLICE_2(param_5,2)) || (lVar9 = CONCAT44(param_2,param_1), MKDS_SLICE_2(param_5,2) < 0x75))
    goto LAB_0213e044;
    if (MKDS_SLICE_2(param_5,2) == 0x75) {
      unaff_r11 = 0;
      uStack_44 = 0;
      unaff_r8 = 10;
      lVar9 = CONCAT44(param_2,param_1);
      goto LAB_0213e044;
    }
    lVar9 = CONCAT44(param_2,param_1);
    if (MKDS_SLICE_2(param_5,2) != 0x78) goto LAB_0213e044;
LAB_0213e038:
    unaff_r11 = 0;
    uStack_44 = 0;
    unaff_r8 = 0x10;
    lVar9 = CONCAT44(param_2,param_1);
  }
LAB_0213e044:
  do {
    psVar7 = psVar6;
    iVar5 = iVar4;
    uVar8 = (undefined4)((ulonglong)lVar9 >> 0x20);
    iStack_48 = param_7;
    iVar4 = _ull_mod((int)lVar9,uVar8,unaff_r8,unaff_r11);
    lVar9 = _ll_udiv((int)lVar9,uVar8,unaff_r8,unaff_r11);
    sVar3 = (short)iVar4;
    if (iVar4 < 10) {
      sVar3 = sVar3 + 0x30;
    }
    else if (MKDS_SLICE_2(param_5,2) == 0x78) {
      sVar3 = sVar3 + 0x57;
    }
    else {
      sVar3 = sVar3 + 0x37;
    }
    psVar6 = psVar7 + -1;
    *psVar6 = sVar3;
    iVar4 = iVar5 + 1;
  } while (lVar9 != 0);
  if (((unaff_r11 == 0 && unaff_r8 == 8) && (uVar1 != 0)) && (*psVar6 != 0x30)) {
    psVar6 = psVar7 + -2;
    *psVar6 = 0x30;
    iVar4 = iVar5 + 2;
  }
  if ((param_4 & 0xff) == 2) {
    iStack_48 = param_6;
    if ((bVar2) || (uStack_44 != 0)) {
      iStack_48 = param_6 + -1;
    }
    if ((unaff_r11 == 0 && unaff_r8 == 0x10) && (uVar1 != 0)) {
      iStack_48 = iStack_48 + -2;
    }
  }
  if (iStack_48 + (param_3 - (int)psVar6) / 2 <= iRam0213e1ec) {
    for (; iVar4 < iStack_48; iVar4 = iVar4 + 1) {
      psVar6 = psVar6 + -1;
      *psVar6 = 0x30;
    }
    if ((unaff_r11 == 0 && unaff_r8 == 0x10) && (uVar1 != 0)) {
      psVar6[-1] = MKDS_SLICE_2(param_5,2);
      psVar6 = psVar6 + -2;
      *psVar6 = 0x30;
    }
    if (bVar2) {
      psVar6 = psVar6 + -1;
      *psVar6 = 0x2d;
    }
    else if (uStack_44 == 1) {
      psVar6 = psVar6 + -1;
      *psVar6 = 0x2b;
    }
    else if (uStack_44 == 2) {
      psVar6 = psVar6 + -1;
      *psVar6 = 0x20;
    }
    return psVar6;
  }
  return (short *)0x0;
}

