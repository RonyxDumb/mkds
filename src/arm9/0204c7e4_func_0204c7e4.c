/* Decompiled C draft; module arm9; ROM address 0204c7e4. No matching claim. */
#include "types.h"
#include "deps/0204c7e4_func_0204c7e4.h"

void func_0204c7e4(uint param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 *puVar13;
  int iVar14;
  uint uVar3;
  
  uVar1 = func_02006fdc(*(undefined2 *)(param_1 + 10));
  iVar14 = iRam0204cc90;
  iVar10 = iRam0204cc7c;
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != 0xc) {
    return;
  }
  uVar3 = param_1 + 4 & 3;
  uVar2 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  if ((int)uVar3 < 3) {
    return;
  }
  if (0xd < (int)uVar3) {
    return;
  }
  if ((int)uVar3 < 8) {
    return;
  }
  if (uVar3 == 8) {
    return;
  }
  if (uVar3 == 10) {
    puVar13 = (undefined4 *)(iRam0204cc7c + uVar1 * 0xc);
    uVar5 = *(undefined4 *)(param_1 + 0x18);
    uVar7 = *(undefined4 *)(param_1 + 0x1c);
    *puVar13 = *(undefined4 *)(param_1 + 0x14);
    puVar13[1] = uVar5;
    puVar13[2] = uVar7;
    uVar3 = param_1 + 0x14 & 3;
    uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
    uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
    if ((uVar3 & 0xf) != 0) {
      if ((uVar3 & 0xf) != 2) {
        return;
      }
      uVar5 = Os_DisableIrq();
      uVar3 = iVar10 + 0x46ccU & 3;
      uVar2 = *(uint *)(iVar10 + 0x46ccU & 0xfffffffc);
      *(uint *)(iVar10 + 0x46cc) =
           uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 1 << (uVar1 & 0xff);
      uVar1 = iVar10 + 0x46c4U & 3;
      uVar3 = *(uint *)(iVar10 + 0x46c4U & 0xfffffffc);
      uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
      uVar1 = param_1 + 0x18 & 3;
      uVar2 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
      while ((uVar3 != 0 &&
             ((uVar11 = uVar3 + 0x80 & 3, uVar4 = *(uint *)(uVar3 + 0x80 & 0xfffffffc),
              (uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) != 2 ||
              (uVar11 = uVar3 + 4 & 3, uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc),
              (uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) !=
              (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)))))) {
        uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      }
      if ((uVar3 != 0) &&
         (uVar1 = uVar3 + 0x84 & 3, uVar2 = *(uint *)(uVar3 + 0x84 & 0xfffffffc),
         *(uint *)(uVar3 + 0x84) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) - 1,
         uVar1 = uVar3 + 0x84 & 3, uVar2 = *(uint *)(uVar3 + 0x84 & 0xfffffffc),
         (int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 1)) {
        *(undefined4 *)(uVar3 + 0x88) = 0;
        uVar1 = param_1 + 0x18 & 3;
        uVar2 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
        func_02006df8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
        func_0204d110((uint *)(uintptr_t)(iVar10 + iRam0204cc8c),(undefined4 *)(uintptr_t)(iVar10 + iRam0204cc88),(uint *)(uintptr_t)(uVar3));
        *(undefined4 *)(uVar3 + 0x80) = 3;
        func_0204bca0();
      }
      Os_RestoreIrq(uVar5);
      return;
    }
    uVar11 = iVar10 + 0x46e0U & 3;
    uVar9 = *(uint *)(iVar10 + 0x46e0U & 0xfffffffc);
    uVar2 = uVar3 >> 8;
    uVar4 = param_1 + 0x18 & 3;
    uVar12 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
    uVar4 = uVar12 >> uVar4 * 8 | uVar12 << uVar4 * -8 + 0x20;
    if ((uVar9 >> uVar11 * 8 == 0 && uVar9 << uVar11 * -8 + 0x20 == 0) &&
       (uVar11 = iRam0204cc80 + 0x28U & 3, uVar9 = *(uint *)(iRam0204cc80 + 0x28U & 0xfffffffc),
       ((uint)*(byte *)(param_1 + 0x1c) | ((uVar3 << 0x18) >> 0x1c) << 8) ==
       (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20))) {
      uVar3 = iVar10 + 0x46c4U & 3;
      uVar11 = *(uint *)(iVar10 + 0x46c4U & 0xfffffffc);
      uVar3 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
      while ((uVar3 != 0 &&
             (((uVar11 = uVar3 + 0x80 & 3, uVar9 = *(uint *)(uVar3 + 0x80 & 0xfffffffc),
               (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) != 2 ||
               (uVar11 = uVar3 + 0x5c & 3, uVar9 = *(uint *)(uVar3 + 0x5c & 0xfffffffc),
               uVar4 != (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20))) ||
              (uVar11 = uVar3 + 0x60 & 3, uVar8 = *(uint *)(uVar3 + 0x60 & 0xfffffffc),
              uVar9 = uVar3 + 0x5c & 3, uVar12 = *(uint *)(uVar3 + 0x5c & 0xfffffffc),
              uVar2 != (uVar8 >> uVar11 * 8 | uVar8 << uVar11 * -8 + 0x20) -
                       (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20)))))) {
        uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
      }
      if (uVar3 == 0) {
        uVar3 = iVar10 + 0x46c8U & 3;
        uVar11 = *(uint *)(iVar10 + 0x46c8U & 0xfffffffc);
        uVar3 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
        while ((uVar3 != 0 &&
               (((uVar11 = uVar3 + 0x80 & 3, uVar9 = *(uint *)(uVar3 + 0x80 & 0xfffffffc),
                 (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) != 1 ||
                 (uVar11 = uVar3 + 0x90 & 3, uVar9 = *(uint *)(uVar3 + 0x90 & 0xfffffffc),
                 (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) != uVar4)) ||
                (uVar11 = uVar3 + 0x94 & 3, uVar9 = *(uint *)(uVar3 + 0x94 & 0xfffffffc),
                (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) != uVar2))))) {
          uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                  *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
        }
        if (uVar3 == 0) {
          uVar3 = iVar10 + 0x46c0U & 3;
          uVar11 = *(uint *)(iVar10 + 0x46c0U & 0xfffffffc);
          uVar3 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
          func_0204d110((uint *)(uintptr_t)(iVar10 + iRam0204cc84),(undefined4 *)(uintptr_t)(iVar10 + iRam0204cc88),(uint *)(uintptr_t)(uVar3));
          *(undefined4 *)(uVar3 + 0x80) = 1;
          uVar11 = iVar10 + 0x46e4U & 3;
          uVar9 = *(uint *)(iVar10 + 0x46e4U & 0xfffffffc);
          *(uint *)(iVar10 + 0x46e4) = (uVar9 >> uVar11 * 8 | uVar9 << uVar11 * -8 + 0x20) + 1;
          *(undefined4 *)(uVar3 + 0x84) = 0;
          *(uint *)(uVar3 + 0x90) = uVar4;
          *(uint *)(uVar3 + 0x94) = uVar2;
          func_0204bca0();
        }
        uVar2 = uVar3 + 0x88 & 3;
        uVar11 = *(uint *)(uVar3 + 0x88 & 0xfffffffc);
        *(uint *)(uVar3 + 0x88) =
             uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20 | 1 << (uVar1 & 0xff);
      }
      else {
        uVar2 = iVar10 + 0x46ccU & 3;
        uVar11 = *(uint *)(iVar10 + 0x46ccU & 0xfffffffc);
        *(uint *)(iVar10 + 0x46cc) =
             uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20 | 1 << (uVar1 & 0xff);
        uVar2 = uVar3 + 0x8c & 3;
        uVar11 = *(uint *)(uVar3 + 0x8c & 0xfffffffc);
        *(uint *)(iVar10 + uVar1 * 0xc + 4) = uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20;
        uVar2 = uVar3 + 0x84 & 3;
        uVar11 = *(uint *)(uVar3 + 0x84 & 0xfffffffc);
        *(uint *)(uVar3 + 0x84) = (uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20) + 1;
      }
      uVar3 = iVar10 + 0x46dcU & 3;
      uVar2 = *(uint *)(iVar10 + 0x46dcU & 0xfffffffc);
      *(uint *)(iVar10 + 0x46dc) =
           uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 1 << (uVar1 & 0xff);
      return;
    }
    *(undefined4 *)(iVar10 + 0x46e0) = 1;
    uVar3 = iVar10 + 0x46e8U & 3;
    uVar2 = *(uint *)(iVar10 + 0x46e8U & 0xfffffffc);
    *(uint *)(iVar10 + 0x46e8) =
         uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 1 << (uVar1 & 0xff);
    uVar3 = iVar10 + 0x46dcU & 3;
    uVar2 = *(uint *)(iVar10 + 0x46dcU & 0xfffffffc);
    *(uint *)(iVar10 + 0x46dc) =
         uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20 | 1 << (uVar1 & 0xff);
    return;
  }
  if (uVar3 != 0xd) {
    return;
  }
  uVar1 = param_1 + 0x14 & 3;
  uVar2 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  *(undefined4 *)(param_1 + 0x1c) = 0;
  uVar3 = iVar14 + 0xb04U & 3;
  uVar11 = *(uint *)(iVar14 + 0xb04U & 0xfffffffc);
  uVar3 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
  while ((uVar3 != 0 &&
         ((uVar11 = uVar3 + 0x80 & 3, uVar4 = *(uint *)(uVar3 + 0x80 & 0xfffffffc),
          (uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) != 2 ||
          (uVar11 = uVar3 + 4 & 3, uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc),
          (uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) !=
          (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20)))))) {
    uVar3 = *(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
            *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20;
  }
  if (uVar3 == 0) {
    return;
  }
  uVar1 = uVar3 + 0x9c & 3;
  uVar11 = *(uint *)(uVar3 + 0x9c & 0xfffffffc);
  iVar10 = (int)*(short *)(param_1 + 0x20);
  uVar2 = uVar3 + 0x98 & 3;
  uVar4 = *(uint *)(uVar3 + 0x98 & 0xfffffffc);
  uVar9 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  uVar2 = param_1 + 0x18 & 3;
  uVar4 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar2 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
  if (((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) != 2) &&
     (uVar1 = uVar3 + 0x44 & 3, uVar11 = *(uint *)(uVar3 + 0x44 & 0xfffffffc),
     ((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) & 1) == 0)) {
    *(undefined4 *)(uVar3 + 0x9c) = 2;
  }
  *(uint *)(uVar3 + 0x98) = uVar2;
  uVar1 = uVar3 + 0x9c & 3;
  uVar4 = *(uint *)(uVar3 + 0x9c & 0xfffffffc);
  uVar11 = 0;
  do {
    if (((uVar11 != (uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20)) &&
        (uVar12 = uVar3 + uVar11 * 4 + 0xa4, uVar8 = uVar12 & 3,
        uVar12 = *(uint *)(uVar12 & 0xfffffffc),
        iVar14 = iVar10 * uVar9 - (uVar12 >> uVar8 * 8 | uVar12 << uVar8 * -8 + 0x20), -1 < iVar14))
       && (iVar14 + iVar10 < 0x401)) {
      *(uint *)(param_1 + 0x18) = uVar9;
      *(uint *)(param_1 + 0x1c) = uVar3 + 0xc0 + uVar11 * 0x400 + iVar14;
      break;
    }
    uVar11 = uVar11 + 1;
  } while ((int)uVar11 < 2);
  uVar1 = uVar3 + 0x9c & 3;
  uVar4 = *(uint *)(uVar3 + 0x9c & 0xfffffffc);
  if ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) != 2) {
    return;
  }
  uVar2 = iVar10 * uVar2;
  iVar14 = 0;
  do {
    uVar1 = uVar3 + iVar14 * 4 + 0xa4;
    uVar4 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    iVar6 = uVar2 - (uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20);
    if ((-1 < iVar6) && (iVar6 + iVar10 < 0x401)) break;
    iVar14 = iVar14 + 1;
  } while (iVar14 < 2);
  if (1 < iVar14) {
    uVar1 = uVar3 + 0xa0 & 3;
    uVar4 = *(uint *)(uVar3 + 0xa0 & 0xfffffffc);
    uVar1 = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20;
    do {
      uVar1 = uVar1 + 1;
      if (1 < (int)uVar1) {
        uVar1 = 0;
      }
    } while (uVar1 == uVar11);
    *(uint *)(uVar3 + 0xa0) = uVar1;
    *(uint *)(uVar3 + 0x9c) = uVar1;
    uVar2 = uVar2 & 0xfffffe00;
    *(uint *)(uVar3 + uVar1 * 4 + 0xa4) = uVar2;
    Fs_File_Seek(uVar3 + 0x38,uVar2,0);
    Fs_File_ReadAsync(uVar3 + 0x38,uVar3 + 0xc0 + uVar1 * 0x400,0x400);
    return;
  }
  return;
}

