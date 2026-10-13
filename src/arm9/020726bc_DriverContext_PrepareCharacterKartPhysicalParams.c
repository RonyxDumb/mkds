/* Decompiled C draft; module arm9; ROM address 020726bc. No matching claim. */
#include "types.h"
#include "deps/020726bc_DriverContext_PrepareCharacterKartPhysicalParams.h"

void DriverContext_PrepareCharacterKartPhysicalParams(int param_1)

{
  uint uVar1;
  longlong lVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  short sVar10;
  int iVar11;
  uint uVar9;
  
  uVar3 = GetKartPhysicalParam(*(undefined2 *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x2cc) = uVar3;
  iVar11 = 0x1000;
  iVar4 = IsAwardOrStaffRoll_0();
  sVar10 = 0;
  if (iVar4 == 0) {
    uVar5 = (*(uint *)(uRam020727c8 & 0xfffffffc) >> (uRam020727c8 & 3) * 8 |
            *(uint *)(uRam020727c8 & 0xfffffffc) << (uRam020727c8 & 3) * -8 + 0x20) + 0x10;
    uVar8 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    uVar5 = uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20;
    if (uVar5 == 0) {
      iVar11 = iRam020727d0;
      sVar10 = -0x28;
    }
    else {
      sVar10 = 0;
      if (uVar5 == 1) {
        sVar10 = -0x14;
        iVar11 = iRam020727cc;
      }
    }
  }
  uVar5 = param_1 + 0x2ccU & 3;
  uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar9 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  uVar5 = uVar9 + 0x10;
  uVar8 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  lVar2 = (longlong)(int)(uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20) * (longlong)iVar11;
  *(uint *)(uVar9 + 0x10) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14;
  uVar5 = param_1 + 0x2ccU & 3;
  uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar5 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  *(short *)(uVar5 + 0x32) = *(short *)(uVar5 + 0x32) + sVar10;
  uVar5 = param_1 + 0x2ccU & 3;
  uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar5 = (uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) + 0x78;
  uVar8 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *(uint *)(param_1 + 0x3f4) = 0x1000 - (uVar5 >> uVar8 * 8 | uVar5 << uVar8 * -8 + 0x20);
  uVar5 = param_1 + 0x2ccU & 3;
  uVar8 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar6 = uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x3f4U & 3;
  uVar9 = *(uint *)(param_1 + 0x3f4U & 0xfffffffc);
  uVar8 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar3 = FX_Div(uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20,
                 (uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) << 1);
  *(undefined4 *)(param_1 + 0x3f4) = uVar3;
  uVar3 = GetCharacterPhysicalParam(*(undefined2 *)(param_1 + 0x74));
  *(undefined4 *)(param_1 + 0x2d0) = uVar3;
  uVar5 = param_1 + 0x2ccU & 3;
  uVar9 = *(uint *)(param_1 + 0x2ccU & 0xfffffffc);
  uVar8 = param_1 + 0x2d0U & 3;
  uVar6 = *(uint *)(param_1 + 0x2d0U & 0xfffffffc);
  uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
  iVar11 = 0;
  do {
    iVar4 = (uVar9 >> uVar5 * 8 | uVar9 << uVar5 * -8 + 0x20) + iVar11 * 4;
    uVar6 = iVar4 + 0x68;
    uVar1 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20;
    if ((int)uVar6 < 0x1000) {
      uVar1 = uVar8 & 3;
      uVar7 = *(uint *)(uVar8 & 0xfffffffc);
      lVar2 = (longlong)(int)uVar6 *
              (longlong)(int)(uVar7 >> uVar1 * 8 | uVar7 << uVar1 * -8 + 0x20) + 0x800;
      *(uint *)(iVar4 + 0x68) = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    }
    iVar11 = (iVar11 + 1) * 0x10000 >> 0x10;
  } while (iVar11 < 0xc);
  return;
}

