/* Decompiled C draft; module arm9; ROM address 0213e1f0. No matching claim. */
#include "types.h"
#include "deps/0213e1f0_func_0213e1f0.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

short * func_0213e1f0(int param_1,int param_2,uint param_3,undefined4 param_4,int param_5,
                     int param_6)

{
  uint uVar1;
  uint uVar2;
  int extraout_r1;
  int iVar3;
  int iVar4;
  short *psVar5;
  short *psVar6;
  int unaff_r8;
  short sVar7;
  uint uVar8;
  uint local_44;
  ushort uStack_2;
  
  uVar1 = param_3 >> 0x18;
  uStack_2 = (ushort)((uint)param_4 >> 0x10);
  local_44 = 0;
  iVar3 = 0;
  uVar8 = param_3 >> 8 & 0xff;
  psVar5 = (short *)(param_2 + -2);
  *psVar5 = 0;
  uVar2 = 0;
  if (((param_1 == 0) && (param_6 == 0)) && ((uVar1 == 0 || (uVar2 = uVar1, uStack_2 != 0x6f)))) {
    return psVar5;
  }
  if (uStack_2 < 0x6a) {
    if (uStack_2 < 0x69) {
      if (uStack_2 < 0x59) {
        if (uStack_2 != 0x58) goto LAB_0213e30c;
        goto LAB_0213e304;
      }
      if (uStack_2 != 100) goto LAB_0213e30c;
    }
    if (param_1 < 0) {
      uVar2 = 1;
    }
    unaff_r8 = 10;
    if (param_1 < 0) {
      param_1 = -param_1;
      local_44 = uVar2;
    }
  }
  else {
    if (uStack_2 < 0x70) {
      if (uStack_2 == 0x6f) {
        unaff_r8 = 8;
        uVar8 = 0;
      }
      goto LAB_0213e30c;
    }
    if ((0x78 < uStack_2) || (uStack_2 < 0x75)) goto LAB_0213e30c;
    if (uStack_2 == 0x75) {
      unaff_r8 = 10;
      uVar8 = 0;
      goto LAB_0213e30c;
    }
    if (uStack_2 != 0x78) goto LAB_0213e30c;
LAB_0213e304:
    unaff_r8 = 0x10;
    uVar8 = 0;
  }
LAB_0213e30c:
  do {
    psVar6 = psVar5;
    iVar4 = iVar3;
    MaybeBoundsCheck(param_1,unaff_r8);
    param_1 = MaybeBoundsCheck(param_1,unaff_r8);
    iVar3 = extraout_r1;
    if (extraout_r1 < 10) {
      iVar3 = extraout_r1 + 0x30;
    }
    sVar7 = (short)iVar3;
    if (9 < extraout_r1) {
      if (uStack_2 == 0x78) {
        sVar7 = sVar7 + 0x57;
      }
      else {
        sVar7 = sVar7 + 0x37;
      }
    }
    psVar5 = psVar6 + -1;
    *psVar5 = sVar7;
    iVar3 = iVar4 + 1;
  } while (param_1 != 0);
  if (((unaff_r8 == 8) && (uVar1 != 0)) && (*psVar5 != 0x30)) {
    psVar5 = psVar6 + -2;
    *psVar5 = 0x30;
    iVar3 = iVar4 + 2;
  }
  if ((param_3 & 0xff) == 2) {
    if ((local_44 != 0) || (param_6 = param_5, uVar8 != 0)) {
      param_6 = param_5 + -1;
    }
    if ((unaff_r8 == 0x10) && (uVar1 != 0)) {
      param_6 = param_6 + -2;
    }
  }
  if (param_6 + (param_2 - (int)psVar5) / 2 <= iRam0213e464) {
    for (; iVar3 < param_6; iVar3 = iVar3 + 1) {
      psVar5 = psVar5 + -1;
      *psVar5 = 0x30;
    }
    if ((unaff_r8 == 0x10) && (uVar1 != 0)) {
      psVar5[-1] = uStack_2;
      psVar5 = psVar5 + -2;
      *psVar5 = 0x30;
    }
    if (local_44 == 0) {
      if (uVar8 == 1) {
        psVar5 = psVar5 + -1;
        *psVar5 = 0x2b;
      }
      else if (uVar8 == 2) {
        psVar5 = psVar5 + -1;
        *psVar5 = 0x20;
      }
    }
    else {
      psVar5 = psVar5 + -1;
      *psVar5 = 0x2d;
    }
    return psVar5;
  }
  return (short *)0x0;
}

