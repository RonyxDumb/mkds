/* Decompiled C draft; module arm9; ROM address 0209d650. No matching claim. */
#include "types.h"
#include "deps/0209d650_func_0209d650.h"

void func_0209d650(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
  func_020d7da8(param_1 + 0xb8,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  func_020ac588(uRam0209d690,0x1e,param_1);
  *(undefined4 *)(param_1 + 0x10) = 0;
  *(undefined4 *)(param_1 + 0x14) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  return;
}

