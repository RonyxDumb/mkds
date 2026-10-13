/* Decompiled C draft; module arm9; ROM address 02058b74. No matching claim. */
#include "types.h"
#include "deps/02058b74_StructZE_E7Fn_22_2_from_thumb.h"

void StructZE_E7Fn_22_2_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = iRam02058b9c;
  piVar1 = piRam02058b98;
  *(short *)(*piRam02058b98 + iRam02058b9c) = *(short *)(*piRam02058b98 + iRam02058b9c) + -1;
  if (*(short *)(*piVar1 + iVar2) < 0) {
    iVar2 = *piVar1 + iRam02058ba0;
    *(undefined2 *)(iVar2 + 0x10) = 7;
    *(undefined2 *)(iVar2 + 0x12) = 1;
  }
  return;
}

