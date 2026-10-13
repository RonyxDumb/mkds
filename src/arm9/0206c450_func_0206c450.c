/* Decompiled C draft; module arm9; ROM address 0206c450. No matching claim. */
#include "types.h"
#include "deps/0206c450_func_0206c450.h"

void func_0206c450(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  
  uVar1 = *(undefined4 *)(param_2 + 0x3b4);
  uVar2 = *(undefined4 *)(param_2 + 0x3b8);
  *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_2 + 0x3b0);
  *(undefined4 *)(param_1 + 0x44) = uVar1;
  *(undefined4 *)(param_1 + 0x48) = uVar2;
  func_02080e88(param_1,param_2);
  return;
}

