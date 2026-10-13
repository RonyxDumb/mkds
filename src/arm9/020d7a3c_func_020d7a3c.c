/* Decompiled C draft; module arm9; ROM address 020d7a3c. No matching claim. */
#include "types.h"
#include "deps/020d7a3c_func_020d7a3c.h"

void func_020d7a3c(uint param_1,int param_2,int *param_3)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  puVar2 = puRam020d7b2c;
  uVar1 = param_1 + 4 & 3;
  uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
  *puRam020d7b28 = 1;
  *puVar2 = 0;
  puVar2[1] = ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x1000) * 2;
  iVar4 = FX_GetSqrtResult();
  uVar1 = param_1 + 8 & 3;
  uVar3 = *(uint *)(param_1 + 8 & 0xfffffffc);
  FX_DivAsync(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20,iVar4);
  iVar5 = (int)((uint)(param_2 << 0xf) >> 0x10) >> 4;
  iVar7 = (int)*(short *)(iRam020d7b30 + iVar5 * 4);
  iVar6 = (int)*(short *)(iRam020d7b30 + (iVar5 * 2 + 1) * 2);
  param_3[1] = (iVar4 >> 1) * iVar7 >> 0xc;
  param_3[3] = (iVar4 >> 1) * iVar6 >> 0xc;
  iVar5 = FX_GetDivResult();
  FX_DivAsync(-(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
               *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20),iVar4);
  *param_3 = iVar5 * iVar6 >> 0xc;
  param_3[2] = iVar5 * iVar7 >> 0xc;
  iVar5 = FX_GetDivResult();
  *param_3 = (*(uint *)((uint)param_3 & 0xfffffffc) >> ((uint)param_3 & 3) * 8 |
             *(uint *)((uint)param_3 & 0xfffffffc) << ((uint)param_3 & 3) * -8 + 0x20) -
             (iVar5 * iVar7 >> 0xc);
  uVar1 = (uint)(param_3 + 2) & 3;
  uVar3 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
  param_3[2] = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + (iVar5 * iVar6 >> 0xc);
  return;
}

