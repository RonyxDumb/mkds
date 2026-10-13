/* Decompiled C draft; module arm9; ROM address 02148f8c. No matching claim. */
#include "types.h"
#include "deps/02148f8c_func_02148f8c.h"

void func_02148f8c(void)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  uVar1 = uRam02148fb0;
  UNRECOVERED_JUMPTABLE = pcRam02148fac;
  *puRam02148fa8 =
       (*(uint *)((uint)puRam02148fa8 & 0xfffffffc) >> ((uint)puRam02148fa8 & 3) * 8 |
       *(uint *)((uint)puRam02148fa8 & 0xfffffffc) << ((uint)puRam02148fa8 & 3) * -8 + 0x20) &
       0xbfffffff;
                    /* WARNING: Could not recover jumptable at 0x02148fa4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

