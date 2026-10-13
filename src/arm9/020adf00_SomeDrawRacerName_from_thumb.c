/* Decompiled C draft; module arm9; ROM address 020adf00. No matching claim. */
#include "types.h"
#include "deps/020adf00_SomeDrawRacerName_from_thumb.h"

void SomeDrawRacerName_from_thumb(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_70 [32];
  undefined1 auStack_50 [16];
  undefined1 auStack_40 [44];
  
  uVar1 = GetLoadedFont_from_thumb(0);
  iVar2 = GetSomeBgCanvasTileData_from_thumb();
  Clear1A44SomeTileData_from_thumb();
  iVar4 = iRam020adfa4;
  iVar3 = 0;
  do {
    *(undefined2 *)(iVar2 + iVar3 * 2) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < iVar4);
  G2d_Sprite_CreateFromTiles(auStack_70,iVar2,8,2,4);
  G2d_Text_Create((undefined4 *)(void *)(auStack_50),(undefined4)(uintptr_t)(auStack_70),uVar1,2,0);
  FormatRacerNameString_from_thumb(param_1,(int)(uintptr_t)(auStack_40),0);
  uVar1 = uRam020adfa8;
  iVar3 = -1;
  iVar4 = iVar3;
  iVar2 = iVar3;
  do {
    do {
      G2d_TextCanvas_PrintString2(auStack_50,iVar2 + 0x20,iVar4 + 8,2,uVar1,auStack_40);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 2);
    iVar2 = iVar2 + 1;
    iVar4 = iVar3;
  } while (iVar2 < 2);
  G2d_TextCanvas_PrintString2(auStack_50,0x20,8,1,uRam020adfa8,auStack_40);
  uVar1 = GetSomeBgCanvasTileData_from_thumb();
  Arm_FlushRange(uVar1,uRam020adfac);
  return;
}

