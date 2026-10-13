/* Decompiled C draft; module arm9_ov001; ROM address 021813f4. No matching claim. */
#include "types.h"
#include "deps/021813f4_func_ov001_021813f4.h"

void func_ov001_021813f4(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x02181404. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0218140c)(param_1,*(uint *)(uRam02181408 & 0xfffffffc) >> (uRam02181408 & 3) * 8 |
                           *(uint *)(uRam02181408 & 0xfffffffc) << (uRam02181408 & 3) * -8 + 0x20,0)
  ;
  return;
}

