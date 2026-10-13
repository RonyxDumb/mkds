/* Decompiled C draft; module arm9; ROM address 0212c9a4. No matching claim. */
#include "types.h"
#include "deps/0212c9a4_func_0212c9a4.h"

void func_0212c9a4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_0212bc20();
    *(undefined4 *)(param_1 + 0x44) = 0;
    *(undefined4 *)(param_1 + 0x48) = 0;
    return;
  }
  return;
}

