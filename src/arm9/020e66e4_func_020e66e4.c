/* Decompiled C draft; module arm9; ROM address 020e66e4. No matching claim. */
#include "types.h"
#include "deps/020e66e4_func_020e66e4.h"

void func_020e66e4(undefined4 param_1,int param_2,int param_3,uint param_4,undefined4 param_5,
                  undefined2 param_6)

{
  uint uVar1;
  uint uVar2;
  undefined4 local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  
  local_28 = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(&local_28),1);
  func_01ff9048(0x19,param_2,0xc);
  if (param_3 != 0) {
    MTX_RotZ33__from_thumb
              ((undefined4 *)(uintptr_t)(*(uint *)(uRam020e67bc & 0xfffffffc) >> (uRam020e67bc & 3) * 8 |
               *(uint *)(uRam020e67bc & 0xfffffffc) << (uRam020e67bc & 3) * -8 + 0x20),
               (int)*(short *)(iRam020e67c0 + (param_3 >> 4) * 4),
               (int)*(short *)(iRam020e67c0 + ((param_3 >> 4) * 2 + 1) * 2));
    func_01ff9048(0x1a,*(uint *)(uRam020e67bc & 0xfffffffc) >> (uRam020e67bc & 3) * 8 |
                       *(uint *)(uRam020e67bc & 0xfffffffc) << (uRam020e67bc & 3) * -8 + 0x20,9);
  }
  if (param_4 != 0) {
    uVar1 = param_4 + 8 & 3;
    uVar2 = *(uint *)(param_4 + 8 & 0xfffffffc);
    local_1c = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = param_4 + 4 & 3;
    uVar2 = *(uint *)(param_4 + 4 & 0xfffffffc);
    local_20 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    local_24 = *(uint *)(param_4 & 0xfffffffc) >> (param_4 & 3) * 8 |
               *(uint *)(param_4 & 0xfffffffc) << (param_4 & 3) * -8 + 0x20;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&local_24),3);
  }
  func_020e6854(param_1,param_2 + 0x24,param_5,param_6);
  return;
}

