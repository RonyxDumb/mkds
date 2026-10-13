/* Decompiled C draft; module arm9; ROM address 02083680. No matching claim. */
#include "types.h"
#include "deps/02083680_func_02083680.h"

void func_02083680(int param_1,int param_2)

{
  uint uVar1;
  longlong lVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  undefined4 uStack_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  int iStack_20;
  
  if (param_2 != 0) {
    return;
  }
  iVar4 = GetGlobalHD5();
  uVar7 = param_1 + 0x94U & 3;
  uVar10 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  iVar5 = func_02061818();
  if ((iVar5 == 0) &&
     ((uVar1 = param_1 + 0x24U & 3, uVar6 = *(uint *)(param_1 + 0x24U & 0xfffffffc),
      -1 < (int)((uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) << 0x1e) ||
      (uVar1 = param_1 + 0x98U & 3, uVar6 = *(uint *)(param_1 + 0x98U & 0xfffffffc),
      *(uint *)(param_1 + 0x98) = (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) + 1,
      uVar1 = param_1 + 0x98U & 3, uVar6 = *(uint *)(param_1 + 0x98U & 0xfffffffc),
      (uVar6 >> uVar1 * 8 | uVar6 << uVar1 * -8 + 0x20) < 6)))) {
    uVar7 = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0x48;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    if (((uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20) & 0x20) == 0) {
      uVar7 = param_1 + 0x24U & 3;
      uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
      *(uint *)(param_1 + 0x24) = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20 | 2;
    }
    uStack_40 = *(undefined4 *)(iVar4 + 0x9c);
    uStack_3c = *(undefined4 *)(iVar4 + 0xa0);
    uStack_38 = *(undefined4 *)(iVar4 + 0xa4);
    uVar7 = iVar4 + 0x15cU & 3;
    uVar10 = *(uint *)(iVar4 + 0x15cU & 0xfffffffc);
    lVar2 = (ulonglong)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) * 0x5000;
    uStack_34 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uVar7 = iVar4 + 0x160U & 3;
    uVar10 = *(uint *)(iVar4 + 0x160U & 0xfffffffc);
    lVar2 = (ulonglong)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) * 0x5000;
    uStack_30 = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    uVar7 = iVar4 + 0x164U & 3;
    uVar10 = *(uint *)(iVar4 + 0x164U & 0xfffffffc);
    lVar2 = (ulonglong)(uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) * 0x5000;
    uStack_2c = (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) * 0x100000;
    VecFx32_Add((uint)(uintptr_t)(&uStack_34),(uint)(uintptr_t)(&uStack_40),&iStack_28);
    uVar7 = param_1 + 0x20U & 3;
    uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar7 = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 4;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x28) = iStack_28 + (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20);
    uVar7 = param_1 + 0x20U & 3;
    uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar7 = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 8;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x2c) = iStack_24 + (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20);
    uVar7 = param_1 + 0x20U & 3;
    uVar10 = *(uint *)(param_1 + 0x20U & 0xfffffffc);
    uVar10 = uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20;
    uVar7 = uVar10 & 3;
    uVar10 = *(uint *)(uVar10 & 0xfffffffc);
    uVar7 = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) + 0xc;
    uVar10 = uVar7 & 3;
    uVar7 = *(uint *)(uVar7 & 0xfffffffc);
    *(uint *)(param_1 + 0x30) = iStack_20 + (uVar7 >> uVar10 * 8 | uVar7 << uVar10 * -8 + 0x20);
    uVar7 = iVar4 + 0x15cU & 3;
    uVar6 = *(uint *)(iVar4 + 0x15cU & 0xfffffffc);
    uVar10 = iVar4 + 0x160U & 3;
    uVar8 = *(uint *)(iVar4 + 0x160U & 0xfffffffc);
    uVar1 = iVar4 + 0x164U & 3;
    uVar9 = *(uint *)(iVar4 + 0x164U & 0xfffffffc);
    *(ushort *)(param_1 + 0x50) =
         -((ushort)(uVar6 >> uVar7 * 8) | (ushort)(uVar6 << uVar7 * -8 + 0x20));
    *(ushort *)(param_1 + 0x52) =
         -((ushort)(uVar8 >> uVar10 * 8) | (ushort)(uVar8 << uVar10 * -8 + 0x20));
    *(ushort *)(param_1 + 0x54) =
         -((ushort)(uVar9 >> uVar1 * 8) | (ushort)(uVar9 << uVar1 * -8 + 0x20));
    return;
  }
  puVar3 = puRam02083830;
  uVar7 = param_1 + 0x24U & 3;
  uVar10 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  *(uint *)(param_1 + 0x24) = (uVar10 >> uVar7 * 8 | uVar10 << uVar7 * -8 + 0x20) & 0xfffffffe | 1;
  *puVar3 = 0;
  return;
}

