/* Decompiled C draft; module arm7; ROM address 06013ebc. No matching claim. */
#include "types.h"
#include "deps/06013ebc_FUN_06013ebc.h"

void FUN_06013ebc(void)

{
  ushort uVar1;
  short sVar2;
  undefined2 uVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined2 *puVar7;
  uint uVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  undefined2 *puVar12;
  
  uVar4 = *(uint *)(DAT_06014210 & 0xfffffffc) >> (DAT_06014210 & 3) * 8 |
          *(uint *)(DAT_06014210 & 0xfffffffc) << (DAT_06014210 & 3) * -8 + 0x20;
  uVar8 = uVar4 + 0x4ac & 3;
  uVar11 = *(uint *)(uVar4 + 0x4ac & 0xfffffffc);
  puVar12 = (undefined2 *)(uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20);
  *puVar12 = 0;
  puVar12[1] = 0;
  puVar12[2] = 0;
  puVar12[3] = 0;
  uVar3 = FUN_0600a450();
  puVar12[4] = uVar3;
  puVar12[6] = 0x80;
  puVar12[7] = 0;
  FUN_0600a8d4(puVar12 + 8,(undefined2 *)(uintptr_t)(DAT_06014214),(undefined2 *)(uintptr_t)(uVar4 + 0x324),(undefined2 *)(uintptr_t)(uVar4 + 0x324));
  puVar12[0x11] = 0;
  sVar2 = (short)puVar12 + 0x24;
  *(undefined4 *)(puVar12 + 0x12) = 0;
  *(undefined4 *)(puVar12 + 0x14) = 0;
  puVar12[0x16] = *(undefined2 *)(uVar4 + 0x3b2);
  puVar12[0x17] = *(undefined2 *)(uVar4 + 0x3c0);
  puVar7 = puVar12 + 0x18;
  if ((int)((uint)*(ushort *)(uVar4 + 0x33a) << 0x1f) < 0) {
    *(undefined2 *)(uVar4 + 0x3d6) = 0;
  }
  else {
    *(short *)(uVar4 + 0x3d6) = (short)puVar7 - sVar2;
    FUN_060096e4(puVar7);
    puVar7 = puVar12 + 0x19;
    FUN_060096e4((ushort *)(uintptr_t)((int)puVar12 + 0x31),*(ushort *)(uVar4 + 0x362) & 0xff);
    for (uVar8 = 0; uVar8 < *(ushort *)(uVar4 + 0x362); uVar8 = uVar8 + 1) {
      uVar6 = FUN_060096c4((ushort *)(uintptr_t)(uVar4 + 0x364 + uVar8));
      FUN_060096e4(puVar7,uVar6);
      puVar7 = (undefined2 *)((int)puVar7 + 1);
    }
    FUN_060096e4((ushort *)(uintptr_t)((int)puVar7 + (-1 - uVar8)),uVar8 & 0xff);
  }
  iVar5 = FUN_060133fc((int)(uintptr_t)(puVar7));
  iVar5 = (int)puVar7 + iVar5;
  FUN_060096e4((ushort *)(uintptr_t)(iVar5),3);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 1),1);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 2),*(ushort *)(uVar4 + 0x3be) & 0xff);
  *(short *)(uVar4 + 0x3d8) = (short)(iVar5 + 3) - sVar2;
  *DAT_06014218 = *(short *)(uVar4 + 0x3d8) + 2;
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 3),5);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 4),5);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 5),0);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 6),*(ushort *)(uVar4 + 0x3b8) & 0xff);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 7),0);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 8),0);
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 9),0);
  *(short *)(uVar4 + 0x3da) = (short)(iVar5 + 10) - sVar2;
  *(ushort *)(uVar4 + 0x3e6) = *(ushort *)(uVar4 + 0x3da) & 1;
  FUN_060096e4((ushort *)(uintptr_t)(iVar5 + 10),0xdd);
  FUN_060096e4(iVar5 + 0xb,*(short *)(uVar4 + 0x3e4) + 8U & 0xff);
  FUN_060096e4(iVar5 + 0xc,0);
  FUN_060096e4(iVar5 + 0xd,9);
  FUN_060096e4(iVar5 + 0xe,0xbf);
  FUN_060096e4(iVar5 + 0xf,0);
  if (*(short *)(uVar4 + 0x352) == 1) {
    FUN_060096e4(iVar5 + 0x10,*(ushort *)(uVar4 + 0x33c) & 0xff);
    FUN_060096e4(iVar5 + 0x11,(int)(uint)*(ushort *)(uVar4 + 0x33c) >> 8);
  }
  else {
    FUN_060096e4(iVar5 + 0x10,0xff);
    FUN_060096e4(iVar5 + 0x11,0xff);
  }
  uVar1 = *DAT_0601421c;
  FUN_060096e4(iVar5 + 0x12,uVar1 & 0xff);
  iVar10 = iVar5 + 0x14;
  FUN_060096e4(iVar5 + 0x13,uVar1 >> 8);
  uVar8 = uVar4 + 0x3e0 & 3;
  uVar11 = *(uint *)(uVar4 + 0x3e0 & 0xfffffffc);
  uVar11 = uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20;
  for (uVar8 = 0; uVar8 < *(ushort *)(uVar4 + 0x3e4); uVar8 = uVar8 + 1) {
    uVar6 = FUN_060096c4(uVar11);
    FUN_060096e4(iVar10,uVar6);
    iVar10 = iVar10 + 1;
    uVar11 = uVar11 + 1;
  }
  if (*(short *)(uVar4 + 0x3e6) != 0) {
    uVar8 = uVar4 + 0x3e0 & 3;
    uVar11 = *(uint *)(uVar4 + 0x3e0 & 0xfffffffc);
    iVar5 = (uVar11 >> uVar8 * 8 | uVar11 << uVar8 * -8 + 0x20) + (uint)*(ushort *)(uVar4 + 0x3e4);
    for (uVar9 = 0; uVar9 < *(ushort *)(uVar4 + 0x3e4); uVar9 = uVar9 + 1) {
      uVar6 = FUN_060096c4(iVar5 + -1);
      FUN_060096e4(iVar5,uVar6);
      iVar5 = iVar5 + -1;
    }
  }
  if ((*(ushort *)
        ((*(uint *)(DAT_06014210 & 0xfffffffc) >> (DAT_06014210 & 3) * 8 |
         *(uint *)(DAT_06014210 & 0xfffffffc) << (DAT_06014210 & 3) * -8 + 0x20) + 0x690) & 4) != 0)
  {
    puVar7 = (undefined2 *)(iVar10 + 3U & 0xfffffffc);
    *puVar7 = (short)DAT_06014220;
    puVar7[1] = (short)DAT_06014224;
  }
  *(undefined2 *)(uVar4 + 1000) = 0;
  puVar12[5] = ((short)iVar10 + 0x1c) - sVar2;
  return;
}

