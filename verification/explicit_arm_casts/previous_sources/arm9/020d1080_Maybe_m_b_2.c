/* Decompiled C draft; module arm9; ROM address 020d1080. No matching claim. */
#include "types.h"
#include "deps/020d1080_Maybe_m_b_2.h"

void Maybe_m_b_2(void)

{
  undefined4 uVar1;
  int iVar2;
  char acStack_104 [260];
  
  iVar2 = *(int *)(*piRam020d10d4 + 0xc) * 8;
  uVar1 = uRam020d10e4;
  if (*(int *)(iRam020d10d8 + iVar2) == 0) {
    uVar1 = uRam020d10e0;
  }
  _snprintf(acStack_104,sRam020d10ec,pcRam020d10f0,uRam020d10f4,uVar1,
            *(undefined4 *)(iRam020d10dc + iVar2),uRam020d10e8);
  OpenReadEntireFileBuffer_from_thumb(acStack_104,*piRam020d10d4 + 0x10,uRam020d10f8);
  Gfx_ReadPalette(*piRam020d10d4,*piRam020d10d4 + 0x10);
  return;
}

