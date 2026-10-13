/* Decompiled C draft; module arm9; ROM address 02067d0c. No matching claim. */
#include "types.h"
#include "deps/02067d0c_func_02067d0c.h"

undefined4 func_02067d0c(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  iVar2 = StructMQRacerEntry_SomeFn_27(param_1,2,0);
  if (iVar2 != 0) {
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10) != 0) {
      uVar4 = func_0208b7bc(0x4f,param_1 + 0x80);
      func_02081e3c(uVar4,*(undefined2 *)(param_1 + 0x74),0x46);
    }
    uVar1 = param_1 + 0x7cU & 3;
    uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
    if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
      iVar2 = GetGlobalRK();
      uVar1 = iVar2 + 0x14U & 3;
      uVar3 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
      *(uint *)(iVar2 + 0x14) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 1;
    }
  }
  *param_2 = 5;
  return 0;
}

