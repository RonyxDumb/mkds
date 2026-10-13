/* Decompiled C draft; module arm9; ROM address 0203c8dc. No matching claim. */
#include "types.h"
#include "deps/0203c8dc_GetDriverPlace.h"

uint GetDriverPlace(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0203c940 & 0xfffffffc) >> (uRam0203c940 & 3) * 8 |
          *(uint *)(uRam0203c940 & 0xfffffffc) << (uRam0203c940 & 3) * -8 + 0x20) + 8;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  if ((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) == 5) {
    return ((uint)*(byte *)(*(char *)((*(uint *)(uRam0203c944 & 0xfffffffc) >>
                                       (uRam0203c944 & 3) * 8 |
                                      *(uint *)(uRam0203c944 & 0xfffffffc) <<
                                      (uRam0203c944 & 3) * -8 + 0x20) + (param_1 & 0xff)) * 0x88 +
                            (*(uint *)(uRam0203c948 & 0xfffffffc) >> (uRam0203c948 & 3) * 8 |
                            *(uint *)(uRam0203c948 & 0xfffffffc) << (uRam0203c948 & 3) * -8 + 0x20)
                           + 0x18a) << 0x18) >> 0x19;
  }
  return *(ushort *)
          (param_1 * 0x8c +
           (*(uint *)(uRam0203c94c & 0xfffffffc) >> (uRam0203c94c & 3) * 8 |
           *(uint *)(uRam0203c94c & 0xfffffffc) << (uRam0203c94c & 3) * -8 + 0x20) + 0x50) & 0xf;
}

