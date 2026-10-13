/* Decompiled C draft; module arm7; ROM address 0601661c. No matching claim. */
#include "types.h"
#include "deps/0601661c_FUN_0601661c.h"

void FUN_0601661c(int param_1)

{
  ushort uVar1;
  short sVar2;
  undefined2 *puVar3;
  short sVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  uint uVar8;
  short *psVar9;
  undefined2 unaff_r4;
  short *psVar10;
  short *psVar11;
  bool bVar12;
  bool bVar13;
  
  puVar3 = DAT_06016b48;
  uVar8 = *(uint *)(DAT_06016b34 & 0xfffffffc) >> (DAT_06016b34 & 3) * 8 |
          *(uint *)(DAT_06016b34 & 0xfffffffc) << (DAT_06016b34 & 3) * -8 + 0x20;
  psVar11 = (short *)(uVar8 + DAT_06016b38);
  psVar10 = (short *)(param_1 + 0x2c);
  if ((*(ushort *)(uVar8 + 0x690) & 8) != 0) {
    psVar9 = (short *)(uVar8 + DAT_06016b3c);
    uVar1 = *DAT_06016b40;
    if (((((uVar1 & 1) == 0) || (*psVar9 == 0)) && (((uVar1 & 4) == 0 || (psVar9[10] == 0)))) &&
       ((((uVar1 & 8) == 0 || (psVar9[0x14] == 0)) && ((*DAT_06016b44 & 1) == 0)))) {
      *DAT_06016b48 = 0;
      *puVar3 = 0x8000;
      *(undefined2 *)
       ((*(uint *)(DAT_06016b34 & 0xfffffffc) >> (DAT_06016b34 & 3) * 8 |
        *(uint *)(DAT_06016b34 & 0xfffffffc) << (DAT_06016b34 & 3) * -8 + 0x20) + 0x4de) = 0;
    }
  }
  iVar5 = FUN_06013528(param_1 + 0x1e,0xb0);
  if (iVar5 != 0) {
    return;
  }
  sVar4 = *(short *)(param_1 + 0x2e) + 1;
  sVar2 = *(short *)(param_1 + 2);
  bVar12 = sVar2 == 0;
  if (bVar12) {
    unaff_r4 = 0x13;
  }
  else {
    if (*(short *)(uVar8 + 0x350) == 1) {
      uVar6 = FUN_0600e918(sVar2);
      if (0x20 < uVar6) {
        FUN_0600ebbc(sVar2,0x20);
        FUN_0600fa04(param_1 + 0x1e,1);
      }
      if (((*(ushort *)(param_1 + 8) & 0x400) != 0) && (iVar5 = FUN_0600e8a0(sVar2), iVar5 != 0)) {
        bVar12 = true;
        *psVar10 = 1;
        unaff_r4 = 0xf;
        sVar4 = 4;
        FUN_0600ea7c(sVar2,0);
        goto LAB_06016af8;
      }
    }
    if (*psVar10 == 0) {
      sVar2 = *(short *)(uVar8 + 0x350);
      if (sVar2 == 1) {
        bVar13 = *(short *)((*(uint *)(DAT_06016b34 & 0xfffffffc) >> (DAT_06016b34 & 3) * 8 |
                            *(uint *)(DAT_06016b34 & 0xfffffffc) << (DAT_06016b34 & 3) * -8 + 0x20)
                           + 0x332) == 1;
        if (bVar13) {
          unaff_r4 = 0xd;
        }
        bVar12 = bVar13 || bVar12;
        if (bVar13) goto LAB_06016af8;
      }
      if (sVar2 == 1) {
        if (*(short *)(param_1 + 0x2e) == 1) {
          unaff_r4 = 0;
        }
        else {
          unaff_r4 = 0xe;
          sVar4 = 2;
        }
        bVar12 = true;
      }
      else if (((sVar2 != 1) && (*(short *)(param_1 + 0x2e) == 2)) &&
              ((uVar8 = (uint)(psVar11 + 0xc) & 3,
               uVar6 = *(uint *)((uint)(psVar11 + 0xc) & 0xfffffffc),
               uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20,
               *(short *)(uVar8 + 0x16) == 0 &&
               ((iVar5 = FUN_0600a578(uVar8 + 0x10,param_1 + 0x1e), iVar5 != 0 && (*psVar11 == 0x31)
                ))))) {
        FUN_0600983c();
        if (*(short *)(param_1 + 0x30) == 0) {
          FUN_0600a970(0x30);
          uVar8 = (uint)(psVar11 + 0xe) & 3;
          uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) = 0;
          uVar8 = (uint)(psVar11 + 0xe) & 3;
          uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 6) = 0;
        }
        else {
          uVar8 = (uint)(psVar11 + 0xe) & 3;
          uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) = 0xc;
          uVar8 = (uint)(psVar11 + 0xe) & 3;
          uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
          *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 6) =
               *(undefined2 *)(param_1 + 0x30);
        }
        *psVar11 = 0x35;
        FUN_06008a8c(2,2);
      }
    }
    else if (*psVar10 == 1) {
      if (*(short *)(uVar8 + 0x350) == 1) {
        FUN_0600ebbc(sVar2,0x20);
        if (*(short *)(param_1 + 0x2e) == 1) {
          iVar5 = FUN_060136d0(param_1 + 0x1e,0x80);
          if (iVar5 != 0) {
            *(short *)(iVar5 + 0x2c) = *psVar10;
            *(short *)(iVar5 + 0x2e) = sVar4;
            *(undefined2 *)(iVar5 + 0x30) = 0;
            FUN_06015df4(sVar2,iVar5);
            FUN_060143ac(iVar5);
          }
        }
        else if (*(short *)(param_1 + 0x2e) == 3) {
          iVar5 = FUN_0600e918(sVar2);
          if ((iVar5 == 0x20) && (iVar5 = FUN_0600e8a0(sVar2), iVar5 != 0)) {
            iVar5 = FUN_06015d6c(param_1);
            if (iVar5 == 0) {
              unaff_r4 = 0xf;
              bVar12 = true;
              FUN_0600ea7c(sVar2,0);
            }
            else {
              FUN_0600ea7c(sVar2,0);
              unaff_r4 = 0;
              bVar12 = true;
            }
          }
          else {
            unaff_r4 = 1;
            bVar12 = true;
          }
        }
        else {
          FUN_0600ea7c(sVar2,0);
          unaff_r4 = 0xe;
          sVar4 = 2;
          bVar12 = true;
        }
      }
      else {
        uVar8 = (uint)(psVar11 + 0xc) & 3;
        uVar6 = *(uint *)((uint)(psVar11 + 0xc) & 0xfffffffc);
        uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
        if ((*(short *)(uVar8 + 0x16) == 1) &&
           (iVar5 = FUN_0600a578(uVar8 + 0x10,param_1 + 0x1e), iVar5 != 0)) {
          if (*(short *)(param_1 + 0x2e) == 2) {
            if (*psVar11 == 0x31) {
              if (*(short *)(param_1 + 0x30) == 0) {
                *psVar11 = 0x33;
                uVar7 = FUN_060096c4(param_1 + 0x33);
                iVar5 = FUN_060136d0(param_1 + 0x1e,uVar7);
                if (iVar5 != 0) {
                  *(ushort *)(iVar5 + 0x14) = *(ushort *)(iVar5 + 0x14) | 0x4000;
                  thunk_FUN_037fb230(param_1 + 0x2c,iVar5 + 0x2c,*(ushort *)(param_1 + 6) + 1);
                  *(short *)(iVar5 + 0x2c) = *psVar10;
                  *(undefined2 *)(iVar5 + 0x2e) = 3;
                  *(undefined2 *)(iVar5 + 0x30) = 0;
                  FUN_060143ac(iVar5);
                }
              }
              else {
                FUN_0600983c();
                *psVar11 = 0x35;
                uVar8 = (uint)(psVar11 + 0xe) & 3;
                uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
                *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) = 0xc;
                uVar8 = (uint)(psVar11 + 0xe) & 3;
                uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
                *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 6) =
                     *(undefined2 *)(param_1 + 0x30);
                FUN_06008a8c(2,2);
                FUN_0600a970(0x20);
              }
            }
          }
          else if ((*(short *)(param_1 + 0x2e) == 4) && (*psVar11 == 0x33)) {
            FUN_0600983c();
            if (*(short *)(param_1 + 0x30) == 0) {
              FUN_0600a970(0x30);
              uVar8 = (uint)(psVar11 + 0xe) & 3;
              uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
              *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) = 0;
              uVar8 = (uint)(psVar11 + 0xe) & 3;
              uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
              *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 6) = 0;
            }
            else {
              uVar8 = (uint)(psVar11 + 0xe) & 3;
              uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
              *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 4) = 0xc;
              uVar8 = (uint)(psVar11 + 0xe) & 3;
              uVar6 = *(uint *)((uint)(psVar11 + 0xe) & 0xfffffffc);
              *(undefined2 *)((uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20) + 6) =
                   *(undefined2 *)(param_1 + 0x30);
            }
            *psVar11 = 0x35;
            FUN_06008a8c(2,2);
          }
        }
      }
    }
    else if (*(short *)(uVar8 + 0x350) == 1) {
      unaff_r4 = 0xd;
      bVar12 = true;
    }
  }
LAB_06016af8:
  if ((bVar12) && (iVar5 = FUN_060136d0(param_1 + 0x1e,0), iVar5 != 0)) {
    *(short *)(iVar5 + 0x2c) = *psVar10;
    *(short *)(iVar5 + 0x2e) = sVar4;
    *(undefined2 *)(iVar5 + 0x30) = unaff_r4;
    FUN_060143ac();
  }
  return;
}

