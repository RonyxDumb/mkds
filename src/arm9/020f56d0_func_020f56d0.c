/* Decompiled C draft; module arm9; ROM address 020f56d0. No matching claim. */
#include "types.h"
#include "deps/020f56d0_func_020f56d0.h"

void func_020f56d0(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  func_020f2228(param_1,0xc000);
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) == 0) {
    uVar1 = param_1 + 0xd4U & 3;
    uVar2 = *(uint *)(param_1 + 0xd4U & 0xfffffffc);
    func_0210ddf4(uRam020f5724,(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x3fffffe0,
                  uRam020f5728,param_1);
    return;
  }
  return;
}

