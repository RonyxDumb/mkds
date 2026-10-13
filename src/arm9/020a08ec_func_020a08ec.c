/* Decompiled C draft; module arm9; ROM address 020a08ec. No matching claim. */
#include "types.h"
#include "deps/020a08ec_func_020a08ec.h"

void func_020a08ec(void)

{
  uint uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  uint uVar14;
  undefined4 *puVar15;
  int iVar16;
  
  uVar1 = uRam020a0dac;
  uVar10 = *(uint *)(uRam020a0dac & 0xfffffffc) >> (uRam020a0dac & 3) * 8 |
           *(uint *)(uRam020a0dac & 0xfffffffc) << (uRam020a0dac & 3) * -8 + 0x20;
  uVar5 = uVar10 + 0x3b4 & 3;
  uVar4 = *(uint *)(uVar10 + 0x3b4 & 0xfffffffc);
  uVar14 = (uint)*(byte *)((*(uint *)(uRam020a0db0 & 0xfffffffc) >> (uRam020a0db0 & 3) * 8 |
                           *(uint *)(uRam020a0db0 & 0xfffffffc) << (uRam020a0db0 & 3) * -8 + 0x20) +
                          0x3d0);
  if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 0) {
    uVar14 = uVar14 - 1;
    if (-1 < (int)uVar14) {
      iVar16 = uVar14 * 0x70;
      do {
        uVar4 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
        iVar11 = uVar4 + iVar16;
        uVar5 = iVar11 + 8;
        uVar10 = uVar5 & 3;
        uVar5 = *(uint *)(uVar5 & 0xfffffffc);
        if ((uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) == 1) {
          GetDriverEntry(uVar14 & 0xffff);
          StructMQRacerEntry_SomeFn_31();
          *(undefined4 *)
           ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
            *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16 + 8) = 2;
        }
        else {
          uVar4 = uVar4 + 0x3b4;
          uVar5 = uVar4 & 3;
          uVar4 = *(uint *)(uVar4 & 0xfffffffc);
          if (((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 0) &&
             (uVar5 = iVar11 + 0x4c, uVar4 = uVar5 & 3, uVar5 = *(uint *)(uVar5 & 0xfffffffc),
             0 < (int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))) {
            iVar11 = GetDriverEntry(uVar14 & 0xffff);
            puVar15 = (undefined4 *)
                      ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                       *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16);
            uVar5 = (uint)(puVar15 + 0x19) & 3;
            uVar4 = *(uint *)((uint)(puVar15 + 0x19) & 0xfffffffc);
            iVar9 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) - 1;
            if (iVar9 < 1) {
              iVar9 = 0;
            }
            puVar15[0x19] = iVar9;
            iVar9 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16;
            uVar5 = iVar9 + 0x68;
            uVar4 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            *(uint *)(iVar9 + 0x68) =
                 -(uint)((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) < 1);
            iVar9 = func_01ffc67c(iVar11);
            if ((iVar9 == 0) &&
               (uVar5 = iVar11 + 0x78U & 3, uVar4 = *(uint *)(iVar11 + 0x78U & 0xfffffffc),
               (*(ushort *)
                 ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 0x5c + iRam020a0db4 + 2) & 3)
               == 0)) {
              iVar9 = IsAwardOrStaffRoll();
              if (iVar9 == 1) {
                uVar5 = iVar11 + 0x78U & 3;
                uVar4 = *(uint *)(iVar11 + 0x78U & 0xfffffffc);
                iVar9 = (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) * 0x5c + iRam020a0db4;
                if ((*(ushort *)(iVar9 + 2) & 4) == 0) {
                  if (*(char *)(iVar9 + 0x5a) != '\0') {
                    *(undefined4 *)
                     ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                      *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16 + 100) = 10
                    ;
                  }
                }
                else {
                  *(undefined4 *)
                   ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16 + 0x68) = 1;
                }
              }
            }
            else {
              *(undefined4 *)
               ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16 + 0x68) =
                   0xffffffff;
              *(undefined4 *)
               ((*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + iVar16 + 100) =
                   0xffffffff;
            }
            uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                    *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x388;
            uVar4 = uVar5 & 3;
            uVar5 = *(uint *)(uVar5 & 0xfffffffc);
            if (uVar5 >> uVar4 * 8 != 0 || uVar5 << uVar4 * -8 + 0x20 != 0) {
              uVar5 = iVar11 + 0x48U & 3;
              uVar4 = *(uint *)(iVar11 + 0x48U & 0xfffffffc);
              uVar10 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
              bVar3 = true;
              uVar5 = iVar11 + 0x180U & 3;
              uVar4 = *(uint *)(iVar11 + 0x180U & 0xfffffffc);
              if ((uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) &&
                 ((uVar10 & 0x4000000) == 0)) {
                bVar3 = false;
              }
              uVar5 = (uint)(puVar15 + 1) & 3;
              uVar4 = *(uint *)((uint)(puVar15 + 1) & 0xfffffffc);
              uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
              uVar2 = (undefined2)uVar14;
              if (((uVar5 == 0) && ((uVar10 & 0x200) != 0)) &&
                 (uVar4 = iVar11 + 0x4cU & 3, uVar10 = *(uint *)(iVar11 + 0x4cU & 0xfffffffc),
                 ((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) & 0x400000) == 0)) {
                puVar15[1] = 1;
                *puVar15 = 0;
                puVar15[6] = 0xfffffffe;
                *(undefined2 *)(puVar15 + 0x11) = uVar2;
                puVar15[8] = 0;
                uVar5 = (uint)(puVar15 + 0x13) & 3;
                uVar4 = *(uint *)((uint)(puVar15 + 0x13) & 0xfffffffc);
                if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 2) {
                  uVar4 = *(uint *)(uRam020a0db0 & 0xfffffffc) >> (uRam020a0db0 & 3) * 8 |
                          *(uint *)(uRam020a0db0 & 0xfffffffc) << (uRam020a0db0 & 3) * -8 + 0x20;
                  uVar5 = uVar4 + 8;
                  uVar10 = uVar5 & 3;
                  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
                  uVar5 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
                  if (((uVar5 == 2) &&
                      (uVar4 = uVar4 + 0x18, uVar10 = uVar4 & 3,
                      uVar4 = *(uint *)(uVar4 & 0xfffffffc),
                      uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0)) || (uVar5 == 4)
                     ) {
                    uVar5 = iVar11 + 0x7cU & 3;
                    uVar4 = *(uint *)(iVar11 + 0x7cU & 0xfffffffc);
                    *(uint *)(iVar11 + 0x7c) =
                         uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x20000000;
                    uVar5 = iVar11 + 0x48U & 3;
                    uVar4 = *(uint *)(iVar11 + 0x48U & 0xfffffffc);
                    *(uint *)(iVar11 + 0x48) =
                         (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0xfdffffff;
                  }
                }
              }
              else if ((uVar5 == 1) &&
                      (uVar5 = iVar11 + 0x44U & 3, uVar4 = *(uint *)(iVar11 + 0x44U & 0xfffffffc),
                      ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x10000) != 0)) {
                puVar15[1] = 0;
                puVar15[7] = 0;
                uVar5 = iVar11 + 0x4cU & 3;
                uVar4 = *(uint *)(iVar11 + 0x4cU & 0xfffffffc);
                if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x400000) == 0) {
                  StructMQRacerEntry_SomeFn_30(iVar11);
                }
              }
              uVar5 = (uint)(puVar15 + 7) & 3;
              uVar4 = *(uint *)((uint)(puVar15 + 7) & 0xfffffffc);
              uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
              if (uVar5 == 0) {
                puVar15[7] = 0xfffffffe;
                uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x388;
                uVar4 = uVar5 & 3;
                uVar5 = *(uint *)(uVar5 & 0xfffffffc);
                (*(code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))(uVar14 & 0xffff,8);
                *(undefined2 *)(puVar15 + 0x11) = uVar2;
              }
              else if (-1 < (int)uVar5) {
                puVar15[7] = uVar5 + 1;
              }
              uVar5 = *(uint *)((uint)puVar15 & 0xfffffffc) >> ((uint)puVar15 & 3) * 8 |
                      *(uint *)((uint)puVar15 & 0xfffffffc) << ((uint)puVar15 & 3) * -8 + 0x20;
              if (((uVar5 == 0) && (bVar3)) &&
                 (uVar4 = iVar11 + 0x4cU & 3, uVar10 = *(uint *)(iVar11 + 0x4cU & 0xfffffffc),
                 ((uVar10 >> uVar4 * 8 | uVar10 << uVar4 * -8 + 0x20) & 0x400000) == 0)) {
                *puVar15 = 1;
                uVar5 = (uint)(puVar15 + 0x13) & 3;
                uVar4 = *(uint *)((uint)(puVar15 + 0x13) & 0xfffffffc);
                if ((int)(uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) < 2) {
                  uVar4 = *(uint *)(uRam020a0db0 & 0xfffffffc) >> (uRam020a0db0 & 3) * 8 |
                          *(uint *)(uRam020a0db0 & 0xfffffffc) << (uRam020a0db0 & 3) * -8 + 0x20;
                  uVar5 = uVar4 + 8;
                  uVar10 = uVar5 & 3;
                  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
                  uVar5 = uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20;
                  if (((uVar5 == 2) &&
                      (uVar4 = uVar4 + 0x18, uVar10 = uVar4 & 3,
                      uVar4 = *(uint *)(uVar4 & 0xfffffffc),
                      uVar4 >> uVar10 * 8 == 0 && uVar4 << uVar10 * -8 + 0x20 == 0)) || (uVar5 == 4)
                     ) {
                    uVar5 = iVar11 + 0x7cU & 3;
                    uVar4 = *(uint *)(iVar11 + 0x7cU & 0xfffffffc);
                    *(uint *)(iVar11 + 0x7c) =
                         uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20 | 0x20000000;
                  }
                }
              }
              else if (((uVar5 == 1) && (!bVar3)) &&
                      (uVar5 = iVar11 + 0x48U & 3, uVar4 = *(uint *)(iVar11 + 0x48U & 0xfffffffc),
                      ((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & uRam020a0db8) == 0)) {
                *puVar15 = 0;
                uVar5 = (uint)(puVar15 + 8) & 3;
                uVar4 = *(uint *)((uint)(puVar15 + 8) & 0xfffffffc);
                if (uVar4 >> uVar5 * 8 == 0 && uVar4 << uVar5 * -8 + 0x20 == 0) {
                  puVar15[6] = 0;
                  uVar5 = iVar11 + 0x4cU & 3;
                  uVar4 = *(uint *)(iVar11 + 0x4cU & 0xfffffffc);
                  if (((uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) & 0x400000) == 0) {
                    StructMQRacerEntry_SomeFn_30(iVar11);
                  }
                }
                else {
                  puVar15[8] = 0;
                }
              }
              uVar5 = (uint)(puVar15 + 6) & 3;
              uVar4 = *(uint *)((uint)(puVar15 + 6) & 0xfffffffc);
              uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
              if (uVar5 == 0) {
                puVar15[6] = 0xfffffffe;
                uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
                        *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x388;
                uVar4 = uVar5 & 3;
                uVar5 = *(uint *)(uVar5 & 0xfffffffc);
                (*(code *)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20))
                          (uVar14 & 0xffff,*(undefined2 *)(puVar15 + 0x11));
                *(undefined2 *)(puVar15 + 0x11) = uVar2;
              }
              else if (-1 < (int)uVar5) {
                puVar15[6] = uVar5 + 1;
              }
            }
            uVar12 = *(undefined4 *)(iVar11 + 0x84);
            uVar13 = *(undefined4 *)(iVar11 + 0x88);
            puVar15[3] = *(undefined4 *)(iVar11 + 0x80);
            puVar15[4] = uVar12;
            puVar15[5] = uVar13;
          }
        }
        iVar16 = iVar16 + -0x70;
        uVar14 = uVar14 - 1;
      } while (-1 < (int)uVar14);
      return;
    }
    return;
  }
  uVar5 = uVar10 + 0x3a8 & 3;
  uVar4 = *(uint *)(uVar10 + 0x3a8 & 0xfffffffc);
  uVar5 = uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20;
  if (0 < (int)uVar5) {
    *(uint *)(uVar10 + 0x3a8) = uVar5 - 1;
    uVar10 = *(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
             *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20;
    uVar5 = uVar10 + 0x3a8;
    uVar4 = uVar5 & 3;
    uVar5 = *(uint *)(uVar5 & 0xfffffffc);
    if ((int)(uVar5 >> uVar4 * 8 | uVar5 << uVar4 * -8 + 0x20) < 1) {
      *(undefined4 *)(uVar10 + 0x3a8) = 0xffffffff;
      uVar5 = (*(uint *)(uVar1 & 0xfffffffc) >> (uVar1 & 3) * 8 |
              *(uint *)(uVar1 & 0xfffffffc) << (uVar1 & 3) * -8 + 0x20) + 0x390;
      uVar1 = uVar5 & 3;
      uVar5 = *(uint *)(uVar5 & 0xfffffffc);
      pcVar6 = (code *)(uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20);
      if (pcVar6 != (code *)0x0) {
        (*pcVar6)();
      }
    }
  }
  uVar1 = uRam020a0db0;
  uVar5 = uRam020a0dac;
  uVar10 = 0;
  uVar4 = uVar10;
  if (uVar14 != 0) {
    do {
      uVar7 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar10 + 8;
      uVar8 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      if ((uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) == 1) {
        uVar7 = uVar1 & 3;
        uVar8 = *(uint *)(uVar1 & 0xfffffffc);
        if (uVar4 != (int)*(char *)((uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20) + 0x62)) {
          GetDriverEntry(uVar4 & 0xffff);
          StructMQRacerEntry_SomeFn_31();
        }
        *(undefined4 *)
         ((*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
          *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + uVar10 + 8) = 2;
      }
      uVar4 = uVar4 + 1;
      uVar10 = uVar10 + 0x70;
    } while ((int)uVar4 < (int)uVar14);
    return;
  }
  return;
}

