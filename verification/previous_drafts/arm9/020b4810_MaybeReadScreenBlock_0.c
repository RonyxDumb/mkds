/* Decompiled C draft; module arm9; ROM address 020b4810. No matching claim. */
#include "types.h"
#include "deps/020b4810_MaybeReadScreenBlock_0.h"

void MaybeReadScreenBlock_0(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  if ((param_2 != 0) && (iVar2 = Common_FindBlockByMagic(param_2,uRam020b4868), iVar2 != 0)) {
    *param_1 = iVar2 + 8;
    Screen_ReadBlock(param_2,param_1);
  }
  uVar3 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar4 = uVar3 + 8;
  uVar1 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  Arm_FlushRange(uVar3 + 0xc,uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return;
}

