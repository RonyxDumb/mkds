/* Decompiled C draft; module arm7; ROM address 06003918. No matching claim. */
#include "types.h"
#include "deps/06003918_FUN_06003918.h"

void FUN_06003918(int param_1)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  undefined2 uVar6;
  int iVar7;
  bool bVar8;
  undefined2 uVar9;
  int iVar10;
  undefined2 *puVar11;
  uint uVar12;
  undefined4 uVar13;
  int iVar14;
  short *psVar15;
  uint uVar16;
  uint uVar18;
  ushort *puVar20;
  int iVar21;
  uint uVar22;
  uint uVar17;
  uint uVar19;
  
  iVar7 = -DAT_06003e6c;
  iVar10 = FUN_06000680();
  uVar19 = iVar10 + 0x154cU & 3;
  uVar18 = *(uint *)(iVar10 + 0x154cU & 0xfffffffc);
  uVar19 = uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20;
  psVar15 = (short *)(*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
                     *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20);
  sVar1 = *psVar15;
  if (((sVar1 == 2) || (sVar1 == 3)) || (sVar1 == 5)) {
    uVar18 = param_1 + 4U & 3;
    uVar12 = *(uint *)(param_1 + 4U & 0xfffffffc);
    *(uint *)(psVar15 + 0xc0) = uVar12 >> uVar18 * 8 | uVar12 << uVar18 * -8 + 0x20;
    uVar2 = *(ushort *)(param_1 + 2);
    *(ushort *)
     ((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
      *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x18c) = uVar2;
    uVar3 = *(ushort *)(param_1 + 10);
    thunk_FUN_037fb390(param_1 + 0xc,&stack0xfffffffa + iVar7,6);
    uVar4 = *(ushort *)(param_1 + 0x36);
    uVar18 = (uint)*(ushort *)(param_1 + 0x12);
    if (uVar18 == 2) {
      bVar8 = true;
      uVar18 = 0;
    }
    else if (uVar18 == 3) {
      bVar8 = true;
      uVar18 = 1;
    }
    else {
      bVar8 = false;
    }
    sVar1 = *(short *)(param_1 + 0x14);
    thunk_FUN_037fb390(param_1 + 0x16,(int)&stack0x00000000 + iVar7,0x20);
    *(uint *)(&stack0xffffffec + iVar7) = (uint)*(ushort *)(param_1 + 8);
    uVar5 = *(ushort *)(&stack0xfffffffa + iVar7);
    if ((uVar5 != DAT_06003e70) && ((uVar5 & 1) != 0)) {
      *(ushort *)(&stack0xfffffffa + iVar7) = uVar5 & 0xfffe;
    }
    uVar12 = *(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
             *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20;
    uVar22 = ((uint)uVar2 << 0x11) >> 0x10 & (uint)*(ushort *)(uVar12 + 0x1f0);
    if (uVar22 == 0) {
      puVar11 = (undefined2 *)thunk_FUN_03807424();
      *puVar11 = 0x26;
      puVar11[1] = 6;
      puVar11[4] = 4;
      thunk_FUN_038074cc();
    }
    else {
      uVar17 = param_1 + 4U & 3;
      uVar16 = *(uint *)(param_1 + 4U & 0xfffffffc);
      uVar17 = uVar16 >> uVar17 * 8 | uVar16 << uVar17 * -8 + 0x20;
      if (((uVar17 == 0) || ((uVar17 & 3) != 0)) || (*(ushort *)(param_1 + 8) < 0x40)) {
        puVar11 = (undefined2 *)thunk_FUN_03807424();
        *puVar11 = 0x26;
        puVar11[1] = 6;
        puVar11[4] = 4;
        thunk_FUN_038074cc();
      }
      else {
        *(undefined2 *)(uVar12 + 0xe2) = 2;
        iVar10 = FUN_06002084(&stack0x00000050 + iVar7);
        if (*(short *)(iVar10 + 4) == 0) {
          if (*(short *)(iVar10 + 6) == 0x10) {
            iVar10 = FUN_06000294(0x26,&stack0x00000050 + iVar7);
            if (iVar10 == 0) {
              return;
            }
            iVar10 = FUN_060020f4(&stack0x00000050 + iVar7);
            if (*(short *)(iVar10 + 4) != 0) {
              FUN_06003854(DAT_06003e74,*(short *)(iVar10 + 4),1);
              return;
            }
            *(undefined2 *)
             (*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
             *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) = 3;
            iVar10 = FUN_06002c40(&stack0x00000050 + iVar7,1,0,1);
            if (*(short *)(iVar10 + 4) != 0) {
              FUN_06003854(1,*(short *)(iVar10 + 4),1);
              return;
            }
            *(undefined2 *)
             ((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
              *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0xc2) = 1;
          }
          if (uVar18 == 0) {
            if (*(short *)((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
                           *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x1ea) == 1
               ) {
              iVar10 = FUN_06002400(&stack0x00000050 + iVar7,0);
              if (*(short *)(iVar10 + 4) != 0) {
                FUN_06003854(DAT_06003e78,*(short *)(iVar10 + 4),1);
                return;
              }
              *(undefined2 *)
               ((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
                *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x1ea) = 0;
            }
          }
          else if (*(short *)((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
                              *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x1ea)
                   == 0) {
            iVar10 = FUN_06002400(&stack0x00000050 + iVar7,1);
            if (*(short *)(iVar10 + 4) != 0) {
              FUN_06003854(DAT_06003e78,*(short *)(iVar10 + 4),1);
              return;
            }
            *(undefined2 *)
             ((*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
              *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x1ea) = 1;
          }
          if (bVar8) {
            thunk_FUN_037fb2fc(&stack0x00000020 + iVar7,0xff,0x20);
            if (uVar4 < 0x21) {
              thunk_FUN_037fb2fc(&stack0x00000020 + iVar7,0,uVar4);
            }
            iVar10 = FUN_06002460(&stack0x00000050 + iVar7,&stack0x00000020 + iVar7);
            if (*(short *)(iVar10 + 4) != 0) {
              FUN_06003854(DAT_06003e7c,*(short *)(iVar10 + 4),1);
              return;
            }
          }
          *(undefined2 *)
           (*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
           *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) = 5;
          uVar12 = 0;
          thunk_FUN_037fb2fc(&stack0x00000040 + iVar7,0,0x10);
          uVar17 = 1;
          do {
            if ((uVar22 & 1 << (uVar17 & 0xff)) != 0) {
              (&stack0x00000040)[uVar12 + iVar7] = (char)uVar17;
              uVar12 = uVar12 + 1 & 0xffff;
            }
            uVar17 = uVar17 + 1 & 0xffff;
          } while (uVar17 < 0xf);
          uVar12 = (uint)(&stack0xffffffec + iVar7) & 3;
          uVar17 = *(uint *)((uint)(&stack0xffffffec + iVar7) & 0xfffffffc);
          uVar13 = FUN_060038a0(uVar17 >> uVar12 * 8 | uVar17 << uVar12 * -8 + 0x20);
          *(int *)(&stack0xffffffdc + iVar7) = (int)&stack0x00000000 + iVar7;
          *(uint *)(&stack0xffffffe0 + iVar7) = uVar18;
          *(undefined1 **)(&stack0xffffffe4 + iVar7) = &stack0x00000040 + iVar7;
          *(uint *)(&stack0xffffffe8 + iVar7) = (uint)uVar3;
          iVar10 = FUN_06002b84(&stack0x00000050 + iVar7,uVar13,&stack0xfffffffa + iVar7,sVar1);
          if (*(short *)(iVar10 + 4) == 0) {
            puVar11 = (undefined2 *)thunk_FUN_03807424();
            uVar6 = (undefined2)((int)uVar22 >> 1);
            if (*(short *)(iVar10 + 8) == 0) {
              *puVar11 = 0x26;
              puVar11[1] = 0;
              puVar11[4] = 4;
              puVar11[7] = 0;
              puVar11[5] = uVar6;
            }
            else {
              puVar20 = (ushort *)(iVar10 + 10);
              uVar19 = (*(uint *)(uVar19 & 0xfffffffc) >> (uVar19 & 3) * 8 |
                       *(uint *)(uVar19 & 0xfffffffc) << (uVar19 & 3) * -8 + 0x20) + 0x180;
              uVar18 = uVar19 & 3;
              uVar19 = *(uint *)(uVar19 & 0xfffffffc);
              uVar12 = uVar19 >> uVar18 * 8 | uVar19 << uVar18 * -8 + 0x20;
              *(undefined2 *)(&stack0xfffffff8 + iVar7) = 0;
              uVar19 = (uint)(&stack0xffffffec + iVar7) & 3;
              uVar18 = *(uint *)((uint)(&stack0xffffffec + iVar7) & 0xfffffffc);
              thunk_FUN_037fb218(*(undefined2 *)(&stack0xfffffff8 + iVar7),uVar12,
                                 uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20);
              *(undefined4 *)(&stack0xfffffff4 + iVar7) = 0x20;
              for (iVar21 = 0; iVar21 < (int)(uint)*(ushort *)(iVar10 + 8); iVar21 = iVar21 + 1) {
                *(uint *)(&stack0xfffffff0 + iVar7) = ((uint)*puVar20 << 0x11) >> 0x10;
                uVar19 = (uint)(&stack0xfffffff0 + iVar7) & 3;
                uVar18 = *(uint *)((uint)(&stack0xfffffff0 + iVar7) & 0xfffffffc);
                thunk_FUN_037fb390(puVar20,uVar12,
                                   uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20);
                if ((sVar1 != 0) && (iVar14 = FUN_060038cc(uVar12), iVar14 == 0)) {
                  *(short *)(uVar12 + 10) = sVar1;
                  uVar19 = (uint)(&stack0xfffffff4 + iVar7) & 3;
                  uVar18 = *(uint *)((uint)(&stack0xfffffff4 + iVar7) & 0xfffffffc);
                  thunk_FUN_037fb390((int)&stack0x00000000 + iVar7,uVar12 + 0xc,
                                     uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20);
                }
                *(uint *)(puVar11 + iVar21 * 2 + 8) = uVar12;
                iVar14 = (int)(puVar20[1] & 0xff) >> 2;
                if ((puVar20[1] & 2) == 0) {
                  iVar14 = iVar14 + 0x19;
                }
                uVar9 = FUN_060001b4(iVar14);
                puVar11[iVar21 + 0x28] = uVar9;
                *DAT_06003e80 =
                     (ushort)iVar14 ^ (ushort)((uint)*DAT_06003e80 << 1) ^
                     (ushort)(((uint)*DAT_06003e80 << 1) >> 0x10);
                uVar19 = (uint)(&stack0xfffffff0 + iVar7) & 3;
                uVar18 = *(uint *)((uint)(&stack0xfffffff0 + iVar7) & 0xfffffffc);
                uVar19 = uVar18 >> uVar19 * 8 | uVar18 << uVar19 * -8 + 0x20;
                puVar20 = (ushort *)((int)puVar20 + uVar19);
                uVar12 = uVar12 + uVar19;
                if ((uVar12 & 2) != 0) {
                  uVar12 = uVar12 + 2 & 0xfffffffc;
                }
              }
              *puVar11 = 0x26;
              puVar11[1] = 0;
              puVar11[4] = 5;
              puVar11[7] = *(undefined2 *)(iVar10 + 8);
              puVar11[5] = uVar6;
            }
            thunk_FUN_038074cc(puVar11);
          }
          else {
            FUN_06003854(2,*(short *)(iVar10 + 4),1);
          }
        }
        else {
          FUN_06003854(0x308,*(short *)(iVar10 + 4),1);
        }
      }
    }
  }
  else {
    puVar11 = (undefined2 *)thunk_FUN_03807424();
    *puVar11 = 0x26;
    puVar11[1] = 3;
    puVar11[4] = 4;
    thunk_FUN_038074cc();
  }
  return;
}

