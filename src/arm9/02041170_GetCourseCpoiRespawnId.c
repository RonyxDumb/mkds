/* Decompiled C draft; module arm9; ROM address 02041170. No matching claim. */
#include "types.h"
#include "deps/02041170_GetCourseCpoiRespawnId.h"

uint GetCourseCpoiRespawnId(int param_1)

{
  undefined2 extraout_r1;
  uint uVar1;
  uint uVar2;
  
  uVar1 = (*(uint *)(uRam020411dc & 0xfffffffc) >> (uRam020411dc & 3) * 8 |
          *(uint *)(uRam020411dc & 0xfffffffc) << (uRam020411dc & 3) * -8 + 0x20) + 8;
  uVar2 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  if ((uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) == 2) {
    uVar2 = *(uint *)(uRam020411e0 & 0xfffffffc) >> (uRam020411e0 & 3) * 8 |
            *(uint *)(uRam020411e0 & 0xfffffffc) << (uRam020411e0 & 3) * -8 + 0x20;
    uVar1 = (uint)*(ushort *)(uVar2 + 0x100);
    _s32_div_f(uVar1 + 1,*(undefined2 *)(uVar2 + 0x28));
    *(undefined2 *)(uVar2 + 0x100) = extraout_r1;
  }
  else {
    uVar1 = (*(uint *)(uRam020411e0 & 0xfffffffc) >> (uRam020411e0 & 3) * 8 |
            *(uint *)(uRam020411e0 & 0xfffffffc) << (uRam020411e0 & 3) * -8 + 0x20) + 0x44;
    uVar2 = uVar1 & 3;
    uVar1 = *(uint *)(uVar1 & 0xfffffffc);
    uVar1 = (uint)*(byte *)(param_1 * 0x24 + (uVar1 >> uVar2 * 8 | uVar1 << uVar2 * -8 + 0x20) +
                           0x22);
  }
  return uVar1;
}

