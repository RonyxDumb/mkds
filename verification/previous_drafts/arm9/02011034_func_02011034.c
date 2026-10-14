/* Decompiled C draft; module arm9; ROM address 02011034. No matching claim. */
#include "types.h"
#include "deps/02011034_func_02011034.h"

void func_02011034(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  func_01ff9048(*(uint *)(uRam02011070 & 0xfffffffc) >> (uRam02011070 & 3) * 8 |
                *(uint *)(uRam02011070 & 0xfffffffc) << (uRam02011070 & 3) * -8 + 0x20,
                uRam02011070 + 4,0x3e);
  uVar1 = uRam02011070;
  uVar3 = uRam02011070 + 0xfc & 3;
  uVar2 = *(uint *)(uRam02011070 + 0xfc & 0xfffffffc);
  uVar3 = uVar2 >> uVar3 * 8 | uVar2 << uVar3 * -8 + 0x20;
  *(uint *)(uRam02011070 + 0xfc) = uVar3 & 0xfffffffe;
  *(uint *)(uVar1 + 0xfc) = uVar3 & 0xfffffffc;
  return;
}

