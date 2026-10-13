/* Decompiled C draft; module arm9; ROM address 020df938. No matching claim. */
#include "types.h"
#include "deps/020df938_func_020df938.h"

void func_020df938(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  *(undefined2 *)(param_1 + 0xa8) = 0;
  uVar2 = uRam020dfa48;
  uVar1 = param_1 + 0xa4U & 3;
  uVar3 = *(uint *)(param_1 + 0xa4U & 0xfffffffc);
  *(uint *)(param_1 + 8) = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  *(undefined4 *)(param_1 + 0x14) = uVar2;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfffd;
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) & 0xfff7;
  *(undefined2 *)(param_1 + 0x66) = 0x1f;
  uVar1 = param_1 + 0x78U & 3;
  uVar3 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
  if (((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) & 4) == 0) {
    uVar1 = param_1 + 0x70U & 3;
    uVar3 = *(uint *)(param_1 + 0x70U & 0xfffffffc);
    uVar4 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
    uVar1 = iRam020dfa4c + 0x68U & 3;
    uVar3 = *(uint *)(iRam020dfa4c + 0x68U & 0xfffffffc);
    if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
      local_10 = 2;
    }
    else {
      uVar1 = iRam020dfa4c + 0x8cU & 3;
      uVar3 = *(uint *)(iRam020dfa4c + 0x8cU & 0xfffffffc);
      if (uVar4 == (uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20)) {
        local_10 = 3;
      }
      else {
        local_10 = 4;
      }
    }
    local_14 = param_1 + 4;
    local_18 = 0x18c;
    local_c = func_020d4ef4();
    func_0210b7a8(&local_18);
  }
  *(undefined1 *)(param_1 + 0xe4) = 0;
  uVar1 = param_1 + 0xe8U & 3;
  uVar3 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar2 = func_0208b7bc(0x45,param_1 + 4);
    *(undefined4 *)(param_1 + 0xe8) = uVar2;
  }
  uVar1 = param_1 + 0xecU & 3;
  uVar3 = *(uint *)(param_1 + 0xecU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    uVar2 = func_0208b7bc(0x46,param_1 + 4);
    *(undefined4 *)(param_1 + 0xec) = uVar2;
  }
  uVar1 = param_1 + 0xe8U & 3;
  uVar3 = *(uint *)(param_1 + 0xe8U & 0xfffffffc);
  if ((uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) ||
     (uVar1 = param_1 + 0xecU & 3, uVar3 = *(uint *)(param_1 + 0xecU & 0xfffffffc),
     uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(param_1 + 0xf0) = uVar2;
  return;
}

