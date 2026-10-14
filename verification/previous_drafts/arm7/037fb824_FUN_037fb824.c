/* Decompiled C draft; module arm7; ROM address 037fb824. No matching claim. */
#include "types.h"
#include "deps/037fb824_FUN_037fb824.h"

void FUN_037fb824(ushort param_1,ushort param_2)

{
  *DAT_037fb840 = param_2 | ~param_1 & *DAT_037fb840;
  return;
}

