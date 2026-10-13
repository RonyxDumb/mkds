/* Decompiled C draft; module arm9; ROM address 02009cc8. No matching claim. */
#include "types.h"
#include "deps/02009cc8_func_02009cc8.h"

void func_02009cc8(void)

{
  *(undefined4 *)(*piRam02009cd8 + iRam02009cdc) = 1;
                    /* WARNING: Could not recover jumptable at 0x02009cd4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02009ce0)();
  return;
}

