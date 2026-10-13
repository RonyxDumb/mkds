/* Decompiled C draft; module arm7; ROM address 0600bddc. No matching claim. */
#include "types.h"
#include "deps/0600bddc_FUN_0600bddc.h"

void FUN_0600bddc(void)

{
  short sVar1;
  ushort uVar2;
  ushort uVar3;
  short sVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  
  iVar12 = DAT_0600c0cc;
  if (*(short *)((*(uint *)(DAT_0600c0c8 & 0xfffffffc) >> (DAT_0600c0c8 & 3) * 8 |
                 *(uint *)(DAT_0600c0c8 & 0xfffffffc) << (DAT_0600c0c8 & 3) * -8 + 0x20) + 0x5f8) !=
      5) {
    iVar12 = DAT_0600c0d0;
  }
  for (uVar8 = 0; uVar8 < 0x69; uVar8 = uVar8 + 1) {
    iVar7 = FUN_06009e58(uVar8,0xff);
    if (iVar7 == -1) {
      uVar8 = 1;
      goto LAB_0600c09c;
    }
  }
  iVar7 = 0;
  uVar9 = 0;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar12 + iVar7 * 2)) {
      iVar7 = iVar7 + 1;
    }
    else {
      sVar1 = FUN_06009e98(uVar6);
      if ((sVar1 != 0xff) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_0600c09c;
    }
    uVar9 = uVar8;
  }
  uVar8 = 0;
  do {
    FUN_06009e58(uVar8,0);
    uVar8 = uVar8 + 1;
  } while (uVar8 < 0x69);
  iVar7 = 0;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar12 + iVar7 * 2)) {
      iVar7 = iVar7 + 1;
    }
    else {
      sVar1 = FUN_06009e98(uVar6);
      if ((sVar1 != 0) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_0600c09c;
    }
    uVar9 = uVar8;
  }
  uVar2 = 0x55;
  uVar8 = 0;
  do {
    FUN_06009e58(uVar8,uVar2);
    uVar8 = uVar8 + 1;
    uVar2 = ~uVar2;
  } while (uVar8 < 0x69);
  uVar2 = 0x55;
  iVar7 = 0;
  for (uVar6 = 0; uVar6 < 0x69; uVar6 = uVar6 + 1) {
    uVar8 = uVar9;
    if (uVar6 == *(ushort *)(iVar12 + iVar7 * 2)) {
      iVar7 = iVar7 + 1;
    }
    else {
      uVar3 = FUN_06009e98(uVar6);
      if ((uVar3 != uVar2) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_0600c09c;
    }
    uVar2 = ~uVar2 & 0xff;
    uVar9 = uVar8;
  }
  sVar1 = 0xff;
  uVar8 = 0;
  do {
    FUN_06009e58(uVar8,sVar1);
    uVar8 = uVar8 + 1;
    sVar1 = sVar1 + -1;
  } while (uVar8 < 0x69);
  sVar1 = 0xff;
  iVar7 = 0;
  for (uVar6 = 0; uVar8 = uVar9, uVar6 < 0x69; uVar6 = uVar6 + 1) {
    if (uVar6 == *(ushort *)(iVar12 + iVar7 * 2)) {
      iVar7 = iVar7 + 1;
    }
    else {
      sVar4 = FUN_06009e98(uVar6);
      if ((sVar4 != sVar1) && (uVar8 = uVar9 + 1, 0x20 < uVar9)) goto LAB_0600c09c;
    }
    sVar1 = sVar1 + -1;
    uVar9 = uVar8;
  }
  iVar7 = 0;
  for (uVar9 = 0; uVar9 < 0x69; uVar9 = uVar9 + 1) {
    uVar6 = uVar8;
    if (uVar9 == *(ushort *)(iVar12 + iVar7 * 2)) {
      iVar7 = iVar7 + 1;
    }
    else {
      uVar10 = 1;
      for (uVar11 = 0; uVar11 < 9; uVar11 = uVar11 + 1) {
        FUN_06009e58(uVar9,uVar10);
        uVar5 = FUN_06009e98(uVar9);
        uVar8 = uVar6;
        if (((uVar5 & 0xffff) != uVar10) && (uVar8 = uVar6 + 1, 0x20 < uVar6)) goto LAB_0600c09c;
        uVar10 = ((uVar10 & 0x7f) << 0x11) >> 0x10;
        uVar6 = uVar8;
      }
    }
    uVar8 = uVar6;
  }
LAB_0600c09c:
  if (uVar8 != 0) {
    uVar8 = *(uint *)(DAT_0600c0c8 & 0xfffffffc) >> (DAT_0600c0c8 & 3) * 8 |
            *(uint *)(DAT_0600c0c8 & 0xfffffffc) << (DAT_0600c0c8 & 3) * -8 + 0x20;
    *(ushort *)(uVar8 + 0x33e) = *(ushort *)(uVar8 + 0x33e) | 8;
  }
  return;
}

