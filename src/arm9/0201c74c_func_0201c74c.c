/* Decompiled C draft; module arm9; ROM address 0201c74c. No matching claim. */
#include "types.h"
#include "deps/0201c74c_func_0201c74c.h"

/* WARNING: Restarted to delay deadcode elimination for space: stack */

void func_0201c74c(int param_1,int param_2,undefined4 param_3)

{
  longlong lVar1;
  uint *puVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar10;
  uint uVar11;
  int local_40;
  ushort *puVar9;
  
  puVar2 = puRam0201ca5c;
  uVar8 = param_2 + 0x20U & 3;
  uVar7 = *(uint *)(param_2 + 0x20U & 0xfffffffc);
  uVar8 = (uVar7 >> uVar8 * 8 | uVar7 << uVar8 * -8 + 0x20) + 0x14;
  uVar7 = uVar8 & 3;
  uVar8 = *(uint *)(uVar8 & 0xfffffffc);
  puVar9 = (ushort *)(uVar8 >> uVar7 * 8 | uVar8 << uVar7 * -8 + 0x20);
  uVar8 = (uint)(byte)puVar9[4] * 0x10000;
  local_40 = 0;
  uVar8 = uVar8 + 0x800 >> 0xc | (uint)(0xfffff7ff < uVar8) << 0x14;
  if ((char)puVar9[6] == '\0') {
    return;
  }
  do {
    iVar4 = func_0201e448((uint *)(uintptr_t)(param_3));
    if (iVar4 == 0) {
      return;
    }
    func_0201e494((undefined4 *)(uintptr_t)(param_2 + 0x14),(uint *)(uintptr_t)(iVar4));
    uVar5 = *(undefined4 *)(param_1 + 0xc);
    uVar6 = *(undefined4 *)(param_1 + 0x10);
    *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(param_1 + 8);
    *(undefined4 *)(iVar4 + 0xc) = uVar5;
    *(undefined4 *)(iVar4 + 0x10) = uVar6;
    uVar7 = param_1 + 0x14U & 3;
    uVar10 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) * iRam0201ca60 +
            iRam0201ca64;
    *puVar2 = uVar7;
    lVar1 = (ulonglong)uVar8 * (ulonglong)uVar10;
    uVar11 = (uint)lVar1;
    *(uint *)(iVar4 + 0x14) =
         (uVar11 + 0x800 >> 0xc |
         (((int)uVar10 >> 0x1f) * uVar8 + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)(0xfffff7ff < uVar11)) * 0x100000) +
         ((int)((int)(short)puVar9[1] * (uVar7 >> 0x17) + (short)puVar9[1] * -0x100) >> 8);
    uVar7 = param_1 + 0x18U & 3;
    uVar10 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) * iRam0201ca60 +
            iRam0201ca64;
    *puVar2 = uVar7;
    lVar1 = (ulonglong)uVar8 * (ulonglong)uVar10;
    uVar11 = (uint)lVar1;
    *(uint *)(iVar4 + 0x18) =
         (uVar11 + 0x800 >> 0xc |
         (((int)uVar10 >> 0x1f) * uVar8 + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)(0xfffff7ff < uVar11)) * 0x100000) +
         ((int)((int)(short)puVar9[1] * (uVar7 >> 0x17) + (short)puVar9[1] * -0x100) >> 8);
    uVar7 = param_1 + 0x1cU & 3;
    uVar10 = *(uint *)(param_1 + 0x1cU & 0xfffffffc);
    uVar11 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = (*(uint *)((uint)puVar2 & 0xfffffffc) >> ((uint)puVar2 & 3) * 8 |
            *(uint *)((uint)puVar2 & 0xfffffffc) << ((uint)puVar2 & 3) * -8 + 0x20) * iRam0201ca60 +
            iRam0201ca64;
    lVar1 = (ulonglong)uVar8 * (ulonglong)uVar11;
    uVar10 = (uint)lVar1;
    *puVar2 = uVar7;
    *(uint *)(iVar4 + 0x1c) =
         (uVar10 + 0x800 >> 0xc |
         (((int)uVar11 >> 0x1f) * uVar8 + (int)((ulonglong)lVar1 >> 0x20) +
         (uint)(0xfffff7ff < uVar10)) * 0x100000) +
         ((int)((int)(short)puVar9[1] * (uVar7 >> 0x17) + (short)puVar9[1] * -0x100) >> 8);
    uVar5 = *(undefined4 *)(param_1 + 0x3c);
    uVar6 = *(undefined4 *)(param_1 + 0x40);
    *(undefined4 *)(iVar4 + 0x38) = *(undefined4 *)(param_1 + 0x38);
    *(undefined4 *)(iVar4 + 0x3c) = uVar5;
    *(undefined4 *)(iVar4 + 0x40) = uVar6;
    uVar7 = param_1 + 0x30U & 3;
    uVar10 = *(uint *)(param_1 + 0x30U & 0xfffffffc);
    *(int *)(iVar4 + 0x30) =
         (int)(((int)((uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) *
                     (int)*(short *)(param_1 + 0x34)) >> 0xc) * (*(byte *)((int)puVar9 + 9) + 1)) >>
         6;
    *(undefined2 *)(iVar4 + 0x34) = 0x1000;
    if ((int)((uint)*puVar9 << 0x19) < 0) {
      *(ushort *)(iVar4 + 0x36) = puVar9[5];
    }
    else {
      *(undefined2 *)(iVar4 + 0x36) = *(undefined2 *)(param_1 + 0x36);
    }
    *(ushort *)(iVar4 + 0x2e) =
         *(ushort *)(iVar4 + 0x2e) & 0xffe0 |
         (ushort)((*(ushort *)(param_1 + 0x2e) & 0x1f) *
                  ((((uint)*(ushort *)(param_1 + 0x2e) << 0x16) >> 0x1b) + 1) * 0x800 >> 0x10) &
         0x1f;
    *(ushort *)(iVar4 + 0x2e) = *(ushort *)(iVar4 + 0x2e) & 0xfc1f | 0x3e0;
    uVar7 = ((uint)*puVar9 << 0x1b) >> 0x1e;
    if (uVar7 == 0) {
      *(undefined2 *)(iVar4 + 0x20) = 0;
      *(undefined2 *)(iVar4 + 0x22) = 0;
    }
    else if (uVar7 == 1) {
      *(undefined2 *)(iVar4 + 0x20) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(iVar4 + 0x22) = 0;
    }
    else if (uVar7 == 2) {
      *(undefined2 *)(iVar4 + 0x20) = *(undefined2 *)(param_1 + 0x20);
      *(undefined2 *)(iVar4 + 0x22) = *(undefined2 *)(param_1 + 0x22);
    }
    uVar5 = uRam0201ca68;
    *(ushort *)(iVar4 + 0x24) = puVar9[3];
    *(undefined2 *)(iVar4 + 0x26) = 0;
    *(undefined1 *)(iVar4 + 0x2c) = *(undefined1 *)((int)puVar9 + 0xf);
    uVar3 = _s32_div_f(uVar5,*(ushort *)(param_1 + 0x24) >> 1);
    *(undefined2 *)(iVar4 + 0x28) = uVar3;
    uVar3 = _s32_div_f(uRam0201ca68,*(undefined2 *)(param_1 + 0x24));
    *(undefined2 *)(iVar4 + 0x2a) = uVar3;
    *(undefined1 *)(iVar4 + 0x2d) = 0;
    local_40 = local_40 + 1;
  } while (local_40 < (int)(uint)(byte)puVar9[6]);
  return;
}

