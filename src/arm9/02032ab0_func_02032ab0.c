/* Decompiled C draft; module arm9; ROM address 02032ab0. No matching claim. */
#include "types.h"
#include "deps/02032ab0_func_02032ab0.h"

void func_02032ab0(void)

{
  *(undefined4 *)(*piRam02032abc + 4) = 1;
                    /* WARNING: Could not recover jumptable at 0x02032aba. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02032ac0)();
  return;
}

