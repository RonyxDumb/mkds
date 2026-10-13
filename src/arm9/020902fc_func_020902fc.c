/* Decompiled C draft; module arm9; ROM address 020902fc. No matching claim. */
#include "types.h"
#include "deps/020902fc_func_020902fc.h"

void func_020902fc(int param_1,int param_2)

{
  uint uVar1;
  code *UNRECOVERED_JUMPTABLE;
  uint uVar2;
  
  UNRECOVERED_JUMPTABLE = pcRam02090338;
  uVar2 = (uint)*(ushort *)(param_2 + 4) * 0x210 +
          (*(uint *)(uRam02090330 & 0xfffffffc) >> (uRam02090330 & 3) * 8 |
          *(uint *)(uRam02090330 & 0xfffffffc) << (uRam02090330 & 3) * -8 + 0x20) + 0x30;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
  *(uint *)(param_1 + 4) =
       (uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0xc +
       (*(uint *)(uRam02090334 & 0xfffffffc) >> (uRam02090334 & 3) * 8 |
       *(uint *)(uRam02090334 & 0xfffffffc) << (uRam02090334 & 3) * -8 + 0x20);
                    /* WARNING: Could not recover jumptable at 0x0209032c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*UNRECOVERED_JUMPTABLE)();
  return;
}

