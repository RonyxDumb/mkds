/* Decompiled C draft; module arm9; ROM address 02045084. No matching claim. */
#include "types.h"
#include "deps/02045084_PrepareCurrentRaceRacer.h"

void PrepareCurrentRaceRacer(uint param_1)

{
  char cVar1;
  bool bVar2;
  uint uVar3;
  short *psVar4;
  byte bVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  byte *pbVar10;
  byte *pbVar11;
  byte *pbVar12;
  int *piVar13;
  int *piVar14;
  uint uVar15;
  uint uVar16;
  bool bVar17;
  
  uVar6 = *(uint *)(uRam02045570 & 0xfffffffc) >> (uRam02045570 & 3) * 8 |
          *(uint *)(uRam02045570 & 0xfffffffc) << (uRam02045570 & 3) * -8 + 0x20;
  uVar16 = uVar6 + 4 & 3;
  uVar8 = *(uint *)(uVar6 + 4 & 0xfffffffc);
  iVar7 = param_1 * 0x30;
  uVar15 = *(uint *)(uRam02045574 & 0xfffffffc) >> (uRam02045574 & 3) * 8 |
           *(uint *)(uRam02045574 & 0xfffffffc) << (uRam02045574 & 3) * -8 + 0x20;
  piVar14 = (int *)(uVar15 + 0x88 + iVar7);
  piVar13 = (int *)(uVar15 + 0x8c + iVar7);
  pbVar12 = (byte *)(uVar15 + 0x94 + iVar7);
  pbVar11 = (byte *)(uVar15 + 0x95 + iVar7);
  pbVar10 = (byte *)(uVar15 + 0x96 + iVar7);
  piVar9 = (int *)(uVar15 + 0x90 + iVar7);
  bVar17 = false;
  if (((int)((uint)*(byte *)((uVar8 >> uVar16 * 8 | uVar8 << uVar16 * -8 + 0x20) + 4) << 0x1f) < 0)
     && (uVar6 = -((int)((uint)*(byte *)((*(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
                                         *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20) +
                                        0x31) << 0x1c) >> 0x1f), uVar6 == 0)) {
    bVar17 = true;
  }
  bVar2 = false;
  *piVar14 = 0;
  *piVar13 = 0;
  *pbVar12 = 0;
  uVar15 = uRam02045578;
  *piVar9 = 0;
  uVar8 = uRam02045574;
  uVar16 = uVar15 & 3;
  uVar15 = *(uint *)(uVar15 & 0xfffffffc);
  uVar16 = uVar15 >> uVar16 * 8 | uVar15 << uVar16 * -8 + 0x20;
  if (bVar17) {
    uVar6 = 1;
  }
  uVar15 = uVar16 & 3;
  uVar16 = *(uint *)(uVar16 & 0xfffffffc);
  *pbVar11 = (byte)(uVar16 >> uVar15 * 8) | (byte)(uVar16 << uVar15 * -8 + 0x20);
  *pbVar10 = 0;
  uVar3 = uRam0204557c;
  uVar15 = uRam02045570;
  uVar16 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  uVar16 = uVar8 >> uVar16 * 8 | uVar8 << uVar16 * -8 + 0x20;
  if (!bVar17) {
    uVar6 = 0;
  }
  if (param_1 == (int)*(char *)(uVar16 + 0x62)) {
    uVar8 = *(uint *)(uRam02045570 & 0xfffffffc) >> (uRam02045570 & 3) * 8 |
            *(uint *)(uRam02045570 & 0xfffffffc) << (uRam02045570 & 3) * -8 + 0x20;
    uVar16 = uVar8 & 3;
    uVar8 = *(uint *)(uVar8 & 0xfffffffc);
    *piVar14 = (uVar8 >> uVar16 * 8 | uVar8 << uVar16 * -8 + 0x20) + 0xc;
    uVar16 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
             *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 4;
    uVar8 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    *piVar13 = (uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) + 8;
    uVar16 = uRam02045578;
    *pbVar12 = uVar6 != 0;
    uVar6 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    uVar16 = uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20;
    uVar6 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    *pbVar11 = (byte)(uVar16 >> uVar6 * 8) | (byte)(uVar16 << uVar6 * -8 + 0x20);
    bVar5 = GetWorstStarRank_from_thumb();
    *pbVar10 = bVar5;
    return;
  }
  iVar7 = uVar16 + iVar7;
  uVar16 = iVar7 + 0x70;
  uVar8 = uVar16 & 3;
  uVar16 = *(uint *)(uVar16 & 0xfffffffc);
  uVar16 = uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20;
  if (uVar16 == 0) {
    uVar6 = *(uint *)(uRam0204557c & 0xfffffffc) >> (uRam0204557c & 3) * 8 |
            *(uint *)(uRam0204557c & 0xfffffffc) << (uRam0204557c & 3) * -8 + 0x20;
    if (uVar6 == 0) {
      uVar16 = 0;
    }
    else {
      uVar16 = *(uint *)(uVar6 & 0xfffffffc) >> (uVar6 & 3) * 8 |
               *(uint *)(uVar6 & 0xfffffffc) << (uVar6 & 3) * -8 + 0x20;
    }
    if ((uVar16 != 0) &&
       (uVar16 = uVar6 + 4 & 3, uVar8 = *(uint *)(uVar6 + 4 & 0xfffffffc),
       (uVar8 >> uVar16 * 8 | uVar8 << uVar16 * -8 + 0x20) != 0xd)) {
      bVar2 = true;
    }
    if (!bVar2) {
      return;
    }
    uVar16 = (uint)*(ushort *)(uVar6 + param_1 * 2 + 0x1e8c);
    if (uVar16 == uRam02045580) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar16 * 0x22c + uVar6 + iRam02045584;
    }
    if (iVar7 == 0) {
      return;
    }
    if (uVar16 == uRam02045580) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar16 * 0x22c + uVar6 + iRam02045584;
    }
    *piVar14 = iVar7;
    uVar6 = uVar3 & 3;
    uVar16 = *(uint *)(uVar3 & 0xfffffffc);
    uVar16 = uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20;
    uVar6 = (uint)*(ushort *)(uVar16 + param_1 * 2 + 0x1e8c);
    if (uVar6 == uRam02045580) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar6 * 0x22c + uVar16 + iRam02045584;
    }
    *piVar13 = iVar7 + 0x14;
    uVar16 = uRam02045580;
    uVar6 = uRam0204557c;
    uVar15 = *(uint *)(uRam0204557c & 0xfffffffc) >> (uRam0204557c & 3) * 8 |
             *(uint *)(uRam0204557c & 0xfffffffc) << (uRam0204557c & 3) * -8 + 0x20;
    uVar8 = (uint)*(ushort *)(uVar15 + param_1 * 2 + 0x1e8c);
    if (uVar8 == uRam02045580) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar8 * 0x22c + uVar15 + iRam02045584;
    }
    *pbVar12 = *(byte *)(iVar7 + 0x214);
    psVar4 = psRam02045588;
    uVar8 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar8 = uVar6 >> uVar8 * 8 | uVar6 << uVar8 * -8 + 0x20;
    uVar6 = (uint)*(ushort *)(uVar8 + param_1 * 2 + 0x1e8c);
    if (uVar6 == uVar16) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar6 * 0x22c + uVar8 + iRam02045584;
    }
    *pbVar11 = (byte)(((uint)*(byte *)(iVar7 + 0x228) << 0x1c) >> 0x1c);
    uVar6 = uRam0204557c;
    bVar17 = *psVar4 == 2;
    if ((!bVar17) &&
       (bVar17 = true,
       uVar16 = *(uint *)(uRam0204557c & 0xfffffffc) >> (uRam0204557c & 3) * 8 |
                *(uint *)(uRam0204557c & 0xfffffffc) << (uRam0204557c & 3) * -8 + 0x20,
       ((uint)*(byte *)(uVar16 + 0x457) & 1 << (*(ushort *)(uVar16 + param_1 * 2 + 0x1e8c) & 0xff))
       == 0)) {
      bVar17 = false;
    }
    if (bVar17) {
      iVar7 = 0;
    }
    else {
      uVar8 = *(uint *)(uRam0204557c & 0xfffffffc) >> (uRam0204557c & 3) * 8 |
              *(uint *)(uRam0204557c & 0xfffffffc) << (uRam0204557c & 3) * -8 + 0x20;
      uVar16 = (uint)*(ushort *)(uVar8 + param_1 * 2 + 0x1e8c);
      if (uVar16 == uRam02045580) {
        iVar7 = 0;
      }
      else {
        iVar7 = uVar16 * 0x22c + uVar8 + iRam02045584;
      }
      iVar7 = iVar7 + 0x218;
    }
    *piVar9 = iVar7;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar16 = uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20;
    uVar6 = (uint)*(ushort *)(uVar16 + param_1 * 2 + 0x1e8c);
    if (uVar6 == uRam02045580) {
      iVar7 = 0;
    }
    else {
      iVar7 = uVar6 * 0x22c + uVar16 + iRam02045584;
    }
    *pbVar10 = *(byte *)(iVar7 + 0x229);
    return;
  }
  if (uVar16 != 2) {
    if (uVar16 != 3) {
      return;
    }
    cVar1 = *(char *)((*(uint *)(uRam0204558c & 0xfffffffc) >> (uRam0204558c & 3) * 8 |
                      *(uint *)(uRam0204558c & 0xfffffffc) << (uRam0204558c & 3) * -8 + 0x20) +
                     (param_1 & 0xff));
    if (cVar1 < '\0') {
      return;
    }
    iVar7 = GetSomeBTKNickname(cVar1);
    *piVar14 = iVar7;
    iVar7 = GetSomeBTKEmblemData(cVar1);
    *piVar13 = iVar7;
    bVar5 = GetSomeBTKUseCustomEmblemFlag(cVar1);
    *pbVar12 = bVar5;
    bVar5 = GetMaybeSomeWifiIdx(cVar1);
    *pbVar11 = bVar5;
    iVar7 = GetSomeBTKFriendCode(cVar1);
    *piVar9 = iVar7;
    bVar5 = GetWorstRankStarValue(cVar1);
    *pbVar10 = bVar5;
    return;
  }
  uVar16 = iVar7 + 0x80;
  uVar8 = uVar16 & 3;
  uVar16 = *(uint *)(uVar16 & 0xfffffffc);
  uVar16 = uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20;
  if (uVar16 == 0) {
    uVar16 = (*(uint *)(uRam02045570 & 0xfffffffc) >> (uRam02045570 & 3) * 8 |
             *(uint *)(uRam02045570 & 0xfffffffc) << (uRam02045570 & 3) * -8 + 0x20) + 0x14;
    uVar8 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    *piVar14 = (uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) + 0xc;
    uVar16 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
             *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 4;
    uVar8 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    *piVar13 = (uVar16 >> uVar8 * 8 | uVar16 << uVar8 * -8 + 0x20) + 8;
    uVar16 = uRam02045570;
    *pbVar12 = uVar6 != 0;
    uVar6 = uVar16 & 3;
    uVar16 = *(uint *)(uVar16 & 0xfffffffc);
    uVar6 = (uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20) + 0x14;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 8;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *pbVar11 = (byte)(((uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) << 0x1c) >> 0x1e);
    *pbVar10 = 0;
    return;
  }
  if (uVar16 != 1) {
    if (uVar16 != 2) {
      return;
    }
    uVar6 = (*(uint *)(uRam02045570 & 0xfffffffc) >> (uRam02045570 & 3) * 8 |
            *(uint *)(uRam02045570 & 0xfffffffc) << (uRam02045570 & 3) * -8 + 0x20) + 0x1c;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *piVar14 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 0xc;
    uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x1c;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *piVar13 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 0x30;
    *pbVar12 = 1;
    uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
            *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x1c;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 8;
    uVar16 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    *pbVar11 = (byte)(((uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) << 0x1c) >> 0x1e);
    *pbVar10 = 1;
    return;
  }
  uVar6 = (*(uint *)(uRam02045570 & 0xfffffffc) >> (uRam02045570 & 3) * 8 |
          *(uint *)(uRam02045570 & 0xfffffffc) << (uRam02045570 & 3) * -8 + 0x20) + 0x18;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *piVar14 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 0xc;
  uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
          *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x18;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *piVar13 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 0x30;
  uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
          *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x18;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 8;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *pbVar12 = (byte)(((uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) << 0x1e) >> 0x1f);
  uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
          *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x18;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  uVar6 = (uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 8;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *pbVar11 = (byte)(((uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) << 0x1c) >> 0x1e);
  uVar6 = (*(uint *)(uVar15 & 0xfffffffc) >> (uVar15 & 3) * 8 |
          *(uint *)(uVar15 & 0xfffffffc) << (uVar15 & 3) * -8 + 0x20) + 0x18;
  uVar16 = uVar6 & 3;
  uVar6 = *(uint *)(uVar6 & 0xfffffffc);
  *pbVar10 = (byte)(((uint)*(byte *)((uVar6 >> uVar16 * 8 | uVar6 << uVar16 * -8 + 0x20) + 0x2f) <<
                    0x1e) >> 0x1e);
  return;
}

