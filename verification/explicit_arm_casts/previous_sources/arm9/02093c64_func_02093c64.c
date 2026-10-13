/* Decompiled C draft; module arm9; ROM address 02093c64. No matching claim. */
#include "types.h"
#include "deps/02093c64_func_02093c64.h"

void func_02093c64(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  
  *(ushort *)(param_1 + 2) = *(ushort *)(param_1 + 2) | *puRam02093cac;
  func_020d2398();
  uVar2 = func_020d286c(param_1);
  *(undefined4 *)(param_1 + 0xa8) = uVar2;
  uVar1 = param_1 + 0xa8U & 3;
  uVar3 = *(uint *)(param_1 + 0xa8U & 0xfffffffc);
  func_0210b850(uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20);
  uVar1 = param_1 + 0x94U & 3;
  uVar3 = *(uint *)(param_1 + 0x94U & 0xfffffffc);
  *(undefined4 *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + 0x30) = uRam02093cb0;
  return;
}

