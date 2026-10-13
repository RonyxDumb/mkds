/* Decompiled C draft; module arm9; ROM address 020ab1a8. No matching claim. */
#include "types.h"
#include "deps/020ab1a8_func_020ab1a8.h"

void func_020ab1a8(ushort param_1,ushort param_2,ushort param_3)

{
  ushort *puVar1;
  
  puVar1 = puRam020ab1c8;
  *puRam020ab1c8 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_3;
                    /* WARNING: Could not recover jumptable at 0x020ab1c4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ab1cc)(puVar1[2] | *puVar1 | 0xf0 | puVar1[1]);
  return;
}

