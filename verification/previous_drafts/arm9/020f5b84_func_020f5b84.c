/* Decompiled C draft; module arm9; ROM address 020f5b84. No matching claim. */
#include "types.h"
#include "deps/020f5b84_func_020f5b84.h"

void func_020f5b84(int param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  func_020f2228(param_1,0x8800);
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) == 0) {
    uVar2 = param_1 + 0xd4U & 3;
    uVar1 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210ddf4(uRam020f5cbc,(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x3fffffe0,
                  uRam020f5cc0,param_1,0);
  }
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 1) != 0) {
    return;
  }
  uVar2 = param_1 + 0x240U & 3;
  uVar1 = *(uint *)(param_1 + 0x240U & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (uVar2 < 0x11) {
    if (uVar2 < 5) {
      return;
    }
    iVar3 = func_020f1180(param_1,0);
    if (iVar3 != 0) {
      *(undefined2 *)(param_1 + 0x24c) = 4;
      *(undefined2 *)(param_1 + 0x24e) = 1;
      uVar2 = param_1 + 0x74U & 3;
      uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
      if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) != 0) {
        uVar2 = param_1 + 0x228U & 3;
        uVar1 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
        func_020fe71c(1,*(undefined2 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f8),
                      (int)*(short *)(param_1 + 0x4e));
        return;
      }
      return;
    }
    return;
  }
  iVar3 = func_020f11f0(param_1,0);
  if (iVar3 == 0) {
    return;
  }
  *(undefined2 *)(param_1 + 0x24c) = 4;
  *(undefined2 *)(param_1 + 0x24e) = 1;
  uVar2 = param_1 + 0x74U & 3;
  uVar1 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x8000000) != 0) {
    uVar2 = param_1 + 0x228U & 3;
    uVar1 = *(uint *)(param_1 + 0x228U & 0xfffffffc);
    func_020fe71c(1,*(undefined2 *)((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1f8),
                  (int)*(short *)(param_1 + 0x4e));
    return;
  }
  return;
}

