/* Decompiled C draft; module arm9; ROM address 020b4bf8. No matching claim. */
#include "types.h"
#include "deps/020b4bf8_func_020b4bf8.h"

void func_020b4bf8(uint *param_1,int param_2,int param_3)

{
  uint uVar1;
  short sVar2;
  short sVar3;
  longlong lVar4;
  longlong lVar5;
  int iVar6;
  uint uVar7;
  
  sVar2 = *(short *)(iRam020b4c70 + (param_3 >> 4) * 4);
  sVar3 = *(short *)(iRam020b4c70 + ((param_3 >> 4) * 2 + 1) * 2);
  if (param_2 == 0) {
    iVar6 = 0x1000;
  }
  else {
    iVar6 = FX_Div(0x1000);
  }
  lVar4 = (longlong)(int)sVar3 * (longlong)iVar6;
  lVar5 = (longlong)(int)sVar2 * (longlong)iVar6;
  *param_1 = (uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14;
  param_1[1] = (uint)lVar5 >> 0xc | (int)((ulonglong)lVar5 >> 0x20) << 0x14;
  uVar1 = (uint)(param_1 + 1) & 3;
  uVar7 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  param_1[2] = -(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20);
  param_1[3] = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  return;
}

