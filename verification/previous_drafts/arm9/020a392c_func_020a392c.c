/* Decompiled C draft; module arm9; ROM address 020a392c. No matching claim. */
#include "types.h"
#include "deps/020a392c_func_020a392c.h"

void func_020a392c(int param_1,int param_2)

{
  uint uVar1;
  undefined2 uVar2;
  uint uVar3;
  
  uVar1 = param_2 + 0xa8U & 3;
  uVar3 = *(uint *)(param_2 + 0xa8U & 0xfffffffc);
  uVar2 = func_0208606c(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  *(undefined2 *)(param_1 + 0x72) = uVar2;
  return;
}

