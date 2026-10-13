/* Decompiled C draft; module arm9; ROM address 0207a538. No matching claim. */
#include "types.h"
#include "deps/0207a538_IsPlayerTouchingWall.h"

bool IsPlayerTouchingWall(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(char *)((*(uint *)(uRam0207a568 & 0xfffffffc) >> (uRam0207a568 & 3) * 8 |
                    *(uint *)(uRam0207a568 & 0xfffffffc) << (uRam0207a568 & 3) * -8 + 0x20) + 0x62)
          * iRam0207a570 +
          (*(uint *)(uRam0207a56c & 0xfffffffc) >> (uRam0207a56c & 3) * 8 |
          *(uint *)(uRam0207a56c & 0xfffffffc) << (uRam0207a56c & 3) * -8 + 0x20) + 0x44;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0xc0) != 0;
}

