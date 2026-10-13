/* Decompiled C draft; module arm9; ROM address 020e6854. No matching claim. */
#include "types.h"
#include "deps/020e6854_func_020e6854.h"

void func_020e6854(uint param_1,uint param_2,int param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  ushort uVar7;
  longlong lVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  uVar1 = param_1 + 8 & 3;
  uVar9 = *(uint *)(param_1 + 8 & 0xfffffffc);
  local_24 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  local_20 = local_24;
  local_1c = local_24;
  func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_24),3);
  uVar1 = param_1 + 0x14 & 3;
  uVar9 = *(uint *)(param_1 + 0x14 & 0xfffffffc);
  local_28 = uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20;
  uVar1 = (local_28 & 0x1f0000) >> 0x10;
  if (param_4 < uVar1) {
    local_28 = local_28 & 0xffe0ffff | param_4 << 0x10;
    iVar10 = func_020d3c44();
    local_28 = local_28 & 0xc0ffffff | iVar10 << 0x18;
  }
  else if (param_3 != 0) {
    uVar9 = param_2 + 4 & 3;
    uVar13 = *(uint *)(param_2 + 4 & 0xfffffffc);
    uVar16 = *(uint *)(uRam020e69b8 & 0xfffffffc) >> (uRam020e69b8 & 3) * 8 |
             *(uint *)(uRam020e69b8 & 0xfffffffc) << (uRam020e69b8 & 3) * -8 + 0x20;
    uVar2 = uVar16 + 0x14 & 3;
    uVar11 = *(uint *)(uVar16 + 0x14 & 0xfffffffc);
    uVar3 = uVar16 + 8 & 3;
    uVar15 = *(uint *)(uVar16 + 8 & 0xfffffffc);
    uVar4 = param_2 + 8 & 3;
    uVar14 = *(uint *)(param_2 + 8 & 0xfffffffc);
    uVar5 = uVar16 + 0x20 & 3;
    uVar12 = *(uint *)(uVar16 + 0x20 & 0xfffffffc);
    uVar6 = uVar16 + 0x2c & 3;
    uVar16 = *(uint *)(uVar16 + 0x2c & 0xfffffffc);
    lVar8 = (longlong)(int)(uVar12 >> uVar5 * 8 | uVar12 << uVar5 * -8 + 0x20) *
            (longlong)(int)(uVar14 >> uVar4 * 8 | uVar14 << uVar4 * -8 + 0x20) +
            (longlong)(int)(uVar15 >> uVar3 * 8 | uVar15 << uVar3 * -8 + 0x20) *
            (longlong)
            (int)(*(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                 *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20) +
            (longlong)(int)(uVar13 >> uVar9 * 8 | uVar13 << uVar9 * -8 + 0x20) *
            (longlong)(int)(uVar11 >> uVar2 * 8 | uVar11 << uVar2 * -8 + 0x20);
    uVar9 = (int)-((uVar16 >> uVar6 * 8 | uVar16 << uVar6 * -8 + 0x20) +
                  ((uint)lVar8 >> 0xc | (int)((ulonglong)lVar8 >> 0x20) << 0x14)) >> 9;
    if (uVar9 < uVar1) {
      if (uVar9 == 0) {
        uVar9 = 1;
      }
      local_28 = local_28 & 0xffe0ffff | uVar9 << 0x10;
      iVar10 = func_020d3c44();
      local_28 = local_28 & 0xc0ffffff | iVar10 << 0x18;
    }
  }
  func_01ff9048(0x29,(undefined4)(uintptr_t)(&local_28),1);
  if (*(short *)(param_1 + 0x1a) != 1) {
    uVar7 = *(ushort *)(param_1 + 0x18);
    uVar1 = param_1 + 0x20 & 3;
    uVar9 = *(uint *)(param_1 + 0x20 & 0xfffffffc);
    func_01ff9048(0x2b,(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + (uint)uVar7 * 4,1);
    uVar1 = param_1 + 0x1c & 3;
    uVar9 = *(uint *)(param_1 + 0x1c & 0xfffffffc);
    func_01ff9048(0x2a,(uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20) + (uint)uVar7 * 4,1);
  }
  uVar1 = param_1 + 4 & 3;
  uVar9 = *(uint *)(param_1 + 4 & 0xfffffffc);
  func_01ff9144(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20,
                uVar9 >> uVar1 * 8 | uVar9 << uVar1 * -8 + 0x20);
  return;
}

