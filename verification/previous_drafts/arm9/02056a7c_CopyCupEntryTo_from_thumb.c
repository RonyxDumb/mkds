/* Decompiled C draft; module arm9; ROM address 02056a7c. No matching claim. */
#include "types.h"
#include "deps/02056a7c_CopyCupEntryTo_from_thumb.h"

undefined4 CopyCupEntryTo_from_thumb(int param_1,int param_2,undefined4 param_3)

{
  StructNKGPCupEntry_CopyTo_from_thumb
            ((uint *)(uintptr_t)(*(int *)(*piRam02056aa0 + 8) + 4 + param_2 * 0xe0 + param_1 * 0x1c),(ushort *)(uintptr_t)(param_3));
  return 1;
}

