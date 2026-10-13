/* Decompiled C draft; module arm9; ROM address 02104f84. No matching claim. */
#include "types.h"
#include "deps/02104f84_func_02104f84.h"

void func_02104f84(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(uint *)(uRam02104fec & 0xfffffffc) >> (uRam02104fec & 3) * 8 |
          *(uint *)(uRam02104fec & 0xfffffffc) << (uRam02104fec & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) != 2) {
    return;
  }
  uVar1 = iRam02104ff0 + param_1 * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((int)(uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) < 0) {
    uVar1 = uRam02104ff4 & 3;
    uVar2 = *(uint *)(uRam02104ff4 & 0xfffffffc);
    *(undefined4 *)(iRam02104ff0 + param_1 * 4) = 0;
    func_020f0044(param_1 * 0x210 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20));
    return;
  }
  return;
}

