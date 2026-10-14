/* Decompiled C draft; module arm9; ROM address 02067ec4. No matching claim. */
#include "types.h"
#include "deps/02067ec4_func_02067ec4.h"

undefined4 func_02067ec4(int param_1,undefined4 *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x2a4U & 3;
  uVar1 = *(uint *)(param_1 + 0x2a4U & 0xfffffffc);
  if (((int)(uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) < 0x3001) &&
     ((*(ushort *)(param_3 + 2) & 0x200) == 0)) {
    *param_2 = 2;
  }
  else {
    iVar2 = StructMQRacerEntry_SomeFn_27(param_1,1,0);
    if (iVar2 != 0) {
      uVar3 = param_1 + 0x590U & 3;
      uVar1 = *(uint *)(param_1 + 0x590U & 0xfffffffc);
      uVar3 = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 0x58;
      uVar1 = uVar3 & 3;
      uVar3 = *(uint *)(uVar3 & 0xfffffffc);
      if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
        func_0208b7bc(0xc,param_1 + 0x80);
        func_0208b7bc(0xd,param_1 + 0x80);
        func_0208b7bc(0xe,param_1 + 0x80);
      }
      uVar3 = param_1 + 0x7cU & 3;
      uVar1 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
      if (((uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) & 1) != 0) {
        iVar2 = GetGlobalRK();
        uVar3 = iVar2 + 0x14U & 3;
        uVar1 = *(uint *)(iVar2 + 0x14U & 0xfffffffc);
        *(uint *)(iVar2 + 0x14) = (uVar1 >> uVar3 * 8 | uVar1 << uVar3 * -8 + 0x20) + 1;
      }
    }
    *param_2 = 3;
  }
  return 0xb;
}

