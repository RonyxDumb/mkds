/* Decompiled C draft; module arm9; ROM address 0207a5c4. No matching claim. */
#include "types.h"
#include "deps/0207a5c4_HasDriverFlagBBit11.h"

bool HasDriverFlagBBit11(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1 * iRam0207a5ec +
          (*(uint *)(uRam0207a5e8 & 0xfffffffc) >> (uRam0207a5e8 & 3) * 8 |
          *(uint *)(uRam0207a5e8 & 0xfffffffc) << (uRam0207a5e8 & 3) * -8 + 0x20) + 0x48;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) & 0x800) != 0;
}

