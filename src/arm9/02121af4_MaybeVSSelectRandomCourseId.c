/* Decompiled C draft; module arm9; ROM address 02121af4. No matching claim. */
#include "types.h"
#include "deps/02121af4_MaybeVSSelectRandomCourseId.h"

void MaybeVSSelectRandomCourseId(void)

{
  longlong lVar1;
  byte *pbVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar12;
  uint uVar13;
  int *piVar14;
  uint uVar15;
  byte bVar16;
  uint uVar17;
  uint local_60 [4];
  byte local_50 [56];
  uint uVar11;
  
  bVar16 = 0;
  local_60[0] = 0;
  local_60[1] = 0;
  local_60[2] = 0;
  local_60[3] = 0;
  uVar12 = 0;
  iVar3 = 0xd;
  pbVar2 = local_50;
  do {
    pbVar6 = pbVar2;
    *pbVar6 = 0;
    pbVar6[1] = 0;
    pbVar6[2] = 0;
    pbVar6[3] = 0;
    iVar3 = iVar3 + -1;
    pbVar2 = pbVar6 + 4;
  } while (iVar3 != 0);
  pbVar6[4] = 0;
  pbVar6[5] = 0;
  pbVar6[6] = 0;
  uVar8 = *(uint *)(uRam02121c70 & 0xfffffffc) >> (uRam02121c70 & 3) * 8 |
          *(uint *)(uRam02121c70 & 0xfffffffc) << (uRam02121c70 & 3) * -8 + 0x20;
  uVar17 = 0;
  if (*(char *)(uVar8 + 0x1f53) != '\0') {
    do {
      if (((uint)*(byte *)(uVar8 + 0x1f55) & 1 << uVar17) != 0) {
        iVar3 = uVar17 * 0x44 + uVar8;
        uVar15 = iVar3 + 0x1e48;
        uVar4 = uVar15 & 3;
        uVar15 = *(uint *)(uVar15 & 0xfffffffc);
        uVar15 = uVar15 >> uVar4 * 8 | uVar15 << uVar4 * -8 + 0x20;
        local_50[uVar15] = local_50[uVar15] + 1;
        uVar15 = iVar3 + 0x1e48;
        uVar4 = uVar15 & 3;
        uVar15 = *(uint *)(uVar15 & 0xfffffffc);
        if (bVar16 < local_50[uVar15 >> uVar4 * 8 | uVar15 << uVar4 * -8 + 0x20]) {
          bVar16 = local_50[uVar15 >> uVar4 * 8 | uVar15 << uVar4 * -8 + 0x20];
        }
      }
      uVar17 = uVar17 + 1 & 0xff;
    } while (uVar17 < *(byte *)(uVar8 + 0x1f53));
  }
  uVar17 = 0;
  do {
    if (bVar16 == local_50[uVar17]) {
      local_60[uVar12] = uVar17;
      uVar12 = uVar12 + 1 & 0xff;
    }
    uVar17 = uVar17 + 1 & 0xff;
  } while (uVar17 < 0x37);
  piVar14 = (int *)(uVar8 + iRam02121c74);
  if (uVar12 == 0) {
    uVar12 = 0;
  }
  else {
    uVar8 = (uint)(piVar14 + 2) & 3;
    uVar17 = *(uint *)((uint)(piVar14 + 2) & 0xfffffffc);
    uVar9 = uVar17 >> uVar8 * 8 | uVar17 << uVar8 * -8 + 0x20;
    uVar7 = *(uint *)((uint)piVar14 & 0xfffffffc) >> ((uint)piVar14 & 3) * 8 |
            *(uint *)((uint)piVar14 & 0xfffffffc) << ((uint)piVar14 & 3) * -8 + 0x20;
    uVar8 = (uint)(piVar14 + 1) & 3;
    uVar4 = *(uint *)((uint)(piVar14 + 1) & 0xfffffffc);
    lVar1 = (ulonglong)uVar7 * (ulonglong)uVar9;
    uVar13 = (uint)lVar1;
    uVar17 = (uint)(piVar14 + 3) & 3;
    uVar5 = *(uint *)((uint)(piVar14 + 3) & 0xfffffffc);
    uVar15 = (uint)(piVar14 + 4) & 3;
    uVar10 = *(uint *)((uint)(piVar14 + 4) & 0xfffffffc);
    uVar11 = uVar10 >> uVar15 * 8 | uVar10 << uVar15 * -8 + 0x20;
    uVar15 = (uint)(piVar14 + 5) & 3;
    uVar10 = *(uint *)((uint)(piVar14 + 5) & 0xfffffffc);
    *piVar14 = uVar11 + uVar13;
    piVar14[1] = (uVar10 >> uVar15 * 8 | uVar10 << uVar15 * -8 + 0x20) +
                 (uVar5 >> uVar17 * 8 | uVar5 << uVar17 * -8 + 0x20) * uVar7 +
                 uVar9 * (uVar4 >> uVar8 * 8 | uVar4 << uVar8 * -8 + 0x20) +
                 (int)((ulonglong)lVar1 >> 0x20) + (uint)CARRY4(uVar11,uVar13);
    if (uVar12 == 0) {
      uVar12 = (uint)(piVar14 + 1) & 3;
      uVar8 = *(uint *)((uint)(piVar14 + 1) & 0xfffffffc);
      uVar12 = uVar8 >> uVar12 * 8 | uVar8 << uVar12 * -8 + 0x20;
    }
    else {
      uVar8 = (uint)(piVar14 + 1) & 3;
      uVar17 = *(uint *)((uint)(piVar14 + 1) & 0xfffffffc);
      uVar12 = (uint)((ulonglong)uVar12 *
                      (ulonglong)(uVar17 >> uVar8 * 8 | uVar17 << uVar8 * -8 + 0x20) >> 0x20);
    }
  }
  uVar12 = local_60[uVar12 & 0xffff];
  iVar3 = GetGlobalCA_from_thumb();
  *(uint *)(iVar3 + 0xd0) = uVar12;
  return;
}

