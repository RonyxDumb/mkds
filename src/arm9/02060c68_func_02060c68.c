/* Decompiled C draft; module arm9; ROM address 02060c68. No matching claim. */
#include "types.h"
#include "deps/02060c68_func_02060c68.h"

void func_02060c68(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02060cac & 0xfffffffc) >> (uRam02060cac & 3) * 8 |
          *(uint *)(uRam02060cac & 0xfffffffc) << (uRam02060cac & 3) * -8 + 0x20) + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  func_02060d1c((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + iRam02060cb0,param_1,
                param_1 + 0x218,0,*(undefined1 *)(param_1 + 0x214),param_2);
  return;
}

