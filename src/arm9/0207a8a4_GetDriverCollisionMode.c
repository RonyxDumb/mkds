/* Decompiled C draft; module arm9; ROM address 0207a8a4. No matching claim. */
#include "types.h"
#include "deps/0207a8a4_GetDriverCollisionMode.h"

uint GetDriverCollisionMode(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * iRam0207a8c0 +
          (*(uint *)(uRam0207a8bc & 0xfffffffc) >> (uRam0207a8bc & 3) * 8 |
          *(uint *)(uRam0207a8bc & 0xfffffffc) << (uRam0207a8bc & 3) * -8 + 0x20) + 0x29c;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

