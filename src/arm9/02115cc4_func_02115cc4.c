/* Decompiled C draft; module arm9; ROM address 02115cc4. No matching claim. */
#include "types.h"
#include "deps/02115cc4_func_02115cc4.h"

void func_02115cc4(void)

{
  int *piVar1;
  
  piVar1 = piRam02115ce8;
  *(undefined4 *)(*piRam02115ce8 + 0x58) = 10;
  *(undefined4 *)(*piVar1 + 0x5c) = 0;
  TextSystem_CloseDialog_from_thumb();
  TextSystem_SetButtonPressSseqId_from_thumb(0,5);
  return;
}

