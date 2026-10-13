/* Decompiled C draft; module arm9; ROM address 020a5918. No matching claim. */
#include "types.h"
#include "deps/020a5918_func_020a5918.h"

void func_020a5918(void)

{
  int iVar1;
  
  iVar1 = CreateAllocateSomeObject_from_thumb(uRam020a5954,0,0,1,0);
  *(undefined4 *)(iVar1 + 0x38) = 0x190000;
  *(undefined4 *)(iVar1 + 0x3c) = 0xffe70000;
  return;
}

