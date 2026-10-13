/* Decompiled C draft; module arm9; ROM address 02086a04. No matching claim. */
#include "types.h"
#include "deps/02086a04_func_02086a04.h"

void func_02086a04(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  ushort uVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  bool bVar15;
  bool bVar16;
  int local_3c;
  int local_38;
  int local_34;
  undefined1 auStack_30 [12];
  
  iVar2 = func_020d50e0();
  uVar1 = uRam02086e80;
  iVar14 = 0;
  if (*(char *)((*(uint *)(uRam02086e7c & 0xfffffffc) >> (uRam02086e7c & 3) * 8 |
                *(uint *)(uRam02086e7c & 0xfffffffc) << (uRam02086e7c & 3) * -8 + 0x20) + 0x3d0) !=
      '\0') {
    do {
      GetDriverEntry(iVar14);
      *(undefined4 *)
       ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar14 * 4 + 0xe4) = 0;
      iVar3 = GetDriverEntry(iVar14);
      uVar9 = iVar3 + 0x1d0U & 3;
      uVar8 = *(uint *)(iVar3 + 0x1d0U & 0xfffffffc);
      iVar12 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) * 3;
      uVar9 = iVar3 + 0x508U & 3;
      uVar4 = *(uint *)(iVar3 + 0x508U & 0xfffffffc);
      uVar8 = iVar3 + 0x590U & 3;
      uVar13 = *(uint *)(iVar3 + 0x590U & 0xfffffffc);
      uVar13 = uVar13 >> uVar8 * 8 | uVar13 << uVar8 * -8 + 0x20;
      VecFx32_Subtract(uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20,iVar2 + 8,(int *)(void *)(auStack_30));
      iVar5 = Vector3_DotProduct((uint)(uintptr_t)(auStack_30),iVar2 + 0x14);
      *(int *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
               *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar14 * 4 + 0x104) =
           iVar5 + iVar12;
      iVar10 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
               *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
               (uint)*(ushort *)(iVar3 + 0x74) * 2;
      *(short *)(iVar10 + 0x74) = *(short *)(iVar10 + 0x24) + *(short *)(iVar10 + 0x34);
      uVar9 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      *(int *)(uVar9 + (uint)*(ushort *)(uVar9 + (uint)*(ushort *)(iVar3 + 0x74) * 2 + 0x74) * 4 +
              0x54) = iVar5;
      uVar9 = iVar3 + 0x508U & 3;
      uVar8 = *(uint *)(iVar3 + 0x508U & 0xfffffffc);
      VecFx32_Subtract(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20,iVar2 + 8,&local_3c);
      local_3c = local_3c >> 0xc;
      local_38 = local_38 >> 0xc;
      local_34 = local_34 >> 0xc;
      uVar8 = local_34 * local_34 + local_3c * local_3c + local_38 * local_38;
      *(uint *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar14 * 4 + 0x124) =
           uVar8;
      uVar9 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
      iVar10 = uVar9 + (uint)*(ushort *)(iVar3 + 0x74) * 2;
      *(uint *)(uVar9 + ((uint)(((int)*(short *)(iVar10 + 0x24) + (int)*(short *)(iVar10 + 0x84)) *
                               0x10000) >> 0xe) + 0xa4) = uVar8;
      if ((uint)*(ushort *)(iVar3 + 0x74) !=
          (int)*(char *)((*(uint *)(uRam02086e7c & 0xfffffffc) >> (uRam02086e7c & 3) * 8 |
                         *(uint *)(uRam02086e7c & 0xfffffffc) << (uRam02086e7c & 3) * -8 + 0x20) +
                        0x62)) {
        uVar9 = iRam02086e84 + 0x20U & 3;
        uVar4 = *(uint *)(iRam02086e84 + 0x20U & 0xfffffffc);
        bVar16 = uVar8 <= (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20);
        bVar15 = (*(ushort *)(iVar3 + 0x34) & 1) != 0;
        if (((bVar16) && (!bVar15)) || ((!bVar16 && (bVar15)))) {
          StructMQRacerEntry_SomeFn_47(iVar3,2,1);
        }
        if (iVar5 < 0) {
          *(undefined4 *)(uVar13 + 0x60) = 1;
          uVar9 = uVar13 + 0x60 & 3;
          uVar8 = *(uint *)(uVar13 + 0x60 & 0xfffffffc);
          *(uint *)(uVar13 + 0x5c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
          uVar9 = uVar13 + 0x5c & 3;
          uVar8 = *(uint *)(uVar13 + 0x5c & 0xfffffffc);
          *(uint *)(uVar13 + 0x58) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
          uVar9 = uVar13 + 0x1c & 3;
          uVar8 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
          uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
          *(ushort *)(uVar9 + 0x70) = *(ushort *)(uVar9 + 0x70) & 0xfffe;
          uVar9 = iVar3 + 0x4cU & 3;
          uVar8 = *(uint *)(iVar3 + 0x4cU & 0xfffffffc);
          *(uint *)(iVar3 + 0x4c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20 | 0x800000;
        }
        else {
          bVar16 = false;
          iVar12 = iVar12 >> 0xc;
          iVar5 = Vector3_DotProduct((uint)(uintptr_t)(&local_3c),iVar2 + 0x20);
          if (iVar5 - iVar12 < 1) {
            iVar5 = Vector3_DotProduct((uint)(uintptr_t)(&local_3c),iVar2 + 0x2c);
            if (0 < iVar5 - iVar12) {
              bVar16 = true;
            }
          }
          else {
            bVar16 = true;
          }
          if (bVar16) {
            uVar9 = iVar3 + 0x4cU & 3;
            uVar8 = *(uint *)(iVar3 + 0x4cU & 0xfffffffc);
            *(uint *)(iVar3 + 0x4c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20 | 0x800000;
          }
          else {
            uVar9 = iVar3 + 0x4cU & 3;
            uVar4 = *(uint *)(iVar3 + 0x4cU & 0xfffffffc);
            puVar6 = (uint *)(iVar3 + 0x4c);
            *(uint *)(iVar3 + 0x4c) = (uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) & 0xff7fffff
            ;
            *(undefined4 *)(uVar13 + 0x60) = 0;
            uVar9 = uVar13 + 0x60 & 3;
            uVar4 = *(uint *)(uVar13 + 0x60 & 0xfffffffc);
            *(uint *)(uVar13 + 0x5c) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
            uVar9 = uVar13 + 0x5c & 3;
            uVar4 = *(uint *)(uVar13 + 0x5c & 0xfffffffc);
            *(uint *)(uVar13 + 0x58) = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
            uVar9 = uVar13 + 0x1c & 3;
            uVar4 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
            uVar9 = uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20;
            *(ushort *)(uVar9 + 0x70) = *(ushort *)(uVar9 + 0x70) | 1;
            uVar11 = *(uint *)(uRam02086e88 & 0xfffffffc) >> (uRam02086e88 & 3) * 8 |
                     *(uint *)(uRam02086e88 & 0xfffffffc) << (uRam02086e88 & 3) * -8 + 0x20;
            uVar9 = uVar11 + 8 & 3;
            uVar4 = *(uint *)(uVar11 + 8 & 0xfffffffc);
            if ((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) < uVar8) {
              *puVar6 = *(uint *)((uint)puVar6 & 0xfffffffc) >> ((uint)puVar6 & 3) * 8 |
                        *(uint *)((uint)puVar6 & 0xfffffffc) << ((uint)puVar6 & 3) * -8 + 0x20 |
                        0x800000;
              *(undefined4 *)(uVar13 + 0x60) = 1;
              uVar9 = uVar13 + 0x60 & 3;
              uVar8 = *(uint *)(uVar13 + 0x60 & 0xfffffffc);
              *(uint *)(uVar13 + 0x5c) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
              uVar9 = uVar13 + 0x5c & 3;
              uVar8 = *(uint *)(uVar13 + 0x5c & 0xfffffffc);
              *(uint *)(uVar13 + 0x58) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
              uVar9 = uVar13 + 0x1c & 3;
              uVar8 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
              uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
              *(ushort *)(uVar9 + 0x70) = *(ushort *)(uVar9 + 0x70) & 0xfffe;
            }
            else {
              uVar9 = uVar11 + 4 & 3;
              uVar4 = *(uint *)(uVar11 + 4 & 0xfffffffc);
              if ((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) < uVar8) {
                *(undefined4 *)(uVar13 + 0x60) = 1;
                uVar9 = uVar13 + 0x60 & 3;
                uVar8 = *(uint *)(uVar13 + 0x60 & 0xfffffffc);
                *(uint *)(uVar13 + 0x58) = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
                uVar9 = uVar13 + 0x1c & 3;
                uVar8 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
                uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
                *(ushort *)(uVar9 + 0x70) = *(ushort *)(uVar9 + 0x70) & 0xfffe;
              }
              else if ((*(uint *)(uVar11 & 0xfffffffc) >> (uVar11 & 3) * 8 |
                       *(uint *)(uVar11 & 0xfffffffc) << (uVar11 & 3) * -8 + 0x20) < uVar8) {
                *(undefined4 *)(uVar13 + 0x60) = 1;
                uVar9 = uVar13 + 0x1c & 3;
                uVar8 = *(uint *)(uVar13 + 0x1c & 0xfffffffc);
                uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
                *(ushort *)(uVar9 + 0x70) = *(ushort *)(uVar9 + 0x70) & 0xfffe;
              }
            }
          }
        }
      }
      iVar14 = iVar14 + 1;
    } while (iVar14 < (int)(uint)*(byte *)((*(uint *)(uRam02086e7c & 0xfffffffc) >>
                                            (uRam02086e7c & 3) * 8 |
                                           *(uint *)(uRam02086e7c & 0xfffffffc) <<
                                           (uRam02086e7c & 3) * -8 + 0x20) + 0x3d0));
  }
  iVar2 = func_02061818();
  uVar9 = uRam02086e80;
  uVar1 = uRam02086e7c;
  if (iVar2 != 3) {
    uVar4 = *(uint *)(uRam02086e7c & 0xfffffffc) >> (uRam02086e7c & 3) * 8 |
            *(uint *)(uRam02086e7c & 0xfffffffc) << (uRam02086e7c & 3) * -8 + 0x20;
    uVar7 = 0;
    uVar8 = *(ushort *)
             ((*(uint *)(uRam02086e80 & 0xfffffffc) >> (uRam02086e80 & 3) * 8 |
              *(uint *)(uRam02086e80 & 0xfffffffc) << (uRam02086e80 & 3) * -8 + 0x20) +
              *(char *)(uVar4 + 0x62) * 2 + 0x74) + 1;
    if (*(byte *)(uVar4 + 0x3d0) <= uVar8) {
      return;
    }
    do {
      uVar11 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
               *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
      uVar4 = uVar11 + (uint)*(ushort *)(uVar11 + uVar8 * 2 + 0x44) * 4;
      uVar13 = uVar4 & 3;
      uVar4 = *(uint *)(uVar4 & 0xfffffffc);
      uVar4 = uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20;
      if (uVar4 != 0) {
        bVar16 = 1 < uVar7;
        if (bVar16) {
          uVar4 = (uint)*(ushort *)(uVar4 + 0xc);
        }
        uVar7 = uVar7 + 1;
        if (bVar16) {
          *(undefined4 *)(uVar11 + uVar4 * 4 + 0xe4) = 1;
        }
      }
      uVar8 = uVar8 + 1;
    } while ((int)uVar8 <
             (int)(uint)*(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                  *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x3d0)
            );
    return;
  }
  uVar7 = 0;
  iVar2 = 0;
  if (*(char *)((*(uint *)(uRam02086e7c & 0xfffffffc) >> (uRam02086e7c & 3) * 8 |
                *(uint *)(uRam02086e7c & 0xfffffffc) << (uRam02086e7c & 3) * -8 + 0x20) + 0x3d0) ==
      '\0') {
    return;
  }
  do {
    uVar13 = *(uint *)(uVar9 & 0xfffffffc) >> (uVar9 & 3) * 8 |
             *(uint *)(uVar9 & 0xfffffffc) << (uVar9 & 3) * -8 + 0x20;
    uVar8 = uVar13 + (uint)*(ushort *)(uVar13 + iVar2 * 2 + 0x44) * 4;
    uVar4 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    uVar8 = uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20;
    if (((uVar8 != 0) &&
        (uVar11 = (uint)*(ushort *)(uVar8 + 0xc),
        uVar8 = uVar13 + (uint)*(ushort *)(uVar13 + uVar11 * 2 + 0x74) * 4 + 0x54, uVar4 = uVar8 & 3
        , uVar8 = *(uint *)(uVar8 & 0xfffffffc),
        -1 < (int)(uVar8 >> uVar4 * 8 | uVar8 << uVar4 * -8 + 0x20))) &&
       (bVar16 = 1 < uVar7, uVar7 = uVar7 + 1, bVar16)) {
      *(undefined4 *)(uVar13 + uVar11 * 4 + 0xe4) = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < (int)(uint)*(byte *)((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                                        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) +
                                       0x3d0));
  return;
}

