/* Decompiled C draft; module arm9; ROM address 020dc608. No matching claim. */
#include "types.h"
#include "deps/020dc608_func_020dc608.h"

void func_020dc608(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1 + 0xfcU & 3;
  uVar2 = *(uint *)(param_1 + 0xfcU & 0xfffffffc);
  if (uVar2 >> uVar6 * 8 == 0 && uVar2 << uVar6 * -8 + 0x20 == 0) {
    uVar6 = param_1 + 0xe8U & 3;
    uVar2 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) == 0xd000) {
      uVar6 = param_1 + 0x14U & 3;
      uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
      *(uint *)(param_1 + 0x14) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - iRam020dc784;
    }
    uVar6 = param_1 + 0x84U & 3;
    uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
    if (0x77 < (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20)) {
      uVar6 = param_1 + 0xe8U & 3;
      uVar2 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
      *(uint *)(param_1 + 0xe8) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x100;
    }
    uVar6 = param_1 + 0xe8U & 3;
    uVar2 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
    iVar4 = iRam020dc780;
    if (iRam020dc780 < (int)uVar6) {
      iVar4 = 3;
    }
    if (iRam020dc780 < (int)uVar6) {
      *(short *)(param_1 + 0x90) = (short)iVar4;
      *(undefined2 *)(param_1 + 0x92) = 1;
    }
    return;
  }
  uVar6 = param_1 + 4U & 3;
  uVar2 = *(uint *)(param_1 + 4U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0xcU & 3;
  uVar2 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  *(uint *)(param_1 + 0x18) = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  func_020d84e4(param_1 + 0x1a0);
  func_020d8b88(param_1 + 0x1a0,param_1 + 4);
  uVar6 = param_1 + 4U & 3;
  uVar5 = *(uint *)(param_1 + 4U & 0xfffffffc);
  uVar2 = param_1 + 0x10U & 3;
  uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  *(uint *)(param_1 + 0x10) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) -
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar6 = param_1 + 0xcU & 3;
  uVar5 = *(uint *)(param_1 + 0xcU & 0xfffffffc);
  uVar2 = param_1 + 0x18U & 3;
  uVar3 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  *(uint *)(param_1 + 0x18) =
       (uVar5 >> uVar6 * 8 | uVar5 << uVar6 * -8 + 0x20) -
       (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20);
  uVar6 = param_1 + 0x18U & 3;
  uVar2 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
  uVar3 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  uVar6 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  lVar1 = (longlong)(int)uVar6 * (longlong)(int)uVar6 + (longlong)(int)uVar3 * (longlong)(int)uVar3;
  if ((int)(uint)((uint)lVar1 < 0x10) <= (int)((ulonglong)lVar1 >> 0x20)) {
    uVar6 = param_1 + 0x10U & 3;
    uVar3 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
    uVar2 = param_1 + 0x18U & 3;
    uVar5 = *(uint *)(param_1 + 0x18U & 0xfffffffc);
    uVar6 = func_02148538(uVar3 >> uVar6 * 8 | uVar3 << uVar6 * -8 + 0x20,
                          uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20);
    func_020d7b34((((int)uVar6 >> 0x1f) * uRam020dc774 +
                   uVar6 * iRam020dc778 + (int)((ulonglong)uRam020dc774 * (ulonglong)uVar6 >> 0x20)
                  + 0x800) * 0x10 >> 0x10,param_1 + 0xd4);
  }
  uVar6 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) < 0x40) {
    uVar6 = param_1 + 0xecU & 3;
    uVar2 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
    *(uint *)(param_1 + 0xec) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x1c;
  }
  uVar6 = param_1 + 0x84U & 3;
  uVar2 = *(uint *)(param_1 + 0x84U & 0xfffffffc);
  if ((uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) < 0x28) {
    uVar6 = param_1 + 0x14U & 3;
    uVar2 = *(uint *)(param_1 + 0x14U & 0xfffffffc);
    *(uint *)(param_1 + 0x14) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) - iRam020dc77c;
  }
  else {
    uVar6 = param_1 + 0xe8U & 3;
    uVar2 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
    *(uint *)(param_1 + 0xe8) = (uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20) + 0x200;
  }
  uVar6 = param_1 + 0xe8U & 3;
  uVar2 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  uVar6 = uVar2 >> uVar6 * 8 | uVar2 << uVar6 * -8 + 0x20;
  iVar4 = iRam020dc780;
  if (iRam020dc780 < (int)uVar6) {
    iVar4 = 5;
  }
  if (iRam020dc780 < (int)uVar6) {
    *(short *)(param_1 + 0x90) = (short)iVar4;
    *(undefined2 *)(param_1 + 0x92) = 1;
  }
  return;
}

