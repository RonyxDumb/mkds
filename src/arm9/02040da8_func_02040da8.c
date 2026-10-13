/* Decompiled C draft; module arm9; ROM address 02040da8. No matching claim. */
#include "types.h"
#include "deps/02040da8_func_02040da8.h"

int func_02040da8(int param_1)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)(uRam02040ddc & 0xfffffffc) >> (uRam02040ddc & 3) * 8 |
          *(uint *)(uRam02040ddc & 0xfffffffc) << (uRam02040ddc & 3) * -8 + 0x20;
  uVar1 = uVar6 + 0xfc & 3;
  uVar4 = *(uint *)(uVar6 + 0xfc & 0xfffffffc);
  uVar2 = uVar6 + 0x34 & 3;
  uVar5 = *(uint *)(uVar6 + 0x34 & 0xfffffffc);
  uVar3 = uVar6 + 0xb8 & 3;
  uVar6 = *(uint *)(uVar6 + 0xb8 & 0xfffffffc);
  return *(short *)((uint)*(ushort *)
                           ((uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20) + param_1 * 2) * 0x1c
                    + (uVar5 >> uVar2 * 8 | uVar5 << uVar2 * -8 + 0x20) + 0x18) * 0x30 +
         (uVar6 >> uVar3 * 8 | uVar6 << uVar3 * -8 + 0x20);
}

