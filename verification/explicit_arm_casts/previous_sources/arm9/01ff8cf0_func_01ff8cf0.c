/* Decompiled C draft; module arm9; ROM address 01ff8cf0. No matching claim. */
#include "types.h"
#include "deps/01ff8cf0_func_01ff8cf0.h"

void func_01ff8cf0(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  undefined1 auStack_194 [396];
  
  if (((*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
       *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) & 0x10) == 0x10) {
    MIi_CpuClear32(0,param_1 + 0xf,8);
    MIi_CpuClear32(0,param_1 + 0x11,8);
    MIi_CpuClear32(0,param_1 + 0x13,8);
    uVar1 = (uint)(param_1 + 2) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 2) & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      func_01ff8dec(param_1 + 0xf);
    }
    uVar1 = (uint)(param_1 + 4) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 4) & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      func_01ff8dec(param_1 + 0x11);
    }
    uVar1 = (uint)(param_1 + 6) & 3;
    uVar2 = *(uint *)((uint)(param_1 + 6) & 0xfffffffc);
    if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
      func_01ff8dec(param_1 + 0x13);
    }
    *param_1 = (*(uint *)((uint)param_1 & 0xfffffffc) >> ((uint)param_1 & 3) * 8 |
               *(uint *)((uint)param_1 & 0xfffffffc) << ((uint)param_1 & 3) * -8 + 0x20) &
               0xffffffef;
  }
  uVar1 = *(uint *)((uint)piRam01ff8de8 & 0xfffffffc) >> ((uint)piRam01ff8de8 & 3) * 8 |
          *(uint *)((uint)piRam01ff8de8 & 0xfffffffc) << ((uint)piRam01ff8de8 & 3) * -8 + 0x20;
  if (uVar1 != 0) {
    func_01ff8e64(uVar1,param_1);
    return;
  }
  *piRam01ff8de8 = (int)auStack_194;
  func_01ff8e64(auStack_194,param_1);
  *piRam01ff8de8 = 0;
  return;
}

