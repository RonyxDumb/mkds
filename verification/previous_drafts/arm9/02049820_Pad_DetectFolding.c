/* Decompiled C draft; module arm9; ROM address 02049820. No matching claim. */
#include "types.h"
#include "deps/02049820_Pad_DetectFolding.h"

int Pad_DetectFolding(void)

{
  return (int)(*puRam02049834 & 0x8000) >> 0xf;
}

