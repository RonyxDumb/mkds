/* Decompiled C draft; module arm9_ov000; ROM address 021aa880. No matching claim. */
#include "types.h"
#include "deps/021aa880_FUN_021aa880.h"

void FUN_021aa880(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if ((param_3 != (int *)0x0) && (*param_3 != 0)) {
    iVar1 = func_0x02133068(*param_3 << 1,2);
    iVar1 = iVar1 + 1;
    iVar2 = (*(code *)*DAT_021aa9e4)(iVar1 * 0x14);
    if (iVar2 != 0) {
      iVar3 = iVar1 * 2;
      iVar9 = iVar2 + iVar3;
      iVar4 = iVar9 + iVar3;
      iVar5 = iVar4 + iVar3;
      iVar6 = iVar5 + iVar3;
      iVar7 = iVar6 + iVar3;
      iVar8 = iVar7 + iVar3;
      FUN_021ac4b8(iVar2,param_2,*param_3,iVar1);
      FUN_021ac4b8(iVar9,param_3[7],param_3[6],iVar1);
      FUN_021ac4b8(iVar7,param_3[3],param_3[2],iVar1);
      FUN_021ac4f4(iVar5,iVar2,iVar9,iVar1,iVar7);
      FUN_021ac4b8(iVar9,param_3[9],param_3[8],iVar1);
      FUN_021ac4b8(iVar7,param_3[5],param_3[4],iVar1);
      FUN_021ac4f4(iVar6,iVar2,iVar9,iVar1,iVar7);
      FUN_021acd24(iVar2,iVar5,iVar6,iVar1);
      FUN_021ac4b8(iVar9,param_3[0xb],param_3[10],iVar1);
      FUN_021acbf8(iVar4,iVar2,iVar9,iVar1);
      FUN_021ac4b8(iVar9,param_3[5],param_3[4],iVar1);
      FUN_021acbf8(iVar2,iVar4,iVar9,iVar1);
      FUN_021ace14(iVar4,iVar2,iVar6,iVar1);
      FUN_021ac4b8(iVar9,param_3[1],*param_3,iVar1);
      iVar5 = FUN_021ace90(iVar4,iVar1);
      if (iVar5 < 0) {
        FUN_021acda8(iVar4,iVar1);
        FUN_021ac900(0,iVar4,iVar9,iVar8,iVar1,iVar8 + iVar3);
        FUN_021acd24(iVar8,iVar9,iVar8,iVar1);
      }
      else {
        FUN_021ac900(0,iVar4,iVar9,iVar8,iVar1,iVar8 + iVar3);
      }
      FUN_021ac488(param_1,iVar8,0x30,iVar1);
      (*(code *)*DAT_021aa9e8)(iVar2);
    }
  }
  return;
}

