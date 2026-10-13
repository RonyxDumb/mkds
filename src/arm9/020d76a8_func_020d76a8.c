/* Decompiled C draft; module arm9; ROM address 020d76a8. No matching claim. */
#include "types.h"
#include "deps/020d76a8_func_020d76a8.h"

void func_020d76a8(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = (int)((uint)(param_2 << 0xf) >> 0x10) >> 4;
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar4 = (int)*(short *)(iRam020d7730 + iVar3 * 4);
  iVar3 = (int)*(short *)(iRam020d7730 + (iVar3 * 2 + 1) * 2);
  *param_3 = iVar2 * iVar4 >> 0xc;
  param_3[1] = iVar1 * iVar3 >> 0xc;
  param_3[2] = -iVar1 * iVar4 >> 0xc;
  param_3[3] = iVar2 * iVar3 >> 0xc;
  return;
}

