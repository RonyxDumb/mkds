/* Decompiled C draft; module arm7; ROM address 0600f234. No matching claim. */
#include "types.h"
#include "deps/0600f234_FUN_0600f234.h"

void FUN_0600f234(void)

{
  undefined2 uVar1;
  uint uVar2;
  uint uVar3;
  ushort uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  ushort uVar8;
  uint *puVar9;
  int in_r12;
  
  uVar2 = DAT_0600f528;
  uVar5 = *(uint *)(DAT_0600f528 & 0xfffffffc) >> (DAT_0600f528 & 3) * 8 |
          *(uint *)(DAT_0600f528 & 0xfffffffc) << (DAT_0600f528 & 3) * -8 + 0x20;
  puVar9 = (uint *)(uVar5 + DAT_0600f52c);
  uVar4 = 0;
  uVar8 = 0;
  if ((short)puVar9[1] != 0) {
    return;
  }
  uVar5 = uVar5 + 0x200;
  uVar7 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  *puVar9 = uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20;
  uVar5 = *(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
          *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20;
  if (uVar5 == 0xffffffff) {
    return;
  }
  iVar6 = uVar5 + (uint)*(ushort *)(uVar5 + 0xe) * 2;
  uVar7 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20;
  if (*(short *)(uVar2 + 0x33e) == 0) {
    uVar7 = (uint)*(ushort *)(uVar5 + 0xc);
    if (uVar7 == *(ushort *)(iVar6 + 0x10)) {
      uVar3 = uVar7 & 0xff00;
      if (uVar3 < 0x101) {
        if (uVar3 < 0x100) {
          if ((*(ushort *)(uVar5 + 0xc) & 0xff00) != 0) goto LAB_0600f434;
          uVar8 = 1;
          uVar7 = uVar7 & 0xff;
          uVar3 = 0xb;
          in_r12 = DAT_0600f530;
          if ((puVar9[1] & 1) == 0) {
            uVar4 = (ushort)(*(ushort *)(uVar2 + 0x34c) < 0x20);
          }
          else {
            uVar4 = 2;
          }
        }
        else {
          uVar8 = 2;
          uVar7 = uVar7 & 0xff;
          uVar3 = 5;
          uVar4 = (ushort)(*(short *)(uVar2 + 0x34c) != 0x40);
          in_r12 = DAT_0600f534;
        }
      }
      else if (uVar3 < 0x201) {
        if (uVar3 == 0x200) {
          uVar7 = uVar7 & 0xff;
          if (uVar7 < 0x40) {
            uVar4 = (ushort)(*(ushort *)(uVar2 + 0x34c) < 0x10);
            uVar8 = 4;
            uVar3 = 0x17;
            in_r12 = DAT_0600f538;
          }
          else if (uVar7 < 0x80) {
            uVar4 = (ushort)(*(short *)(uVar2 + 0x34c) != 0x40);
            uVar8 = 8;
            uVar7 = uVar7 - 0x40 & 0xffff;
            uVar3 = 6;
            in_r12 = DAT_0600f53c;
          }
          else if (uVar7 < 0xc0) {
            uVar4 = (ushort)(*(ushort *)(uVar2 + 0x34c) < 0x10);
            uVar8 = 0x10;
            uVar7 = uVar7 - 0x80 & 0xffff;
            uVar3 = 0x17;
            in_r12 = DAT_0600f540;
          }
          else {
            uVar4 = (ushort)(*(ushort *)(uVar2 + 0x34c) < 0x10);
            uVar8 = 0x20;
            uVar7 = uVar7 - 0xc0 & 0xffff;
            uVar3 = 6;
            in_r12 = DAT_0600f544;
          }
        }
        else {
LAB_0600f434:
          uVar7 = 1;
          uVar3 = 0;
          uVar8 = 0;
        }
      }
      else {
        if (uVar3 != 0x300) goto LAB_0600f434;
        uVar8 = 0x40;
        uVar7 = uVar7 & 0xff;
        uVar3 = 10;
        in_r12 = DAT_0600f548;
      }
      if (uVar3 < uVar7) {
        uVar4 = 3;
      }
      else if ((*(ushort *)(uVar5 + 0xe) < *(ushort *)(in_r12 + uVar7 * 8)) ||
              (*(ushort *)(iVar6 + 0x12) < *(ushort *)(in_r12 + uVar7 * 8 + 2))) {
        uVar4 = 4;
      }
      if (uVar4 == 0) {
        *(ushort *)(puVar9 + 1) = (ushort)puVar9[1] | uVar8;
        uVar2 = in_r12 + uVar7 * 8 + 4;
        uVar7 = uVar2 & 3;
        uVar2 = *(uint *)(uVar2 & 0xfffffffc);
        uVar1 = (*(code *)(uVar2 >> uVar7 * 8 | uVar2 << uVar7 * -8 + 0x20))
                          (uVar5,(ushort *)(iVar6 + 0x10));
        *(undefined2 *)(iVar6 + 0x14) = uVar1;
        if (*(short *)(iVar6 + 0x14) == 0x80) {
          return;
        }
        if (*(short *)(iVar6 + 0x14) == 0x81) {
          *(ushort *)(puVar9 + 1) = (ushort)puVar9[1] & ~uVar8;
          goto LAB_0600f4f8;
        }
      }
      else {
        *(undefined2 *)(iVar6 + 0x12) = 1;
        *(ushort *)(iVar6 + 0x14) = uVar4;
      }
    }
    else {
      *(undefined2 *)(iVar6 + 0x14) = 0xd;
    }
  }
  else {
    *(undefined2 *)(iVar6 + 0x12) = 1;
    *(undefined2 *)(iVar6 + 0x14) = 6;
  }
  *(ushort *)(puVar9 + 1) = (ushort)puVar9[1] & ~uVar8;
  FUN_0600f19c((*(uint *)(DAT_0600f528 & 0xfffffffc) >> (DAT_0600f528 & 3) * 8 |
               *(uint *)(DAT_0600f528 & 0xfffffffc) << (DAT_0600f528 & 3) * -8 + 0x20) + 0x200,
               *(uint *)((uint)puVar9 & 0xfffffffc) >> ((uint)puVar9 & 3) * 8 |
               *(uint *)((uint)puVar9 & 0xfffffffc) << ((uint)puVar9 & 3) * -8 + 0x20);
LAB_0600f4f8:
  if (*(short *)((*(uint *)(DAT_0600f528 & 0xfffffffc) >> (DAT_0600f528 & 3) * 8 |
                 *(uint *)(DAT_0600f528 & 0xfffffffc) << (DAT_0600f528 & 3) * -8 + 0x20) + 0x208) !=
      0) {
    FUN_06008a8c(2,0xb);
  }
  return;
}

