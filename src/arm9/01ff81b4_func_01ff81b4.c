/* Decompiled C draft; module arm9; ROM address 01ff81b4. No matching claim. */
#include "types.h"
#include "deps/01ff81b4_func_01ff81b4.h"

void func_01ff81b4(int *param_1,int param_2)

{
  uint uVar1;
  uint uStack_18;
  uint uStack_14;
  uint uStack_10;
  uint uVar2;
  
  uVar2 = (uint)(param_1 + 2) & 3;
  uVar1 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if (((uVar2 & 0x100) == 0) && ((uVar2 & 0x200) == 0)) {
    if (param_2 == 0) {
      uVar2 = (uint)(param_1 + 0x38) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 0x38) & 0xfffffffc);
      uStack_10 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    else {
      uVar2 = (uint)(param_1 + 0x39) & 3;
      uVar1 = *(uint *)((uint)(param_1 + 0x39) & 0xfffffffc);
      uStack_10 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
    }
    uStack_18 = uStack_10;
    uStack_14 = uStack_10;
    func_01ff9048(0x1b,(undefined4)(uintptr_t)(&uStack_18),3);
  }
  *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
             *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) + 1;
  return;
}

