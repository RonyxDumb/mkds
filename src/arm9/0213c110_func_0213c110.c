/* Decompiled C draft; module arm9; ROM address 0213c110. No matching claim. */
#include "types.h"
#include "deps/0213c110_func_0213c110.h"

/* WARNING: Removing unreachable block (ram,0x0213c1f0) */

undefined8
func_0213c110(uint param_1,int param_2,code *param_3,undefined4 param_4,int *param_5,uint *param_6,
             undefined4 *param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint unaff_r6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  longlong lVar10;
  uint local_38;
  int local_34;
  uint local_30;
  
  *param_7 = 0;
  local_34 = 0;
  uVar3 = 0;
  lVar10 = 0;
  *param_6 = *(uint *)((uint)param_7 & 0xfffffffc) >> ((uint)param_7 & 3) * 8 |
             *(uint *)((uint)param_7 & 0xfffffffc) << ((uint)param_7 & 3) * -8 + 0x20;
  uVar6 = 1;
  if (((((int)param_1 < 0) || (param_1 == 1)) || (0x24 < (int)param_1)) || (param_2 < 1)) {
    uVar6 = 0x40;
    uVar5 = uVar3;
  }
  else {
    uVar5 = 1;
    unaff_r6 = (*param_3)(param_4,0,0);
  }
  uVar8 = uVar3;
  if (param_1 != 0) {
    lVar10 = _ll_udiv(0xffffffff,0xffffffff,param_1,(int)param_1 >> 0x1f);
    uVar3 = 0;
    uVar8 = 0;
  }
LAB_0213c4ec:
  do {
    if (((param_2 < (int)uVar5) || (unaff_r6 == 0xffffffff)) || ((uVar6 & 0x60) != 0)) {
      if ((uVar6 & 0x34) == 0) {
        uVar8 = 0;
        *param_5 = 0;
        uVar3 = uVar8;
      }
      else {
        *param_5 = (uVar5 - 1) + local_34;
      }
      (*param_3)(param_4,unaff_r6,1);
      return CONCAT44(uVar8,uVar3);
    }
    switch(uVar6) {
    case 0:
      break;
    case 1:
      if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(ushort *)(DAT_0213c558 + unaff_r6 * 2) & 0x100;
      }
      if (uVar1 == 0) {
        if (unaff_r6 == 0x2b) {
          uVar5 = uVar5 + 1;
          unaff_r6 = (*param_3)(param_4,0,0);
        }
        else if (unaff_r6 == 0x2d) {
          uVar5 = uVar5 + 1;
          unaff_r6 = (*param_3)(param_4,0,0);
          *param_6 = 1;
        }
        uVar6 = 2;
      }
      else {
        unaff_r6 = (*param_3)(param_4,0,0);
        local_34 = local_34 + 1;
      }
      break;
    case 2:
      if (((param_1 == 0) || (param_1 == 0x10)) && (unaff_r6 == 0x30)) {
        uVar6 = 4;
        uVar5 = uVar5 + 1;
        unaff_r6 = (*param_3)(param_4,0,0);
      }
      else {
        uVar6 = 8;
      }
      break;
    case 3:
      break;
    case 4:
      if ((unaff_r6 == 0x58) || (unaff_r6 == 0x78)) {
        param_1 = 0x10;
        uVar6 = 8;
        uVar5 = uVar5 + 1;
        unaff_r6 = (*param_3)(param_4,0,0);
      }
      else {
        if (param_1 == 0) {
          param_1 = 8;
        }
        uVar6 = 0x10;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      goto LAB_0213c354;
    default:
      goto LAB_0213c218;
    }
  } while( true );
LAB_0213c218:
  if (uVar6 != 0x10) goto LAB_0213c4ec;
LAB_0213c354:
  if (param_1 == 0) {
    param_1 = 10;
  }
  if (lVar10 == 0) {
    lVar10 = _ll_udiv(0xffffffff,0xffffffff,param_1,(int)param_1 >> 0x1f);
  }
  local_38 = (uint)((ulonglong)lVar10 >> 0x20);
  local_30 = (uint)lVar10;
  if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(DAT_0213c558 + unaff_r6 * 2) & 8;
  }
  if (uVar1 != 0) {
    uVar7 = unaff_r6 - 0x30;
    if ((int)param_1 <= (int)uVar7) {
      if (uVar6 == 0x10) {
        uVar6 = 0x20;
      }
      else {
        uVar6 = 0x40;
      }
      goto LAB_0213c4ec;
    }
LAB_0213c470:
    bVar9 = local_38 <= uVar8;
    if (uVar8 == local_38) {
      bVar9 = local_30 <= uVar3;
    }
    if (bVar9 && (uVar8 != local_38 || uVar3 != local_30)) {
      *param_7 = 1;
    }
    uVar2 = (uint)((ulonglong)param_1 * (ulonglong)uVar3);
    iVar4 = uVar8 * param_1 +
            uVar3 * ((int)param_1 >> 0x1f) + (int)((ulonglong)param_1 * (ulonglong)uVar3 >> 0x20);
    uVar6 = (int)uVar7 >> 0x1f;
    uVar3 = -iVar4 - 1;
    bVar9 = uVar3 <= uVar6;
    if (uVar6 == uVar3) {
      bVar9 = -uVar2 - 1 <= uVar7;
    }
    if (bVar9 && (uVar6 != uVar3 || uVar7 != -uVar2 - 1)) {
      *param_7 = 1;
    }
    uVar3 = uVar2 + uVar7;
    uVar8 = iVar4 + uVar6 + (uint)CARRY4(uVar2,uVar7);
    uVar6 = 0x10;
    uVar5 = uVar5 + 1;
    unaff_r6 = (*param_3)(param_4,0,0);
    goto LAB_0213c4ec;
  }
  if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(DAT_0213c558 + unaff_r6 * 2) & 1;
  }
  if (uVar1 != 0) {
    uVar7 = unaff_r6;
    if ((-1 < (int)unaff_r6) && ((int)unaff_r6 < 0x80)) {
      uVar7 = DAT_0213c55c + unaff_r6 & 3;
      uVar2 = *(uint *)(DAT_0213c55c + unaff_r6 & 0xfffffffc);
      uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) & 0xff;
    }
    if ((int)(uVar7 - 0x37) < (int)param_1) {
      if ((-1 < (int)unaff_r6) && ((int)unaff_r6 < 0x80)) {
        uVar6 = DAT_0213c55c + unaff_r6 & 3;
        uVar7 = *(uint *)(DAT_0213c55c + unaff_r6 & 0xfffffffc);
        unaff_r6 = (uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20) & 0xff;
      }
      uVar7 = unaff_r6 - 0x37;
      goto LAB_0213c470;
    }
  }
  if (uVar6 == 0x10) {
    uVar6 = 0x20;
  }
  else {
    uVar6 = 0x40;
  }
  goto LAB_0213c4ec;
}

