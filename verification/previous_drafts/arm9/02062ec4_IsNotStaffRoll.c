/* Decompiled C draft; module arm9; ROM address 02062ec4. No matching claim. */
#include "types.h"
#include "deps/02062ec4_IsNotStaffRoll.h"

uint IsNotStaffRoll(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam02062ed4 & 0xfffffffc) >> (uRam02062ed4 & 3) * 8 |
          *(uint *)(uRam02062ed4 & 0xfffffffc) << (uRam02062ed4 & 3) * -8 + 0x20) + 0x28;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  return uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20;
}

