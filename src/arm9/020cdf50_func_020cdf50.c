/* Decompiled C draft; module arm9; ROM address 020cdf50. No matching claim. */
#include "types.h"
#include "deps/020cdf50_func_020cdf50.h"

void func_020cdf50(void)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar9;
  int iVar10;
  int unaff_r6;
  int iVar11;
  bool bVar12;
  undefined8 uVar13;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint uVar8;
  
  iVar9 = 0;
  uVar1 = func_020c0db0();
  uVar5 = uRam020ce0e0;
  uVar7 = (*(uint *)(uRam020ce0e0 & 0xfffffffc) >> (uRam020ce0e0 & 3) * 8 |
          *(uint *)(uRam020ce0e0 & 0xfffffffc) << (uRam020ce0e0 & 3) * -8 + 0x20) + 0xc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar8 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar7 = uVar8 + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  *(uint *)(uVar8 + 4) = (uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + 1;
  uVar7 = uVar5 & 3;
  uVar2 = *(uint *)(uVar5 & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 0xc;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar5 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  uVar7 = uVar5 + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if (((int)uVar7 < 0) || (7 < (int)uVar7)) {
    *(undefined4 *)(uVar5 + 4) = 0;
  }
  uVar5 = uRam020ce0e0;
  iVar10 = 0;
  uVar8 = *(uint *)(uRam020ce0e0 & 0xfffffffc) >> (uRam020ce0e0 & 3) * 8 |
          *(uint *)(uRam020ce0e0 & 0xfffffffc) << (uRam020ce0e0 & 3) * -8 + 0x20;
  uVar7 = uVar8 + 0xc & 3;
  uVar2 = *(uint *)(uVar8 + 0xc & 0xfffffffc);
  uVar7 = (uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20) + 4;
  uVar2 = uVar7 & 3;
  uVar7 = *(uint *)(uVar7 & 0xfffffffc);
  uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
  if ((int)uVar7 < 4) {
    unaff_r6 = 1;
  }
  uVar2 = uVar8 + 8 & 3;
  uVar6 = *(uint *)(uVar8 + 8 & 0xfffffffc);
  if (3 < (int)uVar7) {
    unaff_r6 = 0;
  }
  if (0 < (int)(uVar6 >> uVar2 * 8 | uVar6 << uVar2 * -8 + 0x20)) {
    local_38 = 0xb2;
    local_30 = 3;
    local_34 = 2;
    iVar11 = 0;
    local_2c = 0x1000;
    do {
      uVar7 = (*(uint *)(uVar8 & 0xfffffffc) >> (uVar8 & 3) * 8 |
              *(uint *)(uVar8 & 0xfffffffc) << (uVar8 & 3) * -8 + 0x20) + iVar10 * 4;
      uVar2 = uVar7 & 3;
      uVar7 = *(uint *)(uVar7 & 0xfffffffc);
      uVar7 = uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20;
      if (((*(ushort *)(uVar7 + 2) & 1) == 0) && (iVar3 = func_020931ac(uVar7), iVar3 != 0)) {
        uVar2 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10;
        uVar8 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        iVar3 = func_020b5ae8(uVar7 + 4,(int *)(uintptr_t)((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + iVar11),
                              uVar1,0,0);
        if (iVar3 != 0) {
          uVar8 = *(uint *)(uRam020ce0e4 & 0xfffffffc) >> (uRam020ce0e4 & 3) * 8 |
                  *(uint *)(uRam020ce0e4 & 0xfffffffc) << (uRam020ce0e4 & 3) * -8 + 0x20;
          uVar2 = uVar8 & 3;
          uVar8 = *(uint *)(uVar8 & 0xfffffffc);
          uVar4 = local_38;
          if ((uVar8 >> uVar2 * 8 | uVar8 << uVar2 * -8 + 0x20) == 0x13) {
            uVar4 = 0xae;
          }
          uVar4 = GetB3C4_Cell_RaceS(uVar4);
          uVar2 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10;
          uVar8 = uVar2 & 3;
          uVar2 = *(uint *)(uVar2 & 0xfffffffc);
          *(undefined4 *)((uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20) + iVar11 + 8) = uVar4;
          uVar13 = CheckVectorBounds_Clock_Airship(uVar7 + 4);
          bVar12 = (int)uVar13 != 0;
          uVar4 = (int)((ulonglong)uVar13 >> 0x20);
          if (bVar12) {
            uVar4 = local_34;
          }
          uVar7 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0x10;
          uVar2 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          if (!bVar12) {
            uVar4 = local_30;
          }
          *(short *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar11 + 0xc) =
               (short)uVar4;
          if (unaff_r6 != 0) {
            uVar4 = local_2c;
          }
          if (unaff_r6 == 0) {
            uVar4 = uRam020ce0e8;
          }
          uVar7 = (*(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
                  *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20) + 0xc;
          uVar2 = uVar7 & 3;
          uVar7 = *(uint *)(uVar7 & 0xfffffffc);
          iVar11 = iVar11 + 0x14;
          *(undefined4 *)((uVar7 >> uVar2 * 8 | uVar7 << uVar2 * -8 + 0x20) + iVar9 * 8) = uVar4;
          iVar9 = iVar9 + 1;
        }
      }
      iVar10 = iVar10 + 1;
      uVar8 = *(uint *)(uVar5 & 0xfffffffc) >> (uVar5 & 3) * 8 |
              *(uint *)(uVar5 & 0xfffffffc) << (uVar5 & 3) * -8 + 0x20;
      uVar7 = uVar8 + 8 & 3;
      uVar2 = *(uint *)(uVar8 + 8 & 0xfffffffc);
    } while (iVar10 < (int)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20));
  }
  *(int *)(uVar8 + 4) = iVar9;
  return;
}

