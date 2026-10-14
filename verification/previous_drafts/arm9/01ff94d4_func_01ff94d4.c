/* Decompiled C draft; module arm9; ROM address 01ff94d4. No matching claim. */
#include "types.h"
#include "deps/01ff94d4_func_01ff94d4.h"

void func_01ff94d4(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = (uint)*(ushort *)(param_2 + 0x2c) << 0xc;
  iVar1 = (uint)*(ushort *)(param_2 + 0x2e) << 0xc;
  FX_DivAsync(iVar1,iVar3);
  *param_1 = (int)*(short *)(param_2 + 0x22);
  param_1[5] = (int)*(short *)(param_2 + 0x22);
  iVar2 = FX_GetDivResult();
  param_1[1] = -(int)*(short *)(param_2 + 0x20) * iVar2 >> 0xc;
  FX_DivAsync(iVar3,iVar1);
  param_1[0xc] = (uint)*(ushort *)(param_2 + 0x2c) *
                 (0x1000 - ((int)*(short *)(param_2 + 0x20) + (int)*(short *)(param_2 + 0x22))) * 8;
  param_1[0xd] = (uint)*(ushort *)(param_2 + 0x2e) *
                 (((int)*(short *)(param_2 + 0x20) - (int)*(short *)(param_2 + 0x22)) + 0x1000) * 8;
  iVar3 = FX_GetDivResult();
  param_1[4] = *(short *)(param_2 + 0x20) * iVar3 >> 0xc;
  return;
}

