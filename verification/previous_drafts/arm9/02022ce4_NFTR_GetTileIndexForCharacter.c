/* Decompiled C draft; module arm9; ROM address 02022ce4. No matching claim. */
#include "types.h"
#include "deps/02022ce4_NFTR_GetTileIndexForCharacter.h"

undefined4 NFTR_GetTileIndexForCharacter(uint param_1,uint param_2)

{
  uint uVar1;
  undefined4 uVar3;
  uint uVar4;
  ushort *puVar2;
  
  uVar1 = (*(uint *)(param_1 & 0xfffffffc) >> (param_1 & 3) * 8 |
          *(uint *)(param_1 & 0xfffffffc) << (param_1 & 3) * -8 + 0x20) + 0x10;
  uVar4 = uVar1 & 3;
  uVar1 = *(uint *)(uVar1 & 0xfffffffc);
  puVar2 = (ushort *)(uVar1 >> uVar4 * 8 | uVar1 << uVar4 * -8 + 0x20);
  while( true ) {
    if (puVar2 == (ushort *)0x0) {
      return uRam02022d40;
    }
    if ((*puVar2 <= param_2) && (param_2 <= puVar2[1])) break;
    uVar1 = (uint)(puVar2 + 4) & 3;
    uVar4 = *(uint *)((uint)(puVar2 + 4) & 0xfffffffc);
    puVar2 = (ushort *)(uVar4 >> uVar1 * 8 | uVar4 << uVar1 * -8 + 0x20);
  }
  uVar3 = NFTR_CharacterMap_GetTileIndexForCharacter();
  return uVar3;
}

