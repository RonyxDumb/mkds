/* Decompiled C draft; module arm9; ROM address 020d0ffc. No matching claim. */
#include "types.h"
#include "deps/020d0ffc_Maybe_m_b.h"

void Maybe_m_b(void)

{
  undefined4 uVar1;
  int iVar2;
  char acStack_104 [260];
  
  iVar2 = *(int *)(*piRam020d1054 + 0xc) * 8;
  uVar1 = uRam020d1064;
  if (*(int *)(iRam020d1058 + iVar2) == 0) {
    uVar1 = uRam020d1060;
  }
  _snprintf(acStack_104,sRam020d106c,pcRam020d1070,uRam020d1074,uVar1,
            *(undefined4 *)(iRam020d105c + iVar2),uRam020d1068);
  OpenReadEntireFileBuffer_from_thumb((undefined4)(uintptr_t)(acStack_104),*piRam020d1054 + iRam020d1078,uRam020d107c);
  Gfx_ReadCharGraphicsV2((int *)(uintptr_t)(*piRam020d1054 + 4),*piRam020d1054 + iRam020d1078);
  return;
}

