/* Decompiled C draft; module arm9; ROM address 02067cb0. No matching claim. */
#include "types.h"
#include "deps/02067cb0_func_02067cb0.h"

undefined4 func_02067cb0(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = StructMQRacerEntry_SomeFn_65();
  if (iVar2 != 0) {
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
      iVar2 = GetGlobalRK();
      uVar1 = iVar2 + 0x14U & 3;
      uVar3 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
      *(uint *)(iVar2 + 0x14) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
    }
    uVar1 = param_1 + 0x48U & 3;
    uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
    *(uint *)(param_1 + 0x48) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20 | 0x20000;
  }
  *param_2 = 7;
  return 2;
}

