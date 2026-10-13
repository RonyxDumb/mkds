/* Decompiled C draft; module arm9; ROM address 021013bc. No matching claim. */
#include "types.h"
#include "deps/021013bc_func_021013bc.h"

void func_021013bc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x24cU & 3;
  uVar2 = *(uint *)(param_1 + 0x24cU & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_02101f7c(param_1,0xffffffff);
    uVar1 = param_1 + 0x140U & 3;
    uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
    func_020fe694(0xb,(int)*(short *)(param_1 + 0x4e),0,
                  (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xff);
    uVar1 = param_1 + 0x140U & 3;
    uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
    *(uint *)(param_1 + 0x250) = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    *(undefined4 *)(param_1 + 0x24c) = 0;
    return;
  }
  return;
}

