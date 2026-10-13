/* Decompiled C draft; module arm9; ROM address 020ee748. No matching claim. */
#include "types.h"
#include "deps/020ee748_func_020ee748.h"

void func_020ee748(uint param_1)

{
  longlong lVar1;
  undefined4 uVar2;
  short sVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  int iVar14;
  uint uVar12;
  
  uVar13 = param_1 + 0x68 & 3;
  uVar5 = *(uint *)(param_1 + 0x68 & 0xfffffffc);
  uVar12 = param_1 + 0x10 & 3;
  uVar6 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar13 = (uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20) * 0x1e0;
  uVar12 = (uVar6 >> uVar12 * 8 | uVar6 << uVar12 * -8 + 0x20) + 0x180;
  uVar5 = uVar12 & 3;
  uVar6 = *(uint *)(uVar12 & 0xfffffffc);
  sVar3 = (short)(uVar13 >> 0x10);
  uVar12 = param_1 + 0xc & 3;
  uVar10 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar10 = uVar10 >> uVar12 * 8 | uVar10 << uVar12 * -8 + 0x20;
  uVar12 = param_1 + 0x20 & 3;
  uVar11 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar12 = uVar11 >> uVar12 * 8 | uVar11 << uVar12 * -8 + 0x20;
  if (uVar6 >> uVar5 * 8 == 0 && uVar6 << uVar5 * -8 + 0x20 == 0) {
    if (*(ushort *)(param_1 + 0x176) < uRam020ee994) {
      *(ushort *)(param_1 + 0x176) = *(ushort *)(param_1 + 0x176) + 0x46;
    }
    if (299 < uVar13 >> 0x10) {
      sVar3 = 300;
    }
    *(short *)(param_1 + 0x174) = *(short *)(param_1 + 0x174) + *(short *)(param_1 + 0x176);
    *(short *)(param_1 + 0x174) = *(short *)(param_1 + 0x174) + sVar3;
  }
  else {
    *(undefined2 *)(param_1 + 0x176) = 0;
  }
  uVar13 = param_1 + 0x7c & 3;
  uVar5 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
  uVar5 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020ee998 * (ulonglong)uVar5;
  uVar13 = param_1 + 0x17c & 3;
  uVar6 = *(uint *)(param_1 + 0x17c & 0xfffffffc);
  *(uint *)(param_1 + 0x17c) =
       (uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
       ((uint)lVar1 >> 0xc |
       (((int)uVar5 >> 0x1f) * uRam020ee998 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  uVar13 = param_1 + 0x17c & 3;
  uVar5 = *(uint *)(param_1 + 0x17c & 0xfffffffc);
  uVar13 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
  *(uint *)(param_1 + 0x17c) =
       uVar13 - ((uint)((ulonglong)uRam020ee99c * (ulonglong)uVar13) >> 0xc |
                (((int)uVar13 >> 0x1f) * uRam020ee99c +
                (int)((ulonglong)uRam020ee99c * (ulonglong)uVar13 >> 0x20)) * 0x100000);
  uVar13 = param_1 + 0x8c & 3;
  uVar5 = *(uint *)(param_1 + 0x8c & 0xfffffffc);
  uVar11 = uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020ee9a0 * (ulonglong)uVar11;
  uVar13 = param_1 + 0x17c & 3;
  uVar9 = *(uint *)(param_1 + 0x17c & 0xfffffffc);
  uVar5 = param_1 + 0x7c & 3;
  uVar6 = *(uint *)(param_1 + 0x7c & 0xfffffffc);
  VecFx32_AddScale1(((uVar9 >> uVar13 * 8 | uVar9 << uVar13 * -8 + 0x20) -
                    (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20)) +
                    ((uint)lVar1 >> 0xc |
                    (((int)uVar11 >> 0x1f) * uRam020ee9a0 + (int)((ulonglong)lVar1 >> 0x20)) *
                    0x100000),param_1 + 0x38,param_1 + 0x50,param_1 + 0x180);
  uVar13 = param_1 + 0x8c & 3;
  uVar5 = *(uint *)(param_1 + 0x8c & 0xfffffffc);
  iVar14 = 0;
  lVar1 = (ulonglong)(uVar5 >> uVar13 * 8 | uVar5 << uVar13 * -8 + 0x20) * 0x3000;
  uVar13 = param_1 + 0x78 & 3;
  uVar6 = *(uint *)(param_1 + 0x78 & 0xfffffffc);
  uVar5 = param_1 + 0x178 & 3;
  uVar11 = *(uint *)(param_1 + 0x178 & 0xfffffffc);
  uVar5 = uVar11 >> uVar5 * 8 | uVar11 << uVar5 * -8 + 0x20;
  uVar13 = ((uVar6 >> uVar13 * 8 | uVar6 << uVar13 * -8 + 0x20) +
           ((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000)) - uVar5;
  lVar1 = (ulonglong)uRam020ee99c * (ulonglong)uVar13;
  *(uint *)(param_1 + 0x178) =
       uVar5 + ((uint)lVar1 >> 0xc |
               (((int)uVar13 >> 0x1f) * uRam020ee99c + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000);
  func_020eea6c(param_1);
  uVar2 = uRam020ee9a8;
  uVar13 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 0xa8 +
           (*(uint *)(uRam020ee9a4 & 0xfffffffc) >> (uRam020ee9a4 & 3) * 8 |
           *(uint *)(uRam020ee9a4 & 0xfffffffc) << (uRam020ee9a4 & 3) * -8 + 0x20) + 0x70;
  uVar5 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  if (0 < (int)uVar12) {
    do {
      uVar6 = param_1 + iVar14 * 4 + 0x14;
      uVar11 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      uVar6 = uVar6 >> uVar11 * 8 | uVar6 << uVar11 * -8 + 0x20;
      iVar4 = func_020fa0b8(uVar6,uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20,uVar2);
      if (iVar4 != 0) {
        uVar11 = param_1 + 0x84 & 3;
        uVar7 = *(uint *)(param_1 + 0x84 & 0xfffffffc);
        uVar9 = param_1 + 0x88 & 3;
        uVar8 = *(uint *)(param_1 + 0x88 & 0xfffffffc);
        func_020f9f08(uVar6,uVar7 >> uVar11 * 8 | uVar7 << uVar11 * -8 + 0x20,
                      uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20);
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < (int)uVar12);
  }
  if ((uint)*(ushort *)(param_1 + 0x28) ==
      (int)*(char *)((*(uint *)(uRam020ee9ac & 0xfffffffc) >> (uRam020ee9ac & 3) * 8 |
                     *(uint *)(uRam020ee9ac & 0xfffffffc) << (uRam020ee9ac & 3) * -8 + 0x20) + 0x62)
     ) {
    uVar13 = uVar10 + 0x1fc;
    uVar5 = uVar13 & 3;
    uVar13 = *(uint *)(uVar13 & 0xfffffffc);
    func_020719a8(uVar13 >> uVar5 * 8 | uVar13 << uVar5 * -8 + 0x20,uVar12 + 0xe0);
  }
  if ((*(ushort *)(uVar10 + 0x1ec) & 0x244) != 0x244) {
    return;
  }
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) == 0xf) {
    return;
  }
  uVar13 = param_1 + 0x24 & 3;
  uVar12 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  if (uVar12 >> uVar13 * 8 != 0 || uVar12 << uVar13 * -8 + 0x20 != 0) {
    return;
  }
  func_020efa60(param_1,1);
  return;
}

