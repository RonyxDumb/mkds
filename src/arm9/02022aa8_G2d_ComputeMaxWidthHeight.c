/* Decompiled C draft; module arm9; ROM address 02022aa8. No matching claim. */
#include "types.h"
#include "deps/02022aa8_G2d_ComputeMaxWidthHeight.h"

void G2d_ComputeMaxWidthHeight(int *param_1,uint param_2,undefined4 param_3,int param_4,int param_5)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int local_28;
  
  local_28 = 0;
  iVar3 = 1;
  if (param_5 != 0) {
    do {
      iVar2 = NFTR_GetStringWidth(param_2,param_3,param_5,&param_5);
      if (local_28 < iVar2) {
        local_28 = iVar2;
      }
      iVar3 = iVar3 + 1;
    } while (param_5 != 0);
  }
  cVar1 = *(char *)((*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                    *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) + 1);
  *param_1 = local_28;
  param_1[1] = (iVar3 + -1) * (param_4 + cVar1) - param_4;
  return;
}

