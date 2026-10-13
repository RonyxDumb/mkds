/* Decompiled C draft; module arm9; ROM address 0205a548. No matching claim. */
#include "types.h"
#include "deps/0205a548_func_0205a548.h"

void func_0205a548(int param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = uRam0205a5ac;
  uVar2 = uRam0205a5a8;
  iVar4 = (*(uint *)(uRam0205a5a4 & 0xfffffffc) >> (uRam0205a5a4 & 3) * 8 |
          *(uint *)(uRam0205a5a4 & 0xfffffffc) << (uRam0205a5a4 & 3) * -8 + 0x20) + 0x16c;
  *(undefined4 *)(iVar4 + param_1 * 0x88) = param_2;
  *(undefined4 *)(iVar4 + param_1 * 0x88 + 4) = param_2;
  uVar1 = uVar2 & 3;
  uVar3 = *(uint *)(uVar2 & 0xfffffffc);
  uVar2 = uVar5 & 3;
  uVar5 = *(uint *)(uVar5 & 0xfffffffc);
  func_020f40dc(((int)*(char *)((uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20) + param_1 + 6) &
                0xffffU) * 0x210 + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x30);
  return;
}

