/* Decompiled C draft; module arm9; ROM address 020224e0. No matching claim. */
#include "types.h"
#include "deps/020224e0_MaybeMakeOamSlot.h"

uint MaybeMakeOamSlot(int param_1,uint param_2,ushort *param_3,uint param_4,uint param_5,
                     ushort param_6,int param_7)

{
  ushort uVar1;
  int iVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint *puVar8;
  uint uVar9;
  int iVar11;
  uint uVar12;
  uint local_58;
  uint local_50;
  uint local_4c;
  int local_38;
  int local_34;
  uint uVar10;
  
  if (*param_3 <= param_2) {
    param_2 = (uint)*param_3;
  }
  local_58 = 0;
  if (param_2 != 0) {
    local_4c = 0x100;
    local_50 = 0x300;
    do {
      uVar10 = (uint)(param_3 + 2) & 3;
      uVar9 = *(uint *)((uint)(param_3 + 2) & 0xfffffffc);
      uVar10 = uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20;
      puVar8 = (uint *)(param_1 + local_58 * 8);
      iVar11 = uVar10 + local_58 * 6;
      *(undefined2 *)(param_1 + local_58 * 8) = *(undefined2 *)(uVar10 + local_58 * 6);
      *(undefined2 *)((int)puVar8 + 2) = *(undefined2 *)(iVar11 + 2);
      *(undefined2 *)(puVar8 + 1) = *(undefined2 *)(iVar11 + 4);
      if ((param_4 != 0) || (param_5 != 0)) {
        uVar10 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                 *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                 uRam02022874;
        local_38 = (int)uVar10 >> 0x10;
        if (0xff < local_38) {
          local_38 = (int)(short)((ushort)(uVar10 >> 0x10) | 0xff00);
        }
        local_38 = local_38 * 0x1000;
        uVar1 = ((ushort)(*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8) |
                (ushort)(*(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20)) &
                0xff;
        uVar10 = (uint)(short)uVar1;
        if (0x7f < uVar10) {
          uVar10 = (uint)(short)(uVar1 | 0xff00);
        }
        local_34 = uVar10 * 0x1000;
        if (param_4 != 0) {
          uVar10 = *(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                   *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20;
          uVar9 = uVar10 & 0x300;
          if ((uVar9 != 0x100) && (uVar9 != 0x300)) {
            uVar9 = uVar10 & 0x30000300;
          }
          if (uVar9 == 0x300) {
            iVar7 = (int)(uVar10 & uRam02022878 & 0xc000) >> 0xe;
            iVar11 = ((uVar10 & uRam02022878) >> 0x1e) * 2;
            local_38 = local_38 + (uint)*(ushort *)(iVar11 + iRam0202287c + iVar7 * 8) * 0x800;
            local_34 = local_34 + (uint)*(ushort *)(iVar11 + iRam02022880 + iVar7 * 8) * 0x800;
          }
          uVar10 = param_4 + 8 & 3;
          uVar6 = *(uint *)(param_4 + 8 & 0xfffffffc);
          uVar9 = local_50;
          if (param_7 == 0) {
            uVar9 = local_4c;
          }
          lVar3 = (longlong)local_38 *
                  (longlong)
                  (int)(*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
                       *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) +
                  (longlong)(int)(uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) *
                  (longlong)local_34 + 0x1000;
          uVar10 = param_4 + 0xc & 3;
          uVar5 = *(uint *)(param_4 + 0xc & 0xfffffffc);
          uVar6 = param_4 + 4 & 3;
          uVar12 = *(uint *)(param_4 + 4 & 0xfffffffc);
          lVar4 = (longlong)local_38 *
                  (longlong)(int)(uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) +
                  (longlong)(int)(uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) *
                  (longlong)local_34 + 0x1000;
          if ((uVar9 == 0x100) || (uVar9 == 0x300)) {
            *puVar8 = (uint)param_6 << 0x19 |
                      (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                      *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                      uRam02022884 | uVar9;
          }
          else {
            *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                      *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                      uRam02022884 | uVar9;
          }
          uVar10 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                   *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                   uRam02022878;
          iVar7 = (int)(uVar10 & 0xc000) >> 0xe;
          iVar11 = (uVar10 >> 0x1e) * 2;
          iVar2 = (int)(uint)*(ushort *)(iVar11 + iRam0202287c + iVar7 * 8) >> 1;
          iVar11 = (int)(uint)*(ushort *)(iVar11 + iRam02022880 + iVar7 * 8) >> 1;
          uVar10 = param_4 + 8 & 3;
          uVar6 = *(uint *)(param_4 + 8 & 0xfffffffc);
          local_38 = ((uint)lVar3 >> 0xc | (int)((ulonglong)lVar3 >> 0x20) << 0x14) +
                     (uVar6 >> uVar10 * 8 | uVar6 << uVar10 * -8 + 0x20) * iVar11 +
                     (*(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
                     *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20) * iVar2 +
                     iVar2 * -0x1000;
          uVar10 = param_4 + 4 & 3;
          uVar5 = *(uint *)(param_4 + 4 & 0xfffffffc);
          uVar6 = param_4 + 0xc & 3;
          uVar12 = *(uint *)(param_4 + 0xc & 0xfffffffc);
          iVar7 = local_38;
          if (uVar9 == 0x300) {
            iVar7 = local_38 + iVar2 * -0x1000;
          }
          local_34 = ((uint)lVar4 >> 0xc | (int)((ulonglong)lVar4 >> 0x20) << 0x14) +
                     (uVar12 >> uVar6 * 8 | uVar12 << uVar6 * -8 + 0x20) * iVar11 +
                     (uVar5 >> uVar10 * 8 | uVar5 << uVar10 * -8 + 0x20) * iVar2 + iVar11 * -0x1000;
          if (uVar9 == 0x300) {
            local_34 = local_34 + iVar11 * -0x1000;
            local_38 = iVar7;
          }
        }
        if (param_5 != 0) {
          local_38 = local_38 +
                     (*(uint *)(param_5 & 0xfffffffc) >> (param_5 & 3) * 8 |
                     *(uint *)(param_5 & 0xfffffffc) << (param_5 & 3) * -8 + 0x20);
          uVar10 = param_5 + 4 & 3;
          uVar9 = *(uint *)(param_5 + 4 & 0xfffffffc);
          local_34 = local_34 + (uVar9 >> uVar10 * 8 | uVar9 << uVar10 * -8 + 0x20);
        }
        *puVar8 = (*(uint *)((uint)puVar8 & 0xfffffffc) >> ((uint)puVar8 & 3) * 8 |
                  *(uint *)((uint)puVar8 & 0xfffffffc) << ((uint)puVar8 & 3) * -8 + 0x20) &
                  uRam0202288c | local_34 + 0x800 >> 0xc & 0xffU |
                  (uRam02022888 & local_38 + 0x800 >> 0xc) << 0x10;
      }
      local_58 = local_58 + 1 & 0xffff;
    } while (local_58 < param_2);
  }
  return param_2;
}

