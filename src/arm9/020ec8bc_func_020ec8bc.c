/* Decompiled C draft; module arm9; ROM address 020ec8bc. No matching claim. */
#include "types.h"
#include "deps/020ec8bc_func_020ec8bc.h"

void func_020ec8bc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
                  undefined4 param_6,undefined2 param_7,undefined4 param_8)

{
  func_020f1ea4(param_1,-(uint)(param_5 == 0),param_6);
  *(undefined4 *)(param_1 + 0x214) = param_2;
  *(undefined4 *)(param_1 + 0x218) = param_3;
  func_020f371c(param_1 + 0x21c,(uint *)(uintptr_t)(param_1 + 0x168),param_7,param_8);
  *(undefined4 *)(param_1 + 0x224) = 0;
  return;
}

