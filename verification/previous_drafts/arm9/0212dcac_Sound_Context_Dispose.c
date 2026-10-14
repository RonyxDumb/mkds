/* Decompiled C draft; module arm9; ROM address 0212dcac. No matching claim. */
#include "types.h"
#include "deps/0212dcac_Sound_Context_Dispose.h"

void Sound_Context_Dispose(uint param_1)

{
  Sound_Context_DisposeLoadedStuff();
  Mem_Frame_Finalize(*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
                     *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20);
  return;
}

