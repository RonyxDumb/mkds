/* Decompiled C draft; module arm9; ROM address 0201e054. No matching claim. */
#include "types.h"
#include "deps/0201e054_func_0201e054.h"

void func_0201e054(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = param_4 + 0x74U & 3;
  uVar3 = *(uint *)(param_4 + 0x74U & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  uVar2 = *(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20;
  if (uVar3 != 0x80000000) {
    uVar2 = uVar3;
  }
  if ((*(ushort *)(param_1 + 6) & 3) == 0) {
    uVar3 = param_2 + 0x3cU & 3;
    uVar5 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
    uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
    if (((int)uVar3 < (int)uVar2) &&
       (uVar5 = param_2 + 0xcU & 3, uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc),
       (int)uVar2 < (int)(uVar3 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)))) {
      *(uint *)(param_2 + 0xc) = uVar2 - uVar3;
      *(undefined2 *)(param_2 + 0x26) = *(undefined2 *)(param_2 + 0x24);
      return;
    }
    if ((int)uVar2 <= (int)uVar3) {
      uVar5 = param_2 + 0xcU & 3;
      uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
      if ((int)(uVar3 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) < (int)uVar2) {
        *(uint *)(param_2 + 0xc) = uVar2 - uVar3;
        *(undefined2 *)(param_2 + 0x26) = *(undefined2 *)(param_2 + 0x24);
      }
      return;
    }
    return;
  }
  if ((*(ushort *)(param_1 + 6) & 3) != 1) {
    return;
  }
  uVar3 = param_2 + 0x3cU & 3;
  uVar5 = *(uint *)(param_2 + 0x3cU & 0xfffffffc);
  uVar3 = uVar5 >> uVar3 * 8 | uVar5 << uVar3 * -8 + 0x20;
  if (((int)uVar3 < (int)uVar2) &&
     (uVar5 = param_2 + 0xcU & 3, uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc),
     (int)uVar2 < (int)(uVar3 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)))) {
    *(uint *)(param_2 + 0xc) = uVar2 - uVar3;
    uVar2 = param_2 + 0x18U & 3;
    uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)*(short *)(param_1 + 4) + 0x800;
    *(uint *)(param_2 + 0x18) = -((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    return;
  }
  if ((int)uVar3 < (int)uVar2) {
    return;
  }
  uVar5 = param_2 + 0xcU & 3;
  uVar4 = *(uint *)(param_2 + 0xcU & 0xfffffffc);
  if ((int)(uVar3 + (uVar4 >> uVar5 * 8 | uVar4 << uVar5 * -8 + 0x20)) < (int)uVar2) {
    *(uint *)(param_2 + 0xc) = uVar2 - uVar3;
    uVar2 = param_2 + 0x18U & 3;
    uVar3 = *(uint *)(param_2 + 0x18U & 0xfffffffc);
    lVar1 = (longlong)(int)(uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20) *
            (longlong)(int)*(short *)(param_1 + 4) + 0x800;
    *(uint *)(param_2 + 0x18) = -((uint)lVar1 >> 0xc | (int)((ulonglong)lVar1 >> 0x20) * 0x100000);
    return;
  }
  return;
}

