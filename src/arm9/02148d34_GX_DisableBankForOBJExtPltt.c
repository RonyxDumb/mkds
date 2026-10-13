/* Decompiled C draft; module arm9; ROM address 02148d34. No matching claim. */
#include "types.h"
#include "deps/02148d34_GX_DisableBankForOBJExtPltt.h"

void GX_DisableBankForOBJExtPltt(void)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  uVar1 = uRam02148d58;
  UNRECOVERED_JUMPTABLE = pcRam02148d54;
  *puRam02148d50 =
       (*(uint *)((uint)puRam02148d50 & 0xfffffffc) >> ((uint)puRam02148d50 & 3) * 8 |
       *(uint *)((uint)puRam02148d50 & 0xfffffffc) << ((uint)puRam02148d50 & 3) * -8 + 0x20) &
       0x7fffffff;
                    /* WARNING: Could not recover jumptable at 0x02148d4c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

