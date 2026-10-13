/* Decompiled C draft; module arm9; ROM address 0207fec0. No matching claim. */
#include "types.h"
#include "deps/0207fec0_func_0207fec0.h"

void func_0207fec0(uint *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar7 = 0;
  iVar3 = GetDriverEntry((short)param_1[7]);
  iVar2 = iRam0207ff58;
  uVar5 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20;
  if (1 < *(ushort *)(uVar5 + 0x24)) {
    uVar7 = (uint)(ushort)param_1[7];
  }
  param_1[1] = uVar5;
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + uVar7 * 4;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *param_1 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar7 = iVar3 + 0x590U & 3;
  uVar4 = *(uint *)(iVar3 + 0x590U & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar5 & 3;
  uVar6 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 8;
  uVar7 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = iVar2 + *(short *)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 4) * 4;
  uVar1 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20;
  if (uVar5 != *(ushort *)((uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) + 0x1a)) {
    DriverContext_UpdateCharacterAnimation(iVar3,uVar5,1);
  }
  uVar7 = (uint)(param_1 + 1) & 3;
  uVar6 = *(uint *)((uint)(param_1 + 1) & 0xfffffffc);
  uVar5 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
          *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 0x18;
  uVar1 = uVar5 & 3;
  uVar4 = *(uint *)(uVar5 & 0xfffffffc);
  uVar5 = (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) + 0x18;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  VecFx32_Subtract(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20,
                   uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20,param_1 + 2);
  Vector3_MaybeNormalize(param_1 + 2,param_1 + 2);
  return;
}

