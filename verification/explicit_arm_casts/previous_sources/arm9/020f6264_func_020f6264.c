/* Decompiled C draft; module arm9; ROM address 020f6264. No matching claim. */
#include "types.h"
#include "deps/020f6264_func_020f6264.h"

void func_020f6264(undefined4 param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 4U & 3;
  uVar1 = *(uint *)(param_2 + 4U & 0xfffffffc);
  uVar2 = (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) + 0x1fc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  StructMQRacerEntry_SomeFn_55(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  func_020f4754(param_2,1);
  uVar2 = (*(uint *)(uRam020f62ac & 0xfffffffc) >> (uRam020f62ac & 3) * 8 |
          *(uint *)(uRam020f62ac & 0xfffffffc) << (uRam020f62ac & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    func_020fe958(4);
    return;
  }
  return;
}

