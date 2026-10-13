/* Decompiled C draft; module arm9; ROM address 020676c4. No matching claim. */
#include "types.h"
#include "deps/020676c4_func_020676c4.h"

undefined4 func_020676c4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x3e4U & 3;
  uVar2 = *(uint *)(param_1 + 0x3e4U & 0xfffffffc);
  uVar1 = iRam020676f8 + (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 4;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  func_02083f6c((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) & 0xffff);
  return 10;
}

