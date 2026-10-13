/* Decompiled C draft; module arm9; ROM address 02011928. No matching claim. */
#include "types.h"
#include "deps/02011928_func_02011928.h"

/* WARNING: Type propagation algorithm not settling */

void func_02011928(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  uint uVar5;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint unaff_r6;
  undefined4 local_58;
  uint local_54 [4];
  undefined1 auStack_44 [36];
  int local_20;
  int local_1c;
  undefined4 local_18;
  uint uVar6;
  
  uVar6 = (uint)(param_1 + 2) & 3;
  uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
  if (((uVar6 & 0x200) == 0) && ((uVar6 & 1) != 0)) {
    uVar6 = (uint)(param_1 + 0x2c) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
    uVar9 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = uVar9 + 0x10;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    uVar6 = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
    if ((uVar6 & 0xc0000000) != 0x80000000) {
      *(uint *)(uVar9 + 0x10) = uVar6 & 0x3fffffff;
      uVar4 = uRam02011bac;
      uVar9 = uRam02011ba8;
      uVar6 = (uint)(param_1 + 0x2c) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
      uVar10 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      uVar6 = uVar10 + 0x10;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar10 + 0x10) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20 | 0x80000000;
      uVar6 = (uint)(param_1 + 0x2c) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
      uVar10 = *(uint *)(uVar9 & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) + 0x10;
      uVar5 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      *(uint *)(uVar9 + 4) = uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20;
      func_01ff9048(uVar10 >> (uVar9 & 3) * 8 | uVar10 << (uVar9 & 3) * -8 + 0x20,uVar4,1);
    }
    local_58 = 3;
    func_01ff9048(0x10,(undefined4)(uintptr_t)(&local_58),1);
    uVar6 = (uint)(param_1 + 0xf) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0xf) & 0xfffffffc);
    bVar2 = uVar5 >> uVar6 * 8 != 0;
    bVar3 = uVar5 << uVar6 * -8 + 0x20 != 0;
    uVar6 = (uint)(param_1 + 0x2c) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
    uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    if (bVar2 || bVar3) {
      unaff_r6 = (uint)*(byte *)(param_1 + 0x26);
    }
    uVar5 = (uint)*(ushort *)(uVar6 + 0x2c);
    uVar6 = (uint)*(ushort *)(uVar6 + 0x2e);
    local_20 = uVar5 << 0xf;
    local_1c = uVar6 * -0x8000;
    if (!bVar2 && !bVar3) {
      unaff_r6 = 0;
    }
    local_18 = 0x10000;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_20),3);
    local_54[0] = (int)(uVar5 << 0x13) >> 0x10 & 0xffffU | ((int)(uVar6 << 0x13) >> 0x10) << 0x10;
    func_01ff9048(0x22,(undefined4)(uintptr_t)(local_54),1);
    uVar6 = (uint)(param_1 + 0x36) & 3;
    uVar5 = *(uint *)((uint)(param_1 + 0x36) & 0xfffffffc);
    uVar9 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
    uVar6 = (uint)*(ushort *)(uVar9 + 4 + (uint)*(ushort *)(uVar9 + 10)) *
            (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20
                            ) + 1) + uVar9 + 4 + (uint)*(ushort *)(uVar9 + 10) + 4;
    uVar5 = uVar6 & 3;
    uVar6 = *(uint *)(uVar6 & 0xfffffffc);
    iVar7 = uVar9 + (uVar6 >> uVar5 * 8 | uVar6 << uVar5 * -8 + 0x20);
    uVar1 = *(ushort *)(iVar7 + 0x1e);
    if ((uVar1 & 0x2000) != 0) {
      iVar8 = iVar7 + 0x2c;
      if ((uVar1 & 2) == 0) {
        iVar8 = iVar7 + 0x34;
      }
      if ((uVar1 & 4) == 0) {
        iVar8 = iVar8 + 4;
      }
      if ((uVar1 & 8) == 0) {
        iVar8 = iVar8 + 8;
      }
      func_01ff9048(0x18,iVar8,0x10);
    }
    if (unaff_r6 == 3) {
      uVar6 = (uint)(param_1 + 2) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0xffffffbf;
      uVar6 = (uint)(param_1 + 0xf) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 0xf) & 0xfffffffc);
      (*(code *)(uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20))(param_1);
      uVar6 = (uint)(param_1 + 2) & 3;
      uVar5 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar6 = (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) & 0x40;
    }
    else {
      uVar6 = 0;
    }
    if (uVar6 == 0) {
      local_54[1] = 2;
      func_01ff9048(0x10,(undefined4)(uintptr_t)(local_54 + 1),1);
      func_02012f58(0,(int)(uintptr_t)(auStack_44));
      local_54[2] = 3;
      func_01ff9048(0x10,(undefined4)(uintptr_t)(local_54 + 2),1);
      uVar6 = iRam02011bb0 + 0xfcU & 3;
      uVar5 = *(uint *)(iRam02011bb0 + 0xfcU & 0xfffffffc);
      uVar6 = uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20;
      if ((uVar6 & 1) == 0) {
        if ((uVar6 & 2) == 0) {
          func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_44),9);
        }
        else {
          func_01ff9048(0x1a,uRam02011bb4,9);
          func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_44),9);
        }
      }
      else {
        func_01ff9048(0x1a,uRam02011bb4,9);
        func_01ff9048(0x1a,uRam02011bb8,9);
        func_01ff9048(0x1a,(undefined4)(uintptr_t)(auStack_44),9);
      }
    }
    local_54[3] = 2;
    func_01ff9048(0x10,(undefined4)(uintptr_t)(local_54 + 3),1);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 3;
  return;
}

