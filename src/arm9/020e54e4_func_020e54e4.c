/* Decompiled C draft; module arm9; ROM address 020e54e4. No matching claim. */
#include "types.h"
#include "deps/020e54e4_func_020e54e4.h"

/* WARNING: Type propagation algorithm not settling */

void func_020e54e4(int param_1,uint param_2,undefined4 param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint local_28 [3];
  uint local_1c;
  uint local_18;
  
  local_28[1] = 0x1e;
  func_01ff9048(0x14,(undefined4)(uintptr_t)(local_28 + 1),1);
  func_01ff9048(0x19,param_1,0xc);
  if (param_2 != 0) {
    local_28[2] = *(uint *)(param_2 & 0xfffffffc) >> (param_2 & 3) * 8 |
                  *(uint *)(param_2 & 0xfffffffc) << (param_2 & 3) * -8 + 0x20;
    local_1c = local_28[2];
    local_18 = local_28[2];
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(local_28 + 2),3);
  }
  uVar2 = (*(uint *)(uRam020e55ac & 0xfffffffc) >> (uRam020e55ac & 3) * 8 |
          *(uint *)(uRam020e55ac & 0xfffffffc) << (uRam020e55ac & 3) * -8 + 0x20) + 0xc;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (*(ushort *)(param_1 + 0x30) <= param_4) {
    param_4 = (uint)*(ushort *)(param_1 + 0x30);
  }
  local_28[0] = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffe0ffff | param_4 << 0x10;
  func_01ff9048(0x29,(undefined4)(uintptr_t)(local_28),1);
  uVar5 = *(uint *)(uRam020e55b0 & 0xfffffffc) >> (uRam020e55b0 & 3) * 8 |
          *(uint *)(uRam020e55b0 & 0xfffffffc) << (uRam020e55b0 & 3) * -8 + 0x20;
  uVar2 = uVar5 + 8 & 3;
  uVar3 = *(uint *)(uVar5 + 8 & 0xfffffffc);
  uVar1 = uVar5 + 0xc & 3;
  uVar4 = *(uint *)(uVar5 + 0xc & 0xfffffffc);
  func_01ff9144(uVar5 + (uVar3 >> uVar2 * 8 | uVar3 << uVar2 * -8 + 0x20),
                uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  return;
}

