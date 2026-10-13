/* Decompiled C draft; module arm9; ROM address 02018578. No matching claim. */
#include "types.h"
#include "deps/02018578_func_02018578.h"

int func_02018578(int param_1,int param_2,undefined4 param_3,undefined4 param_4,code *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x10U & 3;
  uVar2 = *(uint *)(param_1 + 0x10U & 0xfffffffc);
  iVar3 = 0;
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    iVar3 = func_0201e448((uint *)(uintptr_t)(param_1 + 0x10));
    uVar1 = param_1 + 0x28U & 3;
    uVar2 = *(uint *)(param_1 + 0x28U & 0xfffffffc);
    func_02019b28((uint *)(uintptr_t)(iVar3),(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + param_2 * 0x20,param_3);
    if (param_5 != (code *)0x0) {
      (*param_5)(iVar3,param_4);
    }
    func_0201e494((undefined4 *)(uintptr_t)(param_1 + 4),(uint *)(uintptr_t)(iVar3));
    uVar1 = iVar3 + 0x20U & 3;
    uVar2 = *(uint *)(iVar3 + 0x20U & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    uVar2 = uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
    uVar1 = uVar2 & 3;
    uVar2 = *(uint *)(uVar2 & 0xfffffffc);
    if ((int)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) << 0x11) < 0) {
      iVar3 = 0;
    }
  }
  return iVar3;
}

