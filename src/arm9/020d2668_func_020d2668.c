/* Decompiled C draft; module arm9; ROM address 020d2668. No matching claim. */
#include "types.h"
#include "deps/020d2668_func_020d2668.h"

void func_020d2668(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x98U & 3;
  uVar2 = *(uint *)(param_1 + 0x98U & 0xfffffffc);
  uVar3 = (uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) + 0x24;
  uVar2 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20;
  if (uVar3 == 0xffffffff) {
    return;
  }
  uVar2 = param_1 + 0x78U & 3;
  uVar1 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0x40000000) == 0) {
    uVar2 = param_1 + 0x94U & 3;
    uVar1 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
    uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    if (uVar2 == 0) {
      func_02024a28(param_2,uVar3 & 0xffff,param_4,param_3);
      return;
    }
    func_02024a28(uVar2,uVar3 & 0xffff,param_4,param_3);
    return;
  }
  return;
}

