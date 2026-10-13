/* Decompiled C draft; module arm9; ROM address 020d5180. No matching claim. */
#include "types.h"
#include "deps/020d5180_func_020d5180.h"

void func_020d5180(uint param_1,int param_2,ushort param_3)

{
  byte bVar1;
  ushort uVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  uint uVar8;
  
  uVar11 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
           *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  iVar13 = (int)*psRam020d5324;
  uVar16 = param_1 + 8 & 3;
  uVar7 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar8 = uVar7 >> uVar16 * 8 | uVar7 << uVar16 * -8 + 0x20;
  iVar6 = 0;
  uVar12 = *(uint *)(uRam020d5328 & 0xfffffffc) >> (uRam020d5328 & 3) * 8 |
           *(uint *)(uRam020d5328 & 0xfffffffc) << (uRam020d5328 & 3) * -8 + 0x20;
  uVar16 = uRam020d532c & 3;
  uVar10 = *(uint *)(uRam020d532c & 0xfffffffc);
  iVar5 = 0;
  *psRam020d5330 = 0;
  uVar4 = uRam020d5334;
  psVar3 = psRam020d5330;
  uVar7 = uRam020d532c;
  iVar15 = iVar13 + -1;
  while( true ) {
    iVar9 = iVar6 + iVar15;
    iVar14 = iVar5 + iVar15;
    if ((iVar9 <= iVar13) &&
       ((int)*(short *)(uVar12 + (iVar9 + -1) * 4 + 2) < (int)((uVar11 - param_2) * 0x20) >> 0x10))
    {
      iVar6 = iVar9;
    }
    if ((iVar14 <= iVar13) &&
       ((int)*(short *)((uVar10 >> uVar16 * 8 | uVar10 << uVar16 * -8 + 0x20) + iVar14 * 4 + 2) <=
        (int)((uVar11 + param_2) * 0x20) >> 0x10)) {
      iVar5 = iVar14;
    }
    if (iVar15 == 1) break;
    iVar15 = iVar15 + 1 >> 1;
  }
  uVar16 = (uint)*(byte *)(uVar12 + iVar6 * 4 + 1);
  if (iVar5 < (int)uVar16) {
    return;
  }
  do {
    uVar10 = uVar7 & 3;
    uVar11 = *(uint *)(uVar7 & 0xfffffffc);
    uVar10 = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
    if ((int)(uint)*(byte *)(uVar10 + iVar5 * 4) < iVar6) {
LAB_020d52fc:
      if (iVar5 == 0) {
        return;
      }
    }
    else {
      bVar1 = *(byte *)(uVar10 + iVar5 * 4 + 1);
      uVar10 = uVar4 & 3;
      uVar11 = *(uint *)(uVar4 & 0xfffffffc);
      iVar15 = (uint)bVar1 * 0x1c + (uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20);
      uVar2 = *(ushort *)(iVar15 + 0x14);
      uVar10 = iVar15 + 4U & 3;
      uVar11 = *(uint *)(iVar15 + 4U & 0xfffffffc);
      if (((((int)(uVar8 - param_2) <= (int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20))
           && (uVar10 = iVar15 + 8U & 3, uVar11 = *(uint *)(iVar15 + 8U & 0xfffffffc),
              (int)(uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20) <= (int)(uVar8 + param_2)))
          && ((uVar2 & param_3) != 0)) && ((uVar2 & 0x200) == 0)) {
        *(ushort *)
         ((*(uint *)(uRam020d5338 & 0xfffffffc) >> (uRam020d5338 & 3) * 8 |
          *(uint *)(uRam020d5338 & 0xfffffffc) << (uRam020d5338 & 3) * -8 + 0x20) + *psVar3 * 2) =
             (ushort)bVar1;
        *(ushort *)
         ((*(uint *)(uRam020d533c & 0xfffffffc) >> (uRam020d533c & 3) * 8 |
          *(uint *)(uRam020d533c & 0xfffffffc) << (uRam020d533c & 3) * -8 + 0x20) + *psVar3 * 2) =
             uVar2;
        uVar10 = iVar15 + 0x18U & 3;
        uVar11 = *(uint *)(iVar15 + 0x18U & 0xfffffffc);
        *(uint *)((*(uint *)(uRam020d5340 & 0xfffffffc) >> (uRam020d5340 & 3) * 8 |
                  *(uint *)(uRam020d5340 & 0xfffffffc) << (uRam020d5340 & 3) * -8 + 0x20) +
                 *psVar3 * 4) = uVar11 >> uVar10 * 8 | uVar11 << uVar10 * -8 + 0x20;
        *psVar3 = *psVar3 + 1;
        if (*psVar3 == 0x80) {
          return;
        }
        goto LAB_020d52fc;
      }
    }
    iVar5 = iVar5 + -1;
    if (iVar5 < (int)uVar16) {
      return;
    }
  } while( true );
}

