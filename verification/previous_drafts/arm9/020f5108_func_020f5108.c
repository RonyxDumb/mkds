/* Decompiled C draft; module arm9; ROM address 020f5108. No matching claim. */
#include "types.h"
#include "deps/020f5108_func_020f5108.h"

undefined4 func_020f5108(undefined4 param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = param_2 + 0x130U & 3;
    uVar2 = *(uint *)(param_2 + 0x130U & 0xfffffffc);
    func_020ff1b8(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,(uint *)(uintptr_t)(param_2 + 0x60));
  }
  uVar3 = func_020fecdc((byte *)(uintptr_t)(param_1),param_2,param_3);
  if ((param_2 != 0) && (param_3 == 0)) {
    uVar1 = param_2 + 0x60U & 3;
    uVar2 = *(uint *)(param_2 + 0x60U & 0xfffffffc);
    func_020ff1a0(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,(undefined4 *)(uintptr_t)(param_2 + 0x130));
  }
  if ((param_2 != 0) && (param_3 != 0)) {
    uVar1 = param_2 + 0x44U & 3;
    uVar2 = *(uint *)(param_2 + 0x44U & 0xfffffffc);
    uVar3 = func_020fe8ac(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
    return uVar3;
  }
  return uVar3;
}

