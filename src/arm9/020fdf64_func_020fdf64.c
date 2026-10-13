/* Decompiled C draft; module arm9; ROM address 020fdf64. No matching claim. */
#include "types.h"
#include "deps/020fdf64_func_020fdf64.h"

void func_020fdf64(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0x188U & 3;
  uVar2 = *(uint *)(param_1 + 0x188U & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  iVar1 = func_020fa0b8(param_1,*(uint *)(uRam020fe000 & 0xfffffffc) >> (uRam020fe000 & 3) * 8 |
                                *(uint *)(uRam020fe000 & 0xfffffffc) <<
                                (uRam020fe000 & 3) * -8 + 0x20,
                        *(uint *)(uRam020fe004 & 0xfffffffc) >> (uRam020fe004 & 3) * 8 |
                        *(uint *)(uRam020fe004 & 0xfffffffc) << (uRam020fe004 & 3) * -8 + 0x20);
  if (iVar1 != 0) {
    func_020f9fa8(param_1);
  }
  if ((int)uVar3 < 0x16) {
    return;
  }
  if (uVar3 == 0x16) {
    *(undefined4 *)(param_1 + 0x16c) = 1;
  }
  else if (uVar3 == 0x2a) {
    func_020f9c40(param_1);
  }
  if (0x55 < (int)uVar3) {
    uVar3 = param_1 + 0x44U & 3;
    uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
    func_020f0f70((uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20) * 0x44 +
                  (*(uint *)(uRam020fe008 & 0xfffffffc) >> (uRam020fe008 & 3) * 8 |
                  *(uint *)(uRam020fe008 & 0xfffffffc) << (uRam020fe008 & 3) * -8 + 0x20),param_1);
    return;
  }
  return;
}

