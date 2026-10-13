/* Decompiled C draft; module arm9; ROM address 02056d54. No matching claim. */
#include "types.h"
#include "deps/02056d54_SetMKDSSVExtraKartUnlockFlagsByState_from_thumb.h"

void SetMKDSSVExtraKartUnlockFlagsByState_from_thumb(uint param_1)

{
  if (3 < param_1) {
    *(byte *)(*(int *)*puRam02056d94 + 0x22) = *(byte *)(*(int *)*puRam02056d94 + 0x22) | 8;
  }
  if (2 < param_1) {
    *(byte *)(*(int *)*puRam02056d94 + 0x22) = *(byte *)(*(int *)*puRam02056d94 + 0x22) | 4;
  }
  if (1 < param_1) {
    *(byte *)(*(int *)*puRam02056d94 + 0x22) = *(byte *)(*(int *)*puRam02056d94 + 0x22) | 2;
  }
  return;
}

