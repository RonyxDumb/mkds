/* Decompiled C draft; module arm9; ROM address 02148d5c. No matching claim. */
#include "types.h"
#include "deps/02148d5c_GX_DisableBankForBGExtPltt.h"

void GX_DisableBankForBGExtPltt(void)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  uVar1 = uRam02148d80;
  UNRECOVERED_JUMPTABLE = pcRam02148d7c;
  *puRam02148d78 =
       (*(uint *)((uint)puRam02148d78 & 0xfffffffc) >> ((uint)puRam02148d78 & 3) * 8 |
       *(uint *)((uint)puRam02148d78 & 0xfffffffc) << ((uint)puRam02148d78 & 3) * -8 + 0x20) &
       0xbfffffff;
                    /* WARNING: Could not recover jumptable at 0x02148d74. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

