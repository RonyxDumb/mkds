/* Decompiled C draft; module arm9; ROM address 0201dd64. No matching claim. */
#include "types.h"
#include "deps/0201dd64_func_0201dd64.h"

void func_0201dd64(int param_1,uint param_2,int param_3)

{
  short sVar1;
  short sVar2;
  short sVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  bool bVar14;
  ushort *puVar7;
  
  uVar4 = param_2 + 8 & 3;
  uVar6 = *(uint *)(param_2 + 8 & 0xfffffffc);
  puVar7 = (ushort *)(uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20);
  uVar5 = (uint)(byte)puVar7[2];
  uVar6 = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
          *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
  uVar4 = (uint)*(byte *)((int)puVar7 + 5);
  if (param_3 < (int)uVar5) {
    *(ushort *)(param_1 + 0x36) = *puVar7;
    return;
  }
  if (param_3 < (int)uVar4) {
    uVar12 = (uint)*(ushort *)(uVar6 + 0x22);
    uVar11 = (uint)*puVar7;
    bVar14 = -1 < (int)((uint)puVar7[4] << 0x1d);
    uVar10 = (int)uVar12 >> 5 & 0x1f;
    uVar6 = (int)uVar12 >> 10 & 0x1f;
    if (bVar14) {
      uVar4 = uVar12 & 0x1f | uVar10 << 5;
      uVar6 = uVar4 | uVar6 << 10;
    }
    uVar9 = (int)uVar11 >> 5 & 0x1f;
    uVar8 = (int)uVar11 >> 10 & 0x1f;
    if (!bVar14) {
      param_3 = param_3 - uVar5;
      iVar13 = uVar4 - uVar5;
      sVar1 = _s32_div_f(param_3 * (uVar6 - uVar8),iVar13);
      sVar2 = _s32_div_f(param_3 * ((uVar12 & 0x1f) - (uVar11 & 0x1f)),iVar13);
      sVar3 = _s32_div_f(param_3 * (uVar10 - uVar9),iVar13);
      *(short *)(param_1 + 0x36) =
           (short)(uVar11 & 0x1f) + sVar2 | ((short)uVar9 + sVar3) * 0x20 |
           ((short)uVar8 + sVar1) * 0x400;
      return;
    }
    *(short *)(param_1 + 0x36) = (short)uVar6;
    return;
  }
  if ((int)(uint)(byte)puVar7[3] <= param_3) {
    *(ushort *)(param_1 + 0x36) = puVar7[1];
    return;
  }
  uVar10 = (uint)puVar7[1];
  uVar11 = (uint)*(ushort *)(uVar6 + 0x22);
  bVar14 = -1 < (int)((uint)puVar7[4] << 0x1d);
  uVar5 = (int)uVar10 >> 5 & 0x1f;
  uVar6 = (int)uVar10 >> 10 & 0x1f;
  if (bVar14) {
    uVar4 = uVar10 & 0x1f | uVar5 << 5;
    uVar6 = uVar4 | uVar6 << 10;
  }
  uVar12 = (int)uVar11 >> 5 & 0x1f;
  uVar8 = (int)uVar11 >> 10 & 0x1f;
  if (!bVar14) {
    param_3 = param_3 - uVar4;
    iVar13 = (byte)puVar7[3] - uVar4;
    sVar1 = _s32_div_f(param_3 * (uVar6 - uVar8),iVar13);
    sVar2 = _s32_div_f(param_3 * ((uVar10 & 0x1f) - (uVar11 & 0x1f)),iVar13);
    sVar3 = _s32_div_f(param_3 * (uVar5 - uVar12),iVar13);
    *(short *)(param_1 + 0x36) =
         (short)(uVar11 & 0x1f) + sVar2 | ((short)uVar12 + sVar3) * 0x20 |
         ((short)uVar8 + sVar1) * 0x400;
    return;
  }
  *(short *)(param_1 + 0x36) = (short)uVar6;
  return;
}

