/* Decompiled C draft; module arm9; ROM address 020ab4d4. No matching claim. */
#include "types.h"
#include "deps/020ab4d4_func_020ab4d4.h"

uint func_020ab4d4(void)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = func_020ab650(uRam020ab4fc);
  if (iVar1 != 0) {
    uVar2 = func_020ab650(uRam020ab4fc);
    return uVar2 & 0xffff;
  }
  uVar2 = func_020ab500();
  return uVar2;
}

