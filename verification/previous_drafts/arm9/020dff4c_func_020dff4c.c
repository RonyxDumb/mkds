/* Decompiled C draft; module arm9; ROM address 020dff4c. No matching claim. */
#include "types.h"
#include "deps/020dff4c_func_020dff4c.h"

int func_020dff4c(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = func_020d8cac(param_1 + 0x144);
  uVar1 = param_1 + 0x15cU & 3;
  uVar3 = *(uint *)(param_1 + 0x15cU & 0xfffffffc);
  if (uVar3 >> uVar1 * 8 == 0 && uVar3 << uVar1 * -8 + 0x20 == 0) {
    iVar2 = 0x1000 - iVar2;
  }
  return iVar2;
}

