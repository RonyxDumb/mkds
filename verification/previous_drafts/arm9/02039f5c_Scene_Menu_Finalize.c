/* Decompiled C draft; module arm9; ROM address 02039f5c. No matching claim. */
#include "types.h"
#include "deps/02039f5c_Scene_Menu_Finalize.h"

void Scene_Menu_Finalize(void)

{
  uint uVar1;
  
  func_020cb9b8();
  uVar1 = *(uint *)(uRam02039f8c & 0xfffffffc) >> (uRam02039f8c & 3) * 8 |
          *(uint *)(uRam02039f8c & 0xfffffffc) << (uRam02039f8c & 3) * -8 + 0x20;
  *(ushort *)(uVar1 + 0x50) = *(ushort *)(uVar1 + 0x50) & 0xfffe;
  ResetRacersForTimeTrial();
  return;
}

