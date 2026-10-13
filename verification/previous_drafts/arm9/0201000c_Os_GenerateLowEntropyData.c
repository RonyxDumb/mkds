/* Decompiled C draft; module arm9; ROM address 0201000c. No matching claim. */
#include "types.h"
#include "deps/0201000c_Os_GenerateLowEntropyData.h"

void Os_GenerateLowEntropyData(uint *param_1)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  
  iVar2 = iRam020100e8;
  uVar1 = *puRam020100e4;
  uVar7 = OS_GetTickLo();
  *param_1 = uVar7 | (uint)uVar1 << 0x10;
  uVar4 = uRam020100f0;
  uVar7 = uRam020100ec;
  iVar3 = iRam020100e8;
  param_1[1] = (*(uint *)(uRam020100ec & 0xfffffffc) >> (uRam020100ec & 3) * 8 |
               *(uint *)(uRam020100ec & 0xfffffffc) << (uRam020100ec & 3) * -8 + 0x20) ^
               (uint)*(ushort *)(iVar2 + 0xf8) << 0x10;
  uVar10 = uVar7 + 4 & 3;
  uVar11 = *(uint *)(uVar7 + 4 & 0xfffffffc);
  uVar7 = iVar2 + 0xf4;
  uVar9 = uVar7 & 3;
  uVar8 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = iVar3 + 0x3cU & 3;
  uVar12 = *(uint *)(iVar3 + 0x3cU & 0xfffffffc);
  param_1[2] = (uVar12 >> uVar7 * 8 | uVar12 << uVar7 * -8 + 0x20) ^
               (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) ^
               (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
  uVar7 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar10 = uVar4 & 3;
  uVar9 = *(uint *)(uVar4 & 0xfffffffc);
  param_1[2] = (uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) ^
               (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20);
  puVar5 = puRam020100f4;
  uVar7 = iVar3 + 0x1e8U & 3;
  uVar10 = *(uint *)(iVar3 + 0x1e8U & 0xfffffffc);
  param_1[3] = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  puVar6 = puRam020100f8;
  uVar7 = iVar3 + 0x1ecU & 3;
  uVar10 = *(uint *)(iVar3 + 0x1ecU & 0xfffffffc);
  param_1[4] = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
  uVar7 = iVar3 + 0x390U & 3;
  uVar10 = *(uint *)(iVar3 + 0x390U & 0xfffffffc);
  param_1[5] = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) ^
               (uint)*(ushort *)(iVar3 + 0x394) << 0x10;
  param_1[6] = CONCAT22(*(undefined2 *)(iVar3 + 0x3aa),*(undefined2 *)(iVar3 + 0x3ac));
  param_1[7] = CONCAT22(*(undefined2 *)(iVar3 + 0x398),*puVar5 | *puVar6);
  return;
}

