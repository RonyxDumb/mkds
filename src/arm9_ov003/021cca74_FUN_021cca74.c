/* Decompiled C draft; module arm9_ov003; ROM address 021cca74. No matching claim. */
#include "types.h"
#include "deps/021cca74_FUN_021cca74.h"

void FUN_021cca74(int param_1)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*DAT_021cca98;
  FUN_021d17d4(*puVar1,0xffffffff,*(undefined2 *)(puVar1 + 4),
               param_1 + (uint)*(ushort *)((int)puVar1 + 0x12));
  *(char *)(*DAT_021cca98 + 0x1a) = (char)param_1;
  return;
}

