/* Decompiled C draft; module arm9; ROM address 0207a7fc. No matching claim. */
#include "types.h"
#include "deps/0207a7fc_IsDriverInLoop.h"

bool IsDriverInLoop(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * iRam0207a824 +
          (*(uint *)(uRam0207a820 & 0xfffffffc) >> (uRam0207a820 & 3) * 8 |
          *(uint *)(uRam0207a820 & 0xfffffffc) << (uRam0207a820 & 3) * -8 + 0x20) + 0x48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 1) != 0;
}

