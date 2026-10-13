/* Decompiled C draft; module arm9; ROM address 02017138. No matching claim. */
#include "types.h"
#include "deps/02017138_func_02017138.h"

bool func_02017138(uint param_1)

{
  int iVar1;
  
  iVar1 = func_020169a4((uint *)(uintptr_t)(uRam02017188),(uint *)(uintptr_t)(uRam0201718c),(param_1 & uRam02017184) << 3,
                        (param_1 >> 0x10) << 3);
  return iVar1 == 0;
}

