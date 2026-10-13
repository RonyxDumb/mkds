/* Decompiled C draft; module arm9; ROM address 020f90dc. No matching claim. */
#include "types.h"
#include "deps/020f90dc_func_020f90dc.h"

void func_020f90dc(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x74U & 3;
  uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
  if (((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x400000) != 0) {
    func_02109054();
    *(undefined4 *)(param_1 + 0x30) = 0;
    uVar1 = param_1 + 0x74U & 3;
    uVar2 = *(uint *)(param_1 + 0x74U & 0xfffffffc);
    *(uint *)(param_1 + 0x74) = (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xffbfffff;
    return;
  }
  return;
}

