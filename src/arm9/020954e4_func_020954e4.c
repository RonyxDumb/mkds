/* Decompiled C draft; module arm9; ROM address 020954e4. No matching claim. */
#include "types.h"
#include "deps/020954e4_func_020954e4.h"

void func_020954e4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020954f8. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020954fc)(uRam02095500,
                   (int)*(short *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0x2a));
  return;
}

