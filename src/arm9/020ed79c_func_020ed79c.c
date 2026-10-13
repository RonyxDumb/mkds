/* Decompiled C draft; module arm9; ROM address 020ed79c. No matching claim. */
#include "types.h"
#include "deps/020ed79c_func_020ed79c.h"

void func_020ed79c(uint param_1,undefined4 *param_2)

{
  ushort uVar1;
  longlong lVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar13;
  uint uVar15;
  undefined4 *puVar16;
  undefined1 auStack_30 [12];
  uint uVar12;
  uint uVar14;
  
  uVar13 = iRam020ed984 +
           (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) * 4;
  uVar11 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  uVar14 = uVar13 >> uVar11 * 8 | uVar13 << uVar11 * -8 + 0x20;
  uVar13 = param_1 + 0x10 & 3;
  uVar11 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  uVar12 = uVar11 >> uVar13 * 8 | uVar11 << uVar13 * -8 + 0x20;
  uVar13 = param_1 + 0x14 & 3;
  uVar10 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  func_020e6a18(uVar14);
  uVar11 = uVar14 + 0x14 & 3;
  uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
  *(uint *)(uVar14 + 0x14) = (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) & 0xc0ffffff;
  uVar11 = uVar14 + 0x14 & 3;
  uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
  uVar15 = 0;
  puVar16 = (undefined4 *)auStack_30;
  if ((int)uVar12 < 1) {
    puVar16 = (undefined4 *)&stack0xffffffdc;
  }
  *(uint *)(uVar14 + 0x14) = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20 | 0x4000000;
  if (0 < (int)uVar12) {
    puVar16[1] = 0;
    do {
      uVar11 = param_1 + 4 & 3;
      uVar3 = *(uint *)(param_1 + 4 & 0xfffffffc);
      uVar11 = (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) + uVar15 * 4;
      uVar3 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar9 = uVar11 >> uVar3 * 8 | uVar11 << uVar3 * -8 + 0x20;
      uVar11 = uVar9 + 0x74 & 3;
      uVar3 = *(uint *)(uVar9 + 0x74 & 0xfffffffc);
      uVar11 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
      if ((uVar11 & 0x10000) == 0) {
        if ((uVar11 & 0x1000) == 0) {
          LightInfo_MaybeApply((ushort *)(uintptr_t)(uVar9 + 0x7c));
        }
        else {
          uVar11 = uVar9 + 0x90 & 3;
          uVar3 = *(uint *)(uVar9 + 0x90 & 0xfffffffc);
          LightInfo_MaybeApply((ushort *)(uintptr_t)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20));
        }
        uVar1 = *(ushort *)(uVar9 + 0xd8);
        if (uVar1 != 0x1f) {
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) =
               (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) & 0xffe0ffff;
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) =
               uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20 | (uint)uVar1 << 0x10;
        }
        if (uVar15 == (uVar10 >> uVar13 * 8 | uVar10 << uVar13 * -8 + 0x20)) {
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) =
               (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) & 0xc0ffffff;
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20 | 0x3000000;
        }
        uVar11 = uVar9 + 0xf4 & 3;
        uVar3 = *(uint *)(uVar9 + 0xf4 & 0xfffffffc);
        if (((int)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) < iRam020ed988) ||
           (uVar11 = uVar9 + 0x74 & 3, uVar3 = *(uint *)(uVar9 + 0x74 & 0xfffffffc),
           ((uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) & 0x80) != 0)) {
          uVar5 = param_2[1];
          uVar8 = param_2[2];
          *(undefined4 *)(uVar9 + 0xac) = *param_2;
          *(undefined4 *)(uVar9 + 0xb0) = uVar5;
          *(undefined4 *)(uVar9 + 0xb4) = uVar8;
          Vector3_Cross(uVar9 + 0xf0,(uint)(uintptr_t)((undefined4 *)(uVar9 + 0xac)),(uint *)(uintptr_t)(uVar9 + 0x94));
          uVar11 = uVar9 + 0x98 & 3;
          uVar3 = *(uint *)(uVar9 + 0x98 & 0xfffffffc);
          uVar6 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
          uVar11 = uVar9 + 0x94 & 3;
          uVar3 = *(uint *)(uVar9 + 0x94 & 0xfffffffc);
          uVar3 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
          uVar11 = uVar9 + 0x9c & 3;
          uVar4 = *(uint *)(uVar9 + 0x9c & 0xfffffffc);
          uVar11 = uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20;
          lVar2 = (longlong)(int)uVar11 * (longlong)(int)uVar11 +
                  (longlong)(int)uVar3 * (longlong)(int)uVar3 +
                  (longlong)(int)uVar6 * (longlong)(int)uVar6;
          if ((int)(uint)((uint)lVar2 < 0x10) <= (int)((ulonglong)lVar2 >> 0x20)) {
            Vector3_MaybeNormalize(uVar9 + 0x94,(int *)(uintptr_t)(uVar9 + 0x94));
          }
          Vector3_Cross(uVar9 + 0xac,uVar9 + 0x94,(uint *)(uintptr_t)(uVar9 + 0xa0));
          uVar11 = uVar9 + 0xd0 & 3;
          uVar3 = *(uint *)(uVar9 + 0xd0 & 0xfffffffc);
          uVar3 = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20;
          iVar7 = uVar9 + 0x94;
          *(int *)(uVar9 + 0xb8) =
               (int)(*(uint *)(uVar3 & 0xfffffffc) >> (uVar3 & 3) * 8 |
                    *(uint *)(uVar3 & 0xfffffffc) << (uVar3 & 3) * -8 + 0x20) >> 4;
          uVar11 = uVar3 + 4 & 3;
          uVar4 = *(uint *)(uVar3 + 4 & 0xfffffffc);
          *(int *)(uVar9 + 0xbc) = (int)(uVar4 >> uVar11 * 8 | uVar4 << uVar11 * -8 + 0x20) >> 4;
          uVar11 = uVar3 + 8 & 3;
          uVar3 = *(uint *)(uVar3 + 8 & 0xfffffffc);
          *(int *)(uVar9 + 0xc0) = (int)(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) >> 4;
        }
        else {
          uVar11 = uVar9 + 0xd0 & 3;
          uVar3 = *(uint *)(uVar9 + 0xd0 & 0xfffffffc);
          iVar7 = func_020e6b94(uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20);
        }
        *puVar16 = 0x1f;
        func_020e67c4(uVar14,iVar7,uVar9 + 0x68,puVar16[1]);
        if (*(short *)(uVar9 + 0xd8) != 0x1f) {
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) =
               (uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20) & 0xffe0ffff;
          uVar11 = uVar14 + 0x14 & 3;
          uVar3 = *(uint *)(uVar14 + 0x14 & 0xfffffffc);
          *(uint *)(uVar14 + 0x14) = uVar3 >> uVar11 * 8 | uVar3 << uVar11 * -8 + 0x20 | 0x1f0000;
        }
      }
      uVar15 = uVar15 + 1;
    } while ((int)uVar15 < (int)uVar12);
    return;
  }
  return;
}

