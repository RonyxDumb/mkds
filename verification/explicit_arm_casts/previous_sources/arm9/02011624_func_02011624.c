/* Decompiled C draft; module arm9; ROM address 02011624. No matching claim. */
#include "types.h"
#include "deps/02011624_func_02011624.h"

/* WARNING: Type propagation algorithm not settling */

void func_02011624(int *param_1)

{
  ushort uVar1;
  bool bVar2;
  bool bVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  int iVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint unaff_r4;
  undefined4 local_90;
  uint local_8c [3];
  undefined1 auStack_80 [48];
  undefined1 auStack_50 [48];
  int local_20;
  int local_1c;
  uint uVar9;
  
  uVar9 = (uint)(param_1 + 2) & 3;
  uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
  if (((uVar9 & 0x200) == 0) && ((uVar9 & 1) != 0)) {
    func_02012f58(auStack_80,0);
    local_90 = 0x1e;
    func_01ff9048(0x13,&local_90,1);
    uVar9 = (uint)(param_1 + 0x2c) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
    uVar12 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    uVar9 = uVar12 + 0x10;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    uVar9 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
    if ((uVar9 & 0xc0000000) != 0xc0000000) {
      *(uint *)(uVar12 + 0x10) = uVar9 & 0x3fffffff;
      uVar7 = uRam02011904;
      uVar12 = uRam02011900;
      uVar9 = (uint)(param_1 + 0x2c) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
      uVar13 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      uVar9 = uVar13 + 0x10;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      *(uint *)(uVar13 + 0x10) = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20 | 0xc0000000;
      uVar9 = (uint)(param_1 + 0x2c) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
      uVar13 = *(uint *)(uVar12 & 0xfffffffc);
      uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) + 0x10;
      uVar8 = uVar9 & 3;
      uVar9 = *(uint *)(uVar9 & 0xfffffffc);
      unaff_r4 = uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20;
      *(uint *)(uVar12 + 4) = unaff_r4;
      func_01ff9048(uVar13 >> (uVar12 & 3) * 8 | uVar13 << (uVar12 & 3) * -8 + 0x20,uVar7,1);
    }
    piVar4 = piRam02011908;
    uVar9 = (uint)(param_1 + 0x10) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0x10) & 0xfffffffc);
    bVar2 = uVar8 >> uVar9 * 8 != 0;
    bVar3 = uVar8 << uVar9 * -8 + 0x20 != 0;
    uVar9 = (uint)(param_1 + 0x2c) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0x2c) & 0xfffffffc);
    uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    if (bVar2 || bVar3) {
      unaff_r4 = (uint)*(byte *)((int)param_1 + 0x99);
    }
    uVar8 = (uint)*(ushort *)(uVar9 + 0x2e);
    iVar10 = (uint)*(ushort *)(uVar9 + 0x2c) << 0xf;
    piRam02011908[0xd] = uVar8 << 0xf;
    *piVar4 = iVar10;
    piVar4[5] = uVar8 * -0x8000;
    piVar4[0xc] = iVar10;
    if (!bVar2 && !bVar3) {
      unaff_r4 = 0;
    }
    func_01ff9048(0x16,piVar4,0x10);
    uVar9 = (uint)(param_1 + 0x36) & 3;
    uVar8 = *(uint *)((uint)(param_1 + 0x36) & 0xfffffffc);
    uVar12 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
    uVar9 = (uint)*(ushort *)(uVar12 + 4 + (uint)*(ushort *)(uVar12 + 10)) *
            (uint)*(byte *)((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
                            *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20
                            ) + 1) + uVar12 + 4 + (uint)*(ushort *)(uVar12 + 10) + 4;
    uVar8 = uVar9 & 3;
    uVar9 = *(uint *)(uVar9 & 0xfffffffc);
    iVar10 = uVar12 + (uVar9 >> uVar8 * 8 | uVar9 << uVar8 * -8 + 0x20);
    uVar1 = *(ushort *)(iVar10 + 0x1e);
    if ((uVar1 & 0x2000) != 0) {
      iVar11 = iVar10 + 0x2c;
      if ((uVar1 & 2) == 0) {
        iVar11 = iVar10 + 0x34;
      }
      if ((uVar1 & 4) == 0) {
        iVar11 = iVar11 + 4;
      }
      if ((uVar1 & 8) == 0) {
        iVar11 = iVar11 + 8;
      }
      func_01ff9048(0x18,iVar11,0x10);
    }
    if (unaff_r4 == 3) {
      uVar9 = (uint)(param_1 + 2) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      param_1[2] = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 0xffffffbf;
      uVar9 = (uint)(param_1 + 0x10) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 0x10) & 0xfffffffc);
      (*(code *)(uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20))(param_1);
      uVar9 = (uint)(param_1 + 2) & 3;
      uVar8 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
      uVar9 = (uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20) & 0x40;
    }
    else {
      uVar9 = 0;
    }
    if (uVar9 == 0) {
      uVar9 = iRam0201190c + 0xfcU & 3;
      uVar8 = *(uint *)(iRam0201190c + 0xfcU & 0xfffffffc);
      uVar9 = uVar8 >> uVar9 * 8 | uVar8 << uVar9 * -8 + 0x20;
      if ((uVar9 & 1) == 0) {
        if ((uVar9 & 2) == 0) {
          uVar7 = func_02010ed4();
          func_01ff9048(0x19,uVar7,0xc);
          func_01ff9048(0x19,auStack_80,0xc);
        }
        else {
          func_01ff9048(0x19,auStack_80,0xc);
        }
      }
      else {
        func_01ff9048(0x1c,uRam02011910,3);
        func_01ff9048(0x1a,uRam02011914,9);
        func_01ff9048(0x19,auStack_80,0xc);
      }
      func_01ff9234();
      puVar5 = puRam0201191c;
      *puRam02011918 = 0;
      puVar6 = puRam02011920;
      *puVar5 = 0;
      *puVar6 = 0;
      do {
        iVar10 = G3X_GetClipMtx(auStack_50);
      } while (iVar10 != 0);
      *puRam02011924 = 1;
      *puRam02011918 = 3;
      func_01ff9048(0x16,auStack_50,0x10);
      local_8c[0] = ((local_20 >> 4) << 8) >> 0x10 & 0xffffU |
                    (((local_1c >> 4) << 8) >> 0x10) << 0x10;
      func_01ff9048(0x22,local_8c,1);
    }
    local_8c[1] = 2;
    func_01ff9048(0x10,local_8c + 1,1);
    local_8c[2] = 0x1e;
    func_01ff9048(0x14,local_8c + 2,1);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 3;
  return;
}

