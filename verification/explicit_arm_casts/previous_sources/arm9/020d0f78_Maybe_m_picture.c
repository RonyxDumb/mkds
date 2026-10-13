/* Decompiled C draft; module arm9; ROM address 020d0f78. No matching claim. */
#include "types.h"
#include "deps/020d0f78_Maybe_m_picture.h"

void Maybe_m_picture(void)

{
  undefined4 uVar1;
  int iVar2;
  char acStack_104 [260];
  
  iVar2 = *(int *)(*piRam020d0fd0 + 0xc) * 8;
  uVar1 = uRam020d0fe0;
  if (*(int *)(iRam020d0fd4 + iVar2) == 0) {
    uVar1 = uRam020d0fdc;
  }
  _snprintf(acStack_104,sRam020d0fe8,pcRam020d0fec,uRam020d0ff0,uVar1,
            *(undefined4 *)(iRam020d0fd8 + iVar2),uRam020d0fe4);
  OpenReadEntireFileBuffer_from_thumb(acStack_104,*piRam020d0fd0 + iRam020d0ff4,uRam020d0ff8);
  MaybeReadScreenBlock_0(*piRam020d0fd0 + 8,*piRam020d0fd0 + iRam020d0ff4);
  return;
}

