/* Decompiled C draft; module arm9; ROM address 02015044. No matching claim. */
#include "types.h"
#include "deps/02015044_func_02015044.h"

void func_02015044(uint *param_1)

{
  int iVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  ushort *puVar7;
  uint uVar8;
  ushort *puVar9;
  
  uVar5 = *(uint *)(uRam02015190 & 0xfffffffc) >> (uRam02015190 & 3) * 8 |
          *(uint *)(uRam02015190 & 0xfffffffc) << (uRam02015190 & 3) * -8 + 0x20;
  uVar6 = uVar5 + 0xd4 & 3;
  uVar8 = *(uint *)(uVar5 + 0xd4 & 0xfffffffc);
  uVar8 = uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20;
  uVar6 = (uint)*(ushort *)(uVar8 + *(ushort *)(uVar8 + 6)) *
          (uint)*(byte *)((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 1) +
          uVar8 + *(ushort *)(uVar8 + 6) + 4;
  uVar5 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
  uVar2 = *(ushort *)(uVar8 + uVar6);
  puVar9 = (ushort *)(uVar8 + uVar6);
  puVar7 = puVar9 + 2;
  if ((uVar2 & 1) == 0) {
    puVar7 = puVar9 + 8;
  }
  if ((uVar2 & 2) != 0) {
    *param_1 = *(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20 | 2;
    return;
  }
  if ((uVar2 & 8) == 0) {
    param_1[10] = (int)(short)puVar9[1];
    param_1[0xb] = (int)(short)*puVar7;
    param_1[0xc] = (int)(short)puVar7[1];
    param_1[0xd] = (int)(short)puVar7[2];
    param_1[0xe] = (int)(short)puVar7[3];
    param_1[0xf] = (int)(short)puVar7[4];
    param_1[0x10] = (int)(short)puVar7[5];
    param_1[0x11] = (int)(short)puVar7[6];
    param_1[0x12] = (int)(short)puVar7[7];
    return;
  }
  iVar1 = (int)(uVar2 & 0xf0) >> 4;
  uVar5 = (uint)(short)*puVar7;
  uVar6 = (uint)(short)puVar7[1];
  func_0214d32c(param_1 + 10);
  iVar3 = iRam02015194;
  if ((*puVar9 & 0x100) == 0) {
    uVar8 = 0x1000;
  }
  else {
    uVar8 = 0xfffff000;
  }
  param_1[iVar1 + 10] = uVar8;
  iVar4 = iRam02015198;
  param_1[*(byte *)(iVar3 + iVar1 * 4) + 10] = uVar5;
  param_1[*(byte *)(iVar4 + iVar1 * 4) + 10] = uVar6;
  if ((*puVar9 & 0x200) != 0) {
    uVar6 = -uVar6;
  }
  param_1[*(byte *)(iRam0201519c + iVar1 * 4) + 10] = uVar6;
  if ((*puVar9 & 0x400) != 0) {
    uVar5 = -uVar5;
  }
  param_1[*(byte *)(iRam020151a0 + iVar1 * 4) + 10] = uVar5;
  return;
}

