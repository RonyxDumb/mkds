/* Decompiled C draft; module arm9; ROM address 0204bcb4. No matching claim. */
#include "types.h"
#include "deps/0204bcb4_func_0204bcb4.h"

void func_0204bcb4(uint param_1)

{
  Os_DisableIrq();
  *(uint *)(iRam0204bcd8 + 0xb10) = param_1 & 0xfffffffe;
  Os_RestoreIrq();
  return;
}

