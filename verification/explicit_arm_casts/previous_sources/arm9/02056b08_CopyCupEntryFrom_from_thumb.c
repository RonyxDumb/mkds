/* Decompiled C draft; module arm9; ROM address 02056b08. No matching claim. */
#include "types.h"
#include "deps/02056b08_CopyCupEntryFrom_from_thumb.h"

void CopyCupEntryFrom_from_thumb(int param_1,int param_2,undefined4 param_3)

{
  StructNKGPCupEntry_CopyFrom_from_thumb
            (*(int *)(*piRam02056b2c + 8) + 4 + param_2 * 0xe0 + param_1 * 0x1c,param_3);
  return;
}

