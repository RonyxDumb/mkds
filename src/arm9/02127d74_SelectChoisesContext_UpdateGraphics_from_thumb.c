/* Decompiled C draft; module arm9; ROM address 02127d74. No matching claim. */
#include "types.h"
#include "deps/02127d74_SelectChoisesContext_UpdateGraphics_from_thumb.h"

void SelectChoisesContext_UpdateGraphics_from_thumb(void)

{
  int *piVar1;
  
  piVar1 = piRam02127dac;
  *(undefined4 *)(*piRam02127dac + 0x10) = 0;
  *(undefined4 *)(*piVar1 + 0x14) = 1;
  func_02127db8();
  func_02127e30();
  if (*psRam02127db0 != 2) {
    AllocateReserveTEQSub(0x18,0,*piRam02127dac + 0x2c,uRam02127db4);
  }
  return;
}

