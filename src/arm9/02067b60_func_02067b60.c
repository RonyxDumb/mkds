/* Decompiled C draft; module arm9; ROM address 02067b60. No matching claim. */
#include "types.h"
#include "deps/02067b60_func_02067b60.h"

undefined4 func_02067b60(int param_1,undefined4 *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  *param_2 = 0xc;
  uVar1 = param_1 + 0x48U & 3;
  uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & uRam02067bf0;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar1 = param_1 + 0x7cU & 3;
  uVar3 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 1) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar3 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar1 = param_1 + 0x48U & 3, uVar3 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  iVar2 = StructMQRacerEntry_SomeFn_27(param_1,1,0);
  if (iVar2 != 0) {
    func_02081224(*(undefined2 *)(param_1 + 0x74));
  }
  return 5;
}

