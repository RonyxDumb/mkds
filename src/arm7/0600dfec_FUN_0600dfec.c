/* Decompiled C draft; module arm7; ROM address 0600dfec. No matching claim. */
#include "types.h"
#include "deps/0600dfec_FUN_0600dfec.h"

void FUN_0600dfec(void)

{
  ushort uVar1;
  undefined2 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  ushort *puVar6;
  short *psVar7;
  uint uVar8;
  int iVar10;
  int iVar11;
  short *psVar12;
  uint uVar9;
  
  uVar5 = *(uint *)(DAT_0600e1e4 & 0xfffffffc) >> (DAT_0600e1e4 & 3) * 8 |
          *(uint *)(DAT_0600e1e4 & 0xfffffffc) << (DAT_0600e1e4 & 3) * -8 + 0x20;
  iVar11 = uVar5 + DAT_0600e1e8;
  iVar10 = 2;
  do {
    psVar7 = (short *)(iVar10 * 0x14 + iVar11);
    puVar6 = (ushort *)(DAT_0600e1ec + iVar10 * 4);
    if (((*(ushort *)(&DAT_048080a0 + iVar10 * 4) & 0x8000) == 0) && (*psVar7 != 0)) {
      uVar9 = (uint)(psVar7 + 6) & 3;
      uVar8 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
      uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      if (uVar9 == 0) {
        psVar7[2] = psVar7[2] + 1;
        uVar9 = (uint)(psVar7 + 4) & 3;
        uVar3 = *(uint *)((uint)(psVar7 + 4) & 0xfffffffc);
        uVar8 = (uint)(psVar7 + 8) & 3;
        uVar4 = *(uint *)((uint)(psVar7 + 8) & 0xfffffffc);
        (*(code *)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20))
                  (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20,3);
      }
      else {
        uVar8 = (uint)(psVar7 + 4) & 3;
        uVar3 = *(uint *)((uint)(psVar7 + 4) & 0xfffffffc);
        *(undefined2 *)(uVar9 + 8) =
             *(undefined2 *)(uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
        uVar9 = (uint)(psVar7 + 4) & 3;
        uVar3 = *(uint *)((uint)(psVar7 + 4) & 0xfffffffc);
        uVar8 = (uint)(psVar7 + 6) & 3;
        uVar4 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
        *(undefined2 *)((uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) + 0x14) =
             *(undefined2 *)((uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20) + 0xc);
        puVar2 = DAT_0600e1f0;
        uVar9 = (uint)(psVar7 + 4) & 3;
        uVar8 = *(uint *)((uint)(psVar7 + 4) & 0xfffffffc);
        uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
        if ((*(ushort *)(uVar9 + 0xc) & 0x4000) == 0) {
          uVar8 = (uint)(psVar7 + 6) & 3;
          uVar3 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
          *(ushort *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 0xc) =
               *(ushort *)(uVar9 + 4) & 0xff;
        }
        else {
          if ((((*(ushort *)
                  ((*(uint *)(DAT_0600e1e4 & 0xfffffffc) >> (DAT_0600e1e4 & 3) * 8 |
                   *(uint *)(DAT_0600e1e4 & 0xfffffffc) << (DAT_0600e1e4 & 3) * -8 + 0x20) + 0x690)
                & 8) != 0) &&
              (psVar12 = (short *)(uVar9 + *(ushort *)(uVar9 + 10) + 5 & 0xfffffffe), *psVar12 == 0)
              ) && (psVar12[1] == 0)) {
            uVar9 = uVar5 + 0x3ec & 3;
            uVar4 = *(uint *)(uVar5 + 0x3ec & 0xfffffffc);
            uVar8 = (uint)(psVar7 + 6) & 3;
            uVar3 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
            uVar1 = *(ushort *)((uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20) + 4);
            *DAT_0600e1f0 = 0;
            *puVar2 = 0x8000;
            *(short *)(uVar5 + 0x3fe) = *(short *)(uVar5 + 0x3fe) + 1;
            if ((uint)*(ushort *)(uVar5 + 0x3d0) <
                ((uVar4 >> uVar9 * 8 | uVar4 << uVar9 * -8 + 0x20) - (uint)uVar1 & 0xffff)) {
              uVar9 = (uint)(psVar7 + 6) & 3;
              uVar8 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
              *(undefined2 *)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 8) = 2;
              psVar7[2] = psVar7[2] + 1;
              *(short *)(iVar11 + 0xae) = *(short *)(iVar11 + 0xae) + 1;
              uVar9 = (uint)(psVar7 + 6) & 3;
              uVar3 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
              uVar8 = (uint)(psVar7 + 8) & 3;
              uVar4 = *(uint *)((uint)(psVar7 + 8) & 0xfffffffc);
              (*(code *)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20))
                        (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20,1);
            }
            else {
              uVar9 = (uint)(psVar7 + 6) & 3;
              uVar8 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
              *(undefined2 *)((uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 0xc) = 0;
              *puVar6 = *puVar6 | 0x8000;
            }
            goto LAB_0600e1d0;
          }
          uVar8 = (uint)(psVar7 + 6) & 3;
          uVar3 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
          uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
          *(ushort *)(uVar8 + 0xc) = *(short *)(uVar8 + 0xc) + (*(ushort *)(uVar9 + 4) & 0xff);
        }
        psVar7[2] = psVar7[2] + 1;
        uVar9 = (uint)(psVar7 + 6) & 3;
        uVar3 = *(uint *)((uint)(psVar7 + 6) & 0xfffffffc);
        uVar8 = (uint)(psVar7 + 8) & 3;
        uVar4 = *(uint *)((uint)(psVar7 + 8) & 0xfffffffc);
        (*(code *)(uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20))
                  (uVar3 >> uVar9 * 8 | uVar3 << uVar9 * -8 + 0x20,2);
      }
    }
LAB_0600e1d0:
    iVar10 = iVar10 + -1;
    if (iVar10 < 0) {
      return;
    }
  } while( true );
}

