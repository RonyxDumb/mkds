/* Decompiled C draft; module arm9; ROM address 02077060. No matching claim. */
#include "types.h"
#include "deps/02077060_StructHD_SomeFn_2.h"

void StructHD_SomeFn_2(uint param_1)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar6;
  
  if (param_1 ==
      (*(uint *)(uRam02077284 & 0xfffffffc) >> (uRam02077284 & 3) * 8 |
      *(uint *)(uRam02077284 & 0xfffffffc) << (uRam02077284 & 3) * -8 + 0x20)) {
    uVar3 = param_1 + 100 & 3;
    uVar5 = *(uint *)(param_1 + 100 & 0xfffffffc);
    uVar6 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    uVar3 = param_1 + 0x60 & 3;
    uVar5 = *(uint *)(param_1 + 0x60 & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if ((uVar3 == uVar6) &&
       (*(uint *)(uRam02077288 & 0xfffffffc) >> (uRam02077288 & 3) * 8 == 0 &&
        *(uint *)(uRam02077288 & 0xfffffffc) << (uRam02077288 & 3) * -8 + 0x20 == 0)) {
      return;
    }
    iVar2 = AbsValue(uVar3 - uVar6);
    if (iVar2 < 10) {
      uVar3 = param_1 + 100 & 3;
      uVar5 = *(uint *)(param_1 + 100 & 0xfffffffc);
      *(uint *)(param_1 + 0x60) = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    }
  }
  iVar2 = FX_Div((int)*(short *)(param_1 + 0x68),(int)*(short *)(param_1 + 0x6a));
  uVar3 = param_1 + 0x70 & 3;
  uVar5 = *(uint *)(param_1 + 0x70 & 0xfffffffc);
  lVar1 = (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) * (longlong)iVar2;
  *(uint *)(param_1 + 0x78) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar3 = param_1 + 0x78 & 3;
  uVar5 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  *(uint *)(param_1 + 0x7c) = -(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20);
  uVar3 = param_1 + 0x78 & 3;
  uVar4 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  uVar5 = param_1 + 0x6c & 3;
  uVar6 = *(uint *)(param_1 + 0x6c & 0xfffffffc);
  lVar1 = (longlong)(int)-(uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20) *
          (longlong)(int)(uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
  *(uint *)(param_1 + 0x80) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
  uVar5 = uRam0207728c;
  uVar3 = param_1 + 0x24c & 3;
  uVar6 = *(uint *)(param_1 + 0x24c & 0xfffffffc);
  uVar7 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x78 & 3;
  uVar6 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  uVar6 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x7c & 3;
  uVar4 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
  uVar3 = uVar4 >> uVar3 * 8 | uVar4 << uVar3 * -8 + 0x20;
  if (uVar7 == 1) {
    uVar4 = uVar6 * 2;
    uVar3 = uVar6 * -2;
    lVar1 = (longlong)(int)uVar4 *
            (longlong)
            (int)((*(uint *)(uRam0207728c & 0xfffffffc) >> (uRam0207728c & 3) * 8 |
                  *(uint *)(uRam0207728c & 0xfffffffc) << (uRam0207728c & 3) * -8 + 0x20) + 0x1000);
    *(uint *)(param_1 + 0x78) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    lVar1 = (longlong)(int)uVar4 *
            (longlong)
            (int)(*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                 *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20);
    *(uint *)(param_1 + 0x7c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar6 = uVar4;
  }
  else if (uVar7 == 2) {
    uVar4 = uVar3 * 2;
    lVar1 = (longlong)(int)uVar4 *
            (longlong)
            (int)((*(uint *)(uRam0207728c & 0xfffffffc) >> (uRam0207728c & 3) * 8 |
                  *(uint *)(uRam0207728c & 0xfffffffc) << (uRam0207728c & 3) * -8 + 0x20) + 0x1000);
    *(uint *)(param_1 + 0x7c) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    lVar1 = (longlong)(int)uVar4 *
            (longlong)
            (int)(*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                 *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20);
    *(uint *)(param_1 + 0x78) = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) << 0x14;
    uVar6 = uVar3 * -2;
    uVar3 = uVar4;
  }
  if (*(char *)((*(uint *)(uRam02077290 & 0xfffffffc) >> (uRam02077290 & 3) * 8 |
                *(uint *)(uRam02077290 & 0xfffffffc) << (uRam02077290 & 3) * -8 + 0x20) + 0x57) !=
      '\0') {
    uVar5 = param_1 + 0x80 & 3;
    uVar4 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
    *(uint *)(param_1 + 0x80) = -(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20);
  }
  uVar4 = uRam02077290;
  uVar5 = param_1 + 0x80 & 3;
  uVar7 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
  *(uint *)(param_1 + 0x84) = -(uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20);
  uVar5 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  uVar5 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + 0xc;
  uVar4 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if (((uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) == 6) &&
     (uVar5 = param_1 + 0x218 & 3, uVar4 = *(uint *)(param_1 + 0x218 & 0xfffffffc),
     uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20, uVar5 != 0)) {
    uVar4 = param_1 + 0x78 & 3;
    uVar10 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
    uVar5 = uVar5 + 4;
    uVar7 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20) + 0x800;
    uVar5 = param_1 + 0x7c & 3;
    uVar4 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
    uVar7 = (uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000;
    *(uint *)(param_1 + 0x7c) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + uVar7;
    uVar5 = param_1 + 0x78 & 3;
    uVar4 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
    *(uint *)(param_1 + 0x78) = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) + uVar7;
  }
  uVar5 = param_1 + 0x80 & 3;
  uVar7 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
  uVar4 = param_1 + 0x84 & 3;
  uVar10 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
  func_020d4a20(uVar6,uVar3,uVar7 >> uVar5 * 8 | uVar7 << uVar5 * -8 + 0x20,
                uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20);
  *puRam02077294 = 0;
  uVar3 = param_1 + 0x78 & 3;
  uVar7 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  uVar5 = param_1 + 0x7c & 3;
  uVar10 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
  uVar6 = param_1 + 0x80 & 3;
  uVar8 = *(uint *)(param_1 + 0x80 & 0xfffffffc);
  uVar4 = param_1 + 0x84 & 3;
  uVar9 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
  G3i_FrustumW_(uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20,
                uVar10 >> uVar5 * 8 | uVar10 << uVar5 * -8 + 0x20,
                uVar8 >> uVar6 * 8 | uVar8 << uVar6 * -8 + 0x20,
                uVar9 >> uVar4 * 8 | uVar9 << uVar4 * -8 + 0x20);
  return;
}

