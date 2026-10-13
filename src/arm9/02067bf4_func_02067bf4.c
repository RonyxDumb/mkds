/* Decompiled C draft; module arm9; ROM address 02067bf4. No matching claim. */
#include "types.h"
#include "deps/02067bf4_func_02067bf4.h"

undefined4 func_02067bf4(int param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  
  *param_2 = 0xc;
  uVar1 = param_1 + 0x48U & 3;
  uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc);
  *(uint *)(param_1 + 0x48) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & uRam02067c6c;
  *(undefined2 *)(param_1 + 0x238) = 0;
  *(undefined2 *)(param_1 + 0x538) = 0;
  *(undefined2 *)(param_1 + 0x23c) = 0;
  uVar1 = param_1 + 0x7cU & 3;
  uVar2 = *(uint *)(param_1 + 0x7cU & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0) {
    uVar1 = param_1 + 0x4cU & 3;
    uVar2 = *(uint *)(param_1 + 0x4cU & 0xfffffffc);
    if ((((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x10000000) == 0) &&
       (uVar1 = param_1 + 0x48U & 3, uVar2 = *(uint *)(param_1 + 0x48U & 0xfffffffc),
       ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x4000000) == 0)) {
      func_02074854();
    }
    func_02055c5c();
  }
  *(undefined4 *)(param_1 + 0x2a8) = 0;
  return 5;
}

