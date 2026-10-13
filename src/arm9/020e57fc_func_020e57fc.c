/* Decompiled C draft; module arm9; ROM address 020e57fc. No matching claim. */
#include "types.h"
#include "deps/020e57fc_func_020e57fc.h"

undefined1 func_020e57fc(int param_1,int param_2,undefined4 param_3,undefined1 *param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_2 + 0x29cU & 3;
  uVar1 = *(uint *)(param_2 + 0x29cU & 0xfffffffc);
  uVar2 = uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20;
  if ((uVar2 == 1) || (uVar2 == 3)) {
    uVar2 = param_1 + 0x78U & 3;
    uVar1 = *(uint *)(param_1 + 0x78U & 0xfffffffc);
    *(uint *)(param_1 + 0x78) =
         uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20 |
         *(uint *)(uRam020e582c & 0xfffffffc) >> (uRam020e582c & 3) * 8 |
         *(uint *)(uRam020e582c & 0xfffffffc) << (uRam020e582c & 3) * -8 + 0x20;
  }
  return *param_4;
}

