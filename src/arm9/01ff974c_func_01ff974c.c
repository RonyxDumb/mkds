/* Decompiled C draft; module arm9; ROM address 01ff974c. No matching claim. */
#include "types.h"
#include "deps/01ff974c_func_01ff974c.h"

void func_01ff974c(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = (uint)*(ushort *)(param_2 + 0x2c) << 0xc;
  iVar1 = (uint)*(ushort *)(param_2 + 0x2e) << 0xc;
  FX_DivAsync(iVar1,iVar5);
  *param_1 = (int)*(short *)(param_2 + 0x22);
  param_1[5] = (int)*(short *)(param_2 + 0x22);
  iVar3 = FX_GetDivResult();
  param_1[1] = -(int)*(short *)(param_2 + 0x20) * iVar3 >> 0xc;
  FX_DivAsync(iVar5,iVar1);
  uVar2 = param_2 + 0x24U & 3;
  uVar4 = *(uint *)(param_2 + 0x24U & 0xfffffffc);
  param_1[0xc] = (uint)*(ushort *)(param_2 + 0x2c) *
                 (0x1000 - ((int)*(short *)(param_2 + 0x20) + (int)*(short *)(param_2 + 0x22))) * 8
                 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) *
                   (uint)*(ushort *)(param_2 + 0x2c) * -0x10;
  uVar2 = param_2 + 0x28U & 3;
  uVar4 = *(uint *)(param_2 + 0x28U & 0xfffffffc);
  param_1[0xd] = (uint)*(ushort *)(param_2 + 0x2e) *
                 (((int)*(short *)(param_2 + 0x20) - (int)*(short *)(param_2 + 0x22)) + 0x1000) * 8
                 + (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) *
                   (uint)*(ushort *)(param_2 + 0x2e) * 0x10;
  iVar5 = FX_GetDivResult();
  param_1[4] = *(short *)(param_2 + 0x20) * iVar5 >> 0xc;
  return;
}

