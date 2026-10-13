/* Decompiled C draft; module arm9; ROM address 0201625c. No matching claim. */
#include "types.h"
#include "deps/0201625c_func_0201625c.h"

void func_0201625c(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  piVar1 = piRam020162ac;
  iVar5 = param_2 * 0x18 + iRam020162a8;
  iVar4 = param_3 * 0x18 + iRam020162a8;
  iVar3 = param_4 * 0x18 + iRam020162a8;
  iVar2 = param_5 * 0x18 + iRam020162a8;
  *piRam020162ac = param_1 * 0x18 + iRam020162a8;
  piVar1[1] = iVar5;
  piVar1[2] = iVar4;
  piVar1[3] = iVar3;
  piVar1[4] = iVar2;
  return;
}

