/* Decompiled C draft; module arm9; ROM address 0205a7ac. No matching claim. */
#include "types.h"
#include "deps/0205a7ac_func_0205a7ac.h"

void func_0205a7ac(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = (*(uint *)(uRam0205a7d4 & 0xfffffffc) >> (uRam0205a7d4 & 3) * 8 |
          *(uint *)(uRam0205a7d4 & 0xfffffffc) << (uRam0205a7d4 & 3) * -8 + 0x20) + 0x754;
  uVar1 = uVar2 & 3;
  uVar2 = *(uint *)(uVar2 & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0205a7d0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0205a7d8)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x24 + param_1 * 2,0,2);
  return;
}

