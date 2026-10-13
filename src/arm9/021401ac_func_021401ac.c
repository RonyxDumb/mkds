/* Decompiled C draft; module arm9; ROM address 021401ac. No matching claim. */
#include "types.h"
#include "deps/021401ac_func_021401ac.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

undefined8 func_021401ac(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined8 uVar3;
  double dVar4;
  int iVar5;
  undefined4 local_10;
  uint local_c;
  
  uVar3 = CONCAT44(param_2,param_1);
  if ((param_2 & uRam0214045c) == 0) {
    if (((param_2 & uRam02140460) == 0) && (param_1 == 0)) {
      uVar1 = 3;
    }
    else {
      uVar1 = 5;
    }
  }
  else if ((param_2 & uRam0214045c) == uRam0214045c) {
    if (((param_2 & uRam02140460) == 0) && (param_1 == 0)) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 4;
  }
  if ((uVar1 < 3) ||
     (iVar5 = param_1, uVar1 = param_2, iVar2 = FUN_02131bfc(0,0,param_1,param_2), iVar2 != 0)) {
    return CONCAT44(param_2,param_1);
  }
  iVar2 = (int)(param_2 & uRam0214045c) >> 0x14;
  if (iVar2 == 0) {
    if (param_1 == 0 && (param_2 & 0x7fffffff) == 0) {
      return CONCAT44(param_2,param_1);
    }
    uVar3 = func_02130380(param_1,param_2,0,uRam02140464);
    iVar2 = ((int)((uint)((ulonglong)uVar3 >> 0x20) & uRam0214045c) >> 0x14) + -0x36;
    if (param_3 < iRam02140468) {
      uVar3 = func_02130380(uRam0214046c,uRam02140470);
      return uVar3;
    }
  }
  local_c = (uint)((ulonglong)uVar3 >> 0x20);
  local_10 = (undefined4)uVar3;
  if (iVar2 == iRam02140474) {
    uVar3 = func_0212f884(local_10,local_c,local_10,local_c);
    return uVar3;
  }
  iVar2 = iVar2 + param_3;
  if (iVar2 <= iRam02140478) {
    if (0 < iVar2) {
      return CONCAT44(local_c & uRam02140484 | iVar2 * 0x100000,local_10);
    }
    if (-0x36 < iVar2) {
      uVar3 = func_02130380(0,uRam0214048c,local_10);
      return uVar3;
    }
    if (param_3 <= iRam02140488) {
      dVar4 = copysign((double)CONCAT44(uVar1,iVar5),(double)CONCAT44(unaff_r5,unaff_r4));
      uVar3 = func_02130380(uRam0214046c,uRam02140470,SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20)
                           );
      return uVar3;
    }
    dVar4 = copysign((double)CONCAT44(uVar1,iVar5),(double)CONCAT44(unaff_r5,unaff_r4));
    uVar3 = func_02130380(uRam0214047c,uRam02140480,SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
    return uVar3;
  }
  dVar4 = copysign((double)CONCAT44(uVar1,iVar5),(double)CONCAT44(unaff_r5,unaff_r4));
  uVar3 = func_02130380(uRam0214047c,uRam02140480,SUB84(dVar4,0),(int)((ulonglong)dVar4 >> 0x20));
  return uVar3;
}

