/* Decompiled C draft; module arm9; ROM address 020096d4. No matching claim. */
#include "types.h"
#include "deps/020096d4_func_020096d4.h"

void func_020096d4(void)

{
  undefined4 *puVar1;
  
  puVar1 = puRam020096e8;
  *puRam020096e8 = 0;
  puVar1[1] = 0;
  *(undefined1 *)(puVar1 + 3) = 1;
  *puRam020096ec = 0;
                    /* WARNING: Could not recover jumptable at 0x020096e6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020096f0)();
  return;
}

