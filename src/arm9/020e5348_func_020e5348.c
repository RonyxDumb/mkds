/* Decompiled C draft; module arm9; ROM address 020e5348. No matching claim. */
#include "types.h"
#include "deps/020e5348_func_020e5348.h"

void func_020e5348(uint param_1,uint param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam020e536c;
  uVar2 = uRam020e5368;
  if (param_2 <= param_1) {
    param_1 = param_2;
  }
  *(short *)((*(uint *)(uRam020e5368 & 0xfffffffc) >> (uRam020e5368 & 3) * 8 |
             *(uint *)(uRam020e5368 & 0xfffffffc) << (uRam020e5368 & 3) * -8 + 0x20) + 0x6e) =
       (short)param_1;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020e5364. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20);
  return;
}

