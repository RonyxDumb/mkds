/* Decompiled C draft; module arm9; ROM address 020184a0. No matching claim. */
#include "types.h"
#include "deps/020184a0_ArcEntry_ValidateNarcHeader.h"

bool ArcEntry_ValidateNarcHeader(uint param_1)

{
  if ((*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
      *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) != uRam020184dc) {
    return false;
  }
  if (*(ushort *)(param_1 + 4) == uRam020184e0) {
    return *(short *)(param_1 + 6) == 0x100;
  }
  return false;
}

