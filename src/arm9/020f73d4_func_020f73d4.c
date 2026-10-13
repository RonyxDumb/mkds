/* Decompiled C draft; module arm9; ROM address 020f73d4. No matching claim. */
#include "types.h"
#include "deps/020f73d4_func_020f73d4.h"

void func_020f73d4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x44U & 3;
  uVar2 = *(uint *)(param_1 + 0x44U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020f73f0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020f73f8)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) * 0x44 +
                   (*(uint *)(uRam020f73f4 & 0xfffffffc) >> (uRam020f73f4 & 3) * 8 |
                   *(uint *)(uRam020f73f4 & 0xfffffffc) << (uRam020f73f4 & 3) * -8 + 0x20));
  return;
}

