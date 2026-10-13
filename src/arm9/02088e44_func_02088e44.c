/* Decompiled C draft; module arm9; ROM address 02088e44. No matching claim. */
#include "types.h"
#include "deps/02088e44_func_02088e44.h"

void func_02088e44(uint param_1)

{
  bool bVar1;
  byte bVar2;
  longlong lVar3;
  ushort *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  undefined4 uVar11;
  undefined4 *puVar12;
  uint uVar13;
  ushort uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  ushort uVar19;
  ushort uVar20;
  undefined4 uStack_6c;
  uint uStack_68;
  undefined4 uStack_64;
  int iStack_60;
  int iStack_5c;
  int iStack_58;
  undefined4 uStack_54;
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined1 auStack_48 [12];
  undefined1 auStack_3c [12];
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  
  uVar19 = *(ushort *)(param_1 + 4);
  uVar5 = func_02061f90();
  if (uVar19 != uVar5) {
    return;
  }
  uVar5 = (*(uint *)(uRam020892a0 & 0xfffffffc) >> (uRam020892a0 & 3) * 8 |
          *(uint *)(uRam020892a0 & 0xfffffffc) << (uRam020892a0 & 3) * -8 + 0x20) + 0x14;
  uVar15 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  if ((uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20) == 1) {
    return;
  }
  uVar5 = param_1 + 0xb0 & 3;
  uVar15 = *(uint *)(param_1 + 0xb0 & 0xfffffffc);
  uVar5 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
  if (uVar5 != 0) {
    iVar6 = (uint)uVar19 * 0x210 +
            (*(uint *)(uRam020892ac & 0xfffffffc) >> (uRam020892ac & 3) * 8 |
            *(uint *)(uRam020892ac & 0xfffffffc) << (uRam020892ac & 3) * -8 + 0x20);
    uVar15 = iVar6 + 0x58;
    uVar9 = uVar15 & 3;
    uVar15 = *(uint *)(uVar15 & 0xfffffffc);
    if (((((uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) != 0xf) ||
         (uVar15 = iVar6 + 0x30, uVar9 = uVar15 & 3, uVar15 = *(uint *)(uVar15 & 0xfffffffc),
         (uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) != 0x13)) ||
        (uVar15 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                  *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x4c,
        uVar9 = uVar15 & 3, uVar15 = *(uint *)(uVar15 & 0xfffffffc),
        ((uVar15 >> uVar9 * 8 | uVar15 << uVar9 * -8 + 0x20) & 0x40) != 0)) &&
       (iVar6 = GetSomeMQRacerAnotherFlags(*(undefined2 *)(uVar5 + 0x74)), iVar6 != 0)) {
      uVar8 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
              *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
      uVar5 = param_1 + 0xb0 & 3;
      uVar15 = *(uint *)(param_1 + 0xb0 & 0xfffffffc);
      uVar13 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
      uVar5 = uVar8 + 0x88 & 3;
      uVar17 = *(uint *)(uVar8 + 0x88 & 0xfffffffc);
      uVar15 = uVar13 + 0x88 & 3;
      uVar16 = *(uint *)(uVar13 + 0x88 & 0xfffffffc);
      uVar9 = uVar8 + 0x80 & 3;
      uVar18 = *(uint *)(uVar8 + 0x80 & 0xfffffffc);
      iVar6 = (int)((uVar17 >> uVar5 * 8 | uVar17 << uVar5 * -8 + 0x20) -
                   (uVar16 >> uVar15 * 8 | uVar16 << uVar15 * -8 + 0x20)) >> 0xc;
      uVar5 = uVar13 + 0x80 & 3;
      uVar15 = *(uint *)(uVar13 + 0x80 & 0xfffffffc);
      iVar10 = (int)((uVar18 >> uVar9 * 8 | uVar18 << uVar9 * -8 + 0x20) -
                    (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20)) >> 0xc;
      iVar6 = iVar10 * iVar10 + iVar6 * iVar6;
      bVar1 = false;
      if ((iVar6 < iRam020892b0) &&
         (uVar5 = uVar8 + 0x84 & 3, uVar8 = *(uint *)(uVar8 + 0x84 & 0xfffffffc),
         uVar15 = uVar13 + 0x84 & 3, uVar9 = *(uint *)(uVar13 + 0x84 & 0xfffffffc),
         iVar10 = AbsValue((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) -
                           (uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20)), iVar10 < 0x3c000))
      {
        *(int *)(param_1 + 0xb8) = iVar6;
        bVar1 = true;
      }
      if ((bVar1) &&
         (uVar15 = param_1 + 0xb0 & 3, uVar8 = *(uint *)(param_1 + 0xb0 & 0xfffffffc),
         uVar5 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x84,
         uVar9 = uVar5 & 3, uVar13 = *(uint *)(uVar5 & 0xfffffffc),
         uVar5 = (uVar8 >> uVar15 * 8 | uVar8 << uVar15 * -8 + 0x20) + 0x84, uVar15 = uVar5 & 3,
         uVar5 = *(uint *)(uVar5 & 0xfffffffc),
         iVar6 = AbsValue((uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) -
                          (uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20)), iVar6 < 0x3c000)) {
        uVar5 = param_1 + 0xb0 & 3;
        uVar15 = *(uint *)(param_1 + 0xb0 & 0xfffffffc);
        bVar2 = 0;
        VecFx32_Subtract((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) + 0x80,
                         (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                         *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x80,
                         &iStack_60);
        iVar6 = Vector3_DotProduct((uint)(uintptr_t)(&iStack_60),
                                   (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                                   *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) +
                                   0x138);
        if (0 < iVar6) {
          lVar3 = (longlong)iStack_58 * (longlong)iStack_58 +
                  (longlong)iStack_60 * (longlong)iStack_60 +
                  (longlong)iStack_5c * (longlong)iStack_5c;
          if ((int)(uint)((uint)lVar3 < 0x10) <= (int)((ulonglong)lVar3 >> 0x20)) {
            Vector3_MaybeNormalize((uint)(uintptr_t)(&iStack_60),&iStack_60);
          }
          uVar11 = Vector3_DotProduct((uint)(uintptr_t)(&iStack_60),
                                      (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                                      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20)
                                      + 0x138);
          *(undefined4 *)(param_1 + 0xbc) = uVar11;
          bVar2 = 1;
        }
        *(uint *)(param_1 + 0xb4) = (uint)bVar2;
        uVar5 = param_1 + 0xb4 & 3;
        uVar15 = *(uint *)(param_1 + 0xb4 & 0xfffffffc);
        if (uVar15 >> uVar5 * 8 == 0 && uVar15 << uVar5 * -8 + 0x20 == 0) {
          *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
          return;
        }
        iVar6 = (uint)*(ushort *)(param_1 + 4) * 0x210 +
                (*(uint *)(uRam020892ac & 0xfffffffc) >> (uRam020892ac & 3) * 8 |
                *(uint *)(uRam020892ac & 0xfffffffc) << (uRam020892ac & 3) * -8 + 0x20);
        uVar5 = iVar6 + 0x58;
        uVar15 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        bVar1 = true;
        if ((((uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20) == 0xf) &&
            (uVar5 = iVar6 + 0x30, uVar15 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
            (uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20) == 0x13)) &&
           (iVar6 = GetDriverEntry(), uVar5 = iVar6 + 0x4cU & 3,
           uVar15 = *(uint *)(iVar6 + 0x4cU & 0xfffffffc),
           ((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) & 0x40) == 0)) {
          bVar1 = false;
        }
        uVar5 = param_1 + 0xb0 & 3;
        uVar15 = *(uint *)(param_1 + 0xb0 & 0xfffffffc);
        uVar9 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
        uVar5 = uVar9 + 0x4c & 3;
        uVar15 = *(uint *)(uVar9 + 0x4c & 0xfffffffc);
        if (((bVar1) && (((uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) & 0x40) == 0)) &&
           (uVar5 = param_1 + 0xbc & 3, uVar15 = *(uint *)(param_1 + 0xbc & 0xfffffffc),
           iRam020892b4 < (int)(uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20))) {
          uStack_6c = *(undefined4 *)(uVar9 + 0x80);
          uStack_64 = *(undefined4 *)(uVar9 + 0x88);
          uVar5 = param_1 + 0x48 & 3;
          uVar15 = *(uint *)(param_1 + 0x48 & 0xfffffffc);
          uStack_68 = uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20;
          uVar5 = param_1 + 0x28 & 3;
          uVar15 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
          uVar5 = (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) + 0x20;
          uVar15 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          puVar12 = (undefined4 *)(uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20);
          uStack_54 = *puVar12;
          uStack_50 = puVar12[1];
          uStack_4c = puVar12[2];
          uStack_30 = *puRam020892b8;
          uStack_2c = puRam020892b8[1];
          uStack_28 = puRam020892b8[2];
          VecFx32_CrossProduct(param_1 + 0x30,(uint)(uintptr_t)(&uStack_30),(uint *)(void *)(auStack_48));
          VecFx32_Subtract((uint)(uintptr_t)(&uStack_6c),(uint)(uintptr_t)(&uStack_54),(int *)(void *)(auStack_3c));
          VecFx32_CrossProduct_0((uint)(uintptr_t)(auStack_3c),(uint)(uintptr_t)(auStack_48));
          uVar5 = param_1 + 0x28 & 3;
          uVar15 = *(uint *)(param_1 + 0x28 & 0xfffffffc);
          uVar5 = (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20) + 0x24;
          uVar15 = uVar5 & 3;
          uVar5 = *(uint *)(uVar5 & 0xfffffffc);
          iVar6 = AbsValue();
          if ((int)(uVar5 >> uVar15 * 8 | uVar5 << uVar15 * -8 + 0x20) <= iVar6) {
            *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
            return;
          }
          *(undefined4 *)(param_1 + 0x50) = uStack_6c;
          *(uint *)(param_1 + 0x54) = uStack_68;
          *(undefined4 *)(param_1 + 0x58) = uStack_64;
          *(undefined4 **)(param_1 + 0x5c) = (undefined4 *)(param_1 + 0x50);
          return;
        }
        *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
        return;
      }
    }
    *(undefined4 *)(param_1 + 0xb0) = 0;
    *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
    return;
  }
  *(uint *)(param_1 + 0x5c) = param_1 + 0x44;
  uVar20 = 0;
  uVar19 = *puRam020892a4;
  if (*(char *)((*(uint *)(uRam020892a0 & 0xfffffffc) >> (uRam020892a0 & 3) * 8 |
                *(uint *)(uRam020892a0 & 0xfffffffc) << (uRam020892a0 & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      iVar6 = func_0207f554(*(undefined2 *)(param_1 + 4),uVar19);
      if (iVar6 != 0) {
        iVar7 = GetDriverEntry(uVar19);
        uVar13 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                 *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
        uVar5 = iVar7 + 0x88U & 3;
        uVar16 = *(uint *)(iVar7 + 0x88U & 0xfffffffc);
        uVar15 = uVar13 + 0x88 & 3;
        uVar17 = *(uint *)(uVar13 + 0x88 & 0xfffffffc);
        uVar9 = uVar13 + 0x80 & 3;
        uVar8 = *(uint *)(uVar13 + 0x80 & 0xfffffffc);
        iVar6 = (int)((uVar17 >> uVar15 * 8 | uVar17 << uVar15 * -8 + 0x20) -
                     (uVar16 >> uVar5 * 8 | uVar16 << uVar5 * -8 + 0x20)) >> 0xc;
        uVar5 = iVar7 + 0x80U & 3;
        uVar15 = *(uint *)(iVar7 + 0x80U & 0xfffffffc);
        iVar10 = (int)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) -
                      (uVar15 >> uVar5 * 8 | uVar15 << uVar5 * -8 + 0x20)) >> 0xc;
        iVar6 = iVar10 * iVar10 + iVar6 * iVar6;
        bVar1 = false;
        if (iVar6 < iRam020892a8) {
          uVar5 = uVar13 + 0x84 & 3;
          uVar8 = *(uint *)(uVar13 + 0x84 & 0xfffffffc);
          uVar15 = iVar7 + 0x84U & 3;
          uVar9 = *(uint *)(iVar7 + 0x84U & 0xfffffffc);
          iVar10 = AbsValue((uVar8 >> uVar5 * 8 | uVar8 << uVar5 * -8 + 0x20) -
                            (uVar9 >> uVar15 * 8 | uVar9 << uVar15 * -8 + 0x20));
          bVar1 = iVar10 < 0x3c000;
          if (bVar1) {
            *(int *)(param_1 + 0xb8) = iVar6;
          }
        }
        puVar4 = puRam020892a4;
        if (bVar1) {
          bVar2 = *(byte *)((*(uint *)(uRam020892a0 & 0xfffffffc) >> (uRam020892a0 & 3) * 8 |
                            *(uint *)(uRam020892a0 & 0xfffffffc) << (uRam020892a0 & 3) * -8 + 0x20)
                           + 0x3d0);
          *puRam020892a4 = *puRam020892a4 + 1;
          if ((ushort)bVar2 <= *puVar4) {
            *puVar4 = 0;
          }
          goto LAB_02088fb0;
        }
      }
      uVar19 = uVar19 + 1;
      uVar14 = (ushort)*(byte *)((*(uint *)(uRam020892a0 & 0xfffffffc) >> (uRam020892a0 & 3) * 8 |
                                 *(uint *)(uRam020892a0 & 0xfffffffc) <<
                                 (uRam020892a0 & 3) * -8 + 0x20) + 0x3d0);
      uVar20 = uVar20 + 1;
      if (uVar14 <= uVar19) {
        uVar19 = 0;
      }
    } while (uVar20 < uVar14);
  }
  iVar7 = 0;
LAB_02088fb0:
  *(int *)(param_1 + 0xb0) = iVar7;
  return;
}

