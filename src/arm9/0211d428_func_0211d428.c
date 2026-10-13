/* Decompiled C draft; module arm9; ROM address 0211d428. No matching claim. */
#include "types.h"
#include "deps/0211d428_func_0211d428.h"

void func_0211d428(int param_1,int param_2)

{
  *(int *)(*piRam0211d440 + param_1 * 4 + 0x8c) = param_2;
                    /* WARNING: Could not recover jumptable at 0x0211d43c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam0211d448)(param_1,*(undefined4 *)(iRam0211d444 + param_2 * 4));
  return;
}

