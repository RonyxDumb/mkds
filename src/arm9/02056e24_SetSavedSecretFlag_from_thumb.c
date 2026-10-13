/* Decompiled C draft; module arm9; ROM address 02056e24. No matching claim. */
#include "types.h"
#include "deps/02056e24_SetSavedSecretFlag_from_thumb.h"

void SetSavedSecretFlag_from_thumb(uint param_1)

{
  *(byte *)(*(int *)*puRam02056e44 + 0x20 + ((int)param_1 >> 3)) =
       *(byte *)(*(int *)*puRam02056e44 + 0x20 + ((int)param_1 >> 3)) | (byte)(1 << (param_1 & 7));
  return;
}

