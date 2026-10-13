/* Decompiled C draft; module arm9; ROM address 02061fcc. No matching claim. */
#include "types.h"
#include "deps/02061fcc_func_02061fcc.h"

void func_02061fcc(void)

{
  code *UNRECOVERED_JUMPTABLE;
  
  UNRECOVERED_JUMPTABLE = pcRam02061fe8;
  *(undefined2 *)
   (*(uint *)(uRam02061fe4 & 0xfffffffc) >> (uRam02061fe4 & 3) * 8 |
   *(uint *)(uRam02061fe4 & 0xfffffffc) << (uRam02061fe4 & 3) * -8 + 0x20) = 1;
                    /* WARNING: Could not recover jumptable at 0x02061fe0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

