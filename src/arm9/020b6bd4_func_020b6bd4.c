/* Decompiled C draft; module arm9; ROM address 020b6bd4. No matching claim. */
#include "types.h"
#include "deps/020b6bd4_func_020b6bd4.h"

void func_020b6bd4(int *param_1,int *param_2,int param_3,int param_4,short param_5,short param_6)

{
  longlong lVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = (param_5 - param_3) * 0xf000;
  iVar4 = (param_5 - param_3) * 0x1f000;
  iVar5 = (param_6 - param_4) * 0x5000;
  iVar3 = (param_6 - param_4) * 0x18000;
  lVar1 = (longlong)iRam020b6c70;
  lVar2 = (longlong)iRam020b6c70;
  *param_1 = param_3 * 0x1000 + ((int)(iVar6 + ((uint)(iVar6 >> 4) >> 0x1b)) >> 5);
  param_1[1] = ((int)(lVar1 * iVar5 >> 0x22) - (iVar5 >> 0x1f)) + param_4 * 0x1000;
  *param_2 = param_3 * 0x1000 + ((int)(iVar4 + ((uint)(iVar4 >> 4) >> 0x1b)) >> 5);
  param_2[1] = ((int)(lVar2 * iVar3 >> 0x22) - (iVar3 >> 0x1f)) + param_4 * 0x1000;
  return;
}

