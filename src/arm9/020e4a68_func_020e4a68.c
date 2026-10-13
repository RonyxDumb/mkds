/* Decompiled C draft; module arm9; ROM address 020e4a68. No matching claim. */
#include "types.h"
#include "deps/020e4a68_func_020e4a68.h"

void func_020e4a68(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_020ec7e8();
  if (iVar2 == 0) {
    return;
  }
  uVar1 = param_1 + 0x9cU & 3;
  uVar3 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  if (*(short *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x28) != 0) {
    func_020d2398(param_1);
    return;
  }
  *(undefined2 *)(param_1 + 0x90) = 2;
  *(undefined2 *)(param_1 + 0x92) = 1;
  return;
}

