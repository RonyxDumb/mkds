/* Decompiled C draft; module arm9; ROM address 02114398. No matching claim. */
#include "types.h"
#include "deps/02114398_func_02114398.h"

void func_02114398(int param_1)

{
                    /* WARNING: Could not recover jumptable at 0x021143a8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam021143b0)(*(ushort *)(*(int *)(*piRam021143ac + 4) + param_1 * 2) & 0xff);
  return;
}

