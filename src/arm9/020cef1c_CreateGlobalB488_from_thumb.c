/* Decompiled C draft; module arm9; ROM address 020cef1c. No matching claim. */
#include "types.h"
#include "deps/020cef1c_CreateGlobalB488_from_thumb.h"

void CreateGlobalB488_from_thumb(void)

{
  int *piVar1;
  
  SpecialMemoryZero_0(*piRam020cef60,uRam020cef64);
  piVar1 = piRam020cef60;
  *(undefined4 *)*piRam020cef60 = 0;
  *(undefined4 *)(*piVar1 + 4) = 0;
  *(undefined4 *)(*piVar1 + 8) = 0;
  *(undefined4 *)(*piVar1 + 0xc) = 0;
  *(undefined4 *)(*piVar1 + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 0;
  *(undefined4 *)(*piVar1 + 0x1c) = 0;
  *(undefined1 *)(*piVar1 + 0x54) = 0;
  *(undefined4 *)(*piVar1 + 0x58) = 0;
  *(undefined4 *)(*piVar1 + 0x70) = 0;
  return;
}

