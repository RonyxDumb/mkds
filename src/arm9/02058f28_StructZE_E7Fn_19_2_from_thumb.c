/* Decompiled C draft; module arm9; ROM address 02058f28. No matching claim. */
#include "types.h"
#include "deps/02058f28_StructZE_E7Fn_19_2_from_thumb.h"

void StructZE_E7Fn_19_2_from_thumb(void)

{
  int iVar1;
  
  iVar1 = func_02058dc0(uRam02058f4c);
  if (iVar1 == 1) {
    iVar1 = *piRam02058f50 + iRam02058f54;
    *(undefined2 *)(iVar1 + 0x10) = 0xf;
    *(undefined2 *)(iVar1 + 0x12) = 1;
  }
  return;
}

