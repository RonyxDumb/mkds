/* Decompiled C draft; module arm9; ROM address 02148f64. No matching claim. */
#include "types.h"
#include "deps/02148f64_func_02148f64.h"

void func_02148f64(void)

{
  code *UNRECOVERED_JUMPTABLE;
  undefined4 uVar1;
  
  uVar1 = uRam02148f88;
  UNRECOVERED_JUMPTABLE = pcRam02148f84;
  *puRam02148f80 =
       (*(uint *)((uint)puRam02148f80 & 0xfffffffc) >> ((uint)puRam02148f80 & 3) * 8 |
       *(uint *)((uint)puRam02148f80 & 0xfffffffc) << ((uint)puRam02148f80 & 3) * -8 + 0x20) &
       0x7fffffff;
                    /* WARNING: Could not recover jumptable at 0x02148f7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar1);
  return;
}

