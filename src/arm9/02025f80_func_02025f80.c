/* Decompiled C draft; module arm9; ROM address 02025f80. No matching claim. */
#include "types.h"
#include "deps/02025f80_func_02025f80.h"

void func_02025f80(int param_1,undefined4 param_2,undefined4 param_3,undefined2 param_4,
                  undefined2 param_5)

{
  *(undefined4 *)(param_1 + 8) = param_3;
  *(undefined2 *)(param_1 + 0xc) = param_4;
  *(undefined2 *)(param_1 + 0xe) = param_5;
                    /* WARNING: Could not recover jumptable at 0x02025f8a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*pcRam02025f8c)();
  return;
}

