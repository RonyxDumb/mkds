/* Decompiled C draft; module arm9; ROM address 020b496c. No matching claim. */
#include "types.h"
#include "deps/020b496c_Gfx_ReadCharGraphicsV2.h"

void Gfx_ReadCharGraphicsV2(int *param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  if ((param_2 != 0) && (iVar3 = Common_FindBlockByMagic(param_2,uRam020b49b8), iVar3 != 0)) {
    *param_1 = iVar3 + 8;
    Gfx_MakeCharGraphicsOffsetsAbsoluteV2
              (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20);
  }
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  uVar1 = uVar5 + 0x14;
  uVar2 = uVar1 & 3;
  uVar4 = *(uint *)(uVar1 & 0xfffffffc);
  uVar5 = uVar5 + 0x10;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  Arm_FlushRange(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,
                 uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
  return;
}

