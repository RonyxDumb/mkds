/* Decompiled C draft; module arm9; ROM address 020dc354. No matching claim. */
#include "types.h"
#include "deps/020dc354_func_020dc354.h"

void func_020dc354(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  func_020d84e4(param_1 + 0x1a0);
  func_020d8b88(param_1 + 0x1a0,param_1 + 4);
  uVar5 = param_1 + 4U & 3;
  uVar4 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) =
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) -
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar5 = param_1 + 0xcU & 3;
  uVar4 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) =
       (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20) -
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar5 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  uVar5 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar5 = uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar5 * (longlong)(int)uVar5 + (longlong)(int)uVar3 * (longlong)(int)uVar3;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar5 = param_1 + 0x10U & 3;
    uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar2 = param_1 + 0x18U & 3;
    uVar4 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar5 = func_02148538(uVar3 >> uVar5 * 8 | uVar3 << uVar5 * -8 + 0x20,
                          uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20);
    func_020d7b34((((int)uVar5 >> 0x1f) * uRam020dc420 +
                   uVar5 * iRam020dc424 + (int)((ulonglong)uRam020dc420 * (ulonglong)uVar5 >> 0x20)
                  + 0x800) * 0x10 >> 0x10,param_1 + 0xd4);
  }
  uVar5 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) < 0x40) {
    uVar5 = param_1 + 0xecU & 3;
    uVar2 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
    *(uint *)(param_1 + 0xec) = (uVar2 >> uVar5 * 8 | uVar2 << uVar5 * -8 + 0x20) + 0x1c;
  }
  return;
}

