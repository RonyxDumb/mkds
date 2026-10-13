/* Decompiled C draft; module arm9; ROM address 020d7734. No matching claim. */
#include "types.h"
#include "deps/020d7734_func_020d7734.h"

void func_020d7734(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar2 = (int)((uint)(param_2 << 0xf) >> 0x10) >> 4;
  iVar1 = *param_1;
  iVar3 = param_1[1];
  iVar5 = param_1[2];
  iVar6 = param_1[3];
  iVar4 = (int)*(short *)(iRam020d77dc + iVar2 * 4);
  iVar2 = (int)*(short *)(iRam020d77dc + (iVar2 * 2 + 1) * 2);
  *param_3 = iVar1 * iVar2 + iVar3 * iVar4 >> 0xc;
  param_3[1] = iVar3 * iVar2 - iVar1 * iVar4 >> 0xc;
  param_3[2] = iVar6 * iVar4 + iVar5 * iVar2 >> 0xc;
  param_3[3] = iVar6 * iVar2 - iVar5 * iVar4 >> 0xc;
  return;
}

