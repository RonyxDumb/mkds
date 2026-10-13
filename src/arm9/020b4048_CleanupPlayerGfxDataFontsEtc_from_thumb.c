/* Decompiled C draft; module arm9; ROM address 020b4048. No matching claim. */
#include "types.h"
#include "deps/020b4048_CleanupPlayerGfxDataFontsEtc_from_thumb.h"

void CleanupPlayerGfxDataFontsEtc_from_thumb(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar8 = iRam020b4084;
  iVar7 = 0;
  iVar6 = 0;
  do {
    *(undefined4 *)(iVar8 + iVar7 * 4) = 0;
    iVar5 = iRam020b4098;
    iVar4 = iRam020b4094;
    iVar3 = iRam020b4090;
    iVar2 = iRam020b408c;
    iVar1 = iRam020b4088;
    iVar7 = iVar7 + 1;
  } while (iVar7 < 3);
  do {
    iVar8 = iVar6 * 4;
    *(undefined4 *)(iVar1 + iVar8) = 0;
    *(undefined4 *)(iVar2 + iVar8) = 0;
    *(undefined4 *)(iVar3 + iVar8) = 0;
    *(undefined4 *)(iVar4 + iVar8) = 0;
    *(undefined4 *)(iVar5 + iVar8) = 0;
    iVar6 = iVar6 + 1;
  } while (iVar6 < 2);
  return;
}

