/* Decompiled C draft; module arm9; ROM address 0209b5f4. No matching claim. */
#include "types.h"
#include "deps/0209b5f4_func_0209b5f4.h"

void func_0209b5f4(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 + 0x9cU & 3;
  uVar2 = *(uint *)(param_1 + 0x9cU & 0xfffffffc);
                    /* WARNING: Could not recover jumptable at 0x0209b604. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0209b608)(param_1 + 0xf0,uVar2 >> uVar1 * 8 | uVar2 << uVar1 * -8 + 0x20,0);
  return;
}

