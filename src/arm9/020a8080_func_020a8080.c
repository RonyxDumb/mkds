/* Decompiled C draft; module arm9; ROM address 020a8080. No matching claim. */
#include "types.h"
#include "deps/020a8080_func_020a8080.h"

void func_020a8080(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020a8090. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020a8094)(param_1 + 0x1d8,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  return;
}

