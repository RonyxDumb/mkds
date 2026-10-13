/* Decompiled C draft; module arm9; ROM address 020d4418. No matching claim. */
#include "types.h"
#include "deps/020d4418_func_020d4418.h"

void func_020d4418(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  param_1 = param_1 + 0x30;
  uVar2 = (*(uint *)(uRam020d4480 & 0xfffffffc) >> (uRam020d4480 & 3) * 8 |
          *(uint *)(uRam020d4480 & 0xfffffffc) << (uRam020d4480 & 3) * -8 + 0x20) + 0x17c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020dff88(param_1);
  }
  uVar2 = (*(uint *)(uRam020d4480 & 0xfffffffc) >> (uRam020d4480 & 3) * 8 |
          *(uint *)(uRam020d4480 & 0xfffffffc) << (uRam020d4480 & 3) * -8 + 0x20) + 0x180;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020e435c(param_1);
  }
  uVar2 = (*(uint *)(uRam020d4480 & 0xfffffffc) >> (uRam020d4480 & 3) * 8 |
          *(uint *)(uRam020d4480 & 0xfffffffc) << (uRam020d4480 & 3) * -8 + 0x20) + 0x184;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if (uVar2 >> uVar1 * 8 != 0 || uVar2 << uVar1 * -8 + 0x20 != 0) {
    func_020e3b28(param_1);
    return;
  }
  return;
}

