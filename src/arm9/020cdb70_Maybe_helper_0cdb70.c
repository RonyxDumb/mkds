/* Decompiled C draft; module arm9; ROM address 020cdb70. No matching claim. */
#include "types.h"
#include "deps/020cdb70_Maybe_helper_0cdb70.h"

void Maybe_helper_0cdb70(undefined4 param_1)

{
                    /* WARNING: Could not recover jumptable at 0x020cdb80. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020cdb88)(param_1,*(uint *)(uRam020cdb84 & 0xfffffffc) >> (uRam020cdb84 & 3) * 8 |
                           *(uint *)(uRam020cdb84 & 0xfffffffc) << (uRam020cdb84 & 3) * -8 + 0x20,0)
  ;
  return;
}

