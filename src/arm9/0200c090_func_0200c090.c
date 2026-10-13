/* Decompiled C draft; module arm9; ROM address 0200c090. No matching claim. */
#include "types.h"
#include "deps/0200c090_func_0200c090.h"

void func_0200c090(undefined4 param_1)

{
  Os_DisableIrq();
  *(undefined4 *)*puRam0200c0a8 = param_1;
  Os_RestoreIrq();
  return;
}

