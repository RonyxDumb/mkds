/* Decompiled C draft; module arm9; ROM address 021092b0. No matching claim. */
#include "types.h"
#include "deps/021092b0_func_021092b0.h"

uint func_021092b0(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar3 = 0;
  if (uVar4 == 0) {
    uVar4 = param_1 + 0x20 & 3;
    uVar2 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
    uVar4 = (uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20) + 8;
    uVar2 = uVar4 & 3;
    uVar4 = *(uint *)(uVar4 & 0xfffffffc);
    uVar2 = (uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20) * 0x24 + iRam02109460;
  }
  else if (((uVar4 == 0) || (*(char *)(uVar4 + 0x3c) != '\0')) ||
          (uVar2 = uRam0210945c,
          (uint)*(ushort *)(uVar4 + 0x74) ==
          (int)*(char *)((*(uint *)(uRam02109458 & 0xfffffffc) >> (uRam02109458 & 3) * 8 |
                         *(uint *)(uRam02109458 & 0xfffffffc) << (uRam02109458 & 3) * -8 + 0x20) +
                        0x62))) {
    uVar2 = (uint)*(byte *)(uVar4 + 0x3c) * 0x24 + iRam02109460;
  }
  uVar4 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar7 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  uVar4 = uVar2 + 0xc & 3;
  uVar6 = *(uint *)(uVar2 + 0xc & 0xfffffffc);
  uVar4 = uVar6 >> uVar4 * 8 | uVar6 << uVar4 * -8 + 0x20;
  if ((int)uVar4 < (int)uVar7) {
    uVar6 = uVar2 + 4 & 3;
    uVar5 = *(uint *)(uVar2 + 4 & 0xfffffffc);
    if ((int)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) < (int)uVar7) {
      uVar6 = *(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
              *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20;
      if ((int)uVar7 < (int)uVar6) {
        uVar3 = uVar2 + 0x18 & 3;
        uVar5 = *(uint *)(uVar2 + 0x18 & 0xfffffffc);
        lVar1 = (longlong)(int)(uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20) *
                (longlong)(int)((uVar7 - uVar6) * 0x1000) + 0x800;
        uVar3 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc;
      }
    }
    else {
      uVar3 = uVar2 + 0x14 & 3;
      uVar6 = *(uint *)(uVar2 + 0x14 & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) *
              (longlong)(int)((uVar7 - uVar4) * 0x1000) + 0x800;
      uVar3 = uVar2 + 0x10 & 3;
      uVar6 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
      uVar3 = (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) +
              ((int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc);
    }
  }
  else {
    uVar3 = uVar2 + 0x10 & 3;
    uVar6 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
    uVar3 = uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20;
  }
  uVar6 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar6 = uVar7 >> uVar6 * 8 | uVar7 << uVar6 * -8 + 0x20;
  if ((int)uVar6 < 0x36) {
    if (uVar6 == -uVar4 || (int)(uVar6 + uVar4) < 0 != SBORROW4(uVar6,-uVar4)) {
      lVar1 = (ulonglong)uRam02109464 * (ulonglong)(uVar3 * 0x1000);
      uVar4 = (uint)lVar1;
      uVar3 = (int)(uVar4 + 0x800 >> 0xc |
                   (((int)(uVar3 * 0x1000) >> 0x1f) * uRam02109464 + (int)((ulonglong)lVar1 >> 0x20)
                   + (uint)(0xfffff7ff < uVar4)) * 0x100000) >> 0xc;
    }
    else {
      uVar4 = uVar2 + 0x1c & 3;
      uVar7 = *(uint *)(uVar2 + 0x1c & 0xfffffffc);
      lVar1 = (longlong)(int)(uVar7 >> uVar4 * 8 | uVar7 << uVar4 * -8 + 0x20) *
              (longlong)(int)((uVar6 - 0x36) * 0x1000) + 0x800;
      lVar1 = (longlong)
              (int)(((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) + 0x1000) *
              (longlong)(int)(uVar3 << 0xc) + 0x800;
      uVar3 = (int)((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000) >> 0xc;
    }
  }
  if ((int)uVar3 < 0) {
    return 0;
  }
  uVar4 = uVar2 + 0x10 & 3;
  uVar2 = *(uint *)(uVar2 + 0x10 & 0xfffffffc);
  uVar4 = uVar2 >> uVar4 * 8 | uVar2 << uVar4 * -8 + 0x20;
  if ((int)uVar3 <= (int)uVar4) {
    uVar4 = uVar3;
  }
  return uVar4;
}

