/* Decompiled C draft; module arm9; ROM address 02043ae0. No matching claim. */
#include "types.h"
#include "deps/02043ae0_func_02043ae0.h"

void func_02043ae0(void)

{
  code *UNRECOVERED_JUMPTABLE;
  uint uVar1;
  
  UNRECOVERED_JUMPTABLE = pcRam02043b00;
  uVar1 = *(uint *)(uRam02043afc & 0xfffffffc) >> (uRam02043afc & 3) * 8 |
          *(uint *)(uRam02043afc & 0xfffffffc) << (uRam02043afc & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 4) = *(ushort *)(uVar1 + 4) | 8;
                    /* WARNING: Could not recover jumptable at 0x02043af8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

