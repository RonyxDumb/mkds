/* Decompiled C draft; module arm9; ROM address 02061290. No matching claim. */
#include "types.h"
#include "deps/02061290_func_02061290.h"

void func_02061290(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(uRam020612a8 & 0xfffffffc) >> (uRam020612a8 & 3) * 8 |
          *(uint *)(uRam020612a8 & 0xfffffffc) << (uRam020612a8 & 3) * -8 + 0x20;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020612a4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020612ac)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x4c);
  return;
}

