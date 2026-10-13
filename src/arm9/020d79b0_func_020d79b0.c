/* Decompiled C draft; module arm9; ROM address 020d79b0. No matching claim. */
#include "types.h"
#include "deps/020d79b0_func_020d79b0.h"

void func_020d79b0(uint param_1,int param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = (int)((uint)(param_2 << 0xf) >> 0x10) >> 4;
  iVar3 = (int)*(short *)(iRam020d7a38 + iVar2 * 4);
  uVar1 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  iVar2 = (int)*(short *)(iRam020d7a38 + (iVar2 * 2 + 1) * 2);
  *param_3 = (int)((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * iVar2 -
                  (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * iVar3) >> 0xc;
  uVar1 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  param_3[1] = (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * iVar3) >> 0xc;
  uVar1 = param_1 + 8 & 3;
  uVar4 = *(uint *)(param_1 + 8 & 0xfffffffc);
  param_3[2] = (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * iVar2 +
                    (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                    *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * iVar3) >> 0xc;
  uVar1 = param_1 + 0xc & 3;
  uVar4 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  param_3[3] = (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) * iVar2) >> 0xc;
  return;
}

