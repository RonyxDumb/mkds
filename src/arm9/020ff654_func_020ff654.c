/* Decompiled C draft; module arm9; ROM address 020ff654. No matching claim. */
#include "types.h"
#include "deps/020ff654_func_020ff654.h"

void func_020ff654(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
  *(undefined2 *)((uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20) + 0xb0) = 1;
  uVar1 = param_1 + 0x140U & 3;
  uVar2 = *(uint *)(param_1 + 0x140U & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x020ff670. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam020ff674)(uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,uRam020ff678);
  return;
}

