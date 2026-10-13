/* Decompiled C draft; module arm9; ROM address 02023d84. No matching claim. */
#include "types.h"
#include "deps/02023d84_StructCL_SomeFn.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void StructCL_SomeFn(uint param_1)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar12;
  int iVar13;
  uint local_58;
  uint *local_4c;
  uint *local_44;
  int iStack_34;
  undefined1 uStack_30;
  undefined1 uStack_2f;
  int iStack_2c;
  undefined1 uStack_28;
  undefined1 uStack_27;
  uint uVar9;
  uint uVar11;
  
  uVar7 = param_1 + 8 & 3;
  uVar8 = *(uint *)(param_1 + 8 & 0xfffffffc);
  uVar9 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  uVar7 = param_1 + 0xc & 3;
  uVar8 = *(uint *)(param_1 + 0xc & 0xfffffffc);
  uVar7 = uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20;
  local_58 = uVar9;
  if ((int)uVar9 < 0) {
    local_58 = 0;
  }
  uVar8 = param_1 + 0x10 & 3;
  uVar2 = *(uint *)(param_1 + 0x10 & 0xfffffffc);
  iVar13 = uVar9 + (uVar2 >> uVar8 * 8 | uVar2 << uVar8 * -8 + 0x20);
  uVar8 = param_1 + 0x14 & 3;
  uVar3 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  uVar2 = uVar7;
  if ((int)uVar7 < 0) {
    uVar2 = 0;
  }
  iVar6 = uVar7 + (uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20);
  if (7 < iVar13) {
    iVar13 = 8;
  }
  if (7 < iVar6) {
    iVar6 = 8;
  }
  if (0 < (int)uVar7) {
    uVar7 = 0;
  }
  uVar8 = param_1 + 0x20 & 3;
  uVar3 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
  uVar8 = uVar3 >> uVar8 * 8 | uVar3 << uVar8 * -8 + 0x20;
  if (0 < (int)uVar9) {
    uVar9 = 0;
  }
  uVar3 = param_1 + 0x1c & 3;
  uVar10 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
  uVar11 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
  uVar3 = param_1 + 0x18 & 3;
  uVar10 = *(uint *)(param_1 + 0x18 & 0xfffffffc);
  uVar3 = uVar10 >> uVar3 * 8 | uVar10 << uVar3 * -8 + 0x20;
  uVar10 = -uVar7 * uVar3 + uVar11 * -uVar9;
  uVar7 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  uVar7 = uVar9 >> uVar7 * 8 | uVar9 << uVar7 * -8 + 0x20;
  if (uVar8 != 4) {
    uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
            *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
    uVar9 = param_1 + 0x24 & 3;
    uVar12 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
    uVar9 = uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20;
    local_44 = (uint *)(uVar4 + uVar2 * 8);
    puVar1 = (uint *)(uVar4 + iVar6 * 8);
    if (local_44 < puVar1) {
      do {
        iVar6 = (int)uVar10 >> 0x1f;
        uVar12 = *(uint *)((uint)local_44 & 0xfffffffc) >> ((uint)local_44 & 3) * 8 |
                 *(uint *)((uint)local_44 & 0xfffffffc) << ((uint)local_44 & 3) * -8 + 0x20;
        uVar2 = (uint)(local_44 + 1) & 3;
        uVar4 = *(uint *)((uint)(local_44 + 1) & 0xfffffffc);
        uVar4 = uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20;
        iStack_2c = uVar7 + (uVar10 >> 3);
        uStack_28 = 0;
        uStack_27 = uStack_28;
        func_020247fc(&iStack_2c,(uVar10 * 0x20000000 + iVar6 >> 0x1d | iVar6 << 3) - iVar6);
        for (uVar2 = local_58 * uVar8; uVar2 < iVar13 * uVar8; uVar2 = uVar2 + 8) {
          iVar6 = func_020247fc(&iStack_2c,uVar11);
          if (iVar6 != 0) {
            if (uVar2 < 0x20) {
              uVar12 = uVar12 & ~(0xff << (uVar2 & 0xff)) | uVar9 + iVar6 << (uVar2 & 0xff);
            }
            else {
              uVar4 = uVar4 & ~(0xff << (uVar2 - 0x20 & 0xff)) |
                      uVar9 + iVar6 << (uVar2 - 0x20 & 0xff);
            }
          }
        }
        *local_44 = uVar12;
        puVar5 = local_44 + 2;
        local_44[1] = uVar4;
        uVar10 = uVar10 + uVar3;
        local_44 = puVar5;
      } while (puVar5 < puVar1);
      return;
    }
    return;
  }
  uVar4 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  uVar9 = param_1 + 0x24 & 3;
  uVar12 = *(uint *)(param_1 + 0x24 & 0xfffffffc);
  local_4c = (uint *)(uVar4 + uVar2 * 4);
  puVar1 = (uint *)(uVar4 + iVar6 * 4);
  if (local_4c < puVar1) {
    do {
      iVar6 = (int)uVar10 >> 0x1f;
      uVar2 = *(uint *)((uint)local_4c & 0xfffffffc) >> ((uint)local_4c & 3) * 8 |
              *(uint *)((uint)local_4c & 0xfffffffc) << ((uint)local_4c & 3) * -8 + 0x20;
      iStack_34 = uVar7 + (uVar10 >> 3);
      uStack_30 = 0;
      uStack_2f = uStack_30;
      func_020247fc(&iStack_34,(uVar10 * 0x20000000 + iVar6 >> 0x1d | iVar6 << 3) - iVar6);
      for (uVar4 = local_58 * uVar8; uVar4 < iVar13 * uVar8; uVar4 = uVar4 + 4) {
        iVar6 = func_020247fc(&iStack_34,uVar11);
        if (iVar6 != 0) {
          uVar2 = uVar2 & ~(0xf << (uVar4 & 0xff)) |
                  (uVar12 >> uVar9 * 8 | uVar12 << uVar9 * -8 + 0x20) + iVar6 << (uVar4 & 0xff);
        }
      }
      puVar5 = local_4c + 1;
      *local_4c = uVar2;
      uVar10 = uVar10 + uVar3;
      local_4c = puVar5;
    } while (puVar5 < puVar1);
    return;
  }
  return;
}

