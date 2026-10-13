/* Decompiled C draft; module arm9; ROM address 0212c824. No matching claim. */
#include "types.h"
#include "deps/0212c824_func_0212c824.h"

void func_0212c824(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  
  uVar1 = param_1 + 0x24U & 3;
  uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
  if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x1e) < 0) {
    uVar1 = param_1 + 0x40U & 3;
    uVar3 = *(uint *)(param_1 + 0x40U & 0xfffffffc);
    uVar2 = param_1 + 0x44U & 3;
    uVar4 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    SND_StopTimer(uVar4 >> uVar2 * 8 | uVar4 << uVar2 * -8 + 0x20,0,
                  1 << ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0xff),0);
    func_0214f4bc(param_1 + 8);
    func_0214f4a4(param_1 + 0x14);
    uVar1 = param_1 + 0x24U & 3;
    uVar2 = *(uint *)(param_1 + 0x24U & 0xfffffffc);
    *(uint *)(param_1 + 0x24) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xfffffffd;
    uVar5 = func_02021114();
    Sound_FlushCommand(1);
    func_02021154(uVar5);
  }
  func_0212c7f0(param_1);
  return;
}

