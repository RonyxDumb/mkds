/* Decompiled C draft; module arm9; ROM address 0208bd04. No matching claim. */
#include "types.h"
#include "deps/0208bd04_func_0208bd04.h"

void func_0208bd04(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x0208bd14. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0208bd1c)(*(uint *)(uRam0208bd18 & 0xfffffffc) >> (uRam0208bd18 & 3) * 8 |
                   *(uint *)(uRam0208bd18 & 0xfffffffc) << (uRam0208bd18 & 3) * -8 + 0x20,param_1);
  return;
}

