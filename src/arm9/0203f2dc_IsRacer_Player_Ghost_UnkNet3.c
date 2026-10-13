/* Decompiled C draft; module arm9; ROM address 0203f2dc. No matching claim. */
#include "types.h"
#include "deps/0203f2dc_IsRacer_Player_Ghost_UnkNet3.h"

undefined1 IsRacer_Player_Ghost_UnkNet3(int param_1)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  
  uVar2 = 0;
  uVar3 = param_1 * 0x30 +
          (*(uint *)(uRam0203f31c & 0xfffffffc) >> (uRam0203f31c & 3) * 8 |
          *(uint *)(uRam0203f31c & 0xfffffffc) << (uRam0203f31c & 3) * -8 + 0x20) + 0x70;
  uVar1 = uVar3 & 3;
  uVar3 = *(uint *)(uVar3 & 0xfffffffc);
  uVar3 = uVar3 >> uVar1 * 8 | uVar3 << uVar1 * -8 + 0x20;
  if ((uVar3 < 4) && ((1 << (uVar3 & 0xff) & 0xdU) != 0)) {
    uVar2 = 1;
  }
  return uVar2;
}

