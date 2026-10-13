/* Decompiled C draft; module arm9; ROM address 020a9224. No matching claim. */
#include "types.h"
#include "deps/020a9224_func_020a9224.h"

void func_020a9224(void)

{
  int iVar1;
  
  iVar1 = CreateAllocateSomeObject_from_thumb(uRam020a9264,0,0,1,1);
  *(undefined4 *)(iVar1 + 0x38) = 0x190000;
  *(undefined4 *)(iVar1 + 0x3c) = 0xffe0c000;
  return;
}

