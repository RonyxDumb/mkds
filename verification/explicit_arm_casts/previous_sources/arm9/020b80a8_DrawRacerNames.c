/* Decompiled C draft; module arm9; ROM address 020b80a8. No matching claim. */
#include "types.h"
#include "deps/020b80a8_DrawRacerNames.h"

void DrawRacerNames(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 local_90;
  undefined4 local_88;
  undefined1 auStack_80 [32];
  undefined1 *local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined1 auStack_50 [44];
  
  uVar4 = GetLoadedFont_from_thumb(0);
  uVar5 = GetSomeBgCanvasTileData_from_thumb();
  Clear1A44SomeTileData_from_thumb();
  G2d_Sprite_CreateFromTiles(auStack_80,uVar5,0x20,4,4);
  uVar7 = 0;
  local_58 = 1;
  local_88 = 0xe;
  local_90 = 0xc;
  local_60 = auStack_80;
  local_54 = 0;
  local_5c = uVar4;
  do {
    iVar1 = (uVar7 & 3) << 6;
    iVar2 = (uVar7 >> 2) * 0x10;
    FormatRacerNameString_from_thumb(uVar7,auStack_50,0);
    uVar6 = GetCurrentPlayerRacerId();
    uVar4 = local_88;
    if ((uVar7 == uVar6) &&
       (uVar6 = *(uint *)(uRam020b8218 & 0xfffffffc) >> (uRam020b8218 & 3) * 8 |
                *(uint *)(uRam020b8218 & 0xfffffffc) << (uRam020b8218 & 3) * -8 + 0x20,
       uVar4 = local_90, *(char *)(uVar6 + 0x58) != '\0')) {
      uVar6 = uVar7 * 0x30 + uVar6 + 0x74;
      uVar3 = uVar6 & 3;
      uVar6 = *(uint *)(uVar6 & 0xfffffffc);
      if (uVar6 >> uVar3 * 8 == 0 && uVar6 << uVar3 * -8 + 0x20 == 0) {
        uVar4 = 10;
      }
      else {
        uVar4 = 8;
      }
    }
    G2d_Text_PrintString(&local_60,iVar1,iVar2 + 9);
    G2d_Text_PrintString(&local_60,iVar1,iVar2 + 8,uVar4,uRam020b821c,auStack_50);
    uVar7 = uVar7 + 1 & 0xffff;
  } while (uVar7 < 8);
  return;
}

