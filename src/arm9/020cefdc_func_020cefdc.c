/* Decompiled C draft; module arm9; ROM address 020cefdc. No matching claim. */
#include "types.h"
#include "deps/020cefdc_func_020cefdc.h"

void func_020cefdc(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined2 uVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint uVar13;
  bool bVar15;
  undefined6 uVar16;
  int local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  uint uVar14;
  
  iVar9 = 0;
  uVar3 = func_020c0db0();
  uVar2 = uRam020cf2f8;
  uVar4 = *(uint *)(uRam020cf2f4 & 0xfffffffc) >> (uRam020cf2f4 & 3) * 8 |
          *(uint *)(uRam020cf2f4 & 0xfffffffc) << (uRam020cf2f4 & 3) * -8 + 0x20;
  iVar10 = 0;
  uVar13 = uVar4 + 0x278;
  uVar14 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  uVar14 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
  uVar4 = uVar4 + 0x268;
  uVar13 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (0 < (int)uVar14) {
    iVar12 = 0;
    do {
      uVar11 = (uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) + iVar10 * 4;
      uVar1 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
      iVar5 = func_020fd528(uVar11);
      if (iVar5 != 0) {
        uVar6 = func_020fd308(uVar11,&local_34,&local_30);
        uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
        uVar1 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        iVar5 = func_020b5ae8(uVar6,(int *)(uintptr_t)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12),
                              uVar3,1,1);
        if (iVar5 != 0) {
          uVar7 = GetB3C4_Cell_RaceS(99);
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined4 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 8) = uVar7;
          uVar16 = CheckVectorBounds_Clock_Airship(uVar6);
          uVar8 = (undefined2)((uint6)uVar16 >> 0x20);
          bVar15 = (int)uVar16 != 0;
          if (bVar15) {
            uVar8 = 2;
          }
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          if (!bVar15) {
            uVar8 = 3;
          }
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0xc) =
               uVar8;
          uVar8 = (undefined2)local_34;
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0x10) =
               uVar8;
          if (0x15 < local_34) {
            uVar8 = 1;
          }
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          if (local_34 < 0x16) {
            uVar8 = 0;
          }
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0xe) =
               uVar8;
          if (0x15 < local_34) {
            local_30 = ComputeValueInterpolation_from_thumb(1,0x1000,10,local_34 + -0x16,0x22);
          }
          iVar12 = iVar12 + 0x14;
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xc;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined4 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar9 * 8) =
               local_30;
          iVar9 = iVar9 + 1;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)uVar14);
  }
  uVar2 = uRam020cf2f8;
  iVar10 = 0;
  uVar4 = *(uint *)(uRam020cf2f4 & 0xfffffffc) >> (uRam020cf2f4 & 3) * 8 |
          *(uint *)(uRam020cf2f4 & 0xfffffffc) << (uRam020cf2f4 & 3) * -8 + 0x20;
  uVar13 = uVar4 + 0x168;
  uVar14 = uVar13 & 3;
  uVar13 = *(uint *)(uVar13 & 0xfffffffc);
  uVar14 = uVar13 >> uVar14 * 8 | uVar13 << uVar14 * -8 + 0x20;
  uVar4 = uVar4 + 0x158;
  uVar13 = uVar4 & 3;
  uVar4 = *(uint *)(uVar4 & 0xfffffffc);
  if (0 < (int)uVar14) {
    iVar12 = iVar9 * 0x14;
    do {
      uVar11 = (uVar4 >> uVar13 * 8 | uVar4 << uVar13 * -8 + 0x20) + iVar10 * 4;
      uVar1 = uVar11 & 3;
      uVar11 = *(uint *)(uVar11 & 0xfffffffc);
      uVar11 = uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20;
      iVar5 = func_020fadcc(uVar11);
      if (iVar5 != 0) {
        uVar6 = func_020fad9c(uVar11,&local_2c,&local_28);
        uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                 *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
        uVar1 = uVar11 & 3;
        uVar11 = *(uint *)(uVar11 & 0xfffffffc);
        iVar5 = func_020b5ae8(uVar6,(int *)(uintptr_t)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12),
                              uVar3,1,1);
        if (iVar5 != 0) {
          uVar7 = GetB3C4_Cell_RaceS(100);
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined4 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 8) = uVar7;
          uVar16 = CheckVectorBounds_Clock_Airship(uVar6);
          uVar8 = (undefined2)((uint6)uVar16 >> 0x20);
          bVar15 = (int)uVar16 != 0;
          if (bVar15) {
            uVar8 = 2;
          }
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          if (!bVar15) {
            uVar8 = 3;
          }
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0xc) =
               uVar8;
          uVar8 = (undefined2)local_2c;
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0x10) =
               uVar8;
          if (0x15 < local_2c) {
            uVar8 = 1;
          }
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0x10;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          if (local_2c < 0x16) {
            uVar8 = 0;
          }
          *(undefined2 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar12 + 0xe) =
               uVar8;
          if (0x15 < local_2c) {
            local_28 = ComputeValueInterpolation_from_thumb(1,0x1000,10,local_2c + -0x16,0x22);
          }
          iVar12 = iVar12 + 0x14;
          uVar11 = (*(uint *)(uVar2 & 0xfffffffc) >> (uVar2 & 3) * 8 |
                   *(uint *)(uVar2 & 0xfffffffc) << (uVar2 & 3) * -8 + 0x20) + 0xc;
          uVar1 = uVar11 & 3;
          uVar11 = *(uint *)(uVar11 & 0xfffffffc);
          *(undefined4 *)((uVar11 >> uVar1 * 8 | uVar11 << uVar1 * -8 + 0x20) + iVar9 * 8) =
               local_28;
          iVar9 = iVar9 + 1;
        }
      }
      iVar10 = iVar10 + 1;
    } while (iVar10 < (int)uVar14);
  }
  *(int *)((*(uint *)(uRam020cf2f8 & 0xfffffffc) >> (uRam020cf2f8 & 3) * 8 |
           *(uint *)(uRam020cf2f8 & 0xfffffffc) << (uRam020cf2f8 & 3) * -8 + 0x20) + 4) = iVar9;
  return;
}

