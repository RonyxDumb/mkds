/* Decompiled C draft; module arm9; ROM address 0213c560. No matching claim. */
#include "types.h"
#include "deps/0213c560_func_0213c560.h"

/* WARNING: Removing unreachable block (ram,0x0213c62c) */

uint func_0213c560(int param_1,int param_2,code *param_3,undefined4 param_4,int *param_5,
                  uint *param_6,undefined4 *param_7)

{
  ushort uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint unaff_r6;
  uint uVar6;
  uint uVar7;
  int local_2c;
  
  *param_7 = 0;
  local_2c = 0;
  uVar2 = 0;
  *param_6 = *(uint *)((uint)param_7 & 0xfffffffc) >> ((uint)param_7 & 3) * 8 |
             *(uint *)((uint)param_7 & 0xfffffffc) << ((uint)param_7 & 3) * -8 + 0x20;
  uVar5 = 1;
  if ((((param_1 < 0) || (param_1 == 1)) || (0x24 < param_1)) || (param_2 < 1)) {
    uVar5 = 0x40;
    uVar4 = uVar2;
  }
  else {
    uVar4 = 1;
    unaff_r6 = (*param_3)(param_4,0,0);
  }
  uVar7 = uVar2;
  if (param_1 != 0) {
    uVar2 = MaybeBoundsCheck(0xffffffff,param_1);
    uVar7 = 0;
  }
LAB_0213c8e0:
  do {
    if (((param_2 < (int)uVar4) || (unaff_r6 == 0xffffffff)) || ((uVar5 & 0x60) != 0)) {
      if ((uVar5 & 0x34) == 0) {
        uVar7 = 0;
        *param_5 = 0;
      }
      else {
        *param_5 = (uVar4 - 1) + local_2c;
      }
      (*param_3)(param_4,unaff_r6,1);
      return uVar7;
    }
    switch(uVar5) {
    case 0:
      break;
    case 1:
      if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
        uVar1 = 0;
      }
      else {
        uVar1 = *(ushort *)(DAT_0213c944 + unaff_r6 * 2) & 0x100;
      }
      if (uVar1 == 0) {
        if (unaff_r6 == 0x2b) {
          uVar4 = uVar4 + 1;
          unaff_r6 = (*param_3)(param_4,0,0);
        }
        else if (unaff_r6 == 0x2d) {
          uVar4 = uVar4 + 1;
          unaff_r6 = (*param_3)(param_4,0,0);
          *param_6 = 1;
        }
        uVar5 = 2;
      }
      else {
        unaff_r6 = (*param_3)(param_4,0,0);
        local_2c = local_2c + 1;
      }
      break;
    case 2:
      if (((param_1 == 0) || (param_1 == 0x10)) && (unaff_r6 == 0x30)) {
        uVar5 = 4;
        uVar4 = uVar4 + 1;
        unaff_r6 = (*param_3)(param_4,0,0);
      }
      else {
        uVar5 = 8;
      }
      break;
    case 3:
      break;
    case 4:
      if ((unaff_r6 == 0x58) || (unaff_r6 == 0x78)) {
        uVar4 = uVar4 + 1;
        param_1 = 0x10;
        uVar5 = 8;
        unaff_r6 = (*param_3)(param_4,0,0);
      }
      else {
        if (param_1 == 0) {
          param_1 = 8;
        }
        uVar5 = 0x10;
      }
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      goto LAB_0213c790;
    default:
      goto LAB_0213c654;
    }
  } while( true );
LAB_0213c654:
  if (uVar5 != 0x10) goto LAB_0213c8e0;
LAB_0213c790:
  if (param_1 == 0) {
    param_1 = 10;
  }
  if (uVar2 == 0) {
    uVar2 = MaybeBoundsCheck(0xffffffff,param_1);
  }
  if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
    uVar1 = 0;
  }
  else {
    uVar1 = *(ushort *)(DAT_0213c944 + unaff_r6 * 2) & 8;
  }
  if (uVar1 == 0) {
    if (((int)unaff_r6 < 0) || (0x7f < (int)unaff_r6)) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(ushort *)(DAT_0213c944 + unaff_r6 * 2) & 1;
    }
    if (uVar1 != 0) {
      uVar6 = unaff_r6;
      if ((-1 < (int)unaff_r6) && ((int)unaff_r6 < 0x80)) {
        uVar6 = DAT_0213c948 + unaff_r6 & 3;
        uVar3 = *(uint *)(DAT_0213c948 + unaff_r6 & 0xfffffffc);
        uVar6 = (uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20) & 0xff;
      }
      if ((int)(uVar6 - 0x37) < param_1) {
        if ((-1 < (int)unaff_r6) && ((int)unaff_r6 < 0x80)) {
          uVar5 = DAT_0213c948 + unaff_r6 & 3;
          uVar6 = *(uint *)(DAT_0213c948 + unaff_r6 & 0xfffffffc);
          unaff_r6 = (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20) & 0xff;
        }
        uVar6 = unaff_r6 - 0x37;
        goto LAB_0213c890;
      }
    }
    if (uVar5 == 0x10) {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x40;
    }
    goto LAB_0213c8e0;
  }
  uVar6 = unaff_r6 - 0x30;
  if (param_1 <= (int)uVar6) {
    if (uVar5 == 0x10) {
      uVar5 = 0x20;
    }
    else {
      uVar5 = 0x40;
    }
    goto LAB_0213c8e0;
  }
LAB_0213c890:
  if (uVar2 < uVar7) {
    *param_7 = 1;
  }
  if (-(uVar7 * param_1) - 1 < uVar6) {
    *param_7 = 1;
  }
  uVar7 = uVar7 * param_1 + uVar6;
  uVar5 = 0x10;
  uVar4 = uVar4 + 1;
  unaff_r6 = (*param_3)(param_4,0,0);
  goto LAB_0213c8e0;
}

