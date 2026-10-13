/* Decompiled C draft; module arm9; ROM address 020ad268. No matching claim. */
#include "types.h"
#include "deps/020ad268_Title_SomeBldalphaConfig_from_thumb.h"

void Title_SomeBldalphaConfig_from_thumb(void)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(*piRam020ad2d8 + 100);
  *(int *)(*piRam020ad2d8 + 100) = iVar2 + 1;
  if (iVar2 < 0x1e) {
    EnableAlphaSetTopBldcntBldalpha(4,8,0,0x10);
  }
  else if (iVar2 < 0x2f) {
    EnableAlphaSetTopBldcntBldalpha(4,8,iVar2 + -0x1e,0x10 - (iVar2 + -0x1e));
  }
  else if (iVar2 < 0x6b) {
    EnableAlphaSetTopBldcntBldalpha(0,0,0,0);
  }
  else {
    EnableAlphaSetTopBldcntBldalpha(0,0,0,0);
    SetB488TitleMenuSkipIntro(1);
    piVar1 = piRam020ad2d8;
    *(undefined4 *)(*piRam020ad2d8 + 0x50) = 1;
    *(int *)(*piVar1 + 100) = *(int *)(*piVar1 + 100) + -1;
  }
  return;
}

