/* Decompiled C draft; module arm9; ROM address 02067d88. No matching claim. */
#include "types.h"
#include "deps/02067d88_func_02067d88.h"

undefined4 func_02067d88(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = param_1 + 0x2a4U & 3;
  uVar2 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  if (((int)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) < 0x3001) &&
     ((*(ushort *)(param_3 + 2) & 0x200) == 0)) {
    *param_2 = 0;
  }
  else {
    iVar3 = StructMQRacerEntry_SomeFn_27(param_1,2,0);
    if (iVar3 != 0) {
      uVar1 = param_1 + 0x7cU & 3;
      uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
        iVar3 = GetGlobalRK();
        uVar1 = iVar3 + 0x14U & 3;
        uVar2 = *(uint *)(iVar3 + 0x14U & 0xfffffffc);
        *(uint *)(iVar3 + 0x14) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 1;
      }
      func_020812d0(*(undefined2 *)(param_1 + 0x74));
    }
    *param_2 = 4;
  }
  return 0;
}

