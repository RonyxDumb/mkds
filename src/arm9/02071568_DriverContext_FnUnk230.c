/* Decompiled C draft; module arm9; ROM address 02071568. No matching claim. */
#include "types.h"
#include "deps/02071568_DriverContext_FnUnk230.h"

void DriverContext_FnUnk230(int param_1)

{
  int iVar1;
  uint uVar2;
  longlong lVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar1 = iRam02071760;
  uVar7 = param_1 + 0x4ecU & 3;
  uVar6 = *(uint *)(param_1 + 0x4ecU & 0xfffffffc);
  uVar8 = param_1 + 0x4e8U & 3;
  uVar4 = *(uint *)(param_1 + 0x4e8U & 0xfffffffc);
  *(uint *)(param_1 + 0x4ec) =
       (uVar6 >> uVar7 * 8 | uVar6 << uVar7 * -8 + 0x20) +
       (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20);
  uVar8 = uRam02071764;
  uVar7 = param_1 + 0x4ecU & 3;
  uVar4 = *(uint *)(param_1 + 0x4ecU & 0xfffffffc);
  iVar5 = (uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20) - 0x8000;
  if (-1 < iVar5) {
    *(int *)(param_1 + 0x4ec) = iVar5;
  }
  iVar5 = iRam02071768;
  uVar7 = param_1 + 0x4ecU & 3;
  uVar4 = *(uint *)(param_1 + 0x4ecU & 0xfffffffc);
  uVar6 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  uVar7 = (uVar6 << 4) >> 0x10;
  uVar4 = uVar7 + 1 & 0xffff;
  if (7 < uVar4) {
    uVar4 = 0;
  }
  uVar6 = uVar6 & uVar8;
  uVar8 = iVar1 + uVar7 * 4;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
  uVar8 = iVar1 + uVar4 * 4;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  lVar3 = (longlong)(int)uVar6 *
          (longlong)((int)((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) - uVar9) >> 1);
  *(uint *)(param_1 + 0x4f0) =
       uVar9 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  iVar1 = iRam0207176c;
  uVar8 = iVar5 + uVar7 * 4;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20;
  uVar8 = iVar5 + uVar4 * 4;
  uVar2 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  lVar3 = (longlong)(int)uVar6 *
          (longlong)((int)((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) - uVar9) >> 1);
  *(uint *)(param_1 + 0x4f4) =
       uVar9 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar2 = uRam02071770;
  uVar7 = iVar1 + uVar7 * 4;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar9 = uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20;
  uVar7 = iVar1 + uVar4 * 4;
  uVar8 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  lVar3 = (longlong)(int)uVar6 *
          (longlong)((int)((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) - uVar9) >> 1);
  *(uint *)(param_1 + 0x4f8) =
       uVar9 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar7 = param_1 + 0x4d4U & 3;
  uVar8 = *(uint *)(param_1 + 0x4d4U & 0xfffffffc);
  uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  lVar3 = (ulonglong)uVar2 * (ulonglong)uVar7;
  iVar1 = (int)uVar7 >> 0x1f;
  uVar8 = (uint)lVar3 >> 0xc | (iVar1 * uVar2 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
  if (iRam02071774 < (int)uVar7) {
    uVar8 = (uVar7 + iRam02071778) * 0x32;
    lVar3 = (ulonglong)uRam0207177c * (ulonglong)uVar8;
    uVar8 = (uint)lVar3 >> 0xc |
            (((int)uVar8 >> 0x1f) * uRam0207177c + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    if ((int)uRam0207177c < (int)uVar8) {
      uVar8 = uRam0207177c;
    }
    uVar8 = uVar8 + uRam02071770;
    uVar8 = (uint)((ulonglong)uVar8 * (ulonglong)uVar7) >> 0xc |
            (iVar1 * uVar8 +
            uVar7 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)uVar8 * (ulonglong)uVar7 >> 0x20)) *
            0x100000;
  }
  else if (iRam02071780 < (int)uVar7) {
    uVar8 = (uVar7 + iRam02071784) * 0x32;
    lVar3 = (ulonglong)uVar8 * 0x52;
    uVar8 = (uint)lVar3 >> 0xc |
            (((int)uVar8 >> 0x1f) * 0x52 + (int)((ulonglong)lVar3 >> 0x20)) * 0x100000;
    if (0x52 < (int)uVar8) {
      uVar8 = 0x52;
    }
    uVar8 = uVar8 + uRam02071770;
    uVar8 = (uint)((ulonglong)uVar8 * (ulonglong)uVar7) >> 0xc |
            (iVar1 * uVar8 +
            uVar7 * ((int)uVar8 >> 0x1f) + (int)((ulonglong)uVar8 * (ulonglong)uVar7 >> 0x20)) *
            0x100000;
  }
  uVar7 = param_1 + 0x4f0U & 3;
  uVar4 = *(uint *)(param_1 + 0x4f0U & 0xfffffffc);
  uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar8;
  *(uint *)(param_1 + 0x4f0) =
       uVar7 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar7 = param_1 + 0x4f4U & 3;
  uVar4 = *(uint *)(param_1 + 0x4f4U & 0xfffffffc);
  uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar8;
  *(uint *)(param_1 + 0x4f4) =
       uVar7 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  uVar7 = param_1 + 0x4f8U & 3;
  uVar4 = *(uint *)(param_1 + 0x4f8U & 0xfffffffc);
  uVar7 = uVar4 >> uVar7 * 8 | uVar4 << uVar7 * -8 + 0x20;
  lVar3 = (longlong)(int)uVar7 * (longlong)(int)uVar8;
  *(uint *)(param_1 + 0x4f8) =
       uVar7 + ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14);
  return;
}

