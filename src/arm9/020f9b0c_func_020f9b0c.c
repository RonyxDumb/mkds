/* Decompiled C draft; module arm9; ROM address 020f9b0c. No matching claim. */
#include "types.h"
#include "deps/020f9b0c_func_020f9b0c.h"

void func_020f9b0c(int param_1)

{
  longlong lVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar2 = uRam020f9ba4;
  uVar4 = param_1 + 0x74U & 3;
  uVar3 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20) & 0x8000) != 0) {
    func_020f7658(param_1,1);
    return;
  }
  uVar4 = param_1 + 0x5cU & 3;
  uVar3 = *(uint *)(param_1 + 0x5cU & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uRam020f9ba4 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x5c) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uRam020f9ba4 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 0x60U & 3;
  uVar3 = *(uint *)(param_1 + 0x60U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar4;
  *(uint *)(param_1 + 0x60) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  uVar4 = param_1 + 100U & 3;
  uVar3 = *(uint *)(param_1 + 100U & 0xfffffffc);
  uVar4 = uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20;
  lVar1 = (ulonglong)uVar2 * (ulonglong)uVar4;
  *(uint *)(param_1 + 100) =
       (uint)lVar1 >> 0xc |
       (((int)uVar4 >> 0x1f) * uVar2 + (int)((ulonglong)lVar1 >> 0x20)) * 0x100000;
  func_020f6fc4(param_1,1);
  return;
}

