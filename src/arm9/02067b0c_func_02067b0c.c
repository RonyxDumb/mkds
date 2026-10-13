/* Decompiled C draft; module arm9; ROM address 02067b0c. No matching claim. */
#include "types.h"
#include "deps/02067b0c_func_02067b0c.h"

void func_02067b0c(int param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_0206a24c();
  if (((iVar2 != 0) &&
      (uVar1 = param_1 + 0x44cU & 3, uVar3 = *(uint *)(param_1 + 0x44cU & 0xfffffffc),
      (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) != param_3)) &&
     (uVar1 = param_1 + 0x7cU & 3, uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc),
     ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0)) {
    iVar2 = GetGlobalRK();
    uVar1 = iVar2 + 0x14U & 3;
    uVar3 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
    *(uint *)(iVar2 + 0x14) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
  }
  *param_2 = 0;
  return;
}

