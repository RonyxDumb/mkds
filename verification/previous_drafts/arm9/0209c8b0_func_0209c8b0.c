/* Decompiled C draft; module arm9; ROM address 0209c8b0. No matching claim. */
#include "types.h"
#include "deps/0209c8b0_func_0209c8b0.h"

bool func_0209c8b0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  longlong lVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (((*(ushort *)(param_1 + 2) & 0x800) == 0) &&
     (uVar1 = param_1 + 0x11cU & 3, uVar3 = *(uint *)(param_1 + 0x11cU & 0xfffffffc),
     (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) == 1)) {
    uVar1 = param_1 + 0x5cU & 3;
    uVar8 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
    uVar3 = param_1 + 0x58U & 3;
    uVar6 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar7 = param_1 + 0xbcU & 3;
    uVar5 = *(uint *)(param_1 + 0xbcU & 0xfffffffc);
    lVar2 = (longlong)(int)(uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20) *
            (longlong)(int)(uVar5 >> uVar7 * 8 | uVar5 << uVar7 * -8 + 0x20);
    uVar4 = func_020ead80(param_2,param_1 + 4,param_1 + 0x28,
                          (uint)lVar2 >> 0xc | (int)((ulonglong)lVar2 >> 0x20) << 0x14,
                          uVar8 >> uVar1 * 8 | uVar8 << uVar1 * -8 + 0x20,0,param_3,(uint *)(uintptr_t)(param_4));
    *(undefined4 *)(param_1 + 0xa4) = uVar4;
  }
  else {
    uVar1 = param_1 + 0x5cU & 3;
    uVar5 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
    uVar3 = param_1 + 0x58U & 3;
    uVar7 = *(uint *)(param_1 + 0x58U & 0xfffffffc);
    uVar4 = func_020ead80(param_2,param_1 + 4,param_1 + 0x28,
                          uVar7 >> uVar3 * 8 | uVar7 << uVar3 * -8 + 0x20,
                          uVar5 >> uVar1 * 8 | uVar5 << uVar1 * -8 + 0x20,0,param_3,(uint *)(uintptr_t)(param_4));
    *(undefined4 *)(param_1 + 0xa4) = uVar4;
  }
  uVar1 = param_1 + 0xa4U & 3;
  uVar3 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  return uVar3 >> uVar1 * 8 != 0 || uVar3 << uVar1 * -8 + 0x20 != 0;
}

