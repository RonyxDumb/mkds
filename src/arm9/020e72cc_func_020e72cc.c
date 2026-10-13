/* Decompiled C draft; module arm9; ROM address 020e72cc. No matching claim. */
#include "types.h"
#include "deps/020e72cc_func_020e72cc.h"

void func_020e72cc(int param_1,int param_2)

{
  int iVar1;
  
  *(undefined2 *)(param_1 + 0xa0) = *(undefined2 *)(param_2 + 0x28);
  iVar1 = *(int *)(*piRam020e7308 + 0x10);
  if (iVar1 == 0) {
    *(undefined2 *)(param_1 + 0xa2) = *(undefined2 *)(param_2 + 0x2a);
    return;
  }
  if (iVar1 != 1) {
    if (iVar1 != 2) {
      return;
    }
    *(undefined2 *)(param_1 + 0xa2) = *(undefined2 *)(param_2 + 0x2e);
    return;
  }
  *(undefined2 *)(param_1 + 0xa2) = *(undefined2 *)(param_2 + 0x2c);
  return;
}

