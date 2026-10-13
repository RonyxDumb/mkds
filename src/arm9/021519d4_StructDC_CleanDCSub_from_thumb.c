/* Decompiled C draft; module arm9; ROM address 021519d4. No matching claim. */
#include "types.h"
#include "deps/021519d4_StructDC_CleanDCSub_from_thumb.h"

void StructDC_CleanDCSub_from_thumb(int param_1,int param_2)

{
  Mem_CpuFill16(0,param_1 + param_2 * 0x100,uRam021519fc);
  *(undefined1 *)(param_1 + param_2 * 0x100 + 0xe7) = 0xff;
  return;
}

