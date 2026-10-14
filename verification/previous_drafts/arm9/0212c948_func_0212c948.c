/* Decompiled C draft; module arm9; ROM address 0212c948. No matching claim. */
#include "types.h"
#include "deps/0212c948_func_0212c948.h"

void func_0212c948(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = param_1 + 0x40U & 3;
  uVar2 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
  uVar4 = param_1 + 0x44U & 3;
  uVar3 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  SND_StartTimer(uVar3 >> uVar4 * 8 | uVar3 << uVar4 * -8 + 0x20,0,
                 1 << ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xff),0);
  uVar1 = param_1 + 0x24U & 3;
  uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if (-1 < (int)((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) << 0x1e)) {
    func_0214f4ec(param_1 + 8);
    func_0214f4d4(param_1 + 0x14);
    uVar1 = param_1 + 0x24U & 3;
    uVar4 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20 | 2;
    return;
  }
  return;
}

